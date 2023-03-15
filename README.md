# convexhull

A package for obtaining and graphically representing the convex hull of a given set of (x,y) points.

## About

The methods within this package utilise the JAavis March Algroithm for obtaining the convex hull of a set of points.

## Functions

Within this package there are 3 functions:

### jarvis_march()

Given a list of length 2 vectors or an nx2 dataframe, the function returns the line segments of the polygon whose vertices form the convex hull.

### jarvis_plot()

Given a list of length 2 vectors or an nx2 dataframe, the function plots the input datapoints in black, points in the convex hull in blue, as well as red line segments connecting these points.

### in_hull()

Given a point and a list of length 2 vectors or an nx2 dataframe, the function returns whether this point is in the convex hull. In addition, it plots this new point overlaying on the plot from the jarvis_plot() function.
