#include <iostream>
using namespace std;
#define Max 100

int Binary_Search(int array[], int left, int right, int data)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (array[mid] == data)
			return mid;
		else if (array[mid] < data)
		{
			return Binary_Search(array, mid + 1, right, data);
		}
		else
			return Binary_Search(array, left, mid - 1, data);

	}
	else
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
	int result = Binary_Search(array, 0,n-1,data);
	if (result == -1)
		cout << "\nElement not exists!";
	else
		cout << "Element exists!";
	return 0;
}