data {
  int<lower=1> N;
  int<lower=1> K;
  real x_obs[N];
  real y_obs[N];
}

parameters {
vector[K] coefs;
}

model {
	vector[K] mu;
	matrix[K,K] Sigma;
	real y_estim;
	mu <- rep_vector(0, K);
	Sigma <- diag_matrix(rep_vector(1, K));
	coefs ~ multi_normal(mu, Sigma);
	for(i in 1:N){
		y_estim <- eval_chebyshev(coefs, x_obs[i]);
		y_obs[i] ~ normal(y_estim, Sigma[1,1]);
	}
}
