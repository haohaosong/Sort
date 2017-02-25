#pragma once

/*
* author:haohaosong
* date:2017/2/25
* note:选择排序以及优化 
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

//选择排序的优化版本
//时间复杂度：O(N* N)
//思想：
//每次循环在找出最小值的同时，找出最大值
//效率会提高一倍，但是时间复杂度的数量级并没有变
//注意：
//  同时置换最大值和最小值时，如果最大值出现在begin的位置上，交换两次会打乱
//在置换的时候需要加入一个判断，具体如代码所示
//
//  [begin,end]
void SelectSort(int* a, size_t n)
{
	assert(a);

	size_t begin = 0;
	size_t end = n - 1;
	size_t minIndex = 0;
	size_t maxIndex = 0;

	while (begin < end)
	{
		minIndex = begin;
		maxIndex = end;
		for (size_t i = begin + 1; i <= end; ++i)
		{
			//找出最小的数的下标和最大数的下标
			if (a[i] < a[minIndex])
				minIndex = i;

			if (a[i] > a[maxIndex])
				maxIndex = i;
		}
		//交换最小的数和第一个数
		swap(a[minIndex], a[begin]);

		//防止位置冲突而被打乱
		if (maxIndex == begin)
			maxIndex = minIndex;

		//交换最大的数和最后一个数
		swap(a[maxIndex], a[end]);

		//区间向中间减少
		begin++;
		end--;
	}
}

void TestSelectSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
