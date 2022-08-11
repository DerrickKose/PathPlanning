#include "Dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(DijkstraGraph& Graph)
{
	CreateUDN(Graph);

	//遍历所有顶点，更新Visited、Distance、Patharc
	for (int i = 0; i < Graph.vex_num; i++)
	{
		Visited[i] = false; // 全部顶点都未访问
		Distance[i] = Graph.arcs[StartVex][i]; // 读取StartVex为起点的边
		Patharc[i] = StartVex; // 前驱顶点下标全置为StartVex，注：此处不能初始化为0或-1
	}
	//起点初始化
	Distance[StartVex] = 0;
	Visited[StartVex] = true;

	std::cout << std::endl;
	PrintGraph(Graph);
	ShortestPathofDijkstra(Graph);
}

int Dijkstra::LocateVex(DijkstraGraph& Graph, VertexType vex)
{
	// 遍历一维数组
	for (int i = 0; i < Graph.vex_num; i++)
	{
		if (vex == Graph.vexs[i]) return i;
	}
	std::cout << "No such vertex." << std::endl;
	return -1;
}

void Dijkstra::CreateUDN(DijkstraGraph& Graph)
{
	if (MAX_VERTEX_NUM < Graph.vex_num || 0 >= Graph.vex_num) std::cout << "VexNum Oversize!" << std::endl;

	if ((Graph.vex_num) * (Graph.vex_num - 1) / 2 < Graph.arc_num || 0 > Graph.arc_num) std::cout << "ArcNum Oversize!" << std::endl;

	for (int i = 0; i < Graph.vex_num; i++)
	{
		Graph.arcs[i][i] = 0;
	}
}

void Dijkstra::PrintGraph(DijkstraGraph& Graph)
{
	std::cout << "The adjacency matrix of the graph is " << std::endl;
	for (int i = 0; i < Graph.vex_num; i++)
	{
		for (int j = 0; j < Graph.vex_num; j++)
		{
			std::cout << Graph.arcs[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Dijkstra::ShortestPathofDijkstra(DijkstraGraph& Graph)
{
	// 从StartVex的下一个节点开始
	for (int i = 1; i < Graph.vex_num; i++)
	{
		tmp_min = INFINITE;
		for (int j = 0; j < Graph.vex_num; j++)
		{
			// 顶点还未被访问，且现有权值之和小于tmp_min
			if ((!Visited[j]) && (Distance[j] < tmp_min))
			{
				tmp_vex = j;
				tmp_min = Distance[j];
			}
		}
		Visited[tmp_vex] = true; // 更新已访问顶点 

		for (int j = 0; j < Graph.vex_num; j++)
		{
			// 顶点还未被访问，且经过tmp_vex到j顶点的权值之和更短
			if ((!Visited[j]) && (tmp_min + Graph.arcs[tmp_vex][j] < Distance[j]))
			{
				Distance[j] = tmp_min + Graph.arcs[tmp_vex][j];
				Patharc[j] = tmp_vex;
			}
		}
	}
}

void Dijkstra::PrintPath(DijkstraGraph& Graph)
{
	std::cout << "DijkstraPath" << std::endl;
	for (int i = 0; i < Graph.vex_num; i++)
	{
		if (0 != i && INFINITE != Distance[i])
		{
			std::cout << "Vertex " << Graph.vexs[StartVex] << " -> " << Graph.vexs[i] << " MinimumWeight: " << Distance[i] << " ShortestPath: ";

			int tmp_headvex = i;
			while (0 != tmp_headvex)
			{
				path.push(Graph.vexs[tmp_headvex]);
				tmp_headvex = Patharc[tmp_headvex];
			}
			path.push(Graph.vexs[StartVex]);

			while (!path.empty())
			{
				if (1 == path.size()) std::cout << path.top();
				else std::cout << path.top() << " -> ";
				path.pop();
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

