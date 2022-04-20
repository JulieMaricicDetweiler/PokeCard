#ifndef POKECARD_ADJACENCYLIST_H
#define POKECARD_ADJACENCYLIST_H
#include "Card.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class AdjacencyList
{
private:
    map<Card, vector<string>> cardToAttribute;//from CardNode, points to all its attributes
    map<string, vector<Card>> attributeToCard;//from Attribute, points to all its CardNodes
public:
    void InsertNodes(string name, float price, string set, string rarity, float priority);//initializes basically everything
    void GetTop10();
};


#endif //POKECARD_ADJACENCYLIST_H
