#include <iostream>
#include <fstream>

using namespace std;

const int TEST_SIZE = 7;

int get_vertex_with_min_value(int values[], bool is_included[]){
	int min = INT_MAX, min_index;
	for (int i = 0; i < TEST_SIZE; ++i) {
		if (!is_included[i] && values[i] < min) {
			min = values[i];
			min_index = i;
		}
	}
	return min_index;
}


void print(int tree[], int graph[TEST_SIZE][TEST_SIZE]){
	cout << "Edge	" << "Weight" << endl;
	for (int i = 1; i < TEST_SIZE; i++) {
		cout << tree[i] << " - " << i << "	" << graph[i][tree[i]] << endl;
	}
}


void prim_algorithm(int graph[TEST_SIZE][TEST_SIZE]){
	int constructed_tree[TEST_SIZE];
	int values[TEST_SIZE];

	bool is_included[TEST_SIZE];

	for (int i = 0; i < TEST_SIZE; i++) {
		values[i] = INT_MAX;
		is_included[i] = false;
	}

	values[0] = 0;
	constructed_tree[0] = -1;

	for (int count = 0; count < TEST_SIZE - 1; count++){
		int u = get_vertex_with_min_value(values, is_included);
		is_included[u] = true;
		for (int i = 0; i < TEST_SIZE; i++) {
			if (graph[u][i] && !is_included[i] && graph[u][i] < values[i]) {
				constructed_tree[i] = u;
				values[i] = graph[u][i];
			}
		}
	}
	print(constructed_tree, graph);
}


int main(){
	int graph[TEST_SIZE][TEST_SIZE];
	ifstream input;
	input.open("input_lab6.txt");
	for (int i = 0; i < TEST_SIZE; ++i) {
		for (int j = 0; j < TEST_SIZE; ++j) {
			input >> graph[i][j];
		}
	}
	prim_algorithm(graph);
}



