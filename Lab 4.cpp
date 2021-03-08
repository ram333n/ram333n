#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T> struct Node {
    T data;
    Node* next;
    Node(T new_data) {
        next = nullptr;
        data = new_data;
    }
};


template<typename T> struct Stack {
    Node<T>* top;
    size_t stack_size;
    Stack() {
        top = nullptr;
        stack_size = 0;
    }

    void push(T data) {
        Node<T>* new_node = new Node<T>(data);
        new_node->next = top;
        top = new_node;
        ++stack_size;
    }

    T pop() {
        if (!top) throw exception("Stack is null");
        T result = top->data;
        Node<T>* ptemp = top->next;
        top->next = nullptr;
        delete top;
        top = ptemp;
        --stack_size;
        return result;
    }

    size_t size() const {
        return stack_size;
    }

    T peek() {
        if (!top) return NULL;
        return top->data;
    }

    bool is_empty() {
        return size() == 0;
    }

};


template<typename T> struct Queue {
    Node<T>* front;
    Node<T>* back;
    size_t queue_size;

    Queue() {
        front = nullptr;
        back = nullptr;
        queue_size = 0;
    }

    void push_back(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (!front) {
            front = new_node;
        }
        new_node->next = back;
        back = new_node;
        ++queue_size;
    }
     
    T pop_front() {
        if (!front) throw exception("Queue is null");
        Node<T>* ptemp = back;
        T result = front->data;
        if (!ptemp->next) {
            delete front;
            front = back = nullptr;
            --queue_size;
            return result;
        }
        while (ptemp->next->next) {
            ptemp = ptemp->next;
        }
        ptemp->next = nullptr;
        delete front;
        front = ptemp;
        --queue_size;
        return result;
    }

    size_t size() const {
        return queue_size;
    }

    T peek() {
        if (!front) throw exception("Queue is null");
        return front->data;
    }

    bool is_empty() {
        return size()==0;
    }
};

void PrintStack(Stack<int> s) {
    Node<int>* current = s.top;
    while (current) {
        cout << current->data << ",";
        current = current->next;
    }
    cout << endl;
}

bool IsOperator(const char& ch) {
    return ch == '+' ||
        ch == '-' ||
        ch == '/' ||
        ch == '*' ||
        ch == '^';
}

int GetOperationPriority(const char& ch){
    switch (ch){   
        case '^':
            return 4;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case')':
            return 0;
        }
        return -1;
}

void ReplaceVars(string& problem) {
    int quantity_of_variables(0);
    bool is_variable_in_problem = false;
    struct variable {
        char name;
        int value;
        variable() {};
        variable(const char& new_name, const char& new_value) {
            name = new_name;
            value = new_value;
        }
    };
    variable arr[3];
    for (size_t i = 0; i < problem.size(); ++i) {
        if (isalpha(problem[i]) && !is_variable_in_problem) {
            int temp_value(0);
            cout << "Enter the value of " << problem[i] << endl;
            cin >> temp_value;
            variable v(problem[i], temp_value);
            problem[i] = temp_value + '0';
            arr[quantity_of_variables++] = v;
            is_variable_in_problem = true;
        }
        else if (isalpha(problem[i]) && is_variable_in_problem) {
            for (int j = 0; j < quantity_of_variables; j++) {
                if (arr[j].name == problem[i]) {
                    problem[i] = arr[j].value+'0';
                    is_variable_in_problem = false;
                    break;
                }
            }
            if (is_variable_in_problem) {
                i--;
                is_variable_in_problem = false;
            }
        }
    }
}



string GetRPN(string& problem) {
    ReplaceVars(problem);
    Queue<char> queue;
    Stack<char> stack;
    string result;
    for (size_t i = 0; i < problem.size(); i++) {
        if (isdigit(problem[i])) {
            queue.push_back(problem[i]);
        }
        else if (IsOperator(problem[i])){
            if (stack.is_empty() || (stack.peek() == '(')) {
                stack.push(problem[i]);
                //
            }
            else if (GetOperationPriority(problem[i]) > GetOperationPriority(stack.peek())) {
                stack.push(problem[i]);
            }
            else {
                //trouble
                while ((GetOperationPriority(problem[i]) <= GetOperationPriority(stack.peek())) && stack.peek() != '('&&!stack.is_empty()) {
                    queue.push_back(stack.pop());
                }
                stack.push(problem[i]);
            }
        }
        else if (problem[i] == '(') {
            stack.push(problem[i]);
        }
        else {
            while (stack.peek() != '(') {
                queue.push_back(stack.pop());
            }
            stack.pop();
        }
    }
    while (!stack.is_empty()) {
        queue.push_back(stack.pop());
    }
    while (!queue.is_empty()) {
        result.push_back(queue.pop_front());
    }
    return result;
}

//Expression tree



struct TreeNode {
    string data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {};
    TreeNode(const string& new_data) {
        left = right = nullptr;
        data = new_data;
    }
};


TreeNode* ConstructNode(const string& data) {
    TreeNode* new_node = new TreeNode(data);
    return new_node;
}


void PrintTree(TreeNode* t) {
    if (t) {
        PrintTree(t->left);
        cout << t->data;
        PrintTree(t->right);
    }
}

TreeNode* ConstructTree(string postfix) {
    Stack<TreeNode*> stack;
    TreeNode* result_tree, *temp_left, *temp_right;
    for (size_t i = 0; i < postfix.size(); ++i) {
        string temp_data("");
        if (!IsOperator(postfix[i])) {
            temp_data.push_back(postfix[i]);
            result_tree = ConstructNode(temp_data);
            stack.push(result_tree);
        }
        else {
            temp_data.push_back(postfix[i]);
            result_tree = ConstructNode(temp_data);
            temp_right = stack.pop();
            temp_left = stack.pop();
            result_tree->left = temp_left;
            result_tree->right = temp_right;
            stack.push(result_tree);
        }  
    }
    result_tree = stack.pop();
    return result_tree;
}

double CalculateTree(TreeNode* tree)
{
    if (!tree)
        return 0;

    if (!tree->left && !tree->right)
        return stod(tree->data);

    double left_value = CalculateTree(tree->left);
    double right_value = CalculateTree(tree->right);

    if (tree->data == "+") {
        return left_value + right_value;
    }
    if (tree->data == "-") {
        return left_value - right_value;
    }
    if (tree->data == "*") {
        return left_value * right_value;
    }
    if (tree->data == "/") {
        return left_value / right_value;
    }
    if (tree->data == "^") {
        return pow(left_value,right_value);
    }
    if (tree->data == "~") {
        return -left_value;
    }
            
}


int main()
{
    try {
        string t;
        // a*8*(2+9)+(7*5+8-9*a^2+5) a=5;
        cin >> t;
        string postfix = GetRPN(t);
        cout << "RPN : " << postfix << endl;
        TreeNode* r = ConstructTree(postfix);
        cout << "Expression tree : ";
        PrintTree(r);
        cout << endl;
        cout <<"Value : "<< CalculateTree(r) << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
}
