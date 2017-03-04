#pragma once

/*
* author:haohaosong
* date:2017/3/4
* note:归并排序
*/

//归并排序
//时间复杂度:O(N* logN)
//思想:
//运用归并的思想，将两个有序的链表和为一起
//需要一个数组来保存合并后的值
//也有二分的思想

//进行排序
void _Marge(int* a, int* tmp, int left, int mid, int right)
{
	int bgn1 = left;
	int end1 = mid;
	int bgn2 = mid + 1;
	int end2 = right;

	int index = left;

	//进行归并排序,放入到tmp中
	while (bgn1 <= end1 && bgn2 <= end2)
	{
		if (a[bgn1] < a[bgn2])
			tmp[index++] = a[bgn1++];
		else
			tmp[index++] = a[bgn2++];
	} 

	//归并时，必有一个数组是没有放完的，需要判别是bgn1还是bgn2
	//然后将其放入tmp
	while (bgn1 <= end1)
		tmp[index++] = a[bgn1++];
	while (bgn2 <= end2)
		tmp[index++] = a[bgn2++];

	//将tmp中的元素放回数组a中
	for (size_t i = left; i <= right; ++i)
		a[i] = tmp[i];
}

//从排序的控制
void _MargeSort(int* a,int* tmp ,int left, int right)
{
	//如果元素不大于一个，不用进行排序
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);

	//元素不止一个，需要递归排序
	_MargeSort(a, tmp, left, mid);
	_MargeSort(a, tmp, mid+1, right);

	//进行排序
	_Marge(a, tmp, left, mid, right);
}

//主排序，申请和释放tmp
void MargeSort(int* a, size_t n)
{
	assert(a);

	int* tmp = new int[n];

	//调用归并
	_MargeSort(a, tmp, 0, n-1);

	delete[] tmp;
}

void TestMargeSort()
{
	int a[10] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	MargeSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}