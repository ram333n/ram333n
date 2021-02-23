#include <iostream>
#include <fstream>
using namespace std;

bool IsImplicate(const bool& a, const bool& b) { return !a || b; }

// 1! 2. 3! <-> !x*y*!z
struct Argument {
    int index;
    char operation;
    bool ApplyOperation(const bool& arg) {
        if (operation == '!') return !arg;
        return arg;
    }
};

ifstream& operator>>(ifstream& input, Argument& a) {
    input >> a.index >> a.operation;
    return input;
}

template <typename T> struct Node {
    T data;
    Node* next;
};

template<typename T> struct List {
    Node<T>* head;
    List() {
        head = NULL;
    }

    ~List() {
        if (!head) return;
        while (head->next) {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
    }

    void PushFront(T a) {
        Node<T>* temp = new Node<T>;
        temp->data = a;
        temp->next = head;
        head = temp;
    }

    void PushBack(T a) {
        Node<T>* temp_node = new Node<T>;
        temp_node->data = a;
        temp_node->next = NULL;
        if (!head) {
            head = temp_node;
            return;
        }
        Node<T>* temp_head = head;
        while (head->next) head = head->next;
        head->next = temp_node;
        head = temp_head;
    }
};


void AssignmentOfListOfArguments(List<Argument>& result, List<Argument> rhs) {
    while (rhs.head) {
        result.PushBack(rhs.head->data);
        rhs.head = rhs.head->next;
    }
}

struct TempArgForCalculation {
    int index;
    bool value;
};

struct NodeForDnf {
    List<Argument>* data;
    NodeForDnf* next;
};

void PrintSet(List<TempArgForCalculation>* set) {
    Node<TempArgForCalculation>* temp_set = set->head;
    while (temp_set) {
        cout << temp_set->data.value;
        temp_set = temp_set->next;
    }
    cout << endl;
}

struct Dnf {
    NodeForDnf* head_of_dnf;
    List<bool> value;
    Dnf() {
        head_of_dnf = NULL;
    }

    //be careful
    void PushFront(List<Argument>* a) {
        NodeForDnf* temp = new NodeForDnf;
        temp->data = a;
        temp->next = head_of_dnf;
        head_of_dnf = temp;
    }

    void CalculateDnf(int n) {
        int quantity_of_sets = (int)pow(2, n);
        for (int i = 0; i < quantity_of_sets; i++) {
            //зберегти вказівник на початок
            bool temp_value_of_conjuction;
            NodeForDnf* temp_head = head_of_dnf;
            Node<Argument>* temp_head_of_elementary_conjuction = NULL;
            List<TempArgForCalculation>* set = new List<TempArgForCalculation>;
            int mask = 1;
            for (int j = 0; j < n; j++, mask = mask << 1) {
                TempArgForCalculation temp;
                temp.index = j;
                temp.value = (bool)(i & mask);
                set->PushFront(temp);
            }
            //PrintSet(set);
            while (temp_head) {
                //temp_value_of_conjuction = true;
                temp_value_of_conjuction = true;
                temp_head_of_elementary_conjuction = temp_head->data->head;//+
                bool is_break(false);
                while (temp_head_of_elementary_conjuction) {//+
                    Node<TempArgForCalculation>* temp_head_of_set = set->head;
                    //цей цикл проблемний(може рахувати лише ЕК з 1 змінною)
                    while (temp_head_of_set) {//
                        if (temp_head_of_elementary_conjuction->data.index == temp_head_of_set->data.index) {//+
                            temp_value_of_conjuction = temp_value_of_conjuction && temp_head_of_elementary_conjuction->data.ApplyOperation(temp_head_of_set->data.value);
                            if (!temp_value_of_conjuction) {
                                is_break = true;
                            }
                            break;
                        }
                        temp_head_of_set = temp_head_of_set->next;
                    }
                    if (is_break) break;
                    temp_head_of_elementary_conjuction = temp_head_of_elementary_conjuction->next;
                }
                //temp_head_of_set = set->head;
               // cout << temp_value_of_conjuction << endl;
                temp_head = temp_head->next;
                if (temp_value_of_conjuction) {
                    value.PushFront(temp_value_of_conjuction);
                    break;
                };
            }
            if (!temp_value_of_conjuction)value.PushFront(temp_value_of_conjuction);
        }
    }
};

void IsImplicateFunctionsEachOther(Dnf first, Dnf second) {
    bool is_first_implicate_second(true), is_second_implicate_first(true);
    while (first.value.head) {
        if (!IsImplicate(first.value.head->data, second.value.head->data) && is_first_implicate_second) {
            cout << "First function doesn't implicate second" << endl;
            is_first_implicate_second = false;
        }
        if (!IsImplicate(second.value.head->data, first.value.head->data) && is_second_implicate_first) {
            cout << "Second function doesn't implicate first" << endl;
            is_second_implicate_first = false;
        }
        if (!is_first_implicate_second && !is_second_implicate_first) return;
        first.value.head = first.value.head->next;
        second.value.head = second.value.head->next;
    }
    if (is_first_implicate_second) cout << "First function implicate second" << endl;
    if (is_second_implicate_first) cout << "Second function implicate first" << endl;
}

void PrintList(Dnf a) {
    while (a.value.head) {
        cout << a.value.head->data;
        a.value.head = a.value.head->next;
    }
    cout << endl;
}



void ReadDnf(const char* file_name, Dnf& function) {
    ifstream input;
    input.open(file_name);
    Argument temp_arg_for_input;
    List<Argument>* temp_list_for_push = new List<Argument>();
    while (input >> temp_arg_for_input) {
        cout << temp_arg_for_input.index << temp_arg_for_input.operation << " ";
        temp_list_for_push->PushBack(temp_arg_for_input);
        if (input.peek() == '\n' || input.peek() == EOF) {
            cout << endl;
            function.PushFront(temp_list_for_push);
            temp_list_for_push = new List<Argument>();
        }
    }
    input.close();
    cout << endl;
}


int main() {
    Dnf first_func, second_func;
    ReadDnf("function_1.txt", first_func);
    ReadDnf("function_2.txt", second_func);
    first_func.CalculateDnf(4);
    second_func.CalculateDnf(4);
    PrintList(first_func);
    PrintList(second_func);
    IsImplicateFunctionsEachOther(first_func, second_func);
}
