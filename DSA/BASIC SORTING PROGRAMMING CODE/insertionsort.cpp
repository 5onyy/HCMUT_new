template<typename E>
void insertionSort(List<E> &L){
	L.moveToStart();
	int j=0;
	L.next();
	int n = L.length();
	for (int i=1;i<n;i++){
		E y = L.getValue();
		L.moveToStart();
		bool f = 0;
		for (j=0; j<i; j++,L.next()){
			E x = L.getValue();
			if (x>y && f==0){
				L.insert(y);
				f = 1;
			}
		}
		if (f==1) {
		       L.next();
		       L.remove();
		}
		else L.next();
	}
}