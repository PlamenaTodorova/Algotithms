//Radix Sort
//Input:
//	1/ Array of possitibe integers
//	2/ The size of the array
//	3/ The maximu size of the words
//Output:
//	It is a void method
//	The array that is given in the input is being sorted

void RadixSort(unsigned int * arr, unsigned int size, unsigned int wordLength)
{
	int step = 1;
	unsigned int* temp = new unsigned int[size];

	for (int j = 0; j < wordLength; j++)
	{
		int counter[10] = { 0 };
		
		for (int i = 0; i < size; i++)
		{
			counter[arr[i] / step % 10]++;
		}

		for (int i = 1; i < 10; i++)
		{
			counter[i] += counter[i - 1];
		}

		for (int i = size - 1; i >= 0; i--)
		{
			int possition = counter[arr[i] / step % 10];

			temp[possition - 1] = arr[i];

			counter[arr[i] / step % 10]--;
		}
		
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp[i];
		}

		step *= 10;
	}

	delete[] temp;
}