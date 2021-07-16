#include <iostream>
using namespace std;

void Insertion_Sort(int array[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void Print_Array(int array[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}



int main()
{
	int array[] = { 23,78,45,8,32,56 };
	int n = sizeof (array) / sizeof (array[0]);
	cout << "Original array: " << endl;
	Print_Array(array, n);
	cout << endl;
	cout << "Insertion Sorted array: " << endl;
	Insertion_Sort(array, n);
	Print_Array(array, n);
	return 0;
}