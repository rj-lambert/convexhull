#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#include "findleft-Rcpp.h"
#include "eucdist-Rcpp.h"
#include "removeduplicates-Rcpp.h"
#include "jarvismarchcpp-Rcpp.h"

#include <Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]

std::vector<std::vector<double> > jarvis_march_cpp(std::vector<std::vector<double> > input){
    // removing duplicates from the original input data
    std::vector<std::vector<double> > no_duplicates = remove_duplicates(input);
    // defining the output
    std::vector<std::vector<double> > output;
    
    // obtaining a starting point p
    std::vector<double> p = find_left(no_duplicates);
    
    // constraints for the case where number of data points <= 3
    if (no_duplicates.size() < 3){
        return no_duplicates;
    }
    // for case where 3 points
    if(no_duplicates.size() == 3){
        // check if points are all co-linear
        if((no_duplicates[1][1] - no_duplicates[0][1])*(no_duplicates[2][0] - no_duplicates[1][0]) -
          (no_duplicates[1][0] - no_duplicates[0][0])*(no_duplicates[2][1] - no_duplicates[1][1]) == 0){
            // initialising
            std::vector<std::vector<double> > pair_points;
            double pair_dist = -1;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(Euc_dist(no_duplicates[i], no_duplicates[j]) > pair_dist){
                        // updating
                        pair_points = {no_duplicates[i], no_duplicates[j]};
                        pair_dist = Euc_dist(no_duplicates[i], no_duplicates[j]);
                        }
                    }
                }
            // return the par with greatest Euclidean distance
            return pair_points;
            }
        else{
            // if not co-linear, output all 3 points
            return no_duplicates;
        }
    }
    
    // the main part of the jm algorithm
    
    // initialising the convex hull
    // including the leftmost point in the convex hull
    std::vector<std::vector<double> > ch {p};

    // iterating round the points
    while(true){   
        // initialising points q and r
        for(std::vector<double> q : no_duplicates){
            // initialising for use in determining orientation
            int acw = 0;
            // initialising for determining colinearity
            std::vector<std::vector<double> > colinear;
            std::vector<double> farq = p;
            
            // cycling through r
            for(std::vector<double> r : no_duplicates){
                if(q != p){ // q can't be p
                    if(r != p){ // r can't be p
                        if(r != q){ // r can't be q
                            //calculating cross product
                            double cp = (q[1] - p[1])*(r[0] - q[0])-
                                (q[0] - p[0])*(r[1] - q[1]);
                            //orientation depends on sign    
                            if(cp <= 0){
                                acw = acw + 1;
                            }
                            // if co-linear points
                            if(cp == 0){
                                // appending to potential qs
                                colinear.push_back(q);
                                colinear.push_back(r);
                            }
                        }
                    }
                }
                // if acw for all r
                if (acw == (no_duplicates.size() - 2)){

                    // and co-linear points exist
                    if (colinear.size() != 0){
                        // initialise
                        double distance = 0;
                        // for all potential qs
                        for(std::vector<double>colin : colinear){
                            if(Euc_dist(p, colin) > distance){
                                // update so to find furthest q from p
                                farq = colin;
                                distance = Euc_dist(p,colin);
                            }
                        }
                        // update q to be furthest q from p
                        q = farq;
                    }
                    // append q to convex hull
                    ch.push_back(q);
                    // update p
                    p = ch.back();
                    break;
                }
            }
        }
        // break condition - if appending a point already in convex hull: stop
        if (ch.size() != remove_duplicates(ch).size()){
            // creating placeholder vector
            // this ensures order is maintained -useful if we wish to plot the convex hull
            std::vector< std::vector<double> > placeholder  = remove_duplicates(ch);
            // for element in convex hull
            for(std::vector<double> ch_element : ch){
                // if it appears in the list with no duplicates
                if(std::count(placeholder.begin(), placeholder.end(), ch_element)){
                    // and isn't already in output vector
                    if(std::count(output.begin(), output.end(), ch_element)){
                    }
                    else{
                        // append
                        output.push_back(ch_element);
                    }
                    
                }
            }
            // break out of while loop
            break;
        }   
    }
    // return vector of pairs: convex hull
    return output;
}
