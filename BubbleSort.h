#pragma once 

#include<iostream>
using namespace std;

void Print(int* arr, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//升序
template<typename T>
struct Greater
{
	bool operator()(T& t1, T& t2)
	{
		return t1 > t2;
	}
};

//降序
template<typename T>
struct Less
{
	bool operator()(T& t1, T& t2)
	{
		return t1 < t2;
	}
};

//冒泡排序
template<typename T,typename Com = Greater<T>>
void BubbleSort(T* arr,size_t n)
{	
	bool flag = true;
	//进行n-1次的外循环
	for (size_t i = 0; i < n - 1; i++)
	{
		//每次循环比较n-i-1次
		for (size_t j = 0; j < n - i - 1; j++)
		{
			if (Com()(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
				//更改标记，用于判断是否有序
				flag = false;
			}
		}
		//表示已经有序，直接返回
		if (false == true)
			return;
	}
}

void TestBubbleSort()
{
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	BubbleSort<int,Less<int>>(arr, 10);
	cout << "冒泡排序:" << endl;
	Print(arr, 10);
}
