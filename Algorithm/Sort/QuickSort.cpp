#include <iostream>
int partition(int* a, int left, int right)
{
	int pivot = a[left];
	while (left < right) {
		while (left < right && a[right] >= pivot) right--;
		a[left] = a[right];
		while (left < right && a[left] <= pivot) left++;
		a[right] = a[left];
	}
	a[left] = pivot;
	return left;
}

void QuickSort(int* a, int left, int right)
{
	if (left < right) {
		int pos = partition(a, left, right);
		QuickSort(a, left, pos - 1);
		QuickSort(a, pos + 1, right);
	}
}

int main() {
	int a[] = { 1, 12, 15,16, -1, 54, 100 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
		std::cout << a[i] << std::endl;
	}
	return 0;
}