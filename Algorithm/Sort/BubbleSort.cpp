#include <iostream>

void swap(int* arr, int a, int b) 
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void BubbleSort(int* arr, int num)
{
    for (int i = num - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

int main() 
{
    int arr[] = {1, 4, -1, -1, 14, 3, 7, 8};
    int num = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, num);
    for (int i = 0; i < num; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
    
}