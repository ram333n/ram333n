#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

template<typename T> struct Stack {
    T value;
    struct Stack* next;
};

template<typename T> void push(Stack<T>*& TOP, T VALUE) {
    Stack<T>* top = new Stack<T>;
    top->value = VALUE;
    top->next = TOP != NULL ? TOP : NULL;
    TOP = top;
}

template<typename T> T pop(Stack<T>*& TOP) {
    if (TOP == NULL) {
        return NULL;
    }
    T value = TOP->value;
    Stack<T>* oldTop = TOP;
    TOP = oldTop->next;
    delete oldTop;
    return value;
}


void substring(char* str, char* numStr, int s, int e) {
    for (int i = s, j = 0; i < e; i++, j++) {
        numStr[j] = str[i];
    }
}


double ApplyOperation(double op1, char op, double op2 = 0) {

    switch (op) {
    case '+': {
        return op1 + op2;
    }
    case '-': {
        return op1 - op2;
    }
    case '/': {
        return op1 / op2;

    }
    }
    return 0;
}

void calcRPN(Stack<double>*& stack, char* problem, int& i) {

    bool isPrefix = false;
    bool skip = false;
    char prefix[2]{ 0 };

    while (problem[i] != 0) {

        switch (problem[i]) {
        case ')': {
            i++;
            return;
        }
        case '(': {
            i++;
            calcRPN(stack, problem, i);
            break;
        }
        case '+':
        case '-': {

            int j = i - 1;
            while (j >= 0 && problem[j] == ' ') j--;

            if (j < 0 || !isdigit(problem[j])) {
                prefix[0] = problem[i];
                isPrefix = true;
                skip = true;
            }
            else {

                double op2 = pop(stack);
                double op1 = pop(stack);
                double res = ApplyOperation(op1, problem[i], op2);
                push(stack, res);
            }
            i++;
            break;
        }
        case '/': {
            double op2 = pop(stack);
            double op1 = pop(stack);
            double res = ApplyOperation(op1, problem[i], op2);
            push(stack, res);
            i++;
            break;
        }
        case ' ': {
            i++;
            break;
        };
        default: {
            if (!skip) {
                int start = i;

                while (isdigit(problem[i])) {
                    i++;
                }
                char* numStr = new char[i - start]{ 0 };
                substring(problem, numStr, start, i);
                double num = atof(numStr);
                if (isPrefix && prefix[0] == '-') num *= -1;
                push(stack, num);
                isPrefix = false;
                delete[] numStr;
            }
            else {
                skip = false;
            }
        }
        }
    }
}

bool hasHigherPriority(char op1, char op2) {
    if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) {
        return false;
    };
    return op1 > op2;
}



bool isOperation(char* str) {
    return
        strcmp(str, "exp") == 0 ||
        strcmp(str, "+") == 0 ||
        strcmp(str, "-") == 0 ||
        strcmp(str, "/") == 0;
}

int toRPN(char* problem, char* rpn) {
    int i = 0;
    Stack<char*>* stack = NULL;

    bool isPrefix = false;
    bool skip = false;
    char prefix[2]{ 0 };

    while (problem[i] != 0) {

        if (problem[i] == 'e' && problem[i + 1] == 'x' && problem[i + 2] == 'p') {
            char EXP[] = "exp";
            push(stack, EXP);
            i += 3;
        }
        else {
            switch (problem[i]) {
            case ')': {
                while (stack != NULL && strcmp(stack->value, "(") != 0) {
                    char* str = pop(stack);
                    strcat(rpn, str);
                    strcat(rpn, " ");
                }
                if (stack == NULL) {
                    return -1;
                }
                pop(stack);
                i++;
                break;
            }
            case '(': {
                char arr[2]{ '(', 0 };
                push(stack, arr);
                i++;
                break;
            }
            case '+':
            case '-': {

                int j = i - 1;
                while (j >= 0 && problem[j] == ' ') j--;

                if (j < 0 || !isdigit(problem[j])) {
                    prefix[0] = problem[i];
                    isPrefix = true;
                    skip = true;
                }
                else {

                    while (stack != NULL && isOperation(stack->value) && hasHigherPriority(stack->value[0], problem[i])) {
                        char* str = pop(stack);
                        strcat(rpn, str);
                        strcat(rpn, " ");
                    }
                    char arr[2]{ problem[i], 0 };
                    push(stack, arr);
                }
                i++;
                break;
            }
            case '/': {

                while (stack != NULL && isOperation(stack->value) && hasHigherPriority(stack->value[0], problem[i])) {
                    char* str = pop(stack);
                    strcat(rpn, str);
                    strcat(rpn, " ");
                }
                char arr[2]{ problem[i], 0 };
                push(stack, arr);
                i++;
                break;
            }
            case ' ': {
                continue;
            };
            default: {

                if (!skip) {
                    int start = i;

                    char* numStr;

                    if (isalpha(problem[i])) {
                        while (isalpha(problem[i]) || isdigit(problem[i])) {
                            i++;
                        }
                        numStr = new char[i - start + 1]{ 0 };
                        substring(problem, numStr, start, i);
                        char num[50];
                        cout << "enter value of variable " << numStr << endl;
                        cin.getline(num, 50);
                        strcat(rpn, num);
                        strcat(rpn, " ");
                    }
                    else {
                        while (isdigit(problem[i])) {
                            i++;
                        }
                        numStr = new char[i - start + 1]{ 0 };
                        substring(problem, numStr, start, i);
                        if (isPrefix) strcat(rpn, prefix);
                        strcat(numStr, " ");
                        strcat(rpn, numStr);
                    }


                    isPrefix = false;
                }
                else {
                    skip = false;
                }
                //delete[] numStr;
            }
            }
        }
    }

    while (stack != NULL) {
        char* op = pop(stack);
        if (!isOperation(op)) return -1;
        strcat(rpn, op);
        strcat(rpn, " ");
    }

    return 0;
}


int main() {



    char problem[200] = "(-1+a)/4+1";
    //char problem[200];
    //cout << "enter problem" << endl;
    //cin.getline (problem,200);
    char rpn[200]{ 0 };
    toRPN(problem, rpn);
    cout << "RPN notation " << rpn << endl;
    Stack<double>* stack = NULL;
    int i = 0;
    calcRPN(stack, rpn, i);
    cout << stack->value << endl;

}