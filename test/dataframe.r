# Create a data frame
Data_Frame <- data.frame (
  Training = c("Strength", "Stamina", "Other"),
  Pulse = c(100, 150, 120),
  Duration = c(60, 30, 45)
)

# Print the data frame
Data_Frame
summary(Data_Frame)
Data_Frame[["Training"]]

# Add a new row
New_row_DF <- rbind(Data_Frame, c("Strength", 110, 110))
# Print the new row
New_row_DF

New_col_DF <- cbind(Data_Frame, Steps = c(1000, 2000, 3000))
New_col_DF

length(New_col_DF) #number of column