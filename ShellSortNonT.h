#pragma once

/*
* author:haohaosong 
* date:2017/2/25
* note:希尔排序 
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

//希尔排序
//时间复杂度：O(N* N)
//思想:
//将数组分成gap组，然后分组用插入排序
//当gap为1时，就是进行直接插入排序
//希尔排序在逆序或者接近逆序时，会提高插入排序的效率
//将大的元素移到前面的位置花费的次数大大减少
void ShellSort(int* a, size_t n)
{
	assert(a);
	size_t gap = n;

	//while循环控制着多次插入排序
	while (gap > 1)
	{
		//该公式可以保证最后一趟排序的gap为1
		gap = gap / 3 + 1;

		//从第一组的第二个元素开始，多组循环进行直接插入排序
		for (size_t i = gap; i < n; ++i)
		{
			int end = i - gap;
			int tmp = a[i];

			//进行插入排序，每一组的差值为gap
			//从后向前，每组第一个元素的前一个值一定小于0
			while (end >= 0)
			{
				//如果tmp不比前面大，则找到tmp的插入位置，break跳出
				//否则，end元素进行单组的后移
				if (a[end] <= tmp)
					break;

				a[end + gap] = a[end];
				end -= gap;
			}

			//进行插入
			a[end + gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}


//插入排序和希尔排序的比较
//希尔排序在序列接近逆序会通过减少换移动的次数从而提高插入排序的效率
//但是当元素少时，由于数据少，插入排序并不会比希尔排序多换几次位置
//当元素很多时，很多情况用的是快排和堆排
//所以希尔排序是一个不常用排序
