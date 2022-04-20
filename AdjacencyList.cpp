#include "AdjacencyList.h"
void AdjacencyList::InsertNodes(string name, float price, string set, string rarity, float priority) {
    Card insertNode = Card(name, rarity, price, set, priority);
    vector<string> insertVector = {name, to_string(price), set, rarity};
    cardToAttribute.insert(pair<Card, vector<string>>(insertNode, insertVector));
    vector<Card> cardVector = {Card(name, rarity, price, set, priority)};
    //name
    if (attributeToCard.find(name) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<Card>> (name, cardVector));
    }
    else {
        attributeToCard.at(name).push_back(insertNode);
    }

    //price
    if (attributeToCard.find(to_string(price)) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<Card>> (to_string(price), cardVector));
    }
    else {
        attributeToCard.at(to_string(price)).push_back(insertNode);
    }

    //set
    if (attributeToCard.find(set) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<Card>> (set, cardVector));
    }
    else {
        attributeToCard.at(set).push_back(insertNode);
    }

    //rarity
    if (attributeToCard.find(rarity) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<Card>> (rarity, cardVector));
    }
    else {
        attributeToCard.at(rarity).push_back(insertNode);
    }
}
void AdjacencyList::GetTop10()
{
    auto iter = cardToAttribute.begin();
    int count = 0;
    while(count < 10)
    {
        cout << count+1 << ". ";
        iter->first.printCard();
        iter++;
        count++;
    }
}
