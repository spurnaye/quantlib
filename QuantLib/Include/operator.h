
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


#ifndef quantlib_operator_h
#define quantlib_operator_h

#include "qldefines.h"

namespace QuantLib {

	namespace PDE {
	
		class TimeConstantOperator {
		  public:
			enum { isTimeDependent = 0 };
		};
		
		class TimeDependentOperator {
		  public:
			enum { isTimeDependent = 1 };
		};
	
	}

}


#endif
