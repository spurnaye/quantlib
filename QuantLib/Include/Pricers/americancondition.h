
/*
 * Copyright (C) 2000
 * Ferdinando Ametrano, Luigi Ballabio, Adolfo Benin, Marco Marchioro
 * 
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated 
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 *
 * QuantLib license is also available at http://quantlib.sourceforge.net/LICENSE.TXT
*/

#ifndef BSM_american_condition_h
#define BSM_american_condition_h

#include "qldefines.h"
#include "bsmnumericaloption.h"
#include "finitedifferences.h"
#include <algorithm>
#include <functional>

namespace QuantLib {

	namespace Pricers {
	
		class BSMAmericanCondition : public FiniteDifferences::StepCondition<Array> {
		  public:
			BSMAmericanCondition(const Array& initialPrices) : initialPrices(initialPrices) {}
			void applyTo(Array& a, Time t) const {
				for (int i=0; i<a.size(); i++)
					a[i] = QL_MAX(a[i],initialPrices[i]);
			}
		  private:
			Array initialPrices;
		};
	
	}

}

#endif
