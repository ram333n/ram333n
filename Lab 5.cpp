#include <iostream>
#include <string>
using namespace std;

#include "queue.h"


struct Data {
    int counter;
    string english_word;
    string translation;
    Data() {}
    Data(const int& new_counter, const string& new_english_word, const string& new_translation) {
        counter = new_counter;
        english_word = new_english_word;
        translation = new_translation;
    }
};

ostream& operator<<(ostream& os, const Data& d) {
    os << "Counter value : " << d.counter << endl;
    os << "English word : " << d.english_word << endl;
    os << "Translation : " << d.translation << endl;
    os << "____________________________________" << endl;
    return os;
}

istream& operator>>(istream& input, Data& d) {
    int new_counter(0);
    string new_eng_word, new_translation;
    bool is_eng_word_correct(true), is_translation_correct(true);
    input >> new_counter >> new_eng_word >> new_translation;
    for (const char& c : new_eng_word) {
        if (!isalpha(c)) {
            is_eng_word_correct = false;
            break;
        }
    }

    for (const char& c : new_translation) {
        if (!isalpha(c)) {
            is_translation_correct = false;
            break;
        }
    }

    if (new_counter < 0 || !is_eng_word_correct || !is_translation_correct) {
        throw invalid_argument("Incorrect input");
    }

    d = Data(new_counter, new_eng_word, new_translation);
    return input;
}

struct Node {
    Data data;
    Node* left, * right;
    Node(const Data& new_data) {
        data = new_data;
        left = right = nullptr;
    }
};


Node* ConstructNode(const Data& d) {
    Node* result = new Node(d);
    return result;
}




struct Dictionary {
    Node* root;

    Dictionary() {
        root = nullptr;
    }

    Node* get_root() const {
        return root;
    }

    void insert(const Data& d, const bool& insert_by_alphabet) {
        Node* new_node = ConstructNode(d);
        Node* get_pos_to_insert = root;
        Node* temp_ptr = root;
        while (temp_ptr) {
            get_pos_to_insert = temp_ptr;
            if (insert_by_alphabet) {
                temp_ptr = new_node->data.english_word > temp_ptr->data.english_word ? temp_ptr->right : temp_ptr->left;
            }
            else {
                temp_ptr = new_node->data.counter > temp_ptr->data.counter ? temp_ptr->right : temp_ptr->left;
            }
        }
        if (!get_pos_to_insert) {
            root = new_node;
            return;
        }

        bool comparator;
        if (insert_by_alphabet) {
            comparator = new_node->data.english_word > get_pos_to_insert->data.english_word;
        }
        else {
            comparator = new_node->data.counter > get_pos_to_insert->data.counter;
        }

        if (comparator) {
            get_pos_to_insert->right = new_node;
        }
        else {
            get_pos_to_insert->left = new_node;
        }
    }


    void inorder_print(Node* current) {
        if (current) {
            inorder_print(current->left);
            ++current->data.counter;
            cout << current->data;
            inorder_print(current->right);
        }
    }

    void preorder_print(Node* current) {
        if (current) {
            ++current->data.counter;
            cout << current->data;
            inorder_print(current->left);
            inorder_print(current->right);
        }
    }

    Node* max(Node* current) {
        if (!current) {
            return root;
        }

        Node* result = current;
        Node* max_in_left_subtree = max(current->left);
        Node* max_in_right_subtree = max(current->right);

        if (max_in_left_subtree->data.counter > result->data.counter) {
            result = max_in_left_subtree;
        }

        if (max_in_right_subtree->data.counter > result->data.counter) {
            result = max_in_right_subtree;
        }

        return result;
    }

    void remove_node(Node* current, Node* to_remove) {
        if (!current) return;
        if (current == to_remove) {
            delete to_remove;
            root = nullptr;
            return;
        }

        if (current->left == to_remove) {
            delete to_remove;
            current->left = nullptr;
            return;
        }

        if (current->right == to_remove) {
            delete to_remove;
            current->right = nullptr;
            return;
        }

        remove_node(current->left, to_remove);
        remove_node(current->right, to_remove);
    }

    void delete_node(int counter_to_delete) {
        if (!root) return;
        if (!(root->left || root->right)) {
            if (root->data.counter == counter_to_delete) {
                delete root;
                root = nullptr;
            }
            return;
        }

        Queue<Node*> q;
        q.push_back(root);

        Node* node_to_del = nullptr;
        Node* current = nullptr;


        while (!q.is_empty()) {
            current = q.pop_front();

            if (current->data.counter == counter_to_delete) {
                node_to_del = current;
            }

            if (current->left) {
                q.push_back(current->left);

            }

            if (current->right) {
                q.push_back(current->right);

            }
        }

        if (node_to_del) {
            node_to_del->data = current->data;
            remove_node(root, current);
        }
    }

    void rebuild() {
        cout << endl << endl << endl;
        cout << "*************Before rebuilding*************" << endl << endl << endl;
        inorder_print(get_root());
        Dictionary new_dictionary;
        Node* temp = max(get_root());
        while (temp) {
            ++temp->data.counter;
            new_dictionary.insert(temp->data, false);
            delete_node(temp->data.counter);
            //temp = nullptr;
            temp = max(get_root());
        }
        root = new_dictionary.root;
        cout << endl << endl << endl;
        cout << "*************After rebuilding*************" << endl << endl << endl;
        inorder_print(get_root());
    }

};

int main() {
    try {
        Dictionary dictionary;
        cout << "1.Add words" << endl;
        cout << "2.Inorder print" << endl;
        cout << "3.Rebuild" << endl;
        cout << "0.Exit" << endl << endl;
        char command;
        while (cin >> command && command != '0') {
            switch (command) {
            case '1': {
                cout << "Enter the information about words(5 times) \n";
                Data d;
                for (size_t i = 0; i < 5; ++i) {
                    cin >> d;
                    dictionary.insert(d, true);
                }
                cout << "Successfully saved" << endl;
                break;
            }
            case '2':
                dictionary.inorder_print(dictionary.get_root());
                break;
            case '3':
                dictionary.rebuild();
                break;
            }
        }
    }
    catch (invalid_argument& inv) {
        cout << inv.what() << endl;
    }
}

/*digraph before {
  "1 c" -> "2 b"
  "2 b" -> "3 a"
  "1 c" -> "5 d"
  "5 d" -> "4 f"
}

digraph after {
  "8 d" -> "7 f"
  "7 f" -> "6 a"
  "6 a" -> "5 b"
  "5 b" -> "4 c"
}
*/
