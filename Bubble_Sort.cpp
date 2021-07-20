#include <iostream>
using namespace std;

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void Bubble_Sort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
	}
}

void Print_array(int array[], int n)
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
	Print_array(array, 6);
	cout << "\nBubble sorted array: " << endl;
	Bubble_Sort(array, 6);
	Print_array(array, 6);
	return 0;
}