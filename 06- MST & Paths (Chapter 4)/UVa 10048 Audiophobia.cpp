#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

typedef pair<int, int>  ii; // shortcut for a pair...

//
// Union-Find 
vector<int> parents;
inline int find(int element){
    if (parents[element] == element) return element;
    return find(parents[element]);
}
inline void unionElements(int element1, int element2){
    int parent1 = find(element1);
    int parent2 = find(element2);
    parents[parent2] = parent1;
}


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int vertexNum, edgeNum, queryNum;
    int idx = 1;

    while (cin >> vertexNum >> edgeNum >> queryNum && (vertexNum + edgeNum + queryNum)){
        if (idx != 1) cout << "\n";

        //
        // Create a vector with the edges, and vector for unionfind.
        parents.resize(vertexNum);
        for (int i = 0; i < vertexNum; ++i) parents[i] = i;

        vector<pair<int, ii>> edges;
        for (int i = 0; i < edgeNum; ++i){
            //
            // Read the edges and weight.
            int a, b, w;
            cin >> a >> b >> w;
            --a; // 1 indexed, sigh.
            --b; // 1 indexed, sigh.
            edges.push_back({w, {a, b}});
        }

        //
        // Sort edges by weight
        // Also, i dont think i need custom comparator...  The sort function already sorts by first element...
        sort(edges.begin(), edges.end(), [](const pair<int, ii>& edg1, const pair<int, ii>& edg2) {
            return edg1.first < edg2.first;
        });

        int mstsConnectedEdges = 0;
        map<int, vector<ii>> mstsAdjList;
        
        for (int i = 0; i < edgeNum; i++){
            //
            // If we connected all vertecies already, we are done.
            if (mstsConnectedEdges == vertexNum - 1) break;
            
            int parent1 = find(edges[i].second.first);
            int parent2 = find(edges[i].second.second);

            // 
            // These two are already connected.

            if (parent1 == parent2) continue;

            //
            // Connect these two elements, and add
            // this edge to the adj list for edges.
            unionElements(parent1, parent2);
            ++mstsConnectedEdges;
            
            //
            // Add an edge to both of these elements in the
            // adjList that countains the mst's
            if (!mstsAdjList.count(edges[i].second.first)) mstsAdjList[edges[i].second.first] = vector<ii>();
            mstsAdjList[edges[i].second.first].push_back({edges[i].first, edges[i].second.second});

            if (!mstsAdjList.count(edges[i].second.second)) mstsAdjList[edges[i].second.second] = vector<ii>();
            mstsAdjList[edges[i].second.second].push_back({edges[i].first, edges[i].second.first});
        }

        cout << "Case #" << idx << "\n";
        for (int i = 0; i < queryNum; ++i){
            int a, b;
            cin >> a >> b;
            --a;  // 0 indexed..
            --b;  // 0 indexed..
        
            //
            // If we are not connected, we are done.
            if (find(a) != find(b)){
                cout << "no path" << "\n";
                continue;
            }

            //
            // We are connected, so we need to find the shortest path.
            // We can do this with a BFS...
            queue<ii> q;
            q.push({0, a});
            vector<bool> visited(vertexNum, false);
            visited[a] = true;
            while (!q.empty()){
                ii curr = q.front();
                q.pop();
                if (curr.second == b){
                    cout << curr.first << "\n";
                    break;
                }
                for (ii neighbor : mstsAdjList[curr.second]){
                    if (!visited[neighbor.second]){
                        visited[neighbor.second] = true;
                        //
                        // Keep track of the max weight seen in each path...
                        int maxSeenWeight = max(curr.first, neighbor.first);
                        q.push({maxSeenWeight, neighbor.second});
                    }
                }
            }
        }
        idx++;
    }
    
    return 0;
}

