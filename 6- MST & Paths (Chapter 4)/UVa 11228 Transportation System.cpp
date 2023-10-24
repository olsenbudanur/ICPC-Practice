#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


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
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t){
        int n; 
        double r;
        cin >> n >> r;

        //
        // Add all the coordinates to curr vector.
        parents.resize(n);
        vector<pair<int, int>> coordinates(n);
        for (int i = 0; i < n; ++i){
            //
            // every element starts off as being its own parent/cluster
            parents[i] = i;
            cin >> coordinates[i].first >> coordinates[i].second;
        }

        //
        // There is an edge between each vertex.
        // These edges have a weight, and we want to
        // sort these edges by their weight for Kruskal's algorithm.
        // So, we create a DS such that:
        //        (edge_weight, (vertex1, vertex2))
        // where 
        //         edge_weight = distance(vertex1, vertex2)
        vector<pair<double, pair<int, int>>> edges;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                double xDiff = (double)coordinates[i].first - (double)coordinates[j].first;
                double yDiff = (double)coordinates[i].second - (double)coordinates[j].second;
                xDiff *= xDiff;
                yDiff *= yDiff;
                double distance = sqrt(xDiff + yDiff);
                edges.push_back(make_pair(distance, make_pair(i, j)));
            }
        }

        //
        // Sort the edges by weight.
        sort(edges.begin(), edges.end(), [](const pair<double, pair<int, int>> lhs, const pair<double, pair<int, int>> rhs) {
            return lhs.first < rhs.first;
        });

        double railroadLen = 0;
        double roadLen = 0;

        int stateNum = 1; // idk if we start from 1
        int connectedCities = 0;

        //
        // Now, find the MST...
        for (int i = 0; i < edges.size(); ++i){
            pair<double, pair<int, int>> currEdge = edges[i];

            double distance = currEdge.first;
            int element1 = currEdge.second.first;
            int element2 = currEdge.second.second;

            int parent1 = find(element1);
            int parent2 = find(element2);

            //
            // If these two nodes are already in a cluster/
            // already connected, this edge is redundant. Don't
            // consider adding it. 
            if (parent1 == parent2) continue;

            //
            // Join the clusters
            unionElements(parent1, parent2);
            connectedCities++;
        
            //
            // If the distance is greater than what it takes
            // to be a state, make this a railroad.
            if (distance > r){
                ++stateNum; 
                railroadLen += distance;
            }
            else {
                roadLen += distance;
            }

            //
            // If all cities are connected, stop
            // adding new roads.
            if (connectedCities == n - 1) break;
        }

        cout << "Case #" << t << ": " << stateNum << " " << (int)round(roadLen) << " " << (int)round(railroadLen) << "\n";   
    }
    return 0;
}

