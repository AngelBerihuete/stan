#ifndef __STAN__MATH__FUNCTIONS__EVAL_CHEBYSHEV_HPP__
#define __STAN__MATH__FUNCTIONS__EVAL_CHEBYSHEV_HPP__

#include <boost/math/tools/promotion.hpp>
#include <stan/math/matrix/Eigen.hpp>

namespace stan {
	namespace math {
		template <typename T1, typename T2>
		inline typename boost::math::tools::promote_args<T1,T2>::type
		eval_chebyshev(const Eigen::Matrix<T1,Eigen::Dynamic,1>& a , const T2& x) {
		typename boost::math::tools::promote_args<T1, T2>::type yk2 = 0, yk1 = 0, yk = 0;
			for(int i = a.size() - 1; i >= 1; --i) { 
  				yk2 = yk1; yk1 = yk; 
  				yk = 2 * x * yk1 - yk2 + a[i]; 
			} 
		return a[0] / 2 + yk * x - yk1; 
		}
	}
}
//std::vector<T1>& a
#endif

