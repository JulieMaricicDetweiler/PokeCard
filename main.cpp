#include <iostream>
#include <map>
#include <vector>
using namespace std;
class CardNode {
    string name;
    float price;
    string set;
    string rarity;
public:
    CardNode(string name, float price, string set, string rarity) {
        this->name = name;
        this->price = price;
        this->set = set;
        this->rarity = rarity;
    }
    bool operator< (const CardNode& cardObj) const {//overload operator to use for classes when they are keys in a map
        if (cardObj.name < this->name) {
            return true;
        }
    }
    float GetPrice() {
        return price;
    }
    string GetName() {
        return name;
    }
    string GetSet() {
        return set;
    }
    string GetRarity() {
        return rarity;
    }
};

class AdjacencyList {
private:
    map<CardNode, vector<string>> cardToAttribute;//from CardNode, points to all its attributes
    map<string, vector<CardNode>> attributeToCard;//from Attribute, points to all its CardNodes
public:
    void InsertNodes(string name, float price, string set, string rarity);//initializes basically everything
};

void AdjacencyList::InsertNodes(string name, float price, string set, string rarity) {
    CardNode insertNode = CardNode(name, price, set, rarity);
    vector<string> insertVector = {name, to_string(price), set, rarity};
    cardToAttribute.insert(pair<CardNode, vector<string>>(insertNode, insertVector));
    vector<CardNode> cardVector = {CardNode(name, price, set, rarity)};
    //name
    if (attributeToCard.find(name) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<CardNode>> (name, cardVector));
    }
    else {
        attributeToCard.at(name).push_back(CardNode(name, price, set, rarity));
    }

    //price
    if (attributeToCard.find(to_string(price)) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<CardNode>> (to_string(price), cardVector));
    }
    else {
        attributeToCard.at(to_string(price)).push_back(CardNode(name, price, set, rarity));
    }

    //set
    if (attributeToCard.find(set) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<CardNode>> (set, cardVector));
    }
    else {
        attributeToCard.at(set).push_back(CardNode(name, price, set, rarity));
    }

    //rarity
    if (attributeToCard.find(rarity) == attributeToCard.end()) {
        attributeToCard.insert(pair<string, vector<CardNode>> (rarity, cardVector));
    }
    else {
        attributeToCard.at(rarity).push_back(CardNode(name, price, set, rarity));
    }
}

int main() {
    AdjacencyList Graph;
    Graph.InsertNodes("Charizard", 24.99, "Ultra Magnum Condom", "Rare AF");
    return 0;
}
