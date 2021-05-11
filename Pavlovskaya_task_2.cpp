#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Train {
	int number;
	string destination;
	pair<int,int> time;
	Train() {
		number = time.first = time.second = 0;
		destination = "";
	}

	Train(const int& new_number, const string& new_dest, const pair<int, int>& new_time) {
		number = new_number;
		destination = new_dest;
		time = new_time;
	}
};


ostream& operator<<(ostream& os, const Train& t) {
	os << "Number : " << t.number << "\nDestination : " << t.destination << "\nTime : "
		<< setw(2) << setfill('0') << t.time.first << ":" << setw(2) << setfill('0') << t.time.second<<"\n------------------------\n";
	return os;
}

istream& operator>>(istream& input, Train& t) {
	bool is_correct = true;
	Train temp;

	is_correct = is_correct && (input >> temp.number && temp.number > 0);
	input >> temp.destination;

	for (const char& c : temp.destination) {
		is_correct = is_correct && isalpha(c);
		if (!is_correct) break;
	}

	is_correct = is_correct && (input >> temp.time.first >> temp.time.second
		&& (temp.time.first > -1 && temp.time.first < 24)
		&& (temp.time.second > -1 && temp.time.second < 61));

	if (!is_correct) {
		throw invalid_argument("Incorrect input");
	}

	t = temp;

	return input;
}


struct TreeNode {
	Train data;
	TreeNode* left, * right;
	TreeNode(const Train& t) {
		data = t;
		left = right = nullptr;
	}
};

struct InfoSystem {
	InfoSystem() {
		root = nullptr;
	}

	TreeNode* get_root() const {
		return root;
	}

	void insert(const Train& t) {
		TreeNode* new_node = new TreeNode(t);
		TreeNode* get_pos_to_insert = root;
		TreeNode* temp = root;
		while (temp) {
			if (new_node->data.number == temp->data.number) {
				throw runtime_error("Train with this number already exists");
			}
			get_pos_to_insert = temp;
			temp = (new_node->data.number > temp->data.number ? temp->right : temp->left);
		}

		if (!root) {
			root = new_node;
		}
		else if (get_pos_to_insert->data.number > new_node->data.number) {
			get_pos_to_insert->left = new_node;
		}
		else {
			get_pos_to_insert->right = new_node;
		}
	}

	void inorder_print(TreeNode* current) {
		if (current) {
			inorder_print(current->left);
			cout << current->data;
			inorder_print(current->right);
		}
	}

	TreeNode* search_by_number(const int& number_to_search) {
		TreeNode* current = root;
		while (current && !(current->data.number == number_to_search)) {
			current = (current->data.number > number_to_search ? current->left : current->right);
		}
		return current;
	}

	void print_with_destination(const string& dest_to_search, TreeNode* current) {
		if (current) {
			print_with_destination(dest_to_search, current->left);
			if (current->data.destination == dest_to_search) {
				cout << current->data;
			}
			print_with_destination(dest_to_search, current->right);
		}
	}


private:
	TreeNode* root;
};


int main() {
	try {
		InfoSystem info_system;
		cout<<"///////////////////Info system/////////////////////// \n \n \n";
		cout << "1.Add train \n";
		cout << "2.Print all infosystem \n";
		cout << "3.Search by number of train \n";
		cout << "4.Search trains with destination \n \n";
		cout << "0.Exit \n";

		char command;

		while (cin >> command && command != '0') {
			switch (command) {
			case '1': {
				cout << "Enter information about train \n";
				Train t;
				cin >> t;
				info_system.insert(t);
				cout << "Added! \n";
				break;
			}
			case '2':
				if (!info_system.get_root()) {
					cout << "Empty \n";
				}
				else {
					info_system.inorder_print(info_system.get_root());
				}
				break;
			case '3': {
				cout << "Enter the number \n";
				int temp;
				cin >> temp;
				TreeNode* found = info_system.search_by_number(temp);
				if (!found) {
					cout << "Not found \n";
				}
				else {
					cout << found->data;
				}
				break;
			}
			case '4':
				cout << "Enter the destinaton \n";
				string dest;
				cin >> dest;
				info_system.print_with_destination(dest, info_system.get_root());
			}
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}