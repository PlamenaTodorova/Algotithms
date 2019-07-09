//Binary search
//Input:
//	1/ the sorted array
//	2/ the size of the array
//	3/ the element that is being searched
//Output:
//	The index of where the key is supposed to be in the array
//	If the element is not found returns -1

int BinarySearch(int * arr, int size, int key)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		if (arr[mid] == key)
			return mid;
		
		if (arr[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}