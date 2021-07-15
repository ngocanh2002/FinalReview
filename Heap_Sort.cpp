#include <iostream>
#include <cmath>
using namespace std;

void Heapify(int array[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	/* example:
			 index:    0	1	2	3	4
		input data:	   4	10	3	5	1
	 Build Heap:         
							4
						   / \				
						  10  3				
						 /  \
						5	 1		
	*/ 
	if (left < n && array[left]>array[largest])
		largest = left;
	if (right < n && array[right]>array[largest])
		largest = right;
	if (largest != i)
	{
		swap(array[i], array[largest]);

		Heapify(array, n, largest);
	}
	/* Max Heap:
							10
						   / \				
						  5   3				
						 / \
						4   1	


	*/

}

// main function to do Heap Sort
void Heap_Sort(int array[], int n)
{
	// Build heap: Rearrange array
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(array, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(array[0], array[i]);
		// Call max heapify on the reduced heap
		Heapify(array, i,0);
	}
}
// Print array
void Print_Array(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
		
	}
}

int main()
{
	int array[] = { 4, 10, 3, 5, 1 };
	int n = sizeof(array) / sizeof(array[0]);
	cout << "Heap array: " << endl;
	Print_Array(array, n);
	cout << endl;
	Heap_Sort(array, n);
	cout << "Heap Sorted array is: " << endl;
	Print_Array(array, n);

	return 0;
	
	 
	

}