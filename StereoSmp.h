/*
 * StereoSmp.h
 *
 *  Created on: 01 dic 2017
 *      Author: andrearch
 */

#ifndef STEREOSMP_H_
#define STEREOSMP_H_

struct StereoSmp
{
	StereoSmp(float left=0, float right=0): left(left), right(right) {}
	float left;
	float right;
};

#endif /* STEREOSMP_H_ */
