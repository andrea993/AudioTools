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

	friend StereoSmp operator+ (const StereoSmp& a, const StereoSmp& b);
	friend StereoSmp operator+ (const StereoSmp& a, float b);
	friend StereoSmp operator* (const StereoSmp& a, const StereoSmp& b);
	friend StereoSmp operator* (const StereoSmp& a, float b);
	friend bool operator== (const StereoSmp& a, const StereoSmp& b);

	StereoSmp operator=(float a)
	{
		left = right = a;
		return *this;
	}

	StereoSmp operator+= (const StereoSmp& a)
	{
		left+=a.left;
		right+=a.right;
		return *this;
	}

	StereoSmp operator+= (float a)
	{
		left+=a;
		right+=a;
		return *this;
	}

	StereoSmp operator*= (const StereoSmp& a)
	{
		left*=a.left;
		right*=a.right;
		return *this;
	}

	StereoSmp operator*= (float a)
	{
		left*=a;
		right*=a;
		return *this;
	}


	float left;
	float right;
};

StereoSmp operator* (const StereoSmp& a, const StereoSmp& b)
{
	return StereoSmp(a.left*b.left, a.right*b.right);
}

StereoSmp operator* (const StereoSmp& a, float b)
{
	return StereoSmp(a.left*b, a.right*b);
}

StereoSmp operator+ (const StereoSmp& a, const StereoSmp& b)
{
	return StereoSmp(a.left+b.left, a.right+b.right);
}

StereoSmp operator+ (const StereoSmp& a, float b)
{
	return StereoSmp(a.left+b, a.right+b);
}

bool operator== (const StereoSmp& a, const StereoSmp& b)
{
	return a.left == b.left && a.right==b.right;
}

#endif /* STEREOSMP_H_ */
