#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

class item {
	friend ostream& operator<<(ostream&, const item&);
public:
	//for the fruit class to access in the array
	virtual bool expireSoon() { return false; };
	virtual void printDate() { cout << ""; }

	void setName(string);
	void setCategory(string);
	void setPrice(float);
	void setQuantity(int);
	string getName();
	string getCategory();
	float getPrice();
	int getQuantity();
	void sellAmount(int);
	void returnAmount(int);
	// CONSTRUCTORS
	item(void);
	item(string);
	item(string, string);
	item(string, string, float);
	item(string, string, float, int);

private:
	string name;
	string category;
	float price;
	int quantity;
};
ostream& operator<< (ostream& osObject, const item& i) {
	osObject << setw(15) << left << i.name;
	osObject << setw(15) << left << i.category;
	osObject << fixed << setprecision(2) << left << "$" << setw(9) << i.price;
	osObject << setw(15) << left << i.quantity;
	return osObject;
}
item::item() {
	name = "N/A";
	category = "item";
	price = 0;
	quantity = 0;
}
item::item(string n) {
	this->name = n;
	category = "item";
	price = 0;
	quantity = 0;
}
item::item(string n, string c) {
	this->name = n;
	this->category = c;
	price = 0;
	quantity = 0;
}
item::item(string n, string c, float p) {
	this->name = n;
	this->category = c;
	this->price = p;
	quantity = 0;
}
item::item(string n, string c, float p, int q) {
	this->name = n;
	this->category = c;
	this->price = p;
	this->quantity = q;
}
void item::setName(string name) {
	this->name = name;
}
void item::setCategory(string category) {
	this->category = category;
}
void item::setPrice(float price) {
	if (price <= 0)
		this->price = 0.00;
	else
		this->price = price;
}
void item::setQuantity(int quantity) {
	if (quantity < 0)
		this->quantity = 0;
	else
		this->quantity = quantity;
}
string item::getName() {
	return name;
}
string item::getCategory() {
	return category;
}
float item::getPrice() {
	return price;
}
int item::getQuantity() {
	return quantity;
}
void item::sellAmount(int amount) {
	if (quantity == 0)
		cout << "Quantity is 0." << endl;
	else if (quantity - amount <= 0)
		quantity = 0;
	else
		quantity = quantity - amount;
}
void item::returnAmount(int amount) {
	quantity = quantity + amount;
}

#endif // !ITEM_H