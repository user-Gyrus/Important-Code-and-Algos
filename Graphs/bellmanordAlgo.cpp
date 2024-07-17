//Bellman Ford Algorithm is another algo used in the finding the shortest distance from a particular source node to all other nodes
//Only exception is that it helps in finding the negative cycles as well
//we perform the relaxation of edges for n-1 times where n is the number of nodes. The intuition is that after n-1 times, shortest dist is found
//to check for negative cycle, apply the relaxation for one more time, if it occurs, then it indicates the presence of a negative cycle

//time complexity - O(E.V)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector <int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};
