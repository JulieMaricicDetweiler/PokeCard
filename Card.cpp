#include "Card.h"
#include <iomanip>

Card::Card(string& name, string& rarity, float price, string& card_set, float priority)
{
    this->name = name;
    this->rarity = rarity;
    this->price = price;
    this->card_set = card_set;
    this->priority = priority;

}
int Card::getPriority() const
{
    return this->priority;
}
void Card::setPriority(float _priority)
{
    this->priority = _priority;
}
void Card::printCard() const
{
    cout << "Name: " << this->name << endl;
    cout << "Rarity: " << this->rarity <<endl;
    cout << "Price: $" << fixed << setprecision(2) << this->price <<endl;
    cout << "Set: " << this->card_set << endl;
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;
}
bool Card::operator<(const Card& a) const
{
    return a.priority < this->priority;
}
/*bool Card::operator>(const Card &a) const
{
    return a.priority > this->priority;
}
bool Card::operator==(const Card& a) const
{
    return a.priority == this->priority;
}
 */
