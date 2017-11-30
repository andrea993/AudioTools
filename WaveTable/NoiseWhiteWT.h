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

class NoiseWhiteWT: public WaveTable
{
public:
	NoiseWhiteWT(unsigned length=1024): WaveTable(length)
	{
		for (unsigned i=0; i<length; i++)
			operator [](i)=2*(rand()/static_cast<float>(RAND_MAX))-1;

	}

};

#endif /* NOISEWHITEWT_H_ */
