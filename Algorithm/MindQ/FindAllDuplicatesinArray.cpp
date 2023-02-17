/********************************************************************************/
/*	@File Name		:  FindAllDuplicatesinArray.cpp
/*	@Created Date 	: 2022/05/08 09:26
/*	@Description	: 数组中重复的数据
给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。
请你找出所有出现 两次 的整数，并以数组形式返回。

你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-duplicates-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
//	@Description		: 原地hash
//	@Params 			: nums 待检查数组
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
		if (nums[x - 1] > 0) //正数只出现一次
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