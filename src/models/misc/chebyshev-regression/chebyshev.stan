data {
  int<lower=1> N;
  int<lower=1> K;
  real x_obs[N];
  real y_obs[N];
  matrix[K,K] Sigma;
  vector[K] mu;
}

parameters {
vector[K] coefs;
}

model {
	real y_estim;
	coefs ~ multi_normal(mu, Sigma);
	for(i in 1:N){
		y_estim <- eval_chebyshev(coefs, x_obs[i]);
		y_obs[i] ~ normal(y_estim, Sigma[1,1]);
	}
}
