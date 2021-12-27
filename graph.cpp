#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <ctime>
#include <set>

#include "graph.h"
#include "common.h"

using namespace std;

#define INF 10000

Graph::Graph(int V, int E)
{
    this->V = V;
	this->E = E;
    adj = new list< pair<int, int> >[V];
	colors.resize(V);
	
	fill(colors.begin(), colors.end(), 0);
}
  
void Graph::add_edge()
{
	info(3);
	int f = get_data();
	int buf[V][V];
	for (int i = 0;i < V * V; i ++){
		buf[i / V][i % V] = 0;
	}
	int u, w, v;
	srand(time(NULL));
	for (int i = 0; i < E; i ++){
		if (f == 1){
			
			do{
				info(4);
				u = get_data(), v = get_data(), w = get_data();
			}while(buf[u][v] != 0);
		}
    	else{
			
			u = rand() % V;
			w = rand() % 50;
		 	v = rand() % V;
			while (buf[u][v] != 0 || u == v){
				u = rand() % V, v = rand() % V;
			}
			buf[u][v] = 1;
			buf[v][u] = 1;
		}
		adj[u].push_back(make_pair(v, w));
    	adj[v].push_back(make_pair(u, w));
	}
	
	
}

void Graph::metadata(){
	for (int i = 0; i < V; i ++){
		cout << "Vertex " << i << '\n'; 
		cout << "Adjencent vertexes:";
		for(list <pair<int, int>> ::iterator j = adj[i].begin(); j != adj[i].end(); j++) cout<<" ("<<j->first<<", "<<j->second<<"),";
		cout << '\n';
		cout << "Color: " << colors[i] << "\n\n";
	}
}

void Graph::vertex_coloring()
{
    //int result[V];

    // Assign the first color to first vertex

    //result[0]  = 0;
	//colors[0] = 0;
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        //result[u] = -1;  // no color is assigned to u
		colors[u] = -1;
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        list<pair<int, int>>::iterator i;
		int j = 0;
        for (i = adj[u].begin(); i != adj[u].end(); i++, j++)
            //if (result[j] != -1)
                //available[result[j]] = true;
			if (colors[j] != -1)
                available[colors[j]] = true;
 
        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
 
        //result[u] = cr; // Assign the found color
		colors[u] = cr;
        // Reset the values back to false for the next iteration
		j = 0;
        for (i = adj[u].begin(); i != adj[u].end(); i++, j++)
            //if (result[j] != -1)
                //available[result[j]] = false;
			if (colors[j] != -1)
                available[colors[j]] = false;
    }
 
    // print the result
    for (int u = 0; u < V; u++)
        //cout << "Vertex " << u << " --->  Color "
        //    << result[u] << endl;
		cout << "Vertex " << u << " --->  Color "
           << colors[u] << endl;
	cout << "\n\n";
}

// Prints shortest paths from src to all other vertices
void Graph::shortest_path(int src)
{
    // Create a set to store vertices that are being
    // processed
    set< pair<int, int> > setds;
  
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
  
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
  
    /* Looping till all shortest distance are finalized
       then setds will become empty    */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
  
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;
  
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
  
            //    If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.  
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them, 
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
  
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
  
    // Print shortest distances stored in dist[]
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" <<  dist[i] << '\n';
	cout << "\n\n";
}
