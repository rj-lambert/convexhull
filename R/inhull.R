in_hull = function(point, input){
  # function to determine if a point is in the convex hull
  
  # creating a plot to show where the point is in relation to the convex hull
  jarvis_plot(input)
  ## adding the new point
  points(x= point[1], y = point[2], pch = 15, col = "green")
  
  # obtaining the convex hull using jarvis march
  jm_output = jarvis_march(input)
  
  # cycling through all points in convex hull
  # if in the set, return true, else, false
  for (j in 1:length(jm_output)){
    if (point[1] == jm_output[[j]][[1]][1]){
      if (point[2] == jm_output[[j]][[1]][2]){
        print(paste0("(", point[1], ",", point[2], ") is in the convex hull"))
      }
    }
  }
  print(paste0("(", point[1], ",", point[2], ") is not in the convex hull"))
}