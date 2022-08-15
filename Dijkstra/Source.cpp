#include <iostream>
#include "Dijkstra.h"
#include "AntColonyOptimization.h"

int main()
{
	/*Dijkstra start*/
	const int Input_vex_num = 9;
	const int Input_arc_num = 14;
	int Input_vexs[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int Input_arcs[][Input_vex_num] = { { INFINITE, 4, INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 8, INFINITE },
					  { 4, INFINITE, 8, INFINITE, INFINITE, INFINITE, INFINITE, 3, INFINITE },
					  { INFINITE, 8, INFINITE, 7, INFINITE, 4, INFINITE, INFINITE, 2 },
					  { INFINITE, INFINITE, 7, INFINITE, 9, 14, INFINITE, INFINITE, INFINITE },
					  { INFINITE, INFINITE, INFINITE, 9, INFINITE, 10, INFINITE, INFINITE, INFINITE },
					  { INFINITE, INFINITE, 4, 14, 10, INFINITE, 2, INFINITE, INFINITE },
					  { INFINITE, INFINITE, INFINITE, INFINITE, INFINITE, 2, INFINITE, 6, 6 },
					  { 8, 3, INFINITE, INFINITE, INFINITE, INFINITE, 6, INFINITE, 1 },
					  { INFINITE, INFINITE, 2, INFINITE, INFINITE, INFINITE, 6, 1, INFINITE }};

	DijkstraGraph* Graph = new DijkstraGraph(Input_vex_num, Input_arc_num, Input_vexs, (int**) Input_arcs);
	Dijkstra D0(*Graph);
	D0.PrintPath(*Graph);
	delete	Graph;
	/*Dijkstra end*/



	/*AOC start*/
	const double Input_corrd[][2] = { { 1304, 2312 },
	{ 3639, 1315 },
	{ 4177, 2244 },
	{ 3712, 1399 },
	{ 3488, 1535 },
	{ 3326, 1556 },
	{ 3238, 1229 },
	{ 4196, 1004 },
	{ 4312, 790 },
	{ 4386, 570 },
	{ 3007, 1970 },
	{ 2562, 1756 },
	{ 2788, 1491 },
	{ 2381, 1676 },
	{ 1332, 695 },
	{ 3715, 1678 },
	{ 3918, 2179 },
	{ 4061, 2370 },
	{ 3780, 2212 },
	{ 3676, 2578 },
	{ 4029, 2838 },
	{ 4263, 2931 },
	{ 3429, 1908 },
	{ 3507, 2367 },
	{ 3394, 2643 },
	{ 3439, 3201 },
	{ 2935, 3240 },
	{ 3140, 3550 },
	{ 2545, 2357 },
	{ 2778, 2826 },
	{ 2370, 2975 }
	};
	/*AOC end*/



	std::cin.get();
	return 0;
}