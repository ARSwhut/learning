#include <iostream>
void swap(int* arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void InsertSort(int* arr, int num)
{
    for (int i = 1; i < num; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr, j, j + 1);
        }
    }
}

int main()
{
    int arr[] = {1, -1, 0, 1, 3, 14, 15, 7, 10, 5, 6, 7};
    int num = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, num);
    for (auto c : arr) {
        std::cout << c << std::endl;
    }
    return 0;
}