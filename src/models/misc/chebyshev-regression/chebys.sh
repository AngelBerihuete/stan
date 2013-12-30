#!/bin/bash

../../../../bin/stanc --o=chebyshev.cpp chebyshev.stan

g++ -O3 -L/home/angel/stan/bin -I/home/angel/stan/src \
-I/home/angel/stan/lib/boost_1.54.0 -I/home/angel/stan/lib/eigen_3.2.0 \
chebyshev.cpp -o chebyshev