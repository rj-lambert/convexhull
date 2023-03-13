#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]

std::vector<double> find_left(std::vector<std::vector<double> > points){
    // initialising leftmost point
    std::vector<double> leftmost = points.front();
    // cycling through to find leftmost point
    for(std::vector<double> point : points){
        if(point[0] < leftmost[0]){
        leftmost = point;
        }
        if(point[0] == leftmost[0]){
            if(point[1] < leftmost[1]){
            leftmost = point;
            }
        }
    }
    return leftmost;
}
