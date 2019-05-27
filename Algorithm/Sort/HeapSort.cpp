#include <iostream>
void swap(int* arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxheap(int* arr, int l, int r) 
{
    int dad = l;
    int son = dad * 2 + 1;
    while (son < r) { 
        if (son + 1 < r && arr[son + 1] > arr[son]) son++;
        if (arr[son] < arr[dad]) break;
        else {
            swap(arr, dad, son);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void HeapSort(int* arr, int num) 
{
    for (int i = num / 2 - 1; i >= 0; i--) {
        maxheap (arr, i, num - 1);
    }
    for (int i = num - 1; i > 0; i--) {
        swap(arr, 0, i);
        maxheap(arr, 0, i);
    }
}

int main() 
{
    int arr[] = {1, 4, -1, -1, 14, 3, 7, 8};
    int num = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, num);
    for (int i = 0; i < num; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}