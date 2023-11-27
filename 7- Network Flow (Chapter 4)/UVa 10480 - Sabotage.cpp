#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;
#define INF 1e7

#define MAX_V 55

//
// Referenced from gh user ackoroa and the book

//
// mf : max flow
// f : current flow
// source : source node
// target : target node
// residual : residual graph
// adjList : adjacency list
int residual[MAX_V][MAX_V], mf, f, source, target; 
vector<vector<int>> adjList;

//
// dfsv : visited nodes
// SSet : set of nodes in the source set
// p : parent nodes
bitset<60> dfsv;
set<int> SSet;
vector<int> p;

//
// Referenced from gh user ackoroa and the book
//
// DFS to find the nodes in the source set to find the mincut
void dfs(int u) {
	dfsv.set(u);
	SSet.insert(u);
	for (int i = 0; i < (int) adjList[u].size(); i++) {
		int v = adjList[u][i];
		if (!dfsv.test(v) && residual[u][v] > 0) {
			dfs(v);
		}
	}
}

//
// Mincut implementation, referenced from gh user ackoroa and the book
void mincut() {
    //
    // Reset the set and the visited nodes
	SSet.clear();
	for (int i = 0; i < MAX_V; i++)
		dfsv.reset();
    
    //
    // Find the nodes in the source set
	dfs(source);

    //
    // Print the edges that are in the mincut
	set<int>::iterator it;

    //
    // Print the edges that are in the mincut
	for (it = SSet.begin(); it != SSet.end(); it++) {
		int u = *it;
		for (int i = 0; i < (int) adjList[u].size(); i++) {
            //
            // If the node is not in the source set, print the edge
			int v = adjList[u][i];
			if (SSet.count(v))
				continue;
			if (residual[u][v] <= 0) {
				printf("%d %d\n", u + 1, v + 1);
			}
		}
	}
	printf("\n");
}


//
// Augment function, does part of the Edmond Karps algorithm
void augment(int v, int minEdge) {
    //
    // If we reached the source, we are done
	if (v == source) {
		f = minEdge;
		return;
	} else if (p[v] != -1) { // Otherwise, if there is a parent node
        //
        // Recursively call the function
		augment(p[v], min(minEdge, residual[p[v]][v]));
        //
        // Update the residual graph
		residual[p[v]][v] -= f;
		residual[v][p[v]] += f;
	}
}

void EdmondKarps() {
	mf = 0; // max flow
	while (1) {
		f = 0; // current flow

		bitset<MAX_V> visited; 
		visited.set(source);

		queue<int> q;
		q.push(source);
		p.assign(MAX_V, -1); 

        //
        // BFS to find the path
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == target) // If we reached the target, we are done
				break;
			for (int i = 0; i < (int) adjList[u].size(); i++) { // Otherwise, find the next node
				int v = adjList[u][i];
                //
                // If the node is not visited and there is flow, add it to the queue
				if (residual[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
        //
        // Find the augmenting path and update the residual graph
		augment(target, INF);
		if (f == 0)
			break;
		mf += f;
	}
}



int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int n, m, a, b, c;

    source = 0;
    target = 1;

    while (cin >> n >> m && n || m){
        //
        // Reset the graph
        memset(residual, 0, sizeof residual);
        adjList = vector<vector<int>>(MAX_V, vector<int>());

        //
        // Read the new graph
        for (int i = 0; i < m; ++i){
            // 
            // Read the edge
            cin >> a >> b >> c;
            --a; // 0-indexed
            --b; // 0-indexed
            //
            // Add the edge to the graph
            residual[a][b] += c;
            residual[b][a] += c;
            adjList[b].push_back(a);
            adjList[a].push_back(b);
        }

        //
        // Use Edmond Karps to find the max flow
        // Then use mincut to find the edges that are in the mincut
        EdmondKarps();
        mincut();
    }

    return 0;
}

