#pragma once

/*
* author:haohaosong 
* date:2017/2/25
* note:插入排序 
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

//插入排序
//时间复杂度:O(N* N)
//思想:
//从数组的首元素开始，第一次排前两个数，第二次排前三个数...以此论推
//保证前面拍的元素有序的情况下，再拍后一个元素时，可以依次比较找到适合的插入位置
//最优情况下，插入排序的时间复杂度为O(N)
//最坏情况下，也就是逆序的排序时间复杂度为O(N* N)
//
// [0,i]
void InsertSort(int* a, size_t n)
{
	assert(a);

	//第一次排前两个数，第二次排前三个...
	for (size_t i = 1; i < n; ++i)
	{
		int end = i - 1;//end表示最后一个数的前一个数
		int tmp = a[i];
		while (end >= 0)
		{
			//是否是合适的位置，不是的话覆盖
			//是的话break跳出
			if (tmp >= a[end])
				break;

			a[end + 1] = a[end];
			end--;
		}

		//可能是break跳出，在中部找到合适的位置
		//也可能是end == -1，while循环结束，需要放在第一个元素
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[10] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
