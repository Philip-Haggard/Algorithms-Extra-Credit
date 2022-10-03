#include<iostream>
#include<chrono>
#include <algorithm>
using namespace std::chrono;
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int main(int argc, char** argv) {
   /*
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   */

   int arr[atoi(argv[1])]; // create an array with given number of elements

   for(int i = 0; i < atoi(argv[1]); i++) // create random array
      arr[i] = rand()%10000;

   cout << "Array before Sorting: ";
   display(arr, atoi(argv[1]));

   auto start = high_resolution_clock::now();

   quickSort(arr, 0, atoi(argv[1]) - 1);

   auto stop = high_resolution_clock::now();

   auto duration = duration_cast<microseconds>(stop - start);

   cout << "Array after Sorting: ";
   display(arr, atoi(argv[1]));

   cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

   return 0;
}