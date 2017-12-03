/*
 * NoiseWhiteWT.h
 *
 *  Created on: 30 nov 2017
 *      Author: andrearch
 */

#ifndef NOISEWHITEWT_H_
#define NOISEWHITEWT_H_

#include "WaveTable.h"
#include <cmath>

template <class TP>
class NoiseWhiteWT: public WaveTable<TP>
{
public:
	NoiseWhiteWT<TP>(unsigned length=1024): WaveTable<TP>(length)
	{
		for (unsigned i=0; i<length; i++)
			(*this)[i]=2*(rand()/static_cast<float>(RAND_MAX))-1;

	}

};

#endif /* NOISEWHITEWT_H_ */
