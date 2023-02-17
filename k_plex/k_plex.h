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
	void k_plex_matrix_mul(std::vector<float> K_plex_v, string file_name);//����˷�
	void k_plex_matrix_add(std::vector<float> K_plex_v, string file_name);//�������
	
private:
	std::vector<std::vector<int>> read_csv(std::string file_name);//��CSV�ļ�
	void writ_csv(std::string file_name, Matrix& m);//дcsv�ļ�
	int getSubDegree(std::vector<int>& s, int node);//��ĳ��������ͼ��node�Ķ�
	bool isKPlex(std::vector<int>& s, int k);//�жϼ���s�Ƿ���һ��k_plex
	std::unordered_set<int> getNeighbors(std::unordered_set<int>& vertices);// ����ָ����㼯�ϵ��ھӽ�㼯��
	bool isInLine(std::vector<int>& s,int node);//�ж�һ�������Ƿ�����һ���ڵ�����
	std::vector<std::vector<int>> bfs_kplex(std::vector<int> nodes, int k);// �����������ʵ��k-plex
	std::shared_ptr<Matrix> adj;//�ڽӾ���
	int n;//�ڵ���

};