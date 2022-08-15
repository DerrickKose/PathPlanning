//#pragma once
//#include <vector>
//#include <cmath>
//#include <map>
//#include "PlotEasyX.h"
//
//#define VertexType int // �������������
//const int INFINITE 1e5;
//
//class ACOGraph
//{
//public:
//	// ���ϸ�������������������������
//	int antNum, cityNum, iterNum;
//	// ��ʼ��Ϣ��Ũ�ȣ���Ϣ����Ҫ�̶Ȳ���������ʽ������Ҫ�̶Ȳ�������Ϣ������ϵ������Ϣ������ǿ��ϵ��
//	double oriPhe, Alpha, Beta, Rho, incrPhe;
//
//public:
//	int arcNum = cityNum * (cityNum - 1) / 2; // ͼ�ı�����Ĭ�����ж�������֮������ڱ�
//	VertexType startVex, endVex;
//
//public:
//	ACOGraph(int antNum, int cityNum, int iterNum, double oriPhe, double Alpha, double Beta, double Rho, double incrPhe, int** InCorrd);
//
//	std::vector<VertexType> vexs; // �洢ͼ�ж�������
//	std::vector<std::vector<double>> arcs; // ��¼����֮��Ȩֵ
//	std::vector<std::vector<double>> heuristic; // �������ӣ�������֮��Ȩֵ����
//	std::vector<std::vector<double>> deltaPhe; // �������ӱ仯��
//	std::vector<std::vector<double>> pathPhe; // ·������Ϣ��Ũ��
//	std::vector<std::vector<double>> corrd; // �����x,y����
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
//	double shortestLenPath; // ���е�������̾���
//	int minShortestPathIndex = 0; // ���е���������·���ĵ����±�
//	int solveType = 0; // �������
//	
//	/*���黹δ��ʼ��0815*/
//	PlotEasyX* axisGraph, resultGraph; // ͼ�������ᣬ������ݵ�������
//	std::vector<std::vector<VertexType>> Visited; // �ѷ��ʵĳ���
//	std::vector<double> shortestIterPath; // ÿ�ε�����·����̳���
//	std::vector<double> averageIterPath; // ÿ�ε�����·��ƽ������
//	std::vector<std::vector<VertexType>> bestIterPath; // ÿ�ε��������·��
//	std::vector<double> lenAnt; // ÿֻ�����ߵ�·��
//	std::vector<VertexType> shortestPath; // ���е����е�����·��
//
//public:
//	AntColonyOptimization(ACOGraph& Graph);
//	~AntColonyOptimization();
//	int LocateVex(ACOGraph& Graph, VertexType vex); // �ж϶����ڶ�ά�����е�λ��
//	void CreateUDN_TSP(ACOGraph& Graph); // ���������Ȩͼ TSP�����ã����ж���֮�䶼�б�
//	void CreateUDN_SE(ACOGraph& Graph); // ���������Ȩͼ������㵽�յ�������
//	void PlotGraph(ACOGraph& Graph); // ��������ͼ
//
//	double RandomNum(double low, double up); // ����lower��uper֮���һ��double���������
//	void PathofAntColonyOptimization(ACOGraph& Graph); // ��Ⱥ�㷨
//	void UpdatePhe(ACOGraph& Graph); // ������Ϣ�أ�Ϊ��һ�ε����ĸ���ѡ����һ���ʳ�����׼��
//
//	void ShowResult(ACOGraph& Graph);
//	void PlotResultPath(ACOGraph& Graph); // ���ƽ��·��
//	void DrawResult(ACOGraph& Graph); // ���ƽ������
//};
//
