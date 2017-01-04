#pragme once 

template<typename T>
struct Greater
{
	bool operator()(T& t1, T&t2)
	{
		return t1 > t2;
	}
};

template<typename T>
struct Less
{
	bool operator()(T& t1, T&t2)
	{
		return t1 < t2;
	}
};

template<typename T,typename Compare = Greater<int>>
void InsertSort(T* arr, size_t n)
{
	//循环排序到最后一个元素
	for (size_t i = 1; i < n; ++i)
	{
		//用temp保留，被覆盖后无法找到
		T temp = arr[i];
		
		for (int j = i; j >= 0; --j)
		{
			//如果打破了有序，则进行覆盖
			//否则，跳出循环
			if (Compare()(arr[j - 1],temp))
			{
				if (j - 1 >= 0)
					arr[j] = arr[j - 1];
				else
					arr[j] = temp;
			}
			else
			{
				arr[j] = temp;
				break;
			}
		}
	}
}

void TestInsertSort()
{
	int arr[5] = { 2, 5, 8, 10, 7 };
	InsertSort(arr, 5);
	Print(arr, 5);
}
