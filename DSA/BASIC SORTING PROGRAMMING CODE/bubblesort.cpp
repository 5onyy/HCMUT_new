template<typename E> 
void bubbleSort(List<E> &L){
    for (int i=0;i<L.length();i++){
        L.moveToStart();
        for (int j=0; j<L.length()-i-1;j++){
            E curr = L.getValue();
            L.next();
            E next = L.getValue();
            if (curr>next){
                L.moveToPos(j);
                E tmp = L.getValue();
                L.remove();
                L.next();
                L.insert(tmp);
            }
        }
    }    
}