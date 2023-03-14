jarvis_march = function(input){
  # initialising the output
  output = list()
  
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
  
  # obtaining convex hull from cpp jm
  convex_hull = jarvis_march_cpp(input)
  for (i in 1:length(convex_hull)){
    # for all except last point
    if (i < length(convex_hull)){
      vec = c(convex_hull[i], convex_hull[i + 1])
      output[[length(output) + 1]] = vec
      }
    else{
      vec = c(convex_hull[i], convex_hull[1])
      output[[length(output) + 1]] = vec
    }
  }
  return(output)
}
