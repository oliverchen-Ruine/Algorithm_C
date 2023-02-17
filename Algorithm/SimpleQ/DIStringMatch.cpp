/********************************************************************************/
/*	@File Name		: DIStringMatch.cpp
/*	@Created Date 	: 2022/05/09 09:13
/*	@Description	: �����ַ���ƥ��
�ɷ�Χ [0,n] ������������ɵ� n + 1 ���������������п��Ա�ʾΪ����Ϊ n ���ַ��� s ������:

	��� perm[i] < perm[i + 1] ����ô s[i] == 'I'
	��� perm[i] > perm[i + 1] ����ô s[i] == 'D'

����һ���ַ��� s ���ع����� perm ��������������ж����Ч����perm���򷵻����� �κ�һ��

ʾ��:
���룺s = "IDID"
�����[0,4,1,3,2]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/di-string-match
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
	//	@Description		: ̰��,ȷ����i��λ��,ʣ��n-i������ͬ����
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
	ans[n] = low;//���ʣ��һ����,��ʱlow==high
	return ans;
}