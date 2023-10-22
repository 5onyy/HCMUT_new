template <typename E> 
void selectionSort(List<E> &L){
    L.moveToStart();
    int n=L.length();
    for (int i=0;i<n-1;i++,L.next()){
        int lowIndex = i;
        for (int j=n-1;j>i;j--){
            L.moveToPos(j);
            E y = L.getValue(); //a[j]
            L.moveToPos(lowIndex);
            E x = L.getValue();     //a[lowIndex]
            if (y<x)    lowIndex = j;  
        }
        L.moveToPos(i);
        E tmp = L.getValue();
        L.moveToPos(lowIndex);
        E tmp2 = L.getValue();
        L.insert(tmp);
        L.next();   L.remove();
        L.moveToPos(i);
        L.insert(tmp2); 
        L.next();   L.remove();
    }
}