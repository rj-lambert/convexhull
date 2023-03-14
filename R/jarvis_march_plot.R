jarvis_plot = function(input){
  
  ## section to ensure the function works with both a list of vectors and
  ## a dataframe as input type
  
  if (class(input) == "data.frame"){
    # initialising the vectors
    pointlist = list()
    for (i in 1:nrow(input)){
      pointlist[[i]] = c(input[i,1], input[i,2])
    }
    input = pointlist
  } 
  
  ### plotting the convex hull
  
  # original input points
  original_x = c()
  original_y = c()
  for (i in 1:length(input)){
    original_x = c(original_x, input[[i]][1])
    original_y = c(original_y, input[[i]][2])
  }
  
  # obtaining convex hull from cpp jm
  
  convex_hull <<- jarvis_march_cpp(input)
  # initialising
  Xs = c()
  Ys = c()
  n = length(convex_hull)
  
  for (i in 1:n){
    Xs = c(Xs, convex_hull[[i]][1])
    Ys = c(Ys, convex_hull[[i]][2])
  }
  Xs = c(Xs, Xs[1])
  Ys = c(Ys, Ys[1])
  
  plot(original_x, original_y, pch = 19, col = "black", xlab = "x", ylab = "y",
       main = "Convex hull")
  lines(Xs, Ys, col = "red")
  points(Xs, Ys, pch = 19, col = "blue")
  
}