#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]

std::vector<std::vector<double> > remove_duplicates(std::vector<std::vector<double> > input){
    std::sort(input.begin(), input.end());
    input.erase(std::unique(input.begin(), input.end()), input.end());
    return input;
}
