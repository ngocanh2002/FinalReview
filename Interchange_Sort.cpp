#include <iostream>
using namespace std;

void Interchange_Sort(int array[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j = i+1; j < n; j++)
		{
			if (array[i] > array[j])
				swap(array[i], array[j]);
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
	cout << "\nInterchange sorted array: " << endl;
	Interchange_Sort(array, n);
	Print(array, n);
	return 0;
}