#include <iostream>
using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index) {
    // Find the indices of the left and right children
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Find the index of the largest element among the current node and its children
    int largest = index;

    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[largest]) {
        largest = leftChild;
    }

    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[largest]) {
        largest = rightChild;
    }

    // If the largest element is not the current node, swap them and continue reheapDown
    if (largest != index) {
        swap(maxHeap[index], maxHeap[largest]);
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    // Find the index of the parent
    int parent = (index - 1) / 2;

    // Continue moving up the heap until the current element is smaller than its parent
    while (index > 0 && maxHeap[index] > maxHeap[parent]) {
        swap(maxHeap[index], maxHeap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
