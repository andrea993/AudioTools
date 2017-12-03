/*
 * Filter.h
 *
 *  Created on: 29 nov 2017
 *      Author: Andrea993
 */

#ifndef FILTER_H_
#define FILTER_H_

#include <vector>
#include <stdexcept>
#include <initializer_list>

struct FilterCoeff
{
	FilterCoeff(const std::vector<double>& b, const std::vector<double>& a={}): a(a),b(b) {}
	FilterCoeff(const std::initializer_list<double>& b={}, const std::initializer_list<double>& a={}): a(a),b(b) {}
	std::vector<double> b;
	std::vector<double> a;

	int Order() const { return std::max(b.size(), a.size())-1; }
};

template <class TPS>
struct FilterState
{
	FilterState<TPS>(unsigned u_size=0, unsigned y_size=0): u_state(u_size), y_state(y_size) {}
	FilterState<TPS>(const FilterCoeff& coeff)
	{
		u_state=std::vector<TPS>(coeff.b.size() > 0 ? coeff.b.size()-1 : 0, 0);
		y_state=std::vector<TPS>(coeff.a.size() > 0 ? coeff.a.size()-1 : 0, 0);
	}

	std::vector<TPS> u_state;
	std::vector<TPS> y_state;
};

template <class TP>
class Filter
{
public:


	Filter<TP>(const FilterCoeff& coeff={}, const FilterState<TP> &state={}): c(coeff), s(state)
	{
		if (coeff.a.size() > 0 && coeff.b.size() == 0)
			throw std::logic_error("Filter: the filter seems to be an IIR filter but it miss 'b' coefficients");

		if (state.u_state.size() ==0 && state.y_state.size() == 0)
			s = FilterState<TP>(coeff);

		if (FilterState<TP>(coeff).u_state.size() != s.u_state.size() || FilterState<TP>(coeff).y_state.size() != s.y_state.size())
			throw std::logic_error("Filter: the FilterState contains vectors of bad length");

		normalizeCoeff();
	}

	TP filter(TP u)
	{
		unsigned N=c.Order()+1;

		if (N == 0)
			throw std::logic_error("Filter: this filter is not initialized");

		TP y=u*c.b[0];

		for (unsigned i=1; i<N; i++)
		{
			double ai=0, bi=0;
			TP ui=0, yi=0;

			if(i<c.b.size())
			{
				ui=s.u_state[i-1];
				bi=c.b[i];
			}

			if(i<c.a.size())
			{
				yi=s.y_state[i-1];
				ai=c.a[i];
			}

			y += ui*bi-yi*ai;
		}

		//update state
		for (int i=s.u_state.size()-1; i>0; i--)
			s.u_state[i]=s.u_state[i-1];

		if (s.u_state.size() > 0)
			s.u_state[0]=u;

		for (int i=s.y_state.size()-1; i>0; i--)
			s.y_state[i]=s.y_state[i-1];

		if (s.y_state.size() > 0)
			s.y_state[0]=y;

		return y;
	}

	void setCoeff(const FilterCoeff& coeff)
	{
		c=coeff;
		s = FilterState<TP>(coeff);
		normalizeCoeff();
	}

	void setState(const FilterState<TP> &state)
	{
		if (FilterState<TP>(c).u_state.size() != s.u_state.size() || FilterState<TP>(c).y_state.size() != s.y_state.size())
			throw std::logic_error("Filter: the FilterState contains vectors of bad length");

		s=state;
	}

	int Order() const { return c.Order(); }
	FilterCoeff Coeff() const { return c; }
	FilterState<TP> State() const { return s; }


private:
	FilterState<TP> s;
	FilterCoeff c;

	void normalizeCoeff()
	{
		if (c.a.size() > 0)
		{
			double a0=c.a[0];

			for (unsigned i=0; i<c.a.size();i++)
				c.a[i]/=a0;

			for (unsigned i=0; i<c.b.size();i++)
				c.b[i]/=a0;
		}

	}


};

#endif /* FILTER_H_ */
