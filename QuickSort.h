#pragma once

/*
* author:haohaosong  
* date:2017/2/25
* note:快速排序 
*/

#include<iostream>
using namespace std;

#include<assert.h>

void Print(int* a,size_t n)
{
	assert(a);
	for (size_t i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//快速排序
//时间复杂度:O(N* lgN)
//思想:
//第一趟排序，找出最后一个元素的对应位置，并将其放入该位置；
//以该元素分成两块空间，分别对其进行排序
//直到一块空间的元素不大于1时，结束

//第一趟排序
//[left,right]
size_t PartSort(int* a, int left, int right)
{
	int key = a[right];
	
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;

		a[right] = a[left];

		while (left < right && a[right] >= key)
			right--;

		a[left] = a[right];
	}

	a[left] = key;
	return left;
}

//[left,right]
void QuickSort(int* a, int left, int right)
{
	if (left < right)
	{
		int mid = PartSort(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
}

void TestQuickSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	Print(a, sizeof(a) / sizeof(a[0]));
}
