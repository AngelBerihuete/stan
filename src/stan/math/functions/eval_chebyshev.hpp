#ifndef __STAN__MATH__FUNCTIONS__EVAL_CHEBYSHEV_HPP__
#define __STAN__MATH__FUNCTIONS__EVAL_CHEBYSHEV_HPP__

#include <boost/math/tools/polynomial.hpp>

namespace stan {
	namespace math {
		template<typename T1>
		inline T1
		eval_chebyshev(const std::vector<T1> a, const T1 x) {
			return boost::math::tools::evaluate_chebyshev(a,x);
		}
	}
}

#endif