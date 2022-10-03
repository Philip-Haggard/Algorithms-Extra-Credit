#include<iostream>
#include<chrono>
#include <algorithm>
using namespace std::chrono;
using namespace std;

void swapping(int &a, int &b) {         //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         //placing in correct position
         swap(array[i], array[imin]);
   }
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

   selectionSort(arr, atoi(argv[1]));

   auto stop = high_resolution_clock::now();

   auto duration = duration_cast<microseconds>(stop - start);

   cout << "Array after Sorting: ";
   display(arr, atoi(argv[1]));

   cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

   return 0;
}