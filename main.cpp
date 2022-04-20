#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Card {
public:
    string name;
    double price;
    string set;
    string rarity;

// PRIORITY EQUATION VALUES
    double priorityValue; // value for each card to Heapify by
};

class Heap {
private:
    vector<Card> cardHeap;
public:
    void insert(Card* card);
    void heapify(int size);
    void printHeap();
    void heapifyDown(int top);
    void printHeapTop();
};

void Heap::insert(Card* card) { // inserts a Card at the END of the vector... heapify's the card up the Heap
    cardHeap.push_back(*card);
    heapify(cardHeap.size()-1); // heapify the newly inserted card
}

void Heap::heapify(int child) // bubble's the newly inserted Card to the correct position... based on priorityValue
{
    int parent = ceil(((child+1)/2) - 1);
    if (child != 0) { // if the place being tested has >= 1 parent...
        if (cardHeap[child].priorityValue > cardHeap[parent].priorityValue) { // test the child against its parent!
            swap(cardHeap[child], cardHeap[parent]); // swap the child if they are greater
            heapify(parent); // heapify the NEW parent up
        }
    }
}

void Heap::printHeap() // prints heap in vector order
{
    for (int i=0; i < cardHeap.size(); i++)
        cout << cardHeap[i].priorityValue << " ";
    cout << "\n";
}

void Heap::printHeapTop() // prints heap by removing the top and heapifyingDown, one at a time
{
    for (int i=0; i < cardHeap.size(); i++) {
        cout << cardHeap[0].priorityValue << " ";
        cardHeap[0].priorityValue = -1;
        heapifyDown(0);
    }

    cout << "\n";
}

void Heap::heapifyDown(int top) { // when the top value is < -1, it moves the value all the way to the bottom while bringing the highest values up
    if (top < cardHeap.size()) {
        if (cardHeap.size() > 1 && cardHeap[(top * 2) + 1].priorityValue > cardHeap[(top * 2) + 2].priorityValue) {
            if (cardHeap[top].priorityValue < cardHeap[(top * 2) + 1].priorityValue) {
                swap(cardHeap[top], cardHeap[(top * 2) + 1]);
                heapifyDown((top * 2) + 1);
            }
        }
        if (cardHeap.size() > 2) {
            if (cardHeap[top].priorityValue < cardHeap[(top * 2) + 2].priorityValue) {
                swap(cardHeap[top], cardHeap[(top * 2) + 2]);
                heapifyDown((top * 2) + 2);
            }
        }
    }
}

int main() {
    Heap heapOfCards;
    for (int i = 0; i < 100; i++) {
        Card* newCard = new Card;
        newCard->priorityValue = rand()%100;
        heapOfCards.insert(newCard);
    }
    heapOfCards.printHeap(); // prints the heap in vector order
    heapOfCards.printHeapTop(); // prints the heap, greatest to least, by removing the top value and heapifyingDown
    return 0;
}