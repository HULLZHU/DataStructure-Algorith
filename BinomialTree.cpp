#include <vector>
#include <iostream>
#include <math.h>

struct Binomial_Tree
{
    //attributes
    double sigma = 0.2;
    double prob_up = 0.5;
    double prob_down = 0.5;
    vector<double> par_rates;
    vector<double> forward_rates ;
    vector<double> spot_rates;
    vector<double> discount_factors;

    void compute_forward_rates()
    {


    }

    void print_tree()
    {

    }

};

int main()
{
    Binomial_Tree tree; // Construct a Binomial Tree
    vector<double> par_rates{0.01, 0.012, 0.015, 0.017,0.020};
    tree.par_rates = par_rates;//attach vector variable
    tree.sigma = 0.04;//define the sigma

}