#ifndef __K_PLEX_H__
#define __K_PLEX_H__
#endif	
#include <unordered_set>
#include <vector>
#include "matrix.hpp"

class K_plex_matrix
{
public:
	K_plex_matrix()
		: n(0)
	{}

	std::vector<float> k_plex_matrix_B(int node_num, string file_name);
	void k_plex_matrix_mul(std::vector<float> K_plex_v, string file_name);//矩阵乘法
	void k_plex_matrix_add(std::vector<float> K_plex_v, string file_name);//矩阵相加
	
private:
	std::vector<std::vector<int>> read_csv(std::string file_name);//读CSV文件
	void writ_csv(std::string file_name, Matrix& m);//写csv文件
	int getSubDegree(std::vector<int>& s, int node);//求某个导出子图中node的度
	bool isKPlex(std::vector<int>& s, int k);//判断集合s是否是一个k_plex
	std::unordered_set<int> getNeighbors(std::unordered_set<int>& vertices);// 返回指定结点集合的邻居结点集合
	bool isInLine(std::vector<int>& s,int node);//判断一个集合是否与另一个节点相连
	std::vector<std::vector<int>> bfs_kplex(std::vector<int> nodes, int k);// 广度优先搜索实现k-plex
	std::shared_ptr<Matrix> adj;//邻接矩阵
	int n;//节点数

};