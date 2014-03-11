data {
  int<lower=1> N;
  int<lower=1> K;
  real x_obs[N];
  real y_obs[N];
}

transformed data {
	matrix[K,K] Sigma;
	vector[K] mu;
	real sigma;
	sigma <- 0.04;
	mu <- rep_vector(1.0, K);
	Sigma <- diag_matrix(mu);
}

parameters {
vector[K] coefs;
}

model {
	coefs ~ multi_normal(mu, Sigma);
	for(i in 1:N){
		real y_estim; // It'll be forgotten by Stan
		y_estim <- eval_chebyshev(coefs, x_obs[i]);
		y_obs[i] ~ normal(y_estim, sigma);
	}
}
