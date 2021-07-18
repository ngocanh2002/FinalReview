#include <iostream>
using namespace std;

//Merge two subarray: array[l...m] and array[m+1...r]

void Merge(int array[], int const l, int const m, int const r) {
	
	auto const n1 = m - l + 1;
	auto const n2 = r - m;

	//Create temp arrays
	auto* Left = new int[n1];
	auto* Right = new int[n2];

	// Copy data to temp arrays
	for (auto i = 0; i < n1; i++)
	{
		Left[i] = array[l + i];
	}
	for (auto j = 0; j < n2; j++)
	{
		Right[j] = array[m + 1 + j];
	}

	//Initial index of first sub-array
	auto index1 = 0;
	//Initial index of second sub-array
	auto index2 = 0;
	//Initial index of merged array
	int k = l;

	//Merge the temp arrays back into array[left..right]
	while (index1 < n1 && index2 <n2)
	{
		if (Left[index1] <= Right[index2]) 
		{
			array[k] = Left[index1];
			index1++;
		}
		else {
			array[k] = Right[index2];
			index2++;
		}
		k++;
	}

	//copy the remaining elements of Left[],if there are any
	while (index1 < n1)
	{
		array[k] = Left[index1];
		index1++;
		k++;
	}

	//Copy the remaining elements of Right[],if there are any
	while (index2 < n2)
	{
		array[k] = Right[index2];
		index2++;
		k++;
	}
}

void Merge_Sort(int array[], int const left_index, int const right_index)
{
	if (left_index >= right_index)
	{
		return; //Return recursively
	}
	auto mid_index = left_index + (right_index - left_index) / 2;
	Merge_Sort(array, left_index, mid_index);
	Merge_Sort(array, mid_index + 1, right_index);
	Merge(array, left_index, mid_index, right_index);

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
	int array[] = { 23,78,45,8,32,56 };
	int n = sizeof array / sizeof array[0];
	cout << "Original array: " << endl;
	Print_Array(array, n);
	cout << "\nMerge sorted array: " << endl;
	Merge_Sort(array, 0, n - 1);
	Print_Array(array, n);
	return 0;
}