#include <iostream>
 void swap(int* arr, int a, int b) 
 {
     int temp = arr[a];
     arr[a] = arr[b];
     arr[b] = temp;
 }

 void SelectSort(int* arr, int num)
 {
     for (int i = 0; i < num - 1; i++) {
         int minIndex = i;
         for (int j = i + 1; j < num; j++) {
             minIndex = arr[minIndex
             ] < arr[j] ? minIndex : j;
         }
         swap(arr, i, minIndex);
     }
 }

 int main()
 {
     int arr[] = {1, 2, 1, 4, 5, -1, -1, 5, 5, 1, 6};
     int num = sizeof(arr) / sizeof(arr[0]);
     SelectSort(arr, num);
     for (auto c : arr) {
         std::cout << c << std::endl;
     }
     return 0;
 }