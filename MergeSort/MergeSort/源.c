#include<stdio.h>

void MergeSort(int *array, int *temp, int start, int mid, int end)
{
	int left_start = start;
	int left_end = mid;

	int right_start = mid + 1;
	int right_end = end;

	int index = start;

	while (left_start <= left_end && right_start <= right_end)
	{
		if (array[left_start] > array[right_start])
			temp[index++] = array[right_start++];
		else
			temp[index++] = array[left_start++];
	}

	while (left_start <= left_end)
		temp[index++] = array[left_start++];

	while (right_start <= right_end)
		temp[index++] = array[right_start++];

	for (index = start;index <= end;++index)
		array[index] = temp[index];
}
void SortMessage(int *array, int *temp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		SortMessage(array, temp, start, mid);
		SortMessage(array, temp, mid + 1, end);
		MergeSort(array, temp, start, mid, end);
	}
}

int main(void)
{
	int a[] = { 10,9,8,7,6,5,4,3,2,1 };
	int n = sizeof(a) / sizeof(a[0]);
	int i, temp[10];

	printf("原序列为:");
	for (i = 0;i < n;++i)
		printf("%d ", a[i]);
	printf("\n");

	SortMessage(a, temp, 0, n - 1);

	printf("\n排后序列:");
	for (i = 0;i < n;++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
