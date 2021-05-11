#include <iostream>

using namespace std;

#include "task_1_list.h"

struct Database {

	void bus_departure(const int& bus_number) {
		Node<Bus>* searched_bus = in_bus_park.search(bus_number);
		if (!searched_bus) {
			cout << "Bus not found" << endl;
		}
		else {
			Bus for_push = searched_bus->data;
			on_route.push_back(for_push);
			in_bus_park.remove(searched_bus);
			cout << "Bus : " << bus_number << "has left the park" << endl;
		}
	}

	void bus_enterance(const int& bus_number) {
		Node<Bus>* searched_bus = on_route.search(bus_number);
		if (!searched_bus) {
			cout << "Bus not found" << endl;
		}
		else {
			Bus for_push = searched_bus->data;
			in_bus_park.push_back(for_push);
			on_route.remove(searched_bus);
			cout << "Bus : " << bus_number << "has entered park" << endl;
		}
	}


	List<Bus> on_route;
	List<Bus> in_bus_park;
};

//int main() {
//	Database db;
//	cout << "////////////Database////////////" << endl << endl;
//	cout << "1.Add bus" << endl;
//	cout << "2.Depart bus" << endl;
//	cout << "3.Enter bus the park" << endl;
//	cout << "4.Print buses, which aren't in park" << endl;
//	cout << "5.Print buses, which are in park" << endl;
//	cout << "0.Exit" << endl << endl;
//	char command;
//	while (cin >> command && command != '0') {
//		switch (command) {
//		case '1': {
//			cout << "Enter info about bus" << endl;
//			Bus b;
//			cin >> b;
//			db.in_bus_park.push_back(b);
//			break;
//		}
//		case '2':
//			cout << "Enter the number" << endl;
//			int temp_1;
//			cin >> temp_1;
//			db.bus_departure(temp_1);
//			break;
//		case '3':
//			cout << "Enter the number" << endl;
//			int temp_2;
//			cin >> temp_2;
//			db.bus_enterance(temp_2);
//			break;
//
//		case '4':
//			if (!db.on_route.size()) cout << "Empty" << endl;
//			else db.on_route.print();
//			break;
//
//		case '5':
//			if (!db.in_bus_park.size()) cout << "Empty" << endl;
//			else db.in_bus_park.print();
//			break;
//		}
//	}
//}
