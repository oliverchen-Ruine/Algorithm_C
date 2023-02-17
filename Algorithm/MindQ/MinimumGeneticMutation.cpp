/********************************************************************************/
/*	@File Name		: MinimumGeneticMutation.cpp
/*	@Created Date 	: 2022/05/07 09:43
/*	@Description	: 最小基因变化
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
	基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

	假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

		例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。

	另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

	给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

	注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

	示例 1：

	输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
	输出：1

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int minMutation(string start, string end, vector<string>& bank) {
	unordered_set<string> cnt;
	unordered_set<string> visited;//已访问过
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
	//广度优先搜索
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