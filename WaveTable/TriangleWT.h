/*
 * TriangleWT.h
 *
 *  Created on: 29 nov 2017
 *      Author: andrearch
 */

#ifndef TRIANGLEWT_H_
#define TRIANGLEWT_H_

#include "WaveTable.h"

class TriangleWT: public WaveTable
{
public:
	TriangleWT(unsigned length=1024): WaveTable(length)
	{
		unsigned i;
		for (i=0; i<length/2; i++)
			operator [](i)=2.0/(length/2)*i-1.0;
		for (; i<length-1; i++)
			operator [](i)=-2.0/(length/2-1)*i+2.0;
	}

};

#endif /* TRIANGLEWT_H_ */
