//Lower Bound
//Input:
//	1/ the sorted array
//	2/ the size of the array
//	3/ the element that is being searched
//Output:
//	The index of where the left most iteration of the key is in the array
//	If the element is not found the index of the first biggest element then the key

int LowerBound(int * arr, int size, int key)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		if (arr[mid] >= key)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}

//Upper Bound
//Input:
//	1/ the sorted array
//	2/ the size of the array
//	3/ the element that is being searched
//Output:
//	The index of where the right most iteration of the key is in the array
//	If the element is not found the index of the first smallest element then the key

int UpperBound(int * arr, int size, int key)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;

		if (arr[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left - 1;
}