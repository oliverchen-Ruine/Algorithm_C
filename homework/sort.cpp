#include <iostream>
#include <vector>

class my_sort 
{
public:
	void insert_sort(std::vector<int>& list);
	void merge_sort(int list[], int left ,int right);
private:
	void merge(int list[], int p, int q,int r);

	
};




void my_sort::insert_sort(std::vector<int>& list)
{
	for (int i = 1; i < list.size(); ++i)
	{
		int key = list[i];
		int j = i - 1;
		//升序
		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			--j;
		}
		list[j + 1] = key;
	}
}

void my_sort::merge_sort(int list[], int left, int right)
{
	int q = 0;
	if (left < right)
	{
		q = (left + right) / 2;
		merge_sort(list, left, q);
		merge_sort(list, q + 1, right);
		merge(list, left, q, right);
	}

}

void my_sort::merge(int list[], int p, int q, int r)
{
	int n1,n2;
	n1 = q - p + 1;	//左半部分list[]数组大小
	n2 = r - q;		//右半部分list[]数组大小

	int* L = new int[n1 + 2];
	int* R = new int[n2 + 2];

	for (int i = 1; i <= n1; ++i)
	{
		L[i] = list[p + i - 1];
	}

	for (int j = 1; j <= n2; ++j)
	{
		R[j] = list[p + j];
	}
	L[0] = L[n1 + 1] = 65536;
	R[0] = R[n2 + 1] = 65536;

	int i = 1, j = 1;

	for (int k = p; k <= r; ++k)
	{
		if (L[i] <= R[j])
		{
			list[k] = L[i++];
		}
		else
		{
			list[k] = R[j++];
		}
	}
}

void main()
{
	
	auto my_sort_1 = new my_sort();
	std::vector<int> nums = { 4,3,2,7,8,2,3,1 };
	my_sort_1->insert_sort(nums);
	for (auto i : nums)
	{
		std::cout << i << std::endl;
	}
}
