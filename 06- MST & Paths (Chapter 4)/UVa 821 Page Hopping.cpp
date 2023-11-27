#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

//
// shortcut for a pair...
typedef pair<int, int>  ii; 

//
// INF based on the number of vertecies in the graph.
// Calculated by using the number of vertecies where the max number of edges is
// n * (n - 1) / 2. This is the max number of edges in a complete graph.
// n = 100, so 100 * 99 / 2 = 4950. So INF = 4950 + 1 = 4951.
const static int INF = 5000;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    
    //
    // Test case number.
    int t = 1;

    while (1){
        int x, y;
        cin >> x >> y;
        //
        // End of input
        if (!x && !y) break;
        //
        // Reset the graph
        vector<ii> edges;
        set<int> vertecies;
        //
        // n is the max vertex number... 
        // shouldn't need this if we use a array of arrays of size max_vertex x max_vertex.
        int n = 0;

        //
        // Read the edges and populate the graph.
        while (x && y){
            n = max(n, max(x, y));
            --x;
            --y;
            edges.push_back({x, y});
            cin >> x >> y;
            //
            // Realized this is redundant...
            // vertecies.insert(x);
            // vertecies.insert(y);
        }

        //
        // Create the adjacency matrix with INF as default and 
        // n x n size. It is smarter to init a array of arrays of size 
        // max_vertex x max_vertex, but this made more intuitive sense to me.
        // Still, we should array of arrays of size max_vertex x max_vertex for this.
        vector<vector<int>> adjMat(n, std::vector<int>(n, INF)); 

        //
        // Populate the adjacency matrix with the edges, also self loops are 0.
        for (int i = 0; i < n; ++i) adjMat[i][i] = 0; 
        for (int i = 0; i < edges.size(); ++i) adjMat[edges[i].first][edges[i].second] = 1;

        //
        // The Floyd-Warshall algorithm... 
        // Only works on small graphs with < 400 nodes. O(n^3) runtime.
        // Otherwise use Dijkstra's algorithm. O(n^2 log n) runtime.
        // (There is a modified version of Dijkstra's algorithm that is compatible with negative weights!)
        for (int k = 0; k < n; k++) 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);


        //
        // Count the number of paths, and sum the lengths of the paths.
        double count = 0;
        double sum = 0;
        for (int i = 0; i < n; ++i){
            // if (vertecies.count(i) == 0) continue; // if vertex is not in the graph, skip it.
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                // if (vertecies.count(j) == 0) continue; // if either vertex is not in the graph, skip it.
                if (adjMat[i][j] == INF) continue; // if there is no path between the two, skip it.
                sum += adjMat[i][j];
                ++count;
            }
        }

        double avg = sum / count; // double / int should be double...
        cout << setprecision(3) << fixed; // remember this, or use printf...
        cout << "Case " << t << ": average length between pages = " << avg << " clicks\n";
        ++t;
    }
    
    return 0;
}

