#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]

double Euc_dist(std::vector<double> A, std::vector<double> B){
    // difference in x
    double diff_x = A[0]-B[0];
    // difference in y
    double diff_y = A[1]-B[1];
    // pythagoras
    double dist = sqrt(pow(diff_x,2) + pow(diff_y,2));
    return dist;
}
