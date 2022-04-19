#include <iostream>
#include <sstream>
using namespace std;

int readHeap(int* theheap)
{
    int data = 0;
    int size = 0;
    //use std::cin to read in the data
    while (data != -1) {
        cin >> data;
        if (data != -1) {
            theheap[size] = data;
            size++;
        }
    }
    // cout << "size: " << size << endl;
    return size;
    //return the size of the heap
}

void heapifyDown(int index, int* theheap) {
    int temp;
    if (theheap[2*index] == NULL && theheap[2*index + 1] == NULL) {
        return;
    }
    else if (theheap[2*index] != NULL && theheap[2*index + 1] != NULL) {
        if (theheap[index] < theheap[2*index] && theheap[index] < theheap[2*index + 1]) {
            if (theheap[2*index] <= theheap[2*index + 1]) {
                temp = theheap[index];
                theheap[index] = theheap[2*index];
                theheap[2*index] = temp;
                heapifyDown(2*index, theheap);
            }
            else if (theheap[2*index + 1] < theheap[2*index]) {
                temp = theheap[index];
                theheap[index] = theheap[2*index + 1];
                theheap[2*index + 1] = temp;
                heapifyDown(2*index + 1, theheap);
            }
        }
        else if (theheap[index] < theheap[2*index]) {
            temp = theheap[index];
            theheap[index] = theheap[2*index];
            theheap[2*index] = temp;
            heapifyDown(2*index, theheap);
        }
        else if (theheap[index] < theheap[2*index + 1]) {
            temp = theheap[index];
            theheap[index] = theheap[2*index + 1];
            theheap[2*index + 1] = temp;
            heapifyDown(2*index + 1, theheap);
        }
    }
    else if (theheap[2*index] != NULL && theheap[index] < theheap[2*index]) {
        temp = theheap[index];
        theheap[index] = theheap[2*index];
        theheap[2*index] = temp;
        heapifyDown(2*index, theheap);
    }
    else if (theheap[2*index + 1] != NULL && theheap[index] < theheap[2*index + 1]) {
        temp = theheap[index];
        theheap[index] = theheap[2*index + 1];
        theheap[2*index + 1] = temp;
        heapifyDown(2*index + 1, theheap);
    }
}

void heapRemove(int* theheap, int& size)
{
    theheap[0] = theheap[size--];
    heapifyDown(0, theheap);
}

void heapPrint(int* theheap, int size)
{
    for (int i = 0; i< size; i++) {
        cout << theheap[i] << " ";
    }
}

int main() {
    int* theheap;
    int size = 0;
    size = readHeap(theheap);
}



bool isMinHeap(int arr[],int size)
{

}

bool isMaxHeap(int arr[],int size)
{
    //code here
}

int heapPlay(int arr[],int size)
{
    if (isMinHeap(arr[], size) == true) {
        return arr[].top();
    }
    else if (isMaxHeap(arr[], size) == true) {
        return arr[].top();
    }
    else if (isMinHeap(arr[], size) == false && isMaxHeap(arr[], size) == false) {
        return 0;
    }
    else {
        return -1;
    }
}