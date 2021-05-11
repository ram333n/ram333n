#pragma once
#include <string>

struct Bus {
    int bus_number;
    string driver_name;
    int route_number;
    Bus() {
        bus_number = route_number = 0;
        driver_name = "";
    }
    Bus(const int& new_bus_number, const string& new_driver_name, const int& new_route_number) {
        bus_number = new_bus_number;
        driver_name = new_driver_name;
        route_number = new_route_number;
    }
};

//bool operator==(const Bus& lhs, const Bus& rhs) {
//    return lhs.bus_number == rhs.bus_number
//        && lhs.driver_name == rhs.driver_name
//        && lhs.route_number == rhs.route_number;
//}
//
//bool operator!=(const Bus& lhs, const Bus& rhs) {
//    return !(lhs == rhs);
//}

istream& operator>>(istream& input, Bus& b) {
    input >> b.bus_number >> b.driver_name >> b.route_number;
    return input;
}

ostream& operator<<(ostream& output, const Bus& b) {
    output << "Bus number : " << b.bus_number << endl
        << "Driver name : " << b.driver_name << endl
        << "Route number : " << b.route_number << endl
        << "_________________________________";

    return output;
}


template<typename T> struct Node {
    T data;
    Node* next, * prev;
    Node(const T& new_data) {
        data = new_data;
        next = prev = nullptr;
    }
};


template <typename T>struct List {
    List() {
        begin = end = nullptr;
        list_size = 0;
    }

    void push_back(const T& data) {
        Node<T>* to_push = new Node<T>(data);
        if (end) {
            end->next = to_push;
        }
        else {
            begin = to_push;
        }
        to_push->prev = end;
        end = to_push;
        ++list_size;
    }

    void push_front(const T& data) {
        Node<T>* to_push = new Node(data);
        if (begin) {
            begin->prev = to_push;
        }
        else {
            end = to_push;
        }
        to_push->next = begin;
        begin = to_push;
        ++list_size;
    }


    void print() {
        Node<T>* current = begin;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }

    Node<T>* search(const int& data) {
        Node<T>* current = begin;
        while (current) {
            if (current->data.bus_number == data) break;
            current = current->next;
        }
        return current;
    }
    
    void remove(Node<T>* to_remove) {
        if (to_remove->prev) {
            to_remove->prev->next = to_remove->next;
        }
        else {
            begin = to_remove->next;
        }

        if (to_remove->next) {
            to_remove->next->prev = to_remove->prev;
        }
        else {
            end = to_remove->prev;
        }

        delete to_remove;
        --list_size;
    }

    size_t size() const {
        return list_size;
    }

    T& peek_back() {
        return end->data;
    }

    T& peek_front() {
        return begin->data;
    }

    ~List() {
        while (begin) {
            remove(begin);
        }
    }

private:
    Node<T>* begin, * end;
    size_t list_size;
};