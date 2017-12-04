/*
 * StereoSmp.h
 *
 *  Created on: 01 dic 2017
 *      Author: Andrea993
 */

#ifndef STEREOSMP_H_
#define STEREOSMP_H_

template <class TP=float>
struct StereoSmp
{
	StereoSmp<TP>(TP left_and_right = 0): left(left_and_right), right(left_and_right) {}
	StereoSmp<TP>(TP left, TP right): left(left), right(right) {}


	friend StereoSmp operator+ (const StereoSmp& a, const StereoSmp& b)
	{
		return StereoSmp<TP>(a.left + b.left, a.right + b.right);
	}
	friend StereoSmp operator+ (const StereoSmp& a, TP b)
	{
		return StereoSmp<TP>(a.left + b, a.right + b);
	}
	friend StereoSmp operator- (const StereoSmp& a, const StereoSmp& b)
	{
		return StereoSmp<TP>(a.left - b.left, a.right - b.right);
	}
	friend StereoSmp operator- (const StereoSmp& a, TP b)
	{
		return StereoSmp<TP>(a.left - b, a.right - b);
	}
	friend StereoSmp operator* (const StereoSmp& a, const StereoSmp& b)
	{
		return StereoSmp<TP>(a.left * b.left, a.right * b.right);
	}
	friend StereoSmp operator* (const StereoSmp& a, TP b)
	{
		return StereoSmp<TP>(a.left * b, a.right * b);
	}
	friend StereoSmp operator/ (const StereoSmp& a, const StereoSmp& b)
	{
		return StereoSmp<TP>(a.left / b.left, a.right / b.right);
	}
	friend StereoSmp operator/ (const StereoSmp& a, TP b)
	{
		return StereoSmp<TP>(a.left / b, a.right / b);
	}
	friend bool operator== (const StereoSmp& a, const StereoSmp& b)
	{
		return a.left == b.left && a.right==b.right;
	}

	StereoSmp<TP> operator=(TP a)
	{
		left = right = a;
		return *this;
	}

	StereoSmp<TP> operator+= (const StereoSmp<TP>& a)
	{
		left+=a.left;
		right+=a.right;
		return *this;
	}

	StereoSmp<TP> operator+= (TP a)
	{
		left+=a;
		right+=a;
		return *this;
	}


	StereoSmp<TP> operator-= (TP a)
	{
		left-=a;
		right-=a;
		return *this;
	}

	StereoSmp<TP> operator-= (const StereoSmp<TP>& a)
	{
		left-=a.left;
		right-=a.right;
		return *this;
	}

	StereoSmp<TP> operator*= (TP a)
	{
		left*=a;
		right*=a;
		return *this;
	}

	StereoSmp<TP> operator*= (const StereoSmp<TP>& a)
	{
		left*=a.left;
		right*=a.right;
		return *this;
	}

	StereoSmp<TP> operator/= (TP a)
	{
		left/=a;
		right/=a;
		return *this;
	}

	StereoSmp<TP> operator/= (const StereoSmp<TP>& a)
	{
		left/=a.left;
		right/=a.right;
		return *this;
	}

	TP left;
	TP right;
};

#endif /* STEREOSMP_H_ */
