#include "Heap.h"
#include <cmath>
#include <iomanip>

void Heap::insert(Card& card)
{ // inserts a Card at the END of the vector... heapify's the card up the Heap
    cardHeap.push_back(card);
    heapify(cardHeap.size() - 1); // heapify the newly inserted card
}

void Heap::heapify(int child) // bubble's the newly inserted Card to the correct position... based on priority
{
    int parent = ceil(((child + 1) / 2) - 1);
    if (child != 0) { // if the place being tested has >= 1 parent...
        if (cardHeap[child].getPriority() > cardHeap[parent].getPriority()) { // test the child against its parent!
            swap(cardHeap[child], cardHeap[parent]); // swap the child if they are greater
            heapify(parent); // heapify the NEW parent up
        }
    }
}

void Heap::getTop10() // prints heap by removing the top and heapifyingDown, one at a time
{
    for (int i = 1; i < 11; i++)
    {
        if(i < 10)
        {
            cout << " ";
        }
        cout << i << ". ";
        cardHeap[0].printCard();
        cardHeap[0].setPriority(-1);
        heapifyDown(0);
    }
}

void Heap::heapifyDown(int top) { // when the top value is < -1, it moves the value all the way to the bottom while bringing the highest values up
    if (top < cardHeap.size()) {
        if (cardHeap.size() > 1 && cardHeap[(top * 2) + 1].getPriority() > cardHeap[(top * 2) + 2].getPriority()) {
            if (cardHeap[top].getPriority() < cardHeap[(top * 2) + 1].getPriority()) {
                swap(cardHeap[top], cardHeap[(top * 2) + 1]);
                heapifyDown((top * 2) + 1);
            }
        }
        if (cardHeap.size() > 2) {
            if (cardHeap[top].getPriority() < cardHeap[(top * 2) + 2].getPriority()) {
                swap(cardHeap[top], cardHeap[(top * 2) + 2]);
                heapifyDown((top * 2) + 2);
            }
        }
    }
}