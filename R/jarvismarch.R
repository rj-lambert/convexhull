jarvis_march = function(input){
  # initialising the output
  output = c()
  # obtaining convex hull from cpp jm
  convex_hull = jarvis_march_cpp(input)
  for (i in 1:length(convex_hull)){
    # for all except last point
    if (i < length(convex_hull)){
      output = c(output, cbind(convex_hull[i], convex_hull[i + 1]))
      }
    else{
      output = c(output, cbind(convex_hull[i], convex_hull[1]))
    }
  }
  return(output)
}

