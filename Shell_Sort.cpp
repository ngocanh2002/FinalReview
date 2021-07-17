#include <iostream>
using namespace std;

void Shell_Sort(int array[], int n)
{
	for (int gap = n / 2; gap >0 ; gap = gap / 2)
	{
		for (int i = gap; i < n; i++)
		{
			int temp = array[i];
			int j;
			for (j = i; j >= gap && array[j-gap]>temp; j = j - gap)
			{
				array[j] = array[j-gap];
			}
			array[j] = temp;
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

int main() {
	int array[6];
	for (int i = 0; i < 6; i++)
	{
		cout << "Enter the element: ";
		cin >> array[i];
	}
	cout << "Original array: " << endl;
	Print_Array(array, 6);
	cout << "\nShell sorted array: " << endl;
	Shell_Sort(array, 6);
	Print_Array(array, 6);
	return 0;
}