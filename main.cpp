#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <string>
#include <cmath>
#include <chrono>
#include "Card.h"
#include "AdjacencyList.h"
#include "Heap.h"
using namespace std;
using namespace std::chrono;

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
        string priceImpStr;
        string rareImpStr;
        string setImpStr;

        string choiceStr;
        cout << "Would you like to run this program using (1) a max heap or (2) an adjacency list?" << endl;
        getline(cin, choiceStr);
        int choice = stoi(choiceStr);
        string pokemon;
        cout << "Please enter the name of your desired Pokemon:" << endl;
        getline(cin, pokemon);
        cout << "On a scale of 1-10, how important is character selection to you?" << endl;
        getline(cin, nameImpStr);
        float nameImp = stof(nameImpStr);

        string desiredRarity;
        cout << "Please enter the desired rarity of your card (choose from the rarities below):" << endl;
        for(int i = 0; i < rarityVec.size(); ++i)
        {
            cout << rarityVec[i];
            if(i != rarityVec.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
        getline(cin, desiredRarity);
        cout << "On a scale of 1-10, how important is rarity to you?" << endl;
        getline(cin, rareImpStr);
        float rareImp = stof(rareImpStr);

        string fromStr;
        string toStr;
        cout << "Please select a desired price range for your card:" << endl;
        cout << "From: ";
        getline(cin, fromStr);
        float from = stof(fromStr);
        cout << "To: ";
        getline(cin, toStr);
        float to = stof(toStr);
        cout << "On a scale of 1-10, how important is price to you?" << endl;
        getline(cin, priceImpStr);
        float priceImp = stof(priceImpStr);

        string desiredSet;
        cout << "Please enter your desired set:" << endl;
        getline(cin, desiredSet);
        cout << "On a scale of 1-10, how important is the set to you?" << endl;
        getline(cin, setImpStr);
        float setImp = stof(setImpStr);
        cout << endl;

    AdjacencyList adj;
    Heap heap;

    string filePath = "cards.csv";
    ifstream inFile(filePath);
    auto start = high_resolution_clock::now();
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
            priority += getPriceScore(from, to, price) * (priceImp);
            if(card_set.find(desiredSet) != string::npos)
            {
                priority += setImp;
            }
            Card card(name, rarity, price, card_set, priority);
            if(choice == 1)
            {
                heap.insert(card);
            }
            if(choice == 2)
            {
                adj.InsertNodes(name, price, card_set, rarity, priority);
            }
        }
    }
    if(choice == 1)
    {
        heap.getTop10();
    }
    else
    {
        adj.GetTop10();
    }
    auto stop = high_resolution_clock::now();
    auto progTime = duration_cast<milliseconds>(stop - start);
    cout << "Time taken : " << progTime.count() << " milliseconds" << endl;
}
