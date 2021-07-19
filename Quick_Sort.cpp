#include <iostream>
#include <cmath>
using namespace std;

void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int  Partition(int array[], int low, int high) 
{
	int pivot = array[high];
	int i = (low - 1);
	for (int j = low; j <= high-1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			Swap(&array[i], &array[j]);
		}
	}
	Swap(&array[i + 1], &array[high]);
	return (i + 1);
}
void Quick_Sort(int array[], int low, int high)
{
	if (low < high)
	{
		int partition_index = Partition(array, low, high);
		Quick_Sort(array, low, partition_index - 1);
		Quick_Sort(array, partition_index + 1, high);
	}
}

void Print(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}


int main()
{
	int array[] = { 23,78,45,8,32,56 };
	int n = sizeof array / sizeof(array[0]);
	cout << "Original array: " << endl;
	Print(array, n);
	cout << "\nQuick sorted array: " << endl;
	Quick_Sort(array, 0, n - 1);
	Print(array, n);
	
	return 0;
}
