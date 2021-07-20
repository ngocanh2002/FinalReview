#include <iostream>
using namespace std;

void Swap(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
int Partition(int array[], int low, int high)
{
	int pivot = array[low];
	int i = low;
	int j = high;
	while (i < j)
	{
		while (array[i] <= pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			Swap(&array[i], &array[j]);
		}

	}
	Swap(&array[low], &array[j]);
	return j;

}

void Quick_Sort(int array[], int low, int high)
{
	if (low < high)
	{
		int p_index = Partition(array, low, high);
		Quick_Sort(array, low, p_index - 1);
		Quick_Sort(array, p_index + 1, high);
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
	int array[] = { 8,2,5,7,4 };
	int n = sizeof array / sizeof(array[0]);
	cout << "Original array: " << endl;
	Print(array, n);
	cout << "\nQuick sorted array: " << endl;
	Quick_Sort(array, 0, n - 1);
	Print(array, n);

	return 0;

}