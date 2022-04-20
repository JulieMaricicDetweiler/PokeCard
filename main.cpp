#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <cmath>
//#include "Card.h"
#include "AdjacencyList.h"
using namespace std;

float getPriceScore(float from, float to, float price)
{
    float difference = 0;
    if(price < from)
    {
        difference = from - price;
    }
    else if(price > to)
    {
        difference = price - to;
    }
    if(difference != 0)
    {
        difference += 0.99;
        return (float)10.0/difference;
    }
    else
    {
        return (float)11.0;
    }
}
float getRarityScore(vector<string>& vec, string cardRarity, string userRarity)
{
    int userIndex;
    int cardIndex;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == cardRarity)
        {
            cardIndex = i;
        }
        if(vec[i] == userRarity)
        {
            userIndex = i;
        }
    }
    if(userIndex == cardIndex)
    {
        return (float)11;
    }
    else
    {
        return (float)1.0/ abs((float)userIndex - (float)cardIndex);
    }
}
int main()
{
        vector<string> rarityVec = {"Common", "Uncommon", "Rare", "Promo", "Holo Rare", "Rare Ace", "Rare Break", "Ultra Rare", "Amazing Rare", "Prism Rare", "Shiny Holo Rare", "Classic Collection", "Secret Rare"};

        string nameImpStr;
        float priceImp;
        string rareImpStr;
        float setImp;

        string pokemon;
        cout << "Please enter the name of your desired Pokemon:" << endl;
        getline(cin, pokemon);
        cout << "On a scale of 1-10, how important is character selection to you?" << endl;
        getline(cin, nameImpStr);
        float nameImp = stof(nameImpStr);

        string desiredRarity;
        cout << "Please enter the desired rarity of your card:" << endl;

        getline(cin, desiredRarity);
        cout << "On a scale of 1-10, how important is rarity to you?" << endl;
        getline(cin, nameImpStr);
        float nameImp = stof(nameImpStr);

        float priceFrom;
        float priceTo;
        cout << "Please select a desired price range for your card:" << endl;
        cout << "From: ";
        cin >> priceFrom;
        cout << "To: ";
        cin >> priceTo;
        cout << "On a scale of 1-10, how important is price to you?" << endl;
        cin >> priceImp;

        string desiredSet;
        cout << "Please enter your desired set:" << endl;
        cin >> desiredSet;
        cout << "On a scale of 1-10, how important is the set to you?" << endl;
        cin >> setImp;
        cout << endl;

    AdjacencyList adj;

    string filePath = "cards.csv";
    ifstream inFile(filePath);
    if(inFile.is_open())
    {
        string line;
        getline(inFile, line);
        while(getline(inFile, line))
        {
            istringstream stream(line);
            string name;
            string rarity;
            string priceTemp;
            string card_set;

            getline(stream, name, ',');
            getline(stream, rarity, ',');
            getline(stream, priceTemp, ',');
            getline(stream, card_set, ',');

            float priority = 0.0;

            if(name.find(pokemon) != string::npos)
            {
                priority += (float)nameImp * (float)10.0;
            }
            priority += getRarityScore(rarityVec, rarity, desiredRarity) * rareImp;
            float price = stof(priceTemp.substr(1, priceTemp.length() - 2));
            priority += getPriceScore(priceFrom, priceTo, price) * (priceImp / (float)10);
            if(card_set == desiredSet)
            {
                priority += setImp;
            }
            //Card card(name, rarity, price, card_set, priority);
            adj.InsertNodes(name, price, card_set, rarity, priority);
        }
    }
    adj.GetTop10();
}
