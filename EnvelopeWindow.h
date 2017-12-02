/*
 * EnvelopeWindow.h
 *
 *  Created on: 02 dic 2017
 *      Author: Andrea993
 */

#ifndef ENVELOPEWINDOW_H_
#define ENVELOPEWINDOW_H_

#include "WaveTable/WaveTable.h"
#include <cmath>

struct Envelope
{
	enum class Type { linear, exponential };

	float attack_dur;
	float attack_max;
	Type attack_type;

	float decay_dur;
	float decay_min;
	Type decay_type;

	float release_dur;
	Type release_type;

	float tauFactor;
};


class EnvelopeWindow
{
private:
	Envelope e;
	WaveTable att_dec;
	WaveTable rel;


	void WriteWave()
	{
		double dt = 1.0/WINSR;

		double t=0;
		unsigned i;
		for (i=0; i<WINSR*e.attack_dur; i++)
		{
			switch (e.attack_type)
			{
			case Envelope::Type::linear:
				att_dec[i]=e.attack_max/e.attack_dur*t;
				break;
			case Envelope::Type::exponential:
				att_dec[i]=e.attack_max*(1-exp(-t/(e.attack_dur/e.tauFactor)));
				break;
			}

			t+=dt;
		}

		t=0;
		for (; i<att_dec.Length(); i++)
		{
			switch (e.decay_type)
			{
			case Envelope::Type::linear:
				att_dec[i]=-(e.attack_max-e.decay_min)/e.decay_dur*t+e.attack_max;
				break;
			case Envelope::Type::exponential:
				att_dec[i]=(1-e.decay_min)*exp(-t/(e.decay_dur/e.tauFactor))+e.decay_min;
				break;
			}

			t+=dt;
		}

		t=0;
		for (i=0; i<rel.Length(); i++)
		{
			switch (e.release_type)
			{
			case Envelope::Type::linear:
				rel[i]=-e.decay_min/e.release_dur*t+e.decay_min;
				break;
			case Envelope::Type::exponential:
				rel[i]=e.decay_min*exp(-t/(e.release_dur/e.tauFactor));
				break;
			}

			t+=dt;
		}

	}

public:
	const double WINSR = 200; // window sampling rate

	EnvelopeWindow() {}
	EnvelopeWindow(const Envelope& envelope):
		e(envelope),
		att_dec(WINSR*(e.attack_dur+e.decay_dur), e.attack_dur+e.decay_dur),
		rel(WINSR*e.release_dur,e.release_dur)
	{
		WriteWave();
	}

	Envelope Envelope() const { return e; }
	void setEnvelope(const Envelope& envelope)
	{
		e=envelope;

		att_dec.Data().resize((WINSR*(e.attack_dur+e.decay_dur)));
		att_dec.setPeriod(e.attack_dur+e.decay_dur);

		rel.Data().resize(WINSR*e.release_dur);
		rel.setPeriod(e.release_dur);

		WriteWave();
	}

	float Value(double t, double releasedAt = -1) // if releaseAt is negative it assumes that the key is pressed
	{
		if (releasedAt < 0)
		{
			t-=releasedAt;
			if (t > e.release_dur)
				return 0;

			return rel(t);
		}
		else
		{
			if (t > (e.attack_dur + e.decay_dur))
				return e.decay_min;

			return att_dec(t);
		}
	}

};

#endif /* ENVELOPEWINDOW_H_ */
