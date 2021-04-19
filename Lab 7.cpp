#include <iostream>
#include <fstream>
using namespace std;

#include "sorting_algorithms.h"

const int TEST_SIZE = 7;



void Task1(const int graph[TEST_SIZE][TEST_SIZE]) {
    Vertex result[TEST_SIZE];

    for (int i = 0; i < TEST_SIZE; ++i) {
        int q = 0;
        for (int j = 0; j < TEST_SIZE; ++j) {
            if (graph[i][j]) q++;
        }
        result[i] = Vertex(i, q);
    }

    InsertionSort(result, TEST_SIZE);
    cout << "Task 1 : ";
    for (int i = 0; i < TEST_SIZE; ++i) {
        cout << result[i].number << " ";
    }
    cout << endl << endl;
}


//Task 2(Bubble sort)


void Task2(const int graph[TEST_SIZE][TEST_SIZE]) {
    Vertex result[TEST_SIZE];
    for (int i = 0; i < TEST_SIZE; ++i) {
        int sum = 0;
        for (int j = 0; j < TEST_SIZE; ++j) {
            sum += graph[i][j];
        }
        result[i] = Vertex(i,0,sum);
    }
    BubbleSort(result, TEST_SIZE);
    cout << "Task 2 : ";
    for (int i = 0; i < TEST_SIZE; ++i) {
        cout << result[i].number << " ";
    }
    cout << endl << endl;
}

//Task 3(Shaker sort)

double PointDistance(const int& x, const int& y) {
    return sqrt(x * x + y * y);
}

void Task3(double (*function)(const int&,const int&)) {
    Vertex result[TEST_SIZE];
    for (int i = 0; i < TEST_SIZE; ++i) {
        int new_x = rand() % 50;
        int new_y = rand() % 50;
        result[i].InitializeByCoords(i,new_x, new_y, function(new_x, new_y));
    }
    ShakerSort(result, TEST_SIZE);

    cout << "Task 3 : ";
    for (int i = 0; i < TEST_SIZE; ++i) {
        cout << "{ " << result[i].number << ", (" << result[i].x << ", " << result[i].y << ") ," << result[i].function_value << " } ;";
    }
    cout << endl << endl;
}

// Task 4(Quick sort)


void Task4(const int graph[TEST_SIZE][TEST_SIZE],const int& quantity_of_edges) {
    Edge *result = new Edge[quantity_of_edges];
    int current_idx(0);
    for (int i = 0; i < TEST_SIZE; ++i) {
        for (int j = 0; j < i; ++j) {
            if (graph[i][j]) {
                result[current_idx++] = Edge(i, j, graph[i][j]);
            }
        }
    }

    QuickSort(result, 0, quantity_of_edges - 1);

    cout << "Task 4 :";
    for (int i = 0; i < quantity_of_edges; ++i) {
        cout << "{ (" << result[i].from << ", " << result[i].to << ") ," << result[i].value << " } ;";   
    }
    cout << endl << endl;
    delete[]result;
}


// Task 5(Shell sort)

void Task5(const int graph[TEST_SIZE][TEST_SIZE], const int& quantity_of_edges, double (*function)(const int&, const int&)) {
    Edge* result = new Edge[quantity_of_edges];
    int idx_of_edge(0);
    for (int i = 0; i < TEST_SIZE; ++i) {
        for (int j = 0; j < i; ++j) {
            if (graph[i][j]) {
                result[idx_of_edge] = Edge(i, j, graph[i][j]);
                result[idx_of_edge].middle_x = rand() % 50;
                result[idx_of_edge].middle_y = rand() % 50;
                result[idx_of_edge].function_value = function(result[idx_of_edge].middle_x, result[idx_of_edge].middle_y);
                idx_of_edge++;
            }
        }
    }
    ShellSort(result, quantity_of_edges);

    cout << "Task 5 :";
    for (int i = 0; i < quantity_of_edges; ++i) {
        cout << "{ (" << result[i].from << ", " << result[i].to << ") ," << "(" << result[i].middle_x << ", " << result[i].middle_y << ") ," << result[i].function_value << "} ;";
    }
    cout << endl << endl;
    delete[]result;
}

double CalculateArea(const int& a, const int& b, const int& c) {
    double p = (a + b + c) / 2;
    if (p * (p - a) * (p - b) * (p - c) < 0) return 0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Task6(const int graph[TEST_SIZE][TEST_SIZE]) {
    Cycle result[25];
    int current_idx(0);
    for (int i = 0; i < TEST_SIZE; ++i) {
        for (int j = i + 1; j < TEST_SIZE; ++j) {
            if (graph[i][j]) {
                for (int k = j + 1; k < TEST_SIZE; ++k) {
                    if (graph[j][k] && graph[i][k]) {
                        result[current_idx] = Cycle(i, j, k);
                        result[current_idx].area = CalculateArea(graph[i][j], graph[j][k], graph[i][k]);
                        current_idx++;
                    }
                }
            }
        }
    }
    cout << "Task 6 : ";
    for (int i = 0; result[i].area != -1; ++i) {
        cout << "{(" << result[i].vertices[0] << ", " << result[i].vertices[1] << ", " << result[i].vertices[2] << "), " << result[i].area << "}; ";
    }
    cout << endl << endl;
}

int main(){
    int quantity_of_edges(0);
    int graph[TEST_SIZE][TEST_SIZE];
    ifstream input;
    input.open("input_lab7.txt");
    for (int i = 0; i < TEST_SIZE; ++i) {
        for (int j = 0; j < TEST_SIZE; ++j) {
            input >> graph[i][j];
            if (graph[i][j] && j < i) quantity_of_edges++;
        }
    }

    Task1(graph);
    Task2(graph);
    Task3(PointDistance);
    Task4(graph, quantity_of_edges);
    Task5(graph, quantity_of_edges, PointDistance);
    Task6(graph);
    /*int a[] = { 3,-2,0,54,7,-31,76,43,8,6,-23,-3131 };
    int a_size = sizeof(a) / sizeof(int);

    MergeSort(a, 0, a_size - 1);
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        cout << a[i] << " ";
    }*/
}
