#pragma once

struct Vertex {
    int number;
    int quantity_of_adjacency_edges;
    int sum_of_values_of_edges;
    int x = 0;
    int y = 0;
    double function_value = 0;

    Vertex(const int& new_number = 0, const int& new_quantity_of_adjacency_edges = 0, const int& new_sum_of_values_of_edges = 0) {
        number = new_number;
        quantity_of_adjacency_edges = new_quantity_of_adjacency_edges;
        sum_of_values_of_edges = new_sum_of_values_of_edges;
    }

    void InitializeByCoords(const int& new_number ,const int& new_x, const int& new_y, const double& new_function_value) {
        number = new_number;
        x = new_x;
        y = new_y;
        function_value = new_function_value;
    }
};

struct Edge {
    int from;
    int to;
    int value;

    int middle_x = 0, middle_y = 0;
    double function_value = 0;

    Edge() {
        from = 0;
        to = 0;
        value = 0;
    }

    Edge(const int& new_from, const int& new_to, const int& new_value) {
        from = new_from;
        to = new_to;
        value = new_value;
    }
};

struct Cycle {
    int vertices[3]{ 0 };
    double area;
    Cycle() {
        area = -1;
    };
    Cycle(const int& a, const int& b, const int& c) {
        vertices[0] = a;
        vertices[1] = b;
        vertices[2] = c;
    }
};


//Task 1(Insertion sort)
//______________________________________________


void InsertionSort(Vertex array[], int size) {
    for (int i = 1; i < size; i++) {
        Vertex key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j].quantity_of_adjacency_edges > key.quantity_of_adjacency_edges) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void BubbleSort(Vertex array[], int size) {
    bool is_swapped;
    for (int i = 0; i < size - 1; ++i) {
        is_swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j].sum_of_values_of_edges > array[j + 1].sum_of_values_of_edges) {
                swap(array[j], array[j + 1]);
                is_swapped = true;
            }
        }
        if (!is_swapped) break;
    }
}

void ShakerSort(Vertex array[], int size) {
    bool is_swapped = true;
    int begin = 0, end = size - 1;

    while (is_swapped) {
        is_swapped = false;

        for (int i = begin; i < end; ++i) {
            if (array[i].function_value>array[i + 1].function_value) {
                swap(array[i], array[i + 1]);
                is_swapped = true;
            }
        }

        if (!is_swapped) break;
        is_swapped = false;
        end--;

        for (int i = end - 1; i >= begin; --i) {
            if (array[i].function_value > array[i + 1].function_value) {
                swap(array[i], array[i + 1]);
                is_swapped = true;
            }
        }
        begin++;
    }
}

void ShellSort(Edge array[], int size) {
    for (int gap = size / 2; gap; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            Edge temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap].function_value > temp.function_value; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int Partition(Edge array[], int begin, int end) {
    int pivot = array[end].value;
    int border = begin - 1;

    for (int i = begin; i <= end - 1; ++i) {
        if (array[i].value < pivot) {
            ++border;
            swap(array[border], array[i]);
        }
    }
    swap(array[border + 1], array[end]);
    return border + 1;
}

void QuickSort(Edge array[], int begin, int end) {
    if (begin < end) {
        int partitioning_idx = Partition(array, begin, end);
        QuickSort(array, begin, partitioning_idx - 1);
        QuickSort(array, partitioning_idx + 1, end);
    }
}

void Merge(Cycle array[], int left, int medium, int right) {
    int n1 = medium - left + 1;
    int n2 = right - medium;

    Cycle* left_subarray = new Cycle[n1];
    Cycle* right_subarray = new Cycle[n2];
    for (int i = 0; i < n1; ++i) {
        left_subarray[i] = array[left + i];
    }

    for (int i = 0; i < n1; ++i) {
        right_subarray[i] = array[medium + i + 1];
    }

    int i(0), j(0), k(left);

    while (i < n1 && j < n2) {
        if (left_subarray[i].area <= right_subarray[j].area) {
            array[k] = left_subarray[i++];
        }
        else {
            array[k] = right_subarray[j++];
        }
        k++;
    }

    while (i < n1) {
        array[k++] = left_subarray[i++];
    }

    while (j < n2) {
        array[k++] = right_subarray[j++];
    }

    delete[] left_subarray, right_subarray;
}

void MergeSort(Cycle array[], int left, int right) {
    if (left < right) {
        int medium = (left + right) / 2;
        MergeSort(array, left, medium);
        MergeSort(array, medium + 1, right);
        Merge(array, left, medium, right);
    }
}
