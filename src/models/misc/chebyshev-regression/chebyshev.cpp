// Code generated by Stan version 2.0

#include <stan/model/model_header.hpp>

namespace chebyshev_model_namespace {

using std::vector;
using std::string;
using std::stringstream;
using stan::model::prob_grad;
using stan::math::get_base1;
using stan::math::initialize;
using stan::math::stan_print;
using stan::io::dump;
using std::istream;
using namespace stan::math;
using namespace stan::prob;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

class chebyshev_model : public prob_grad {
private:
    int N;
    int K;
    vector<double> x_obs;
    vector<double> y_obs;
    matrix_d Sigma;
    vector_d mu;
    double sigma;
public:
    chebyshev_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad::prob_grad(0) {
        static const char* function__ = "chebyshev_model_namespace::chebyshev_model(%1%)";
        (void) function__; // dummy call to supress warning
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        context__.validate_dims("data initialization", "N", "int", context__.to_vec());
        N = int(0);
        vals_i__ = context__.vals_i("N");
        pos__ = 0;
        N = vals_i__[pos__++];
        context__.validate_dims("data initialization", "K", "int", context__.to_vec());
        K = int(0);
        vals_i__ = context__.vals_i("K");
        pos__ = 0;
        K = vals_i__[pos__++];
        context__.validate_dims("data initialization", "x_obs", "double", context__.to_vec(N));
        stan::math::validate_non_negative_index("x_obs", "N", N);
        x_obs = std::vector<double>(N,double(0));
        vals_r__ = context__.vals_r("x_obs");
        pos__ = 0;
        size_t x_obs_limit_0__ = N;
        for (size_t i_0__ = 0; i_0__ < x_obs_limit_0__; ++i_0__) {
            x_obs[i_0__] = vals_r__[pos__++];
        }
        context__.validate_dims("data initialization", "y_obs", "double", context__.to_vec(N));
        stan::math::validate_non_negative_index("y_obs", "N", N);
        y_obs = std::vector<double>(N,double(0));
        vals_r__ = context__.vals_r("y_obs");
        pos__ = 0;
        size_t y_obs_limit_0__ = N;
        for (size_t i_0__ = 0; i_0__ < y_obs_limit_0__; ++i_0__) {
            y_obs[i_0__] = vals_r__[pos__++];
        }

        // validate data
        try { 
            check_greater_or_equal(function__,N,1,"N");
        } catch (std::domain_error& e) { 
            throw std::domain_error(std::string("Invalid value of N: ") + std::string(e.what()));
        };
        try { 
            check_greater_or_equal(function__,K,1,"K");
        } catch (std::domain_error& e) { 
            throw std::domain_error(std::string("Invalid value of K: ") + std::string(e.what()));
        };
        stan::math::validate_non_negative_index("Sigma", "K", K);
        stan::math::validate_non_negative_index("Sigma", "K", K);
        Sigma = matrix_d(K,K);
        stan::math::validate_non_negative_index("mu", "K", K);
        mu = vector_d(K);
        sigma = double(0);

        stan::math::assign(sigma, 1.0);
        stan::math::assign(mu, rep_vector(1.0,K));
        stan::math::assign(Sigma, diag_matrix(mu));

        // validate transformed data

        // set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        num_params_r__ += K;
    }

    ~chebyshev_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;


        if (!(context__.contains_r("coefs")))
            throw std::runtime_error("variable coefs missing");
        vals_r__ = context__.vals_r("coefs");
        pos__ = 0U;
        context__.validate_dims("initialization", "coefs", "vector_d", context__.to_vec(K));
        vector_d coefs(K);
        for (int j1__ = 0U; j1__ < K; ++j1__)
            coefs(j1__) = vals_r__[pos__++];
        try { writer__.vector_unconstrain(coefs); } catch (std::exception& e) {  throw std::runtime_error(std::string("Error transforming variable coefs: ") + e.what()); }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        Eigen::Matrix<T__,Eigen::Dynamic,1>  coefs;
        (void) coefs;   // dummy to suppress unused var warning
        if (jacobian__)
            coefs = in__.vector_constrain(K,lp__);
        else
            coefs = in__.vector_constrain(K);


        // transformed parameters

        // initialized transformed params to avoid seg fault on val access
        

        // validate transformed parameters

        const char* function__ = "validate transformed params %1%";
        (void) function__; // dummy to suppress unused var warning
        // model body
        lp_accum__.add(multi_normal_log<propto__>(coefs, mu, Sigma));
        for (int i = 1; i <= N; ++i) {
            {
                T__ y_estim;
                (void) y_estim;   // dummy to suppress unused var warning
                stan::math::initialize(y_estim, DUMMY_VAR__);
                stan::math::assign(y_estim, 1.0);
                lp_accum__.add(normal_log<propto__>(get_base1(y_obs,i,"y_obs",1), y_estim, sigma));
            }
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("coefs");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "chebyshev_model_namespace::write_array(%1%)";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        vector_d coefs = in__.vector_constrain(K);
        for (int k_0__ = 0; k_0__ < K; ++k_0__) {
            vars__.push_back(coefs[k_0__]);
        }

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;



        // validate transformed parameters

        // write transformed parameters

        if (!include_gqs__) return;
        // declare and define generated quantities


        // validate generated quantities

        // write generated quantities
    }


    void write_csv_header(std::ostream& o__) const {
        stan::io::csv_writer writer__(o__);
        for (int k_0__ = 1; k_0__ <= K; ++k_0__) {
            writer__.comma();
            o__ << "coefs" << '.' << k_0__;
        }
        writer__.newline();
    }

    template <typename RNG>
    void write_csv(RNG& base_rng__,
                   std::vector<double>& params_r__,
                   std::vector<int>& params_i__,
                   std::ostream& o__,
                   std::ostream* pstream__ = 0) const {
        stan::io::reader<double> in__(params_r__,params_i__);
        stan::io::csv_writer writer__(o__);
        static const char* function__ = "chebyshev_model_namespace::write_csv(%1%)";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        vector_d coefs = in__.vector_constrain(K);
        writer__.write(coefs);

        // declare, define and validate transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;




        // write transformed parameters

        // declare and define generated quantities


        // validate generated quantities

        // write generated quantities
        writer__.newline();
    }

    static std::string model_name() {
        return "chebyshev_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= K; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "coefs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= K; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "coefs" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
    }

}; // model

} // namespace

int main(int argc, const char* argv[]) {
    try {
        return stan::gm::command<chebyshev_model_namespace::chebyshev_model>(argc,argv);
    } catch (std::exception& e) {
        std::cerr << std::endl << "Exception: " << e.what() << std::endl;
        std::cerr << "Diagnostic information: " << std::endl << boost::diagnostic_information(e) << std::endl;
        return -1;
    }
}

