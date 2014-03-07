#!/bin/bash
for i in {1..4}
do			
./chebyshev sample random seed=12345 id=$i \
data file=chebyshev.dataset.R \
output file=samples$i.csv &	\
done