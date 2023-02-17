/********************************************************************************/
/*	@File Name		: MinimumGeneticMutation.cpp
/*	@Created Date 	: 2022/05/07 09:43
/*	@Description	: ��С����仯
/*
/*	@Version 		: V1.0
/*	@Copyright 		: Copyright(C) 2021-2022
/*	@Last Modified	: 2022/05/07 09:43
/*
/*	@Author 		: oliver_chen
/*	@Data   		: 2022/05/07 09:43
/*	@Remark			: @...@ 
/*
/*	@Reviser 		:
/*	@Data 			: 2022/05/07 09:43
/*	@Remark			: @...@
/********************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using std::string;
using std::vector;
using std::unordered_set;
using std::queue;

/*
	�������п��Ա�ʾΪһ���� 8 ���ַ���ɵ��ַ���������ÿ���ַ����� 'A'��'C'��'G' �� 'T' ֮һ��

	����������Ҫ����ӻ������� start ��Ϊ end �������Ļ���仯��һ�λ���仯����ζ��������������е�һ���ַ������˱仯��

		���磬"AACCGGTT" --> "AACCGGTA" ����һ�λ���仯��

	����һ������� bank ��¼��������Ч�Ļ���仯��ֻ�л�����еĻ��������Ч�Ļ������С�

	���������������� start �� end ���Լ�һ������� bank �������ҳ��������ܹ�ʹ start �仯Ϊ end ��������ٱ仯����������޷���ɴ˻���仯������ -1 ��

	ע�⣺��ʼ�������� start Ĭ������Ч�ģ�����������һ��������ڻ�����С�

	ʾ�� 1��

	���룺start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
	�����1

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/minimum-genetic-mutation
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

int minMutation(string start, string end, vector<string>& bank) {
	unordered_set<string> cnt;
	unordered_set<string> visited;//�ѷ��ʹ�
	char key[4] = { 'A','C','G','T' };

	for (auto& w : bank) 
	{
		cnt.emplace(w);
	}

	if (start == end)
	{
		return 0;
	}

	if (!cnt.count(end))
	{
		return -1;
	}
	//�����������
	queue<string> q;
	q.emplace(start);
	visited.emplace(start);
	int step = 1;
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; ++i) {
			string s = q.front();
			q.pop();
			for (int j = 0; j < 8; ++j) {
				for (int k = 0; k < 4; ++k) {
					if (key[k] != s[j]) {
						string next = s;
						next[j] = key[k];
						if (!visited.count(next) && cnt.count(next)) 
						{
							if (next == end)
							{
								return step;
							}
							q.emplace(next);
							visited.emplace(next);
						}
					}
				}
			}
		}
		step++;
	}
	return -1;
}