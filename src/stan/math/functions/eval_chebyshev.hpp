#ifndef __STAN__MATH__FUNCTIONS__EVAL_CHEBYSHEV_HPP__
#define __STAN__MATH__FUNCTIONS__EVAL_CHEBYSHEV_HPP__

#include <boost/math/tools/polynomial.hpp>
//#include <boost/math/tools/promotion.hpp>

namespace stan {
  namespace math {
    inline double eval_chebyshev(const std::vector<double>& a, const double x) {
	return boost::math::tools::evaluate_chebyshev(a,x);
    }
  }
}
#endif
