data {
  int<lower=1> N;
  int<lower=1> K;
  real x[N];
  real y[N];
}

parameters {
vector[K] coefs;
}

transformed parameters {
vector[K] y_estim;
for(i in 1:N)
	y_estim[i] <- eval_chebyshev(coefs, x[i]);
}

model {
vector[K] mu;
matrix[K,K] Sigma;
Sigma <- diag_matrix(rep_vector(1, K));
mu <- rep_vector(0, K);
coefs ~ multi_normal(mu, Sigma);
for(i in 1:N)
  y_estim[i] ~ normal(y[i], Sigma[1,1]);
}
