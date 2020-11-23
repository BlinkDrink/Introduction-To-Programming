void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void selectionSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int min = array[i];
		int minIndex = -1;
		for (int j = i; j < size; j++) {
			if (array[j] < min) {
				min = array[j];
				minIndex = j;
			}
		}
		if (minIndex != -1) {
			swap(array[i], array[minIndex]);
		}
	}
}

void shellSort(int array[], int size) {
	int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
	int gapsLength = 8;

	for (int k = 0; k < gapsLength; k++) {
		int gap = gaps[k];
		for (int i = gap; i < size; i++) {
			int temp = array[i];
			int j;
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
	}
}