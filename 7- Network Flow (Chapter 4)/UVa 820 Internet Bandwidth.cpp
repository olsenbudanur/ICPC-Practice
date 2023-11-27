#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;
#define INF 1e7



int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    //
    // This is a basic max-flow problem.
    int caseNum = 1;
    int nodeCount;
    while (cin >> nodeCount && nodeCount != 0){
        int source, target, edgeCount;
        cin >> source >> target >> edgeCount;

        vector<vector<int>> adjList(nodeCount + 1, vector<int>(nodeCount + 1, 0));

        for (int i = 0; i < edgeCount; i++){
            int from, to, bandwidth;
            cin >> from >> to >> bandwidth;
            adjList[from][to] += bandwidth;
            adjList[to][from] += bandwidth;
        }
        int maxFlow = 0;

        //
        // Calculate max flow using Edmond Karps
        while (1){
            int flow = 0;
            vector<int> parent(nodeCount + 1, -1);
            queue<pair<int, int>> q;
            q.push({source, INF});
            vector<bool> visited(nodeCount + 1, false);
            visited[source] = true;
            //
            // BFS to find the path
            while (!q.empty()){
                int node = q.front().first;
                int minFlow = q.front().second;
                q.pop();
                if (node == target){
                    flow = minFlow;
                    break;
                }
                //
                // Find the next node
                for (int i = 1; i <= nodeCount; i++){
                    if (adjList[node][i] > 0 && !visited[i]){
                        visited[i] = true;
                        parent[i] = node;
                        q.push({i, min(minFlow, adjList[node][i])});
                    }
                }
            }
            //
            // If no path was found, break
            if (flow == 0) break;
            //
            // Update the max flow
            maxFlow += flow;
            int currNode = target;
            while (currNode != source){
                int prevNode = parent[currNode];
                adjList[prevNode][currNode] -= flow;
                adjList[currNode][prevNode] += flow;
                currNode = prevNode;
            }
        }

        cout << "Network " << caseNum << "\n";
        cout << "The bandwidth is " << maxFlow << ".\n";
        caseNum++;
    }
}

