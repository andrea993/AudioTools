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


	template <typename TE> friend StereoSmp<TE> operator+ (const StereoSmp<TE>& a, const StereoSmp<TE>& b);
	template <typename TE> friend StereoSmp<TE> operator+ (const StereoSmp<TE>& a, TE b);
	template <typename TE> friend StereoSmp<TE> operator- (const StereoSmp<TE>& a, const StereoSmp<TE>& b);
	template <typename TE> friend StereoSmp<TE> operator- (const StereoSmp<TE>& a, TE b);
	template <typename TE> friend StereoSmp<TE> operator* (const StereoSmp<TE>& a, const StereoSmp<TE>& b);
	template <typename TE> friend StereoSmp<TE> operator* (const StereoSmp<TE>& a, TE b);
	template <typename TE> friend StereoSmp<TE> operator/ (const StereoSmp<TE>& a, const StereoSmp<TE>& b);
	template <typename TE> friend StereoSmp<TE> operator/ (const StereoSmp<TE>& a, TE b);
	template <typename TE> friend bool operator== (const StereoSmp<TE>& a, const StereoSmp<TE>& b);

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

template <typename TE>
StereoSmp<TE> operator/ (const StereoSmp<TE>& a, const StereoSmp<TE>& b)
{
	return StereoSmp<TE>(a.left/b.left, a.right/b.right);
}

template <typename TE>
StereoSmp<TE> operator/ (const StereoSmp<TE>& a, TE b)
{
	return StereoSmp<TE>(a.left/b, a.right/b);
}

template <typename TE>
StereoSmp<TE> operator* (const StereoSmp<TE>& a, const StereoSmp<TE>& b)
{
	return StereoSmp<TE>(a.left*b.left, a.right*b.right);
}

template <typename TE>
StereoSmp<TE> operator* (const StereoSmp<TE>& a, TE b)
{
	return StereoSmp<TE>(a.left*b, a.right*b);
}

template <typename TE>
StereoSmp<TE> operator+ (const StereoSmp<TE>& a, const StereoSmp<TE>& b)
{
	return StereoSmp<TE>(a.left+b.left, a.right+b.right);
}

template <typename TE>
StereoSmp<TE> operator+ (const StereoSmp<TE>& a, TE b)
{
	return StereoSmp<TE>(a.left+b, a.right+b);
}

template <typename TE>
StereoSmp<TE> operator- (const StereoSmp<TE>& a, const StereoSmp<TE>& b)
{
	return StereoSmp<TE>(a.left-b.left, a.right-b.right);
}

template <typename TE>
StereoSmp<TE> operator- (const StereoSmp<TE>& a, TE b)
{
	return StereoSmp<TE>(a.left-b, a.right-b);
}

template <typename TE>
bool operator== (const StereoSmp<TE>& a, const StereoSmp<TE>& b)
{
	return a.left == b.left && a.right==b.right;
}

#endif /* STEREOSMP_H_ */
