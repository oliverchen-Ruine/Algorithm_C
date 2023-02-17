#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "k_plex.h"


std::vector<std::vector<int>> K_plex_matrix::read_csv(std::string file_name)
{
	std::vector<std::vector<int>> result;
	std::ifstream myFile(file_name);
	if (!myFile.is_open()) throw std::runtime_error("Could not open file");
	std::string line;
	int val;
	std::vector<int> r;
	r.clear();

	while (std::getline(myFile, line))
	{
		// Create a stringstream of the current line
		std::stringstream ss(line);
		// Extract each integer
		while (ss >> val) {
			
			r.push_back(val);
			// If the next token is a comma, ignore it and move on
			if (ss.peek() == ',') ss.ignore();
		}
		result.push_back(r);
		r.clear();
	}
	myFile.close();

	return result;
}

void K_plex_matrix::writ_csv(std::string file_name, Matrix& m)
{
	ofstream outfile;
	outfile.open(file_name);

	// 写入数据
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			outfile << m.getElement(i, j, false);
			if (j < m.getCols() - 1) {
				outfile << ",";
			}
		}
		outfile << endl;
	}

	// 关闭文件
	outfile.close();

	std::cout << "success" << std::endl;
}

int K_plex_matrix::getSubDegree(std::vector<int>& s, int node)
{
	int degree = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (adj->getElement(node, s[i]) || adj->getElement(s[i], node)) {
			degree++;
		}
	}
	return degree;
}

bool K_plex_matrix::isKPlex(std::vector<int>& s, int k)
{
	for (auto i : s)
	{
		if (getSubDegree(s, i) < s.size() - k)
		{
			return false;
		}
	}
	return true;
}

std::unordered_set<int> K_plex_matrix::getNeighbors(std::unordered_set<int>& vertices)
{
	std::unordered_set<int> neighbors;
	for (int v : vertices) {
		for (int i = 0; i < n; ++i) {
			if (adj->getElement(v, i) != 0 && vertices.count(adj->getElement(v, i)) == 0) { // 如果邻居结点不在集合中，则添加到邻居集合中
				neighbors.insert(adj->getElement(v, i));
			}
		}
	}
	return neighbors;

}

bool K_plex_matrix::isInLine(std::vector<int>& s, int node)
{
	for (int i : s)
	{
		if (adj->getElement(i, node) == 1)
		{
			return true;
		}
	}
	return false;
}

// 广度优先搜索
std::vector<std::vector<int>> K_plex_matrix::bfs_kplex(std::vector<int> nodes, int k) {
	/**
	 * 
	 * 	 nodes : 节点从小到大排序
	 * 
	 */

	std::queue<std::vector<int>> q; // 存储待扩展的集合
	q.push(nodes);
	
	std::vector<std::vector<int>> ans; // 存储最终结果
	std::vector<int> S;
	std::vector<int> newS;
	while (!q.empty()) {
		S.clear();
		S = q.front();
		q.pop();
		if (isKPlex(S,k)) {
			ans.push_back(S);
		}
		int last = S.back();
		for (int i = last + 1; i < n; i++) {
			newS.clear();
			newS = S;
			newS.push_back(i);
			q.push(newS);
		}
	}
	int max_size = 0;
	if (ans.size()!=0)
	{
		max_size = ans.back().size();
	}
	
	std::vector<std::vector<int>> res;
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		if (ans[i].size() != max_size)
		{
			break;
		}
		res.insert(res.begin(),ans[i]);
	}

	return res;
}

std::vector<float> K_plex_matrix::k_plex_matrix_B(int node_num, string file_name)
{
	int k = 1;
	std::shared_ptr<Matrix> m = std::make_shared<Matrix>(node_num, node_num);
	//从csv构造领接矩阵
	auto adj_info = read_csv(file_name);
	for (int i = 1; i < adj_info.size(); ++i)
	{
		m->setElement(adj_info[i][0], adj_info[i][1], 1);
		m->setElement(adj_info[i][1], adj_info[i][0], 1);
	}
	this->adj = m;
	this->n = node_num;

	//保存所有k_plex
	std::vector<std::vector<int>> k_plex_v;

	//顶点set集
	std::unordered_set<int> nodes;

	//归一化计算结果集
	std::vector<std::vector<float>> k_plex_node;

	for (int i = 0; i < node_num; ++i)
	{
		nodes.insert(i);
		k_plex_node.push_back({ float(i) });
	}

	while (k < node_num - 1)
	{
		auto s = bfs_kplex({ 0 }, k);

		for (auto kp_i : s)
		{
			for (auto i : kp_i)
			{
				if (nodes.count(i) == 1)
				{
					//从顶点集中去掉
					nodes.erase(i);
					//计算权重，归一化
					int w = node_num - 1 - k;
					float norm_w = float(w) / float(node_num - 2);
					k_plex_node[i].push_back(norm_w);
				}
			}
		}

		for (auto j : s)
		{
			k_plex_v.push_back(j);
		}
		++k;
	}

	//输出k_plex容器内容
	/*for (auto i : k_plex_v)
	{
		for (auto j : i)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}*/

	std::vector<float> B;
	for (auto u : k_plex_node)
	{
		B.push_back(u[1]);
	}

	//输出归一化结果
	/*for (auto u : k_plex_node)
	{
		std::cout << "{";
		for (auto k : u)
		{
			std::cout << k << " ";
		}
		std::cout << "}" << std::endl;
	}*/

	return B;
}

void K_plex_matrix::k_plex_matrix_mul(std::vector<float> K_plex_v, string file_name)
{
	auto m_B = Matrix(1, K_plex_v.size());
	auto m_Bt = Matrix(K_plex_v.size(), 1);

	for (int i = 0; i < K_plex_v.size(); ++i)
	{
		m_B.setElement(0, i, K_plex_v[i]);
		m_Bt.setElement(i, 0, K_plex_v[i]);
	}

	auto C = m_Bt * m_B;
	//C.print();
	writ_csv(file_name, C);
}

void K_plex_matrix::k_plex_matrix_add(std::vector<float> K_plex_v, string file_name)
{
	auto m_B = Matrix(1, K_plex_v.size());
	auto m_Bt = Matrix(K_plex_v.size(), 1);

	for (int i = 0; i < K_plex_v.size(); ++i)
	{
		m_B.setElement(0, i, K_plex_v[i]);
		m_Bt.setElement(i, 0, K_plex_v[i]);
	}

	auto c = Matrix(K_plex_v.size(), K_plex_v.size());
	for (int i = 0; i < K_plex_v.size(); ++i) 
	{
		for (int j = 0; j < K_plex_v.size(); ++j) 
		{
			float v = (m_Bt.getElement(i, 0, false) + m_B.getElement(0, j, false)) / 2.0;
			c.setElement(i, j, v);
		}
	}
	c.print();
}

void main()
{
	int node_num = 8;
	
	auto kp = std::make_shared<K_plex_matrix>();
	auto B = kp->k_plex_matrix_B(node_num, "D:/vs/code/Algorithm/k_plex/test_small_network_edges.csv");

	kp->k_plex_matrix_mul(B,"D:/vs/code/Algorithm/k_plex/test_mul.csv");
	kp->k_plex_matrix_add(B,"D:/vs/code/Algorithm/k_plex/test_add.csv");
	

	
}