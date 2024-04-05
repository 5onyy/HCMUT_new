thisarray <- c(1:23)
multiarray <- array(thisarray, dim = c(4, 3, 2))

#multiarray[2, 3, 2]
multiarray
thisarray <- c(1:24)

# Access all the items from the first row from matrix one
multiarray <- array(thisarray, dim = c(4, 3, 2))
multiarray[c(1),,1]

# Access all the items from the first column from matrix one
multiarray <- array(thisarray, dim = c(4, 3, 2))
multiarray[,c(1),1]