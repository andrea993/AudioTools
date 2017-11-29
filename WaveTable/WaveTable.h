/*
 * WaveTable.h
 *
 *  Created on: 26 nov 2017
 *      Author: andrearch
 */

#ifndef WAVETABLE_H_
#define WAVETABLE_H_

#include <cmath>
#include <vector>

class WaveTable
{
public:
	WaveTable(unsigned length=1024, float period=2*M_PI): T(period), w(length) {}
	WaveTable(const std::vector<float> &wave, float period=2*M_PI): T(period), w(wave) {}

	unsigned Length() const
	{
		return w.size();
	}

	float& operator[](unsigned i)
	{
		return w[i];
	}
	float operator[](unsigned i) const
	{
		return w[i];
	}

	float operator()(double t) const
	{
		unsigned L=w.size();
		float tL=fmod(t,T)/T*L;

		unsigned t0=floor(tL);
		unsigned t1=ceil(tL);
		float y0=w[t0];
		float y1=w[t1%L];

		if(t0==t1)
			return y0;

		return (y0-y1)/(t0-t1)*(tL-t0)+y0;
	}


private:
	float T;
	std::vector<float> w;

};


#endif /* WAVETABLE_H_ */
