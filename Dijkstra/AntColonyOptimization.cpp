//#include "AntColonyOptimization.h"
//
//
//
//AntColonyOptimization::AntColonyOptimization(ACOGraph& Graph)
//{
//	axisGraph = new PlotEasyX(80, 700, 1000, 600, 50, 10, _T("X坐标"), _T("Y坐标"), 1, 1);
//	resultGraph = new PlotEasyX(80, 700, 1000, 600, 50, 10, _T("迭代次数"), _T("最短距离"), 10, s * 3);
//
//
//	switch (std::cin >> solveType)
//	{
//	case 0:
//		std::cout << "EXIT" << std::endl;
//		break;
//	case 1:
//		CreateUDN_TSP(Graph);
//		break;
//	case 2:
//		CreateUDN_SE(Graph);
//		break;
//	default:
//		std::cout << "Operator Mode Error!" << std::endl;
//		break;
//	}
//
//	PrintGraph(Graph);
//	PlotGraph(Graph);
//}
//
//AntColonyOptimization::~AntColonyOptimization()
//{
//	if (nullptr != axisGraph)
//	{
//		delete axisGraph;
//		axisGraph = nullptr;
//	}
//
//	if (nullptr != resultGraph)
//	{
//		delete resultGraph;
//		resultGraph = nullptr;
//	}
//}
//
//int AntColonyOptimization::LocateVex(ACOGraph& Graph, VertexType vex)
//{
//	for (int i = 0; i < Graph.cityNum; i++)
//		if (vex == Graph.vexs[i]) return i;
//	std::cout << "no such vertex!" << std::endl;
//	return -1;
//}
//
//void AntColonyOptimization::CreateUDN_TSP(ACOGraph& Graph)
//{
//
//}
//
//void AntColonyOptimization::CreateUDN_SE(ACOGraph& Graph)
//{
//}
//
//void AntColonyOptimization::PlotGraph(ACOGraph& Graph)
//{
//	while (true)
//	{
//		initgraph(switch, sheight, EW_NOMINIMIZE | EW_SHOWCONSOLE); // easyx初始化，同时创建图形窗口和命令窗口
//		(*axisGraph).plotAxis();
//		setlinecolor(RED); // 边框
//		setfillcolor(RED); // 填充
//		setfillstyle(BS_SOLID); // 填充样式
//		setlinestyle(PS_SOLID, 1);
//
//		setbkcolor(WHITE);
//		for (int i = 0; i < Graph.cityNum; i++)
//		{
//			fillcircle(Graph.corrd[i][0] / proportion, Graph.corrd[i][1] / proportion, 3);
//			
//			if (i + 1 < n) line(Graph.corrd[i][0] / proportion, -Graph.corrd[i][1] / proportion, Graph.corrd[i + 1][0] / proportion, -Graph.corrd[i + 1][1] / proportion);
//			else break;
//
//			for (int j = i; j < Graph.cityNum; j++)
//			{
//				if (Graph.arcs[i][j] != INFINITE & i != j) line(graph.corrd[i][0] / proportion, -graph.corrd[i][1] / proportion, graph.corrd[j][0] / proportion, -graph.corrd[j][1] / proportion);
//			}
//		}
//	}
//}
//
//double AntColonyOptimization::RandomNum(double low, double up)
//{
//	return  (rand() / (double)RAND_MAX) * (up - low) + low;
//}
//
//void AntColonyOptimization::PathofAntColonyOptimization(ACOGraph& Graph)
//{
//	srand(unsinged)time(NULL);
//	int iter = 0;
//	std::vector<int> tmp;
//
//	while (iter < Graph.iterNum)
//	{
//		tmp.clear();
//		for (int i = 0; i < Graph.antNum; i++)
//		{
//			tmp.push_back(0);
//			Visited[i][0] = tmp[i]; // 更新每只蚂蚁的禁忌表
//		}
//
//		for (int i = 0; i < Graph.antNum; i++)
//		{
//			for (int j = 1; j < Graph.cityNum; j++)
//			{
//				std::vector<int> visited_i; // 第i只蚂蚁已访问过的城市
//				std::vector<int> toVisit_i; // 第i只蚂蚁待访问的城市
//				std::vector<double> compete_i; // 第i只蚂蚁待访问城市的竞争值
//				std::vector<double> proba_i; // 第i只蚂蚁待访问的城市的概率
//
//				double sumCompete = 0.0; // 竞争值和
//				double sumProba = 0.0; // 概率值和
//				double randNum = 0.0; // 随机数
//				double sumRoulette = 0.0; // 轮盘赌算法累加值
//				int toVisit = 0; // 下一个要去的城市
//
//				for (int k = 0; k < j; k++)
//					visited_i.push_back(Visited[i][k]); // 把当前蚂蚁的禁忌表进行赋值
//
//				// 添加待访问城市
//				for (int k = 0; k < Graph.cityNum; k++)
//				{
//					// 若在visited中没有找到k，则说明还未被访问
//					if (find(visited_i.begin(), visited_i.end(), k) == visited_i.end())
//					{
//						toVisit_i.push_back(k);
//						compete_i.push_back(0.0);
//						proba_i.push_back(0.0);
//					}
//				}
//
//				// 计算去下一座城市的竞争值（已访问城市中最后一个城市—>各待访问各城市）
//				for (int k = 0; k < compete_i.size(); k++)
//				{
//					compete_i[k] = std::pow(Graph.pathPhe[visited_i.back()][toVisit_i[k]], Graph.Alpha) * std::pow(Graph.heuristic[visited_i.back()][toVisit_i[k]], Graph.Beta); // 对应公式的分子
//					sumCompete += compete_i[k];
//				}
//
//				// 计算去下一座城市的各种概率（已访问城市中最后一个城市—>各待访问各城市）
//				for (int k = 0; k < proba_i.size(); k++)
//				{
//					proba_i[k] = compete_i[k] / sumCompete;
//					sumProba += proba_i[k];
//				}
//
//				// 使用轮盘赌算法，挑选下一座要去的城市
//				randNum = RandomNum(0.0, sumProba); // 返回sumProba * r, 0<r<1
//				for (int k = 0; k < proba_i.size(); k++)
//				{
//					sumRoulette += proba_i[k];
//					if (sumRoulette >= randNum)
//					{
//						toVisit = toVisit_i[k];// 根据概率选择下一访问城市
//						break;
//					}
//				}
//
//				Visited[i][j] = toVisit; // 更新禁忌表（把刚选出的下一访问城市及时加入）
//			}
//		}
//
//		// 记录本次迭代蚂蚁行走的路线数据
//		for (int i = 0; i < Graph.antNum; i++)
//		{
//			lenAnt.push_back(0.0);
//		}
//
//		/*0815暂停蚁群*/
//
//	}
//}
//
//ACOGraph::ACOGraph(int antNum, int cityNum, int iterNum, double oriPhe, double Alpha, double Beta, double Rho, double incrPhe, int** InCorrd)
//{
//	this->antNum = antNum;
//	this->cityNum = cityNum;
//	this->iterNum = iterNum;
//	this->oriPhe = oriPhe;
//	this->Alpha = Alpha;
//	this->Beta = Beta;
//	this->Rho = Rho;
//	this->incrPhe = incrPhe;
//
//	for (int i = 0; i < this->cityNum; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			this->corrd.push_back(*((int*) Incorrd + 2 * i + j));
//		}
//	}
//
//	for (int i = 0; i < this->cityNum; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			if (i != j)
//			{
//				this->arcs.push_back(std::pow(std::pow((corrd[i][0] - corrd[j][0], 2) + std::pow((City_Position[i][1] - City_Position[j][1]), 2), 0.5));
//				this->heuristic.push_back(1.0 / arcs[i][j]);
//			}
//			else
//			{
//				this->arcs.push_back(0.0);
//				this->heuristic.push_back(INFINITE);
//			}
//		}
//		this->vexs = i + 1;
//	}
//
//	this->startVex = this->vexs[0];
//	std::map<int, int, CompareMap> heuristic_tmp;// 降序排列
//
//	for (int i = 0; i < this->cityNum; i++)
//	{
//		heuristic_tmp.insert(std::pair<int, int>(arcs[i], i));
//		for (int j = 0; j < this->cityNum; j++)
//		{
//			this->pathPhe.push_back(oriPhe);
//			this->deltaPhe.push_back(0.0);
//		}
//	}
//	this->endVex = vexs[(*(heuristic_tmp)).second];
//}
