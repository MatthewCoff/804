#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//////
class Device abstract
{
protected:

	///
	string model;
	int quantity;
	double price;
	string color;
	string namepr;
public:

	Device(string model, int quantity, double price, string color, string namepr) :
		model(model),
		quantity(quantity),
		price(price),
		color(color),
		namepr(namepr) {}

	// чисто виртуальный метод
	virtual void pocaz() = 0;
};
//////
class MobilePhone : public Device
{
protected:

	double screen_size;


public:
	MobilePhone(string model, int quantity, double price, string color, string namepr,
		string operating_system, double screen_size) :
		Device(model, quantity, price, color, namepr),  screen_size(screen_size) {}
	void pocaz() override {
		cout << "Mobile Phone : " << model << " : " << color << " : " << namepr << " : " << screen_size << " inch screen : " << quantity << " in stock : " << price << " $" << endl;
	}
};

////
class Laptop : public Device
{
protected:

	double screen_size;
public:
	Laptop(string model, int quantity, double price, string color, string namepr,
		string operating_system, double screen_size) :
		Device(model, quantity, price, color, namepr), screen_size(screen_size) {}
	void pocaz() override {
		cout << "Laptop : " << model << " : " << color << " : " << namepr << " : " << screen_size << " inch screen : " << quantity << " in stock : " << price << " $" << endl;
	}

};
//////
class Tablet : public Device {
private:

	double screen_size;
public:
	Tablet(string model, int quantity, double price, string color, string namepr,
		string operating_system, double screen_size) :
		Device(model, quantity, price, color, namepr), screen_size(screen_size) {}
	void pocaz() override {
		cout << "Tablet : " << model << " : " << color << " : " << namepr << " : " << screen_size << " inch screen : " << quantity << " in stock : " << price << " $" << endl;
	}
};
//
int main()
{
	setlocale(LC_ALL, "Russian");

	vector<Device*> devices;
	devices.push_back(new Tablet("iPad 8", 8, 5.99, "red", "iPad", "nice", 19.5));
	devices.push_back(new MobilePhone("SAMSUNGG", 72, 9999.99, "light Silver", "iOS", "nice", 15.5));
	devices.push_back(new Laptop("ASUS", 70, 8799.99, "white", "Windows 11", "nice", 10.5));



	cout << "\n\t\tPechat списка:\n" << endl;
	for (auto device : devices) {
		device->pocaz();
	}
	cout << "\n\t\tDelete a device -1" << endl;
	devices.erase(devices.begin());  //erase - удаляет элементы из диапазона в данный момент первый обьект


	cout << "\n\t\tPechat списка:\n" << endl;
	for (auto device : devices) {
		device->pocaz();
	}



}



