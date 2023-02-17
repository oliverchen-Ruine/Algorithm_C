/********************************************************************************/
/*	@File Name		:  FindAllDuplicatesinArray.cpp
/*	@Created Date 	: 2022/05/08 09:26
/*	@Description	: �������ظ�������
����һ������Ϊ n ���������� nums ������ nums �������������ڷ�Χ [1, n] �ڣ���ÿ���������� һ�� �� ���� ��
�����ҳ����г��� ���� ������������������ʽ���ء�

�������Ʋ�ʵ��һ��ʱ�临�Ӷ�Ϊ O(n) �ҽ�ʹ�ó�������ռ���㷨���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
/*
/*	@Version 		: V1.0
/*	@Copyright 		: Copyright(C) 2021-2022
/*	@Last Modified	: 2022/05/08 09:26
/*
/*	@Author 		: oliver_chen
/*	@Data   		: 2022/05/08 09:26
/*	@Remark			: @...@ 
/*
/*	@Reviser 		:
/*	@Data 			: 2022/05/08 09:26
/*	@Remark			: @...@
/********************************************************************************/
#include <vector>
#include <unordered_set>
#include <iostream>

using std::vector;
using std::unordered_set;
using std::abs;
//******************************************************************************//
//	@Author 			: oliver_chen
//	@Created Date 		: 2022/05/08 09:31
//
//	@Function Name		: findDuplicates
//	@Description		: ԭ��hash
//	@Params 			: nums ���������
//	@Return	 			: 
//	@Remark				: @...@
//******************************************************************************//
vector<int> findDuplicates(vector<int>& nums) {
	/*unordered_set<int> table;
	vector<int> res;
	for (auto& n : nums)
	{
		if (!table.count(n))
		{
			table.emplace(n);
		}
		else
		{
			res.push_back(n);
		}
	}
	return res;*/
	vector<int> res;
	int n = nums.size();
	for (int i = 0; i < n; ++i) 
	{
		int x = abs(nums[i]);
		if (nums[x - 1] > 0) //����ֻ����һ��
		{
			nums[x - 1] = -nums[x - 1];
		}
		else {
			res.push_back(x);
		}
	}
	return res;
}

void main() {
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	vector<int> res = findDuplicates(nums);
	for (int& i : res) 
	{
		std::cout << i << std::endl;
	}
}