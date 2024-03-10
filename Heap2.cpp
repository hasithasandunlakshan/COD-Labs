#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int max = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < n && arr[root] < arr[left]) {
        max = left;
    }
    if (right < n && arr[max] < arr[right]) {
        max = right;
    }
    if (max != root) {
        int temp = arr[root];
        arr[root] = arr[max];
        arr[max] = temp;
        heapify(arr, n, max);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    int firstkey = (n / 2) - 1;
    for (int i = firstkey; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int j = n - 1; j > 0; j--) {
        int temp = arr[j];
        arr[j] = arr[0];
        arr[0] = temp;
        heapify(arr, j, 0);
    }
}

// print contents of array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    for(int n=1000000;n<1000050;n++) {



        // Generate random numbers and fill the array
        int *arr = new int[n];
        srand(time(0)); // Seed for random number generation
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 1000; // Generating random numbers between 0 and 999
        }

        // Measure time taken by heap sort
        auto start = high_resolution_clock::now();
        heapSort(arr, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<chrono::milliseconds>(stop - start);
        cout << duration.count() << endl;

        // Display the sorted array



        delete[] arr;
    }
    return 0;
}
