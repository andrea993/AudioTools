/*
 * NoisePinkWT.h
 *
 *  Created on: 30 nov 2017
 *      Author: andrearch
 */

#ifndef NOISEPINKWT_H_
#define NOISEPINKWT_H_

#include "WaveTable.h"
#include "../Filter.h"
#include <cmath>


template <class TP>
class NoisePinkWT : public WaveTable<TP>
{
public:
	NoisePinkWT<TP>(unsigned length=1024): WaveTable<TP>(length)
	{
		Filter<TP> rc_filt(Filter<TP>::FilterCoeff({0.5},{1,-0.5}));

		for (unsigned i=0; i<length; i++)
			operator [](i)=rc_filt.filter(2*(rand()/static_cast<float>(RAND_MAX))-1);

	}

};

#endif /* WAVETABLE_NOISEPINKWT_H_ */
