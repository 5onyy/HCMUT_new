void printArray(int n)
{
    if (n==0)   {cout<<0;   return;}
    printArray(n-1);
    cout<<", "<<n;
}