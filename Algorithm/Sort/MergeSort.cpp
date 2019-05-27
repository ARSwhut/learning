#include <iostream>

void Merge(int* a, int* tmp, int l, int mid, int r)
{
    int p1 = l;
    int p2 = mid + 1;
    int t = l;
    while (p1 <= mid && p2 <= r) {
        tmp[t++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
    }
    while (p1 <= mid) {
        tmp[t++] = a[p1++];
    }
    while (p2 <= r) {
        tmp[t++] = a[p2++];
    }
    for (int i = l; i <= r; i++) {
        a[i] = tmp[i];
    }
    
}

void MergeSort(int* a, int* tmp, int l, int r) 
{
    if (l < r) {
        int mid = l + (r - l) / 2;
        MergeSort(a, tmp, l, mid);
        MergeSort(a, tmp, mid + 1, r);
        Merge(a, tmp, l, mid, r);
    }

}

int main() {
	int a[] = { 1, 2, -100, -50, 100, 50, 51, 50, 54, 15, 16 };
    int num = sizeof(a) / sizeof(a[0]);
    int* tmp = new int[num];
	MergeSort(a, tmp, 0, num - 1);
	for (int i = 0; i < num; ++i) {
		std::cout << a[i] << std::endl;
	}
     delete[] tmp;
	return 0;
}