#include <iostream>
#include <fstream>
using namespace std;

const int TEST_SIZE = 5;


struct MatrixElementNode {
    int value, column;
    MatrixElementNode* next, * prev;
    MatrixElementNode(const int& new_value, const int& new_column) {
        next = prev = nullptr;
        value = new_value;
        column = new_column;
    }
};
 
struct MatrixRow {
    MatrixElementNode* begin, *end;
    MatrixRow() {
        begin = end = nullptr;
    }

    void push_back(const int& value, const int& column) {
        MatrixElementNode* new_node = new MatrixElementNode(value, column);
        if (end) {
            end->next = new_node;
        }
        else {
            begin = new_node;
        }
        end = new_node;
    }

    void push_front(const int& value, const int& column) {
        MatrixElementNode* new_node = new MatrixElementNode(value, column);
        if (begin) {
            begin->prev = new_node;
        }
        else {
            end = new_node;
        }
        begin = new_node;
    }
    //ggqwgqwgq
    int search_element_by_index(const int& idx) {
        MatrixElementNode* current = begin;
        while (current) {
            if (current->column == idx) return current->value;
            current = current->next;
        }
        return 0;
    }

    MatrixElementNode* get_pointer_to_remove(const int& idx) {
        MatrixElementNode* current = begin;
        while (current) {
            if (current->column == idx) return current;
            current = current->next;
        }
        return nullptr;
    }

    void remove_node(MatrixElementNode* node_to_remove) {
        if (!node_to_remove)return;
        if (node_to_remove->prev) {
            node_to_remove->prev->next = node_to_remove->next;
        }
        else {
            begin = node_to_remove->next;
        }

        if (node_to_remove->next) {
            node_to_remove->next->prev = node_to_remove->prev;
        }
        else {
            end = node_to_remove->prev;
        }
        delete node_to_remove;
    }
};


struct MatrixRowNode {
    int row_index;
    MatrixRow* row;
    MatrixRowNode* next;
    MatrixRowNode* prev;
    MatrixRowNode(MatrixRow* new_row, const int& new_index) {
        row = new_row;
        next = prev = nullptr;
        row_index = new_index;
    }

};

MatrixRow* DEF_ROW = new MatrixRow;
MatrixRowNode* DEFAULT = new MatrixRowNode(DEF_ROW,-1);

struct Matrix {
    MatrixRowNode* begin, * end;
    Matrix() {
        DEF_ROW->push_back(0, 5);
        begin = end = nullptr;
    }
    void push_back(const int& idx, MatrixRow row) {
        MatrixRow* pRow = new MatrixRow(row);
        MatrixRowNode* new_node = new MatrixRowNode(pRow, idx);
        if (end) {
            end->next = new_node;
        }
        else {
            begin = new_node;
        }
        end = new_node;
    }

    void push_front(MatrixRowNode* new_node) {
        if (begin) {
            begin->prev = new_node;
        }
        else {
            end = new_node;
        }
        begin = new_node;
    }

    MatrixRowNode* search_row_by_index(const int& idx) {
        if (!begin) return DEFAULT;
        MatrixRowNode* current = begin;
        while (current) {
            if (current->row_index == idx) return current;
            current = current->next;
        }
        return DEFAULT;
    }

    Matrix(const char* file_name) {
        begin = end = nullptr;
        ifstream input;
        input.open(file_name);
        int buff(0);
        for (int i = 0; i < TEST_SIZE; ++i) {
            MatrixRow new_row;
            bool is_zero_row(true);
            for (int j = 0; j < TEST_SIZE; ++j) {
                input >> buff;
                if (buff != 0) {
                    is_zero_row = false;
                    new_row.push_back(buff, j);
                }
            }
            if (!is_zero_row) {
                push_back(i, new_row);
            }
        }
        input.close();
    }

    void print() {
        for (int i = 0; i < TEST_SIZE; ++i) {
            MatrixRowNode* searched_row = search_row_by_index(i);
            if (!searched_row) {
                cout << "0 0 0 0 0";
            }
            else {
                for (int j = 0; j < TEST_SIZE; ++j) {
                    int searched_elem = searched_row->row->search_element_by_index(j);
                    cout << searched_elem << " ";
                }
            }
            cout << endl;
        }
    }
};


Matrix Adding(Matrix m_1, Matrix m_2) {
    Matrix result;
    for (int i = 0; i < TEST_SIZE; ++i) {
        bool to_push(false);
        MatrixRowNode* searched_in_1 = m_1.search_row_by_index(i);
        MatrixRowNode* searched_in_2 = m_2.search_row_by_index(i);
        if (!m_1.search_row_by_index(i) && m_2.search_row_by_index(i)) {
            result.push_back(i, *searched_in_2->row);
            to_push = true;
        }
        else if (m_1.search_row_by_index(i) && !m_2.search_row_by_index(i)) {
            result.push_back(i, *searched_in_1->row);
            to_push = true;
        }
        else if(!m_1.search_row_by_index(i) && !m_2.search_row_by_index(i)) {
            to_push = true;
        }
        if (to_push) continue;
        for (int j = 0; j < TEST_SIZE; ++j) {
            int value_of_1 = searched_in_1->row->search_element_by_index(j);
            int value_of_2 = searched_in_2->row->search_element_by_index(j);
            if (!value_of_1 && value_of_2) {
                searched_in_1->row->push_back(value_of_2, j);
            }
            else if (value_of_1 && !value_of_2) { to_push = true; }
            else if (!(value_of_1 || value_of_2) || value_of_1 + value_of_2 == 0) {
                if (value_of_1 + value_of_2 == 0) {
                    searched_in_1->row->remove_node(searched_in_1->row->get_pointer_to_remove(j));
                }
                continue;
            }
            to_push = true;
            searched_in_1->row->remove_node(searched_in_1->row->get_pointer_to_remove(j));
            searched_in_1->row->push_back(value_of_1 + value_of_2, j);
        }
        if (to_push) result.push_back(i,*searched_in_1->row);
    }
    return result;
}


Matrix multiply(Matrix m_1, Matrix m_2) {
    Matrix result;
    for (int row = 0; row < TEST_SIZE; row++) {
        MatrixRow to_push;
        for (int column = 0; column < TEST_SIZE; column++) {
            int t(0);
            for (int a = 0; a < TEST_SIZE; a++) {//
                t += m_1.search_row_by_index(row)->row->search_element_by_index(a) * m_2.search_row_by_index(a)->row->search_element_by_index(column);
            }
            if (t == 0) continue;
            to_push.push_back(t, column);
        }
        result.push_back(row, to_push);
    }
    return result;
}
int main()
{
    Matrix m1("Matr1.txt");
    m1.print();
    cout << endl;
    Matrix m2("Matr2.txt");
    m2.print();
   // cout << endl << "Sum:" << endl;
   // Matrix m3 = Adding(m1, m2);
   // m3.print();
    cout << endl << "Multiply:" << endl;
    Matrix m4 = multiply(m1, m2);
    m4.print();
    delete DEF_ROW, DEFAULT;

}
