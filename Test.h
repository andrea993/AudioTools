/*
 * Test.h
 *
 *  Created on: 03 dic 2017
 *      Author: andrearch
 */

#ifndef TEST_H_
#define TEST_H_

#include <cmath>
#include "OutputMaker.h"
#include "StereoSmp.h"
#include "WaveTable/SinWT.h"
#include "WaveTable/WaveTable.h"
#include "EnvelopeWindow.h"
#include <iostream>

class Test: public OutputMaker<StereoSmp<float>>
{
public:
	Test() :
		OutputMaker<StereoSmp<float>>(44100)
	{
		Tattack=0.005;
		Tdecay=0.01;
		Trelease=0.8;
		Tzero=0.2;

		Envelope decay_env;
		decay_env.attack_dur = Tattack;
		decay_env.attack_max = 1;
		decay_env.attack_type = Envelope::Type::linear;
		decay_env.decay_dur = Tdecay;
		decay_env.decay_min = 0.8;
		decay_env.decay_type = Envelope::Type::linear;
		decay_env.release_dur = Trelease;
		decay_env.release_type = Envelope::Type::exponential;
		decay_env.tauFactor = 5;

		d_envWin.setEnvelope(decay_env);


	}

	StereoSmp<float> MakeSample()
	{
		float dur = Tattack + Tdecay + Trelease + Tzero;
		StereoSmp<float> y=Kick(fmod(t(),dur));

		SampleMade();
		return y;

	}

private:
	SinWT<float> sinwt;
	float Tattack, Tdecay, Trelease, Tzero;
	EnvelopeWindow<float> d_envWin;

	float Kick(float t)
	{
		if (t <= Tattack + Tdecay)
			return sinwt(2*M_PI*200*t)*d_envWin.Value(t);

		else if (t <= Trelease)
			return sinwt(2*M_PI*70*t)*d_envWin.Value(t, Tattack + Tdecay);
		else
			return 0;

	}







};

#endif /* TEST_H_ */
