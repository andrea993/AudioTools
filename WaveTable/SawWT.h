/*
 * SawWT.h
 *
 *  Created on: 29 nov 2017
 *      Author: andrearch
 */

#ifndef SAWWT_H_
#define SAWWT_H_

#include "WaveTable.h"

class SawWT: public WaveTable
{
public:
	SawWT(unsigned length=1024): WaveTable(length)
	{
		for (unsigned i=0; i<length; i++)
			operator [](i)=2.0/(length-1.0)*i-1.0;
	}

};

#endif /* SAWWT_H_ */

