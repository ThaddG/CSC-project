#ifndef FRUIT_H
#define FRUIT_H
#include <iostream>
#include <conio.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include "item.h"

using namespace std;

class date {
public:
	void setDate(int month, int day, int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate() const; //MIGHT NOT NEED THIS
	date(int m = 4, int d = 17, int y = 2019);
private:
	int month;
	int day;
	int year;
};
void date::setDate(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}
int date::getDay() const {
	return day;
}
int date::getMonth() const {
	return month;
}
int date::getYear() const {
	return year;
}
void date::printDate() const {
	cout << month << "/" << day << "/" << year;
}
date::date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

//-------------------------

class Fruit : public item {
public:
	void setExpirationDate(int, int, int);
	void printDate();
	int getMonth();
	int getDay();
	int getYear();
	bool expireSoon();
	Fruit();
	Fruit(string);
	Fruit(string, float);
	Fruit(string, float, int);
	Fruit(string name, float price, int quantity, int month, int day, int year);
private:
	date expirationDate;
};
Fruit::Fruit() {
	setName("fdefault");
	setCategory("fruit");
}
Fruit::Fruit(string name) : item(name) {
	setCategory("fruit");
}
Fruit::Fruit(string name, float price) {
	setName(name);
	setCategory("fruit");
	setPrice(price);
}
Fruit::Fruit(string name, float price, int quantity) {
	setName(name);
	setCategory("fruit");
	setPrice(price);
	setQuantity(quantity);
}
Fruit::Fruit(string name, float price, int quantity,
	int month, int day, int year) :expirationDate(month, day, year) {
	setName(name);
	setCategory("fruit");
	setPrice(price);
	setQuantity(quantity);
}
bool Fruit::expireSoon() {
	if (getDay() < 22)
		return true;
	else
		return false;
}
int Fruit::getMonth() {
	return expirationDate.getMonth();
}
int Fruit::getDay() {
	return expirationDate.getDay();
}
int Fruit::getYear() {
	return expirationDate.getYear();
}
void Fruit::printDate() {
	expirationDate.printDate();
}
void Fruit::setExpirationDate(int m, int d, int y) {
	expirationDate.setDate(m, d, y);
}

#endif // !FRUIT_H