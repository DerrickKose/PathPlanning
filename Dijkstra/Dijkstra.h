#pragma once
#include <stack>

#define MAX_VERTEX_NUM 100	// ����������
#define INFINITE 1e5		// �������ֵ
#define VRType int			// ��Ȩͼ��ʹ��0����1��ʾ�Ƿ��бߣ����ڴ�ȨͼΪȨֵ
#define VertexType int		// ������������

struct DijkstraGraph
{
	int vex_num; // ͼ�ж�������
	int arc_num; // ͼ�б�����
	VertexType vexs[MAX_VERTEX_NUM]; // һά����洢ͼ�ж���
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ��ά���ݴ洢����֮��Ĺ�ϵ������Ϣ
};

class Dijkstra
{
public:
	Dijkstra(DijkstraGraph& Graph); // ��ʼ���ڽӾ���
	int LocateVex(DijkstraGraph& Graph, VertexType vex); // ���ݶ��������ж϶����ڶ�ά�����е�λ��
	void CreateUDN(DijkstraGraph& Graph); // ���������Ȩͼ
	void PrintGraph(DijkstraGraph& Graph); // ��ӡͼ
	void ShortestPathofDijkstra(DijkstraGraph& Graph);
	void PrintPath(DijkstraGraph& Graph);

public:
	//DijkstraGraph Graph;
	int StartVex = 0; // ����±꣬��ʼֵΪ0��Ĭ�������һ��ֵΪ���
	int Patharc[MAX_VERTEX_NUM]; // �洢���·���±꣬��ÿ�����㱻���ʺ��ǰ��������±�
	int Distance[MAX_VERTEX_NUM]; // �洢���������·����Ȩֵ֮��
	bool Visited[MAX_VERTEX_NUM]; // ��־λ��Visited[2]=true���������㵽Vw�����·����Vw�ѱ�����
	int tmp_vex, tmp_min; // ��ʱ�±����ʱ���·��Ȩֵ

	std::stack<int> path;
};

