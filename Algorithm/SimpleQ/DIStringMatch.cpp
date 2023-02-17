/********************************************************************************/
/*	@File Name		: DIStringMatch.cpp
/*	@Created Date 	: 2022/05/09 09:13
/*	@Description	: 增减字符串匹配
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

	如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I'
	如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D'

给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个

示例:
输入：s = "IDID"
输出：[0,4,1,3,2]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/di-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/*
/*	@Version 		: V1.0
/*	@Copyright 		: Copyright(C) 2021-2022
/*	@Last Modified	: 2022/05/09 09:13
/*
/*	@Author 		: oliver_chen
/*	@Data   		: 2022/05/09 09:13
/*	@Remark			: @...@ 
/*
/*	@Reviser 		:
/*	@Data 			: 2022/05/09 09:13
/*	@Remark			: @...@
/********************************************************************************/
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<int> diStringMatch(string s) {
	//******************************************************************************//
	//	@Author 			: oliver_chen
	//	@Created Date 		: 2022/05/09 09:24
	//
	//	@Function Name		: diStringMatch
	//	@Description		: 贪心,确定第i个位置,剩下n-i都是相同问题
	//	@Params 			: string s
	//	@Return	 			: 
	//	@Remark				: @...@
	//******************************************************************************//
	int n = s.size(), low = 0, high = n;
	vector<int> ans(n+1);
	for (int i = 0; i < n; ++i) 
	{
		ans[i] = s[i] == 'I' ? low++ : high--;
	}
	ans[n] = low;//最后剩下一个数,此时low==high
	return ans;
}