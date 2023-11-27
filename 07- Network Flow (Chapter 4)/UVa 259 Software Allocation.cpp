#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;
#define INF 1e7

int maxAppCount = 26;
int maxComputerCount = 10;
int totalNodes = maxAppCount + maxComputerCount + 2; // 2 extra nodes for the source and sink
int source = totalNodes - 1;
int sink = totalNodes - 2;

int maxFlow;
int flow;
int total = 0;

//
// Helper function for Edmond Karps
// referenced from 
// https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20259%20-%20Software%20Allocation/src/UVa%20259%20-%20Software%20Allocation.cpp
void augment(int v, int minEdge, vector<int> &p, vector<vector<int>> &graph) {
	if (v == source) {
		flow = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, graph[p[v]][v]), p, graph);
		graph[p[v]][v] -= flow;
		graph[v][p[v]] += flow;
	}
}

//
// Edmond Karps implementation, referenced from:
// https://github.com/ackoroa/UVa-Solutions/blob/master/UVa%20259%20-%20Software%20Allocation/src/UVa%20259%20-%20Software%20Allocation.cpp
void EdmondKarps(vector<vector<int>> &adjList, vector<vector<int>> &graph, vector<int> &p) {
	maxFlow = 0;
	while (1) {
		flow = 0;
		bitset<38> visited;
		visited.set(source);
		queue<int> q;
		q.push(source);
		p.assign(totalNodes, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == sink)
				break;
			for (int i = 0; i < (int) adjList[u].size(); i++) {
				int v = adjList[u][i];
				if (graph[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(sink, INF, p, graph);
		if (flow == 0)
			break;
		maxFlow += flow;
	}

    if (total != maxFlow) {
		printf("!\n");
	} else {
		for (int i = 26; i < 36; i++) {
			bool alloc = false;
			for (int j = 0; j < 26; j++) {
				if (graph[i][j]) {
					printf("%c", j + 'A');
					alloc = true;
					break;
				}
			}
			if (!alloc)
				printf("_");
		}
		printf("\n");
	}
}

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    cin.unsetf(ios::skipws); // No need to skip whitespace

    //
    // This is a network flow question. We model the problem as a graph where
    // each computer is a node and each application is a node. We connect the
    // source to each application with the computers that can run it. 
    // Each edge has a capacity of 1. We connect each computer to the sink with
    // a capacity of 1. We then run a max flow algorithm on the graph. 
    // Using edmonds-karp, we can find the max flow in O(V * E^2) time.
    
    char currApp;
    int currAppRequests;
    vector<int> validComputers;
    

    //
    // Until the end of the input
    bool seenNewLine = false;
    vector<vector<int>> graph(totalNodes, vector<int>(totalNodes, 0));
    vector<vector<int>> adjList(totalNodes, vector<int>(0));
    while (cin >> currApp){
        //
        // See if our test case is over.
        if (currApp == '\n'){
            if (seenNewLine) {
                //
                // We have seen two new lines in a row. This means our test case is over.
                // Let's run the max flow algorithm on the graph.
                // Then reset the graph for the next test case.

                //
                // Connect the source to the computers
                for (int i = maxAppCount; i < totalNodes - 2; i++) {
                    graph[i][sink] = 1;
                    adjList[i].push_back(sink);
                    adjList[sink].push_back(i);
                }

                //
                // Run the max flow algorithm
                vector<int> p;
                EdmondKarps(adjList, graph, p);

                //
                // Reset the graph for the next test case
                // adjList.clear();
                adjList = vector<vector<int>>(totalNodes, vector<int>(0));
                graph = vector<vector<int>>(totalNodes, vector<int>(totalNodes, 0));
                total = 0;
            }
            seenNewLine = true;
            continue;
        } else {
            seenNewLine = false;
        }
        
        //
        // Read the valid computers for the current app 
        cin >> currAppRequests;
        char c;
        cin >> c;
        while (cin >> c && c != ';'){
            int num =  c - '0';
            validComputers.push_back(num);
        }

        //
        // Connect source to app node
        int appNode = currApp - 'A';
        graph[source][appNode] = currAppRequests; // Capacity of the edge is the number of requests
        adjList[source].push_back(appNode);
        adjList[appNode].push_back(source);
        total += currAppRequests;

        //
        // Connect app node to computers
        for (int comp : validComputers) {
            int compNode = maxAppCount + comp;
            graph[appNode][compNode] = 1; // Capacity 1 edge
            adjList[appNode].push_back(compNode);
            adjList[compNode].push_back(appNode);
        }

        //
        // Clear the vector for the next iteration
        validComputers.clear();
    }

    //
    // We have reached the end of the input. We need to run the max flow algorithm one last time.
    //
    // Connect the source to the computers
    for (int i = maxAppCount; i < totalNodes - 2; i++) {
        graph[i][sink] = 1;
        adjList[i].push_back(sink);
        adjList[sink].push_back(i);
    }

    //
    // Run the max flow algorithm
    vector<int> p;
    EdmondKarps(adjList, graph, p);
    
    return 0;
}

