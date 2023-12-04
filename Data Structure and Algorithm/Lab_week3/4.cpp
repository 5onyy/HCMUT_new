// Given a list of distinct unsorted integers nums.

// Your task is to implement a function with following prototype:
// int minDiffPairs(int* arr, int n);
// This function identify and return all pairs of elements with the smallest absolute difference among them. If there are multiple pairs that meet this criterion, the function should find and return all of them.

// Note: Following libraries are included: iostream, string, algorithm, sstream
string minDiffPairs(int* arr, int n) {
    if (n < 2) {
        return "";
    }

    std::sort(arr, arr + n);  
    
    int minDiff = arr[1] - arr[0];    
    for (int i = 2; i < n; ++i) {
        minDiff = std::min(minDiff, arr[i] - arr[i-1]);
    }

    std::ostringstream oss;

    for (int i = 1; i < n; ++i) {
        if (arr[i] - arr[i-1] == minDiff) {
            if (oss.tellp() != std::streampos(0)) oss << ", ";
            oss << "(" << arr[i-1] << ", " << arr[i] << ")";
        }
    }

    return oss.str();
}