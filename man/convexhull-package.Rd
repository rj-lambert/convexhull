\name{convexhull-package}
\alias{convexhull-package}
\alias{convexhull}
\docType{package}
\title{
  Package to obtain the convex hull of a set of points.
}
\description{
  This package implements the Jarvis March algorithm for obtaining the convex
  hull of a given list of (x,y) co-ordinate pairs.
}
\details{
  This section should provide a more detailed overview of how to use the
  package, including the most important functions.
}
\author{
Robert Lambert: r.lambert1@lancaster.ac.uk

\keyword{convexhull}

\examples{
  \dontrun{
     ## implementing the Jarvis march algorithm:
     
     # can take a list of vectors or data frame as input
     
     df = data.frame(x = rnorm(100,1,1), y = rnorm(100,2,5))
     jarvis_march(df)
     
     # plotting the convex hull
     
     jarvis_plot(df)
     
     # determining if a point is in the convexhull
     
     in_hull(c(0,0), df)
     
  }
}
