#!/bin/bash

../../../../bin/stanc --o=chebyshev.cpp chebyshev.stan

g++ -O3 -L../../../../bin -I../../../../src \
-isystem../../../../lib/boost_1.54.0 -isystem../../../../lib/eigen_3.2.0 \
chebyshev.cpp -o chebyshev -lstan