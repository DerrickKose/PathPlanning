#include <iostream>
#include "Dijkstra.h"

int main()
{
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

	std::cin.get();
	return 0;
}