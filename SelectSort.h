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

template<typename T,typename Com = Greater<int>>
void SelectSort(T* arr,size_t n)
{
	//对max进行初始化
	int max = 0;
	//进行选择排序
	for (size_t i = 0; i < n-1; ++i)
	{
		max = i;
		for (size_t j = i; j < n; ++j)
		{
			if (Com()(arr[max], arr[j]))
				max = j;
		}
		if (max != i)
			swap(arr[max], arr[i]);
	}
}

void TestSelectSort()
{
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	SelectSort<int,Less<int>>(arr, 10);
	cout << "选择排序:" << endl;
	Print(arr, 10);
}
