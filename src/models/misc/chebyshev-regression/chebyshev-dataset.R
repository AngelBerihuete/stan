# R example
require(chebpol)

f <- function(x) cos(3*pi*x)/(1+25*(x-0.25)^2) # funtion to approximate
f <- function(x) x^2 # funtion to approximate

# Make a standard Chebyshev interpolation
y <- evalongrid(f,10) # f evaluation on 50 knots (Chebyshev grid)
coef <- chebcoef(y) # Chebyshev coefs

# coef
#  [1] -2.986001e-02 -2.612925e-02  1.683954e-02  4.622027e-02 -3.076064e-02
#  [6] -9.918270e-02 -8.274922e-02  7.930017e-02  1.731641e-01 -1.515823e-03
# [11] -1.537712e-01 -5.625417e-02  8.885969e-02  7.217681e-02 -3.163819e-02
# [16] -6.047045e-02 -2.962661e-03  3.895612e-02  1.749633e-02 -1.888014e-02
# [21] -1.914716e-02  4.894181e-03  1.466366e-02  2.601669e-03 -8.696492e-03
# [26] -5.197031e-03  3.699522e-03  4.926206e-03 -4.901816e-04 -3.465785e-03
# [31] -1.057763e-03  1.878391e-03  1.451997e-03 -6.669031e-04 -1.230061e-03
# [36] -4.921875e-05  7.963292e-04  3.517882e-04 -3.865226e-04 -3.887842e-04
# [41]  9.819425e-05  2.968534e-04  5.794363e-05 -1.704946e-04 -1.114796e-04
# [46]  6.050256e-05  1.007302e-04  1.393397e-05 -5.684359e-05 -5.019685e-05

tch <- Vectorize(function(x) chebeval(x,coef)) # Given Chebyshev coefficients,
# evaluate the interpolation in x point.

# check interpolation
x <- chebknots(2)[[1]] # using 50 knots for clarity in the process
chebknots(2)[[1]] # using 50 knots for clarity in the process
plot(x,f(x), type = 'l')
lines(x,tch(x),col='blue')

N <- length(x)
dump(c("N","x","y"),"chebyshev.data.R")

