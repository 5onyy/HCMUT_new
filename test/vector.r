fruits <- c("banana", "apple", "orange", "mango", "lemon")

# Access the first and third item (banana and orange)
fruits[c(1, 3)]
fruits[-2] #all the element except 2th element

repeat_each <- rep(c(1,2,3), each = 3)
repeat_each

repeat_time <- rep(c(1,2,3), time = 3)
repeat_time

repeat_indepent <- rep(c(1,2,3), times = c(5,2,1))
repeat_indepent

numbers <- seq(from = 0, to = 100, by = 20)
numbers