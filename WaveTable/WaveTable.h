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

template <class TP>
class WaveTable
{
public:
	WaveTable<TP>(unsigned length=1024, float period=2*M_PI, const Filter* filter=nullptr): T(period), w(length), filt(filter){}
	WaveTable<TP>(const std::vector<float> &wave, float period=2*M_PI, const Filter<TP>* filter=nullptr): T(period), w(wave), filt(filter) {}

	unsigned Length() const { return w.size(); }
	float Period() const { return T; }
	std::vector<float> ConstData() const { return w; }
	std::vector<float> Data() { return w; }
	Filter<TP>* Filter() { return filt; }
	Filter<TP>* Filter() const { return filt; }
	void setPeriod(float period) { T=period; }
	void setWave(const std::vector<TP> &wave) { w=wave; }
	void setFilter(const Filter<TP>* filter) { filt=filter; }


	TP& operator[](unsigned i) {	return w[i]; }
	TP operator[](unsigned i) const { return w[i]; }

	TP operator()(double t) const
	{
		unsigned L=w.size();
		float tL=fmod(t,T)/T*L;

		unsigned t0=floor(tL);
		unsigned t1=ceil(tL);
		TP y0=w[t0];
		TP y1=w[t1%L];

		TP y;
		if(t0==t1)
			y=y0;
		else
			y=(y0-y1)/(t0-t1)*(tL-t0)+y0;

		if (filt != nullptr && filt->Order()>=0)
			y=filt->filter(y);

		return y;
	}

	virtual ~WaveTable()
	{
		if (filt != nullptr)
			delete filt;
	}


private:
	float T;
	std::vector<TP> w;
	Filter<TP> *filt;

};



#endif /* WAVETABLE_H_ */
