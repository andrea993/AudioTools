/*
 * SinWT.h
 *
 *  Created on: 26 nov 2017
 *      Author: andrearch
 */

#ifndef SINWT_H_
#define SINWT_H_

#include "WaveTable.h"
#include <cmath>

template <class TP>
class SinWT: public WaveTable<TP>
{
public:
	SinWT<TP>(unsigned length=1024): WaveTable<TP>(length)
	{
		double dt=1.0/(length+1.0);
		for (unsigned i=0; i<length; i++)
			(*this)[i]=sin(2*M_PI*i*dt);
	}

};
#endif /* SINWT_H_ */
