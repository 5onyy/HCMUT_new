Print the elements of an array in the decreasing frequency order while preserving the relative order of the elements.

Students are not allowed to use map/unordered map.

iostream, algorithm libraries are included.

For example:

Test	Result
	int arr[] = {-4,1,2,2,-4,9,1,-1};
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
-4 -4 1 1 2 2 9 -1
	int arr[] = {-5,3,8,1,-9,-9};
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
-9 -9 -5 3 8 1


struct Element {
    int val;  // Element value
    int freq; // Frequency
    int idx;  // First occurrence index
};
bool compare(const Element& e1, const Element& e2) {
    // If frequencies are not equal, sort in decreasing order of frequency
    if (e1.freq != e2.freq)
        return e1.freq > e2.freq;
    
    // If frequencies are equal, sort based on first occurrence
    return e1.idx < e2.idx;
}

void sortByFrequency(int arr[], int n) {
    Element elements[n];

    // Fill elements array with elements of the input array
    for (int i = 0; i < n; i++) {
        elements[i].val = arr[i];
        elements[i].idx = i;
        elements[i].freq = 0;
    }

    // Calculate frequency
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (elements[j].val == arr[i])
                break;
        }
        
        // Increment the frequency
        elements[j].freq++;
        
        // Set index if it is the first occurrence
        if (elements[j].idx == -1 || elements[j].idx > i) 
            elements[j].idx = i;
    }

    // Sort elements based on frequency
    sort(elements, elements + n, compare);

    // Fill arr[] with elements from sorted elements[]
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int freq = elements[i].freq; freq > 0; freq--) {
            arr[j++] = elements[i].val;
        }
    }
}