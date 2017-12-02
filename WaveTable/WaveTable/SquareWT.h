/*
 * SquareWT.h
 *
 *  Created on: 29 nov 2017
 *      Author: andrearch
 */

#ifndef SQUAREWT_H_
#define SQUAREWT_H_

#include "WaveTable.h"

template <class TP>
class SquareWT: public WaveTable<TP>
{
public:
	SquareWT(unsigned length=1024): WaveTable<TP>(length)
	{
		unsigned i;
		for (i=0; i<length/2; i++)
			operator [](i)=1;
		for (; i<length; i++)
			operator [](i)=-1;
	}

};

#endif /* SQUAREWT_H_ */
