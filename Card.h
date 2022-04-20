#ifndef POKECARD_CARD_H
#define POKECARD_CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card
{
private:
    string name;
    string rarity;
    float price;
    string card_set;
    int priority;
public:
    Card(string& name, string& rarity, float price, string& card_set, float priority);
    int getPriority() const;
    void printCard() const;

    bool operator<(const Card& a) const;
    bool operator>(const Card& a) const;
    bool operator==(const Card& a) const;
};

#endif //POKECARD_CARD_H
