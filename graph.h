#ifndef graph_h
#define graph_h


#include <list>
#include <vector>

// This class represents a directed graph using 
// adjacency list representation
class Graph
{
    int V; //  Vertexes
	int E; //  Edges
    // In a weighted graph, we need to store vertex 
    // and weight pair for every edge
    std::list< std::pair<int, int> > *adj;
	std::vector <int> colors;

public:
    Graph(int V, int E);  // Constructor
  
    // function to add an edge to graph
    void add_edge();
  
    // prints shortest path from s
    void shortest_path(int s);

	// Prints greedy coloring of the vertices
    void vertex_coloring();

	// Info about graph
	void metadata();

};

#endif //graph_h