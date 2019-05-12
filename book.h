#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include "item.h"

class book : public item {
	friend ostream& operator<<(ostream&, book&);
public:
	book();
	book(string);
	book(string, float);
	book(string, float, int);
};
// DONT NEED THIS RIGHT NOW
// FIX THIS IF I HAVE THE TIME
ostream& operator<< (ostream& osObject, book& b) {
	osObject << setw(25) << left << b.getName();
	osObject << setw(15) << left << b.getCategory();
	osObject << setw(10) << left << b.getPrice();
	osObject << setw(15) << left << b.getQuantity();
	return osObject;
}
book::book() {
	setName("bdefault");
	setCategory("book");
}
book::book(string name) : item(name) {
	setCategory("book");
}
book::book(string name, float price) {
	setName(name);
	setCategory("book");
	setPrice(price);
}
book::book(string name, float price, int quantity) {
	setName(name);
	setCategory("book");
	setPrice(price);
	setQuantity(quantity);
}

#endif // !BOOK_H