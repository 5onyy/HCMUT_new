bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
   for (int i = 0; i < n - 3; i++)
       for (int j = i + 1; j < n - 2; j++)
           for (int k = j + 1; k < n - 1; k++)
               for (int l = k + 1; l < n; l++){
                   vector<int> test = {arr[i] , arr[j], arr[k], arr[l]};
                   sort(test.begin(),test.end());
                   if ( test[0] + test[3] == test[1] + test[2])    {
                       pair1 = {test[0], test[3]};   pair2 = {test[1], test[2]};  return 1;
                       
                   }
               }   
   return 0;
}