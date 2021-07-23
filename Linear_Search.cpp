#include <iostream>
using namespace std;
#define MAX 100
int Search(int array[], int n, int data)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (array[i] == data)
			return i;
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
	int array[MAX];
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the element: ";
		cin >> array[i];
	}
	cout << "Your array: ";
	Print(array, n);
	int data;
	cout << "\nFind data: ";
	cin >> data;
	int result=Search(array, n, data);
	if (result == -1)
	{
		cout << "\nElement not found!";
	}
	else if (result >= 0)
	{
		cout << "\nElement found!" << endl;
	}
	return 0;
}