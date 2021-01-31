int binsearch(int* array, int length, int searchval) {
	int low = 0, high = length - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (searchval < array[mid])
			high = mid - 1;
		else if (searchval > array[mid]) 
			low = mid + 1;
		else
			return 1;
	}

	return 0;
}
