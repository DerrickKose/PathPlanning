//#pragma once
//#include <vector>
//#include <cmath>
//#include <map>
//#include "PlotEasyX.h"
//
//#define VertexType int // 顶点的数据类型
//const int INFINITE 1e5;
//
//class ACOGraph
//{
//public:
//	// 蚂蚁个数，城市数量，最大迭代次数
//	int antNum, cityNum, iterNum;
//	// 初始信息素浓度，信息素重要程度参数，启发式因子重要程度参数，信息素蒸发系数，信息素增加强度系数
//	double oriPhe, Alpha, Beta, Rho, incrPhe;
//
//public:
//	int arcNum = cityNum * (cityNum - 1) / 2; // 图的边数，默认所有顶点两两之间均存在边
//	VertexType startVex, endVex;
//
//public:
//	ACOGraph(int antNum, int cityNum, int iterNum, double oriPhe, double Alpha, double Beta, double Rho, double incrPhe, int** InCorrd);
//
//	std::vector<VertexType> vexs; // 存储图中顶点数据
//	std::vector<std::vector<double>> arcs; // 记录顶点之间权值
//	std::vector<std::vector<double>> heuristic; // 启发因子，即顶点之间权值倒数
//	std::vector<std::vector<double>> deltaPhe; // 启发因子变化量
//	std::vector<std::vector<double>> pathPhe; // 路径上信息素浓度
//	std::vector<std::vector<double>> corrd; // 顶点的x,y坐标
//};
//
//class CompareMap
//{
//public:
//	bool operator()(int vex1, int vex2) const { return vex1 > vex2; }
//};
//
//class AntColonyOptimization
//{
//public:
//	double shortestLenPath; // 所有迭代中最短距离
//	int minShortestPathIndex = 0; // 所有迭代中最优路径的迭代下标
//	int solveType = 0; // 求解类型
//	
//	/*数组还未初始化0815*/
//	PlotEasyX* axisGraph, resultGraph; // 图的坐标轴，结果数据的坐标轴
//	std::vector<std::vector<VertexType>> Visited; // 已访问的城市
//	std::vector<double> shortestIterPath; // 每次迭代的路径最短长度
//	std::vector<double> averageIterPath; // 每次迭代的路径平均长度
//	std::vector<std::vector<VertexType>> bestIterPath; // 每次迭代的最佳路线
//	std::vector<double> lenAnt; // 每只蚂蚁走的路程
//	std::vector<VertexType> shortestPath; // 所有迭代中的最优路径
//
//public:
//	AntColonyOptimization(ACOGraph& Graph);
//	~AntColonyOptimization();
//	int LocateVex(ACOGraph& Graph, VertexType vex); // 判断顶点在二维数组中的位置
//	void CreateUDN_TSP(ACOGraph& Graph); // 构造无向带权图 TSP问题用，所有顶点之间都有边
//	void CreateUDN_SE(ACOGraph& Graph); // 构造无向带权图，从起点到终点问题用
//	void PlotGraph(ACOGraph& Graph); // 绘制整个图
//
//	double RandomNum(double low, double up); // 生成lower和uper之间的一个double类型随机数
//	void PathofAntColonyOptimization(ACOGraph& Graph); // 蚁群算法
//	void UpdatePhe(ACOGraph& Graph); // 更新信息素，为下一次迭代的概率选择下一访问城市作准备
//
//	void ShowResult(ACOGraph& Graph);
//	void PlotResultPath(ACOGraph& Graph); // 绘制结果路径
//	void DrawResult(ACOGraph& Graph); // 绘制结果数据
//};
//
