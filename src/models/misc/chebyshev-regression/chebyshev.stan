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
	cholesky_factor_cov[K] L;
	real y_estim;
	coefs ~ multi_normal(mu, L*L');
	for(i in 1:N){
		y_estim <- eval_chebyshev(coefs, x_obs[i]);
		y_obs[i] ~ normal(y_estim, Sigma[1,1]);
	}
}
