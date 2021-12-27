//#include<iostream>
#include <vector>
#include <ctime>

#include "graph.h"
#include "common.h"

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
	info(1);
	
	int V = get_data();
	int E;
	while ((E = get_data()) > V * (V - 1) / 2) 
		info(2);

    Graph g(V, E);

	g.add_edge();

	
	g.vertex_coloring();
	
    //info(5);
	//int f = get_data();
	g.shortest_path(2);
	
	g.metadata();
	
    return 0;
}