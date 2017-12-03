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
#include "../Filter.h"

template <class TP, class TPF=TP>
class WaveTable
{
public:
	WaveTable<TP, TPF>(unsigned length=1024, float period=2*M_PI, bool oneShot=false, const Filter<TPF>& filter=Filter<TPF>()):
		T(period), w(length), oneShot(oneShot), filt(filter) {}

	WaveTable<TP, TPF>(const std::vector<float> &wave, float period=2*M_PI, bool oneShot=false, const Filter<TPF>& filter=Filter<TPF>()):
		T(period), w(wave), oneShot(oneShot), filt(filter) {}


	unsigned Length() const { return w.size(); }
	float Period() const { return T; }
	std::vector<float> ConstData() const { return w; }
	std::vector<float> Data() { return w; }
	Filter<TPF>& getFilter() { return filt; }
	Filter<TPF> getFilter() const { return filt; }
	void setPeriod(float period) { T=period; }
	void setWave(const std::vector<TP> &wave) { w=wave; }
	void setFilter(const Filter<TPF> &filter) { filt=filter; }
	bool isOneShot() const { return oneShot; }
	void setOneShot(bool oneShot) { this->oneShot = oneShot; }
	void Resize(unsigned length) { w.resize(length); }


	TP& operator[](unsigned i) { return w[i]; }
	TP operator[](unsigned i) const { return w[i]; }

	TP operator()(double t)
	{
		if (oneShot && t>T)
		{
			if (filt.Order() >= 0)
				return filt.filter(TP(0));

			return TP(0);
		}

		unsigned L=w.size();

		float tL=fmod(t,T)/T*L;

		int t0=floor(tL);
		int t1=ceil(tL);
		TP y0=w[t0];
		TP y1=w[t1%L];

		TP y;
		if(t0==t1)
			y=y0;
		else
			y=(y0-y1)/(t0-t1)*(tL-t0)+y0;

		if (filt.Order() >= 0)
			y=filt.filter(y);

		return y;
	}

private:
	float T;
	bool oneShot;
	std::vector<TP> w;
	Filter<TPF> filt;

};



#endif /* WAVETABLE_H_ */
