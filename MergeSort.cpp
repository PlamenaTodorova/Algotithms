#include<iostream>

//MergeSort - stable sorting algorithm
//Input:
//	1/ An array of integers
//	2/ Starting position a.k.a 0
//	3/ End position a.k.a size - 1 (the last valid index)

void Merge(int * arr, int start, int mid, int end)
{
	int* left = new int[mid + 1 - start];
	int* right = new int[end - mid];

	for (int i = start; i <= mid; i++)
	{
		left[i - start] = arr[i];
	}

	for (int i = mid + 1; i <= end; i++)
	{
		right[i - mid - 1] = arr[i];
	}

	int leftIndex = 0;
	int rightIndex = 0;
	int totalIndex = start;

	while (leftIndex <= mid - start && rightIndex < end - mid)
	{
		if (left[leftIndex] < right[rightIndex])
			arr[totalIndex++] = left[leftIndex++];
		else
			arr[totalIndex++] = right[rightIndex++];
	}

	while (leftIndex <= mid - start)
	{
		arr[totalIndex++] = left[leftIndex++];
	}

	while (rightIndex < end - mid)
	{
		arr[totalIndex++] = right[rightIndex++];
	}
}

void MergeSort(int * arr, int start, int end)
{
	if (start < end)
	{
		int mid = (end + start) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}