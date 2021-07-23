#include <iostream>
using namespace std;
#define Max 100

int Interpolation_Search(int array[], int start, int end, int data)
{
	int pos;
	if (start <= end && data <= array[end] && data >= array[start] )
	{
		pos = start + ((double)((end - start) / (array[end] - array[start])) * ((data - array[start])));
		if (array[pos] == data)
			return pos;
		else if (array[pos] > data)
			return Interpolation_Search(array, start, pos - 1, data);
		else
			return Interpolation_Search(array, pos + 1, end, data);
	}
	return -1;
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
	int array[Max];
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the element: ";
		cin >> array[i];
	}
	cout << "Your array: ";
	Print(array, n);
	int data;
	cout << "\nFind element: ";
	cin >> data;
	int result = Interpolation_Search(array, 0, n - 1, data);
	if (result == -1)
		cout << "Element not exists!";
	if( result >= 0)
		cout << "Element exists!";

	return 0;
}