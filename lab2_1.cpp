#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

struct Tree {
    int id;
    char type[30];
    int age;
    struct {
        int x;
        int y;
    } coords;  
};

struct LoginData {
    char login[30];
    char password[20];
};


bool operator ==(const LoginData& d1, const LoginData& d2) {
    return strcmp(d1.login, d2.login) == 0 && strcmp(d1.password, d2.password) == 0;
}

void PrintTree(const Tree& t) {
    cout << "______________________________" << endl;
    cout <<"Id: "<<t.id<<'\n'<< "Type: " << t.type << '\n' << "Age: " << t.age << '\n'
        << "Coords: " << "(" << t.coords.x << " , " << t.coords.y << ")" << '\n';
}

void PrintLogInMenu() {
    cout << "................." << "1.Sign in" << endl;
    cout << "................." << "2.Sign up" << endl;
    cout << "................." << "3.Sign in(for admins)" << endl << endl;
    cout << "If you want to exit, press e" << endl;
}

void PrintAdminMenu() {
    cout << "................." << "1.Plant a tree " << endl;
    cout << "................." << "2.Calculate average age " << endl;
    cout << "................." << "3.Request for searching and deleting" << endl;
    cout << "................." << "4.Sign up admin" << endl << endl;
    cout << "If you want to log out, press e" << endl;
}

void PrintUserMenu() {
    cout << "................." << "1.Plant a tree " << endl;
    cout << "................." << "2.Calculate average age " << endl;
    cout << "................." << "3.Request for searching and deleting" << endl;
    cout << "If you want to log out, press e" << endl;
}

void SignUp(const char* fileName) {
    LoginData input;
    cout << "Enter the login and password" << endl;
    cin >> input.login >> input.password;
    ifstream read_users;
    read_users.open(fileName, ios::binary|ios::app);
    LoginData temp;
    bool IsCopyExist = false;
    while (read_users.read((char*)(&temp), sizeof(LoginData))) {
        if (strcmp(input.login, temp.login) == 0) {
            IsCopyExist = true;
            cout << "This user already exists \n";
            break;
        }
    }
    read_users.close();
    if (!IsCopyExist) {
        ofstream Users;
        Users.open(fileName, ios::binary);
        Users.write((char*)(&input), sizeof(LoginData));
        cout << "Signed up successfully" << endl;
    }
}


bool LogIn(const char* fileName) {
    ifstream Users;
    Users.open(fileName, ios::binary);
    LoginData input, temp;
    cout << "Enter the login and password" << endl;
    cin >> input.login >> input.password;
    while (Users.read((char*)(&temp), sizeof(temp))) {
        if (input == temp) {
            cout << "You're entered, as " << temp.login << endl;
            Users.close();
            return true;
        }
    }
    cout << "Incorrect login or password" << endl;
    Users.close();
    return false;
}

void PlantTree() {
    Tree new_tree;
    cout << "Enter the information about tree(id,type,age,coords)" << endl;
    cin >> new_tree.id >> new_tree.type >> new_tree.age 
        >> new_tree.coords.x >> new_tree.coords.y;
    Tree temp;
    ifstream read_trees;
    read_trees.open("trees.dat", ios::binary);
    bool IsCopyExist(false);
    while (read_trees.read((char*)(&temp), sizeof(temp))) {
        if (temp.id == new_tree.id) {
            cout << "Id isn't unique, try again" << endl;
            IsCopyExist = true;
            break;
        }
        else if (temp.coords.x == new_tree.coords.x && temp.coords.y == new_tree.coords.y) {
            cout << "The coords aren't unique, try again" << endl;
            IsCopyExist = true;
            break;
        }
    }
    read_trees.close();
    if (!IsCopyExist) {
        ofstream trees;
        trees.open("trees.dat", ios::binary|ios::app);
        trees.write((char*)&new_tree, sizeof(new_tree));
        cout << "Planted successfully" << endl;
        trees.close();
    }
}

void CalculateAverageAge() {
    char search_type[30];
    cout << "Enter the type of tree" << endl;
    cin >> search_type;
    double result(0);
    int quantity(0);
    Tree temp;
    ifstream trees;
    trees.open("trees.dat", ios::binary);
    while (trees.read((char*)(&temp), sizeof(temp))) {
        if (strcmp(search_type, temp.type) == 0) {
            result += temp.age;
            quantity++;
        }
    }
    trees.close();
    if (quantity == 0) { 
        cout << "The type doesn't exist" << endl;
        return;
    }
    cout << "Average age of trees of type: " << search_type << " is " << result / quantity << endl;
}


//SELECT s Apple trees.dat
void ParseSqlCommand(bool& to_delete) {
    cout << "Enter the command \n \n";
    cout << "For example : SELECT s Apple trees.dat, where s-type, n-id or coord(mode)" << endl;
    char command[30];
    cin >> command;
    if (strcmp(command, "DELETE") != 0 && strcmp(command, "SELECT") != 0) {
        cout << "Unknown command, try again" << endl;
        return;
    }
    char mode;
    cin >> mode;
    if (mode != 's' && mode != 'n') {
        cout << "Unknown mode, try again" << endl;
        return;
    }
    if (mode == 's') {
        streampos pos;
        char search_type[30], file_name[20];
        cin >> search_type >> file_name;
        ifstream source;
        source.open(file_name, ios::binary);
        if (!source.is_open()) {
            cout << "Unknown file" << endl;
            return;
        }
        bool is_response_null = true;
        Tree temp;
        while (source.read((char*)&temp, sizeof(temp))) {
            if (strcmp(search_type, temp.type) == 0) {
                PrintTree(temp);
                is_response_null = false;
            }
        }
        source.close();
        if (is_response_null) {
            cout << "Not found" << endl;
            return;
        }
        if (strcmp(command, "DELETE") == 0) {
            cout << "Confirm deleting by entering id of tree" << endl;
            int id;
            cin >> id;
            source.open(file_name, ios::binary);
            while (source.read((char*)&temp, sizeof(temp))) {
                if (id == temp.id) {
                    ofstream deleting_data;
                    deleting_data.open("felled_trees.dat", ios::binary|ios::app);
                    deleting_data.write((char*)&temp, sizeof(temp));
                    to_delete = true;
                    cout << "Deleted successfully" << endl;
                    deleting_data.close();
                    break;
                }
            }
        }
        source.close();
    }
    else {
        int data;
        char file_name[20];
        cin >> data >> file_name;
        if (strcmp(command, "SELECT") == 0) {
            ifstream source;
            source.open(file_name, ios::binary);
            if (!source.is_open()) {
                cout << "Unknown file" << endl;
                return;
            }
            bool is_response_null = true;
            Tree temp;
            while (source.read((char*)&temp, sizeof(temp))) {
                if (data == temp.id || data == temp.coords.x || data == temp.coords.y) {
                    PrintTree(temp);
                    is_response_null = false;
                }
            }
            source.close();
            if (is_response_null) {
                cout << "Not found" << endl;
                return;
            }
            if (strcmp(command, "DELETE") == 0) {
                cout << "Confirm deleting by entering id of tree" << endl;
                int id;
                cin >> id;
                source.open(file_name, ios::binary);
                while (source.read((char*)&temp, sizeof(temp))) {
                    if (id == temp.id) {
                        ofstream deleting_data;
                        deleting_data.open("felled_trees.dat", ios::binary);
                        deleting_data.write((char*)&temp, sizeof(temp));                        
                        to_delete = true;
                        cout << "Deleted successfully" << endl;
                        deleting_data.close();
                        break;
                    }
                }

            }
            source.close();
        }
    }
}


void Delete() {
    streampos pos;
    ofstream temp_file;
    ifstream source, felled_trees;
    temp_file.open("temp.dat", ios::binary|ios::app);
    source.open("trees.dat", ios::binary);
    felled_trees.open("felled_trees.dat", ios::binary);
    Tree deleted, temp;
    while (felled_trees.read((char*)&deleted, sizeof(deleted))) {
        while (source.read((char*)&temp, sizeof(temp))) {
            if (temp.id == deleted.id) {
                pos = source.tellg();
                continue;
            }
            temp_file.write((char*)&temp, sizeof(temp));
        }
        source.seekg(pos);
    }
    source.close();
    remove("trees.dat");
    felled_trees.close();
    temp_file.close();
    rename("temp.dat", "trees.dat");
    felled_trees.open("felled_trees.dat", ios::trunc | ios::binary);
    felled_trees.close();
}
    

//SELECT, DELETE

int main()
{
    char command;
    PrintLogInMenu();
    cin >> command;
    while (command != 'e') {
        switch (command) {
        case '1': {
            if (LogIn("users.dat")) {
                bool to_delete(false);
                PrintUserMenu();
                cin >> command;
                while (command != 'e') {
                    switch (command)
                    {
                    case '1':
                        PlantTree();
                        break;
                    case '2':
                        CalculateAverageAge();
                        break;
                    case '3':
                        ParseSqlCommand(to_delete);
                    }
                    cin >> command;
                }
                if (to_delete) Delete();
                PrintLogInMenu();
                break;
            }
            break;
        }
        case '2':
            SignUp("users.dat");
            break;
        case '3': {
            if (LogIn("admins.dat")) {
                PrintAdminMenu();
                bool to_delete(false);
                cin >> command;
                while (command != 'e') {
                    switch (command)
                    {
                    case '1':
                        PlantTree();
                        break;
                    case '2':
                        CalculateAverageAge();
                        break;
                    case '3':
                        ParseSqlCommand(to_delete);
                        break;
                    case '4':
                        SignUp("admins.dat");
                        break;
                    }
                    cin >> command;
                }
                PrintLogInMenu();
                if (to_delete) Delete();
            }
        }
        case 'e':break;
        default: cout << "Enter the right action " << endl;
        }
        cin >> command;
    }              
    cout << "Goodbye! Have a nice day)" << endl;   
}
    
