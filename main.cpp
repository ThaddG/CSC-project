#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include "item.h"
#include "fruit.h"
#include "book.h"

using namespace std;

// choice menu for the user
int menuOption() {
	int option;
	cout << "(1) Search Inventory" << endl;
	cout << "(2) Sell Items" << endl;
	cout << "(3) Return Items" << endl;
	cout << "(4) Add New Items to Inventory" << endl;
	cout << "(5) Update Items" << endl;
	cout << "(6) **Expired by the 21st**" << endl;
	cout << "(9) Exit" << endl;
	cout << "Enter an option: ";
	cin >> option;
	return option;
}

//show the inventory
void showInventory(vector<item*> vect) {
	cout << "-----------" << endl;
	cout << " INVENTORY" << endl;
	cout << "-----------" << endl;
	cout << setw(9) << right << "Item"
		<< setw(19) << "Category"
		<< setw(12) << "Price"
		<< setw(13) << "Quantity" << endl;
	for (int i = 0; i < vect.size(); i++) {
		cout << setw(2) << left << i + 1 << " - " << *vect[i] << endl;
	}
	cout << endl;
}

void searchInventoryByName(vector<item*> &vect) {
	string searchItem;
	bool found = false;
	int index = 0;
	cin.ignore();
	getline(cin, searchItem);

	while (index != vect.size() && !found) {
		if (searchItem.compare(vect[index]->getName()) == 0) //if the names match
			found = true;
		else
			index++;
	}
	if (found) {
		cout << "found at [" << index + 1 << "]" << endl;
		cout << setw(8) << right << "Item"
			<< setw(19) << "Category"
			<< setw(12) << "Price"
			<< setw(13) << "Quantity" << endl;
		cout << index + 1 << " - " << *vect[index] << endl;
	}
	else
		cout << "not found" << endl;
}

void searchInventoryByCategory(vector<item*> &vect) {
	string searchItem;
	cin.ignore();
	getline(cin, searchItem);
	// search for an item by name
	for (int i = 0; i < vect.size(); i++) {
		if (searchItem.compare(vect[i]->getCategory()) == 0) {
			cout << setw(2) << left << i + 1 << " - " << *vect[i] << endl;
		}
		if (i == vect.size() && searchItem.compare(vect[i]->getName()) != 0)
			cout << "nothing in this category" << endl;
	}
}

void sellItems(item &obj) {
	int amount;
	cout << "Amount to sell: ";
	cin >> amount;
	obj.sellAmount(amount);
	cout << "Quantity after sell: " << obj.getQuantity() << endl;
}

void returnItems(item &obj) {
	int amount;
	cout << "Amount to return: ";
	cin >> amount;
	obj.returnAmount(amount);
	cout << "Quantity after return: " << obj.getQuantity() << endl;
}

void newItem(vector<item*>& vect) {
	string name, category;
	float price;
	int quantity;

	cout << "Initialize new object (use lowercase)" << endl;
	cout << "Object Name: ";
	cin.ignore(); // clear the buffer, won't work without this
	getline(cin, name);

	cout << "Set Category [item, fruit, book]: ";
	getline(cin, category);

	cout << "Set Price: ";
	cin >> price;

	cout << "Set Quantity: ";
	cin >> quantity;

	// add type of object depending on user input
	if (category == "item")
		vect.push_back(new item(name, category, price, quantity));
	else if (category == "fruit")
		vect.push_back(new Fruit(name, price, quantity));
	else if (category == "book")
		vect.push_back(new book(name, price, quantity));
}

// these items are pre-loaded to include 3 of each item, one of each initiated without parameters
void loadDefaultItems(vector<item*> &vect) {
	vect.push_back(new item);
	vect.push_back(new item("computer", "item", 1299));
	vect.push_back(new item("tv", "item", 599, 3));
	vect.push_back(new Fruit);
	vect.push_back(new Fruit("apple", 1.99, 19, 4, 20, 2019));
	vect.push_back(new Fruit("orange", 2.99, 7, 4, 15, 2019));
	vect.push_back(new book);
	vect.push_back(new book("some book", 10.99));
	vect.push_back(new book("another book", 11.99, 20));
	vect.push_back(new item("random item"));
}

// display the fruit items in the list that will expire by 4/21/2019
// fruit  expiration dates are defaulted to 4/17/2019
void soonToExpire(vector<item*> &vect) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i]->getCategory() == "fruit") {
			if (vect[i]->expireSoon() == 1) {
				cout << setw(2) << left << i + 1 << " - " << *vect[i] << "\t";
				vect[i]->printDate(); cout << endl;
			}
		}
	}
}





int main() {

	int itemChosen; //used to select items in the array that will be altered
	int option = 0; //stores the user's choice for the option menu

	//store inventory in a list
	vector<item*> itemList;
	loadDefaultItems(itemList);


	cout << "Point of Sale Project" << endl;
	cout << "---------------------" << endl;

	showInventory(itemList);
	while (option != 9) {
		option = menuOption();
		cout << endl;
		switch (option) {
		case 1:
			int nameOrCategory;
			// initial prompt to ask user
			// also used to re-get user-input if this is picked after being chosen before
			cout << "1 - Search by name\n2 - Search by category" << endl;
			cin >> nameOrCategory;

			while (nameOrCategory < 1 || nameOrCategory > 2) {
				cout << "1 - Search by name\n2 - Search by category" << endl;
				cin >> nameOrCategory;
			}
			switch (nameOrCategory) {
			case 1:
				cout << "Search by name (lowercase): ";
				searchInventoryByName(itemList);
				cout << endl;
				break;
			case 2:
				cout << "Search by category [item, fruit, book]: ";
				searchInventoryByCategory(itemList);
				cout << endl;
				break;
			default:
				break;
			}
			break;
		case 2:
			showInventory(itemList);
			cout << "select an item to sell: ";
			cin >> itemChosen;
			sellItems(*itemList[itemChosen-1]);
			cout << endl;
			break;
		case 3:
			showInventory(itemList);
			cout << "select an item you would like to return: ";
			cin >> itemChosen;
			returnItems(*itemList[itemChosen - 1]);
			cout << endl;
			break;
		case 4:
			//showInventory(itemList);
			newItem(itemList);
			cout << endl;
			break;
		case 5:
			showInventory(itemList);
			break;
		case 6:
			cout << "Fruits expired by the 21st" << endl;
			soonToExpire(itemList);
			cout << endl;
			break;
		case 9:
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}
