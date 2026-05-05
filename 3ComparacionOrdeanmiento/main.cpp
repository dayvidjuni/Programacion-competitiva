#include <iostream>
#include <chrono>
#include <random>
#include <string>

using namespace std;

int bubbleSort(int arr[], int n) {
    int p = 0;
    bool sw;
    for (int i = 0; i < n - 1; ++i) {
        sw = false;
        for (int j = 0; j < n - i - 1; ++j) {
            p++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                p++;
                sw = true;
            }
        }
        if (!sw) break;
    }
    return p;
}

int selectionSort(int arr[], int n) {
    int p = 0;
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            p++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            p++;
        }
    }
    return p;
}

int insertionSort(int arr[], int n) {
    int p = 0;
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        p++;
        while (j >= 0 && arr[j] > key) {
            p++;
            arr[j + 1] = arr[j];
            p++;
            j = j - 1;
        }
        arr[j + 1] = key;
        p++;
    }
    return p;
}

int partitionArray(int arr[], int low, int high, int& p) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) { int t = arr[low]; arr[low] = arr[mid]; arr[mid] = t; p++; }
    if (arr[high] < arr[low]) { int t = arr[low]; arr[low] = arr[high]; arr[high] = t; p++; }
    if (arr[high] < arr[mid]) { int t = arr[mid]; arr[mid] = arr[high]; arr[high] = t; p++; }
    
    int t = arr[mid]; arr[mid] = arr[high]; arr[high] = t; p++;
    int pivot = arr[high];
    
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        p++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            p++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    p++;
    return (i + 1);
}

void quickSortRecursive(int arr[], int low, int high, int& p) {
    if (low < high) {
        int pi = partitionArray(arr, low, high, p);
        quickSortRecursive(arr, low, pi - 1, p);
        quickSortRecursive(arr, pi + 1, high, p);
    }
}

int quickSort(int arr[], int n) {
    int p = 0;
    if (n > 1) {
        quickSortRecursive(arr, 0, n - 1, p);
    }
    return p;
}

int shellSort(int arr[], int n) {
    int p = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            p++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                p++;
                arr[j] = arr[j - gap];
                p++;
            }
            arr[j] = temp;
            p++;
        }
    }
    return p;
}

void heapify(int arr[], int n, int i, int& p) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    p++;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    p++;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        p++;
        heapify(arr, n, largest, p);
    }
}

int heapSort(int arr[], int n) {
    int p = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, p);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        p++;
        heapify(arr, i, 0, p);
    }
    return p;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void printArray(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

void evaluateAndDisplay(int base_arr[], int amount, string scenario) {
    string names[6] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Quick Sort", "Shell Sort", "Heap Sort"};
    int steps[6] = {0, 0, 0, 0, 0, 0};
    int times[6] = {0, 0, 0, 0, 0, 0};
    int* sorted_results[6];

    for (int i = 0; i < 6; i++) {
        sorted_results[i] = new int[amount];
    }

    int* temp_arr = new int[amount];

    copyArray(base_arr, temp_arr, amount);
    auto start = chrono::high_resolution_clock::now();
    steps[0] = bubbleSort(temp_arr, amount);
    auto end = chrono::high_resolution_clock::now();
    times[0] = (int)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    copyArray(temp_arr, sorted_results[0], amount);

    copyArray(base_arr, temp_arr, amount);
    start = chrono::high_resolution_clock::now();
    steps[1] = selectionSort(temp_arr, amount);
    end = chrono::high_resolution_clock::now();
    times[1] = (int)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    copyArray(temp_arr, sorted_results[1], amount);

    copyArray(base_arr, temp_arr, amount);
    start = chrono::high_resolution_clock::now();
    steps[2] = insertionSort(temp_arr, amount);
    end = chrono::high_resolution_clock::now();
    times[2] = (int)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    copyArray(temp_arr, sorted_results[2], amount);

    copyArray(base_arr, temp_arr, amount);
    start = chrono::high_resolution_clock::now();
    steps[3] = quickSort(temp_arr, amount);
    end = chrono::high_resolution_clock::now();
    times[3] = (int)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    copyArray(temp_arr, sorted_results[3], amount);

    copyArray(base_arr, temp_arr, amount);
    start = chrono::high_resolution_clock::now();
    steps[4] = shellSort(temp_arr, amount);
    end = chrono::high_resolution_clock::now();
    times[4] = (int)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    copyArray(temp_arr, sorted_results[4], amount);

    copyArray(base_arr, temp_arr, amount);
    start = chrono::high_resolution_clock::now();
    steps[5] = heapSort(temp_arr, amount);
    end = chrono::high_resolution_clock::now();
    times[5] = (int)chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    copyArray(temp_arr, sorted_results[5], amount);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (times[j] > times[j + 1]) {
                int temp_t = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp_t;

                int temp_p = steps[j];
                steps[j] = steps[j + 1];
                steps[j + 1] = temp_p;

                string temp_n = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp_n;

                int* temp_arr_ptr = sorted_results[j];
                sorted_results[j] = sorted_results[j + 1];
                sorted_results[j + 1] = temp_arr_ptr;
            }
        }
    }

    cout << "\n=== STATISTICS: " << scenario << " ===\n";
    for (int i = 0; i < 6; i++) {
        if (i == 0) cout << "[1ST PLACE] ";
        else cout << "Position " << (i + 1) << ": ";
        cout << names[i] << " | Steps: " << steps[i] << " | Time: " << times[i] << " ns\n";
        cout << "Sorted Array: ";
        printArray(sorted_results[i], amount);
        cout << "\n";
    }

    delete[] temp_arr;
    for (int i = 0; i < 6; i++) {
        delete[] sorted_results[i];
    }
}

int main() {
    int amount, min_val, max_val;
    
    cout << "Enter the amount of numbers to generate: ";
    cin >> amount;
    
    if (amount <= 0) {
        return 0;
    }

    cout << "Enter the range of numbers (minimum and maximum separated by a space): ";
    cin >> min_val >> max_val;

    if (min_val > max_val) {
        int temp = min_val;
        min_val = max_val;
        max_val = temp;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min_val, max_val);

    int* random_array = new int[amount];
    int* sorted_array = new int[amount];
    int* reverse_array = new int[amount];
    
    for (int i = 0; i < amount; i++) {
        random_array[i] = dist(gen);
    }

    char choice;
    cout << "Do you want to continue and see the comparison? (y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        delete[] random_array;
        delete[] sorted_array;
        delete[] reverse_array;
        return 0;
    }

    evaluateAndDisplay(random_array, amount, "Random Array (Average Case)");

    copyArray(random_array, sorted_array, amount);
    int dummy = 0; 
    quickSortRecursive(sorted_array, 0, amount - 1, dummy); 
    
    evaluateAndDisplay(sorted_array, amount, "Already Sorted Array (Best General Case)");

    for(int i = 0; i < amount; i++) {
        reverse_array[i] = sorted_array[amount - 1 - i];
    }
    
    evaluateAndDisplay(reverse_array, amount, "Reversely Sorted Array (Worst General Case)");

    delete[] random_array;
    delete[] sorted_array;
    delete[] reverse_array;

    system("pause");
    return 0;
}