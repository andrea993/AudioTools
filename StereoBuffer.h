/*
 * StereoBuffer.h
 *
 *  Created on: 01 dic 2017
 *      Author: Andrea993
 */

#ifndef STEREOBUFFER_H_
#define STEREOBUFFER_H_

#include "StereoSmp.h"
#include <vector>

class StereoBuffer
{
public:
	StereoBuffer(unsigned length=0): buff(length) {};
	StereoBuffer(const std::vector<StereoSmp> &buffer): buff(buffer) {};

	StereoSmp operator[] (unsigned i) const { return buff[i]; }
	StereoSmp& operator[] (unsigned i) { return buff[i]; }
	StereoSmp at(unsigned i) const { return buff.at(i); }
	StereoSmp& at(unsigned i) { return buff.at(i); }

	std::vector<StereoSmp>& Data() { return buff; }
	std::vector<StereoSmp>& ConstData() const { return buff; }

private:
	std::vector<StereoSmp> buff;

};

#endif /* STEREOBUFFER_H_ */
