#include <iostream>

//经典快排
int partition(int* a, int left, int right)
{
	int pivot = a[left];
	while (left < right) {
		while (left < right && a[right] >= pivot) right--;
		if (left < right) a[left++] = a[right];
		while (left < right && a[left] <= pivot) left++;
		if (left <right) a[right--] = a[left];
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

//三路划分的快排
void swap(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void partition(int* a, int left, int right, int& i, int& j) 
{
	i = left;
	j = right;
	int key = a[right];
	while (left < j) {
		if (a[left] < key) {
			swap(a[i++], a[left++]);
		}
		else if (a[left] > key) {
			swap(a[--j], a[left]);
		}
		else {
			left++;
		}
	}
	swap(a[j], a[right]);

}

void QuickSort_1(int* a, int left, int right) 
{
	if (left < right) {
		int i, j;
		partition(a, left, right, i, j);
		QuickSort_1(a, left, i - 1);
		QuickSort_1(a, j + 1, right);

	}
}

//随机快排
void QuickSort_2(int* a, int left ,int right)
{
	if (left < right) {
		int i, j;
		swap(a[left + rand() % (right - 1 - left)], a[right]);
		partition(a, left, right, i, j);
		QuickSort_2(a, left, i - 1);
		QuickSort_2(a, j + 1, right);
	}
}

int main() {
	int a[] = { 1, 12, 15, 16, -1, 54, 54, 54, 54, 54, 54, 54, 54, 54, 100 };
	QuickSort_1(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
		std::cout << a[i] << std::endl;
	}
	return 0;
}