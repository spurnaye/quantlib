
/*
 * Copyright (C) 2000
 * Ferdinando Ametrano, Luigi Ballabio, Adolfo Benin, Marco Marchioro
 * 
 * This file is part of QuantLib
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated 
 * in the QuantLib License: see the file LICENSE.TXT for details.
 * Contact ferdinando@ametrano.net if LICENSE.TXT was not distributed with this file.
 * LICENCE.TXT is also available at http://quantlib.sourceforge.net/LICENSE.TXT
*/


#ifndef quantlib_normal_distribution_h
#define quantlib_normal_distribution_h

#include "qldefines.h"
#include <functional>
#include <cmath>

namespace QuantLib {

	namespace Math {

		class NormalDistribution : public std::unary_function<double,double> {
		  public:
			NormalDistribution(double average = 0.0, double sigma = 1.0);
			// function
			double operator()(double x);
		  private:
			static const double pi;
			double average, sigma, normalizationFactor, denominator;
		};
		
		typedef NormalDistribution GaussianDistribution;
		
		class CumulativeNormalDistribution : public std::unary_function<double,double> {
		  public:
			CumulativeNormalDistribution();
			// function
			double operator()(double x);
			double derivative(double x);
		  private:
			static const double a1, a2, a3, a4, a5, gamma, precision;
			NormalDistribution gaussian;
		};
		
		// inline definitions
		
		inline NormalDistribution::NormalDistribution(double average, double sigma)
		: average(average), sigma(sigma) {
			normalizationFactor = 1.0/(sigma*QL_SQRT(2.0*pi));
			denominator = 2.0*sigma*sigma;
		}
		
		inline double NormalDistribution::operator()(double x) {
			double deltax = x-average;
			return normalizationFactor*QL_EXP(-deltax*deltax/denominator);
		}
		
		inline CumulativeNormalDistribution::CumulativeNormalDistribution() {}
		
		inline double CumulativeNormalDistribution::derivative(double x) {
			return gaussian(x);
		}

	}
	
}


#endif
