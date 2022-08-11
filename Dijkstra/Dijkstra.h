#pragma once
#include <stack>

#define MAX_VERTEX_NUM 100	// 顶点最大个数
#define INFINITE 1e5		// 无穷大数值
#define VRType int			// 无权图中使用0或者1表示是否有边；对于带权图为权值
#define VertexType int		// 顶点数据类型

struct DijkstraGraph
{
	int vex_num; // 图中顶点数量
	int arc_num; // 图中边数量
	VertexType vexs[MAX_VERTEX_NUM]; // 一维数组存储图中顶点
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 二维数据存储顶点之间的关系即边信息
};

class Dijkstra
{
public:
	Dijkstra(DijkstraGraph& Graph); // 初始化邻接矩阵
	int LocateVex(DijkstraGraph& Graph, VertexType vex); // 根据顶点数据判断顶点在二维数组中的位置
	void CreateUDN(DijkstraGraph& Graph); // 构造无向带权图
	void PrintGraph(DijkstraGraph& Graph); // 打印图
	void ShortestPathofDijkstra(DijkstraGraph& Graph);
	void PrintPath(DijkstraGraph& Graph);

public:
	//DijkstraGraph Graph;
	int StartVex = 0; // 起点下标，初始值为0即默认输入第一个值为起点
	int Patharc[MAX_VERTEX_NUM]; // 存储最短路径下标，即每个顶点被访问后的前驱顶点的下标
	int Distance[MAX_VERTEX_NUM]; // 存储到各点最短路径的权值之和
	bool Visited[MAX_VERTEX_NUM]; // 标志位，Visited[2]=true代已求得起点到Vw的最短路径，Vw已被访问
	int tmp_vex, tmp_min; // 临时下标和临时最短路径权值

	std::stack<int> path;
};

