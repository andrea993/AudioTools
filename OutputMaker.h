/*
 * OutputMaker.h
 *
 *  Created on: 02 dic 2017
 *      Author: andrearch
 */

#ifndef OUTPUTMAKER_H_
#define OUTPUTMAKER_H_

template <class TP>
class OutputMaker
{
public:
	OutputMaker<TP>(double SR=44100): _SR(SR), _dt(1.0/SR), _t(0) {}
	virtual ~OutputMaker() {}

	virtual TP MakeSample() = 0;


	double t() const { return _t; }
	double SR() const { return _SR; }
	double dt() const { return _dt; }
	unsigned SamplesCount() const { return _t/_dt; }

	void SampleMade() //call this function at the end of MakeSample()
	{
		_t += _dt;
	}

private:
	double _t;
	double _SR;
	double _dt;

};

#endif /* OUTPUTMAKER_H_ */
