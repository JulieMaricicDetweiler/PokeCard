#ifndef POKECARD_HEAP_H
#define POKECARD_HEAP_H
#include "Card.h"
#include <vector>
using namespace std;

class Heap {
private:
    vector<Card> cardHeap;
public:
    void insert(Card& card);
    void heapify(int size);
    void heapifyDown(int top);
    void getTop10();
};


#endif //POKECARD_HEAP_H
