#include<iostream>
using namespace std;

void Swap(int* p1, int  *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void Selection_Sort(int array[],int n) {
	int min_idex;
	for (int i = 0; i < n - 1; i++)
	{
		min_idex = i;
		for (int j = i+1; j < n; j++) {
			if (array[j] < array[min_idex]) {
				min_idex = j;
			}
		}
		if (min_idex != i) {
			Swap(&array[i], &array[min_idex]);
		}
	}
}

void Print_Array(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	
	int array[6];
	for (int i = 0; i < 6; i++)
	{
		cout << "Enter the element: ";
		cin >> array[i];
		
	}
	cout << "Original array: " << endl;
	Print_Array(array, 6);
	cout << "\nSelection sorted array: " << endl;
	Selection_Sort(array, 6);
	Print_Array(array, 6);
	
	return 0;

}