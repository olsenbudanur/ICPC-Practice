#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


vector<vector<int>> dirs = {
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
};

int dfsSink(vector<string> &graph, int i, int j){ // make sure to pass by pointer
    //
    // If out of bounds, or land return 0.
    if (i >= graph.size() || i < 0 || j < 0 || j >= graph[0].size() || graph[i][j] == '1') return 0;
    //
    // Set this to visited.
    graph[i][j] = '1';
    //
    // Recursively find all neighbors.
    int answ = 1;
    for (vector<int> dir : dirs){
        answ += dfsSink(graph, i + dir[0], j + dir[1]);
    }
    return answ;
}

int main(){
    //
    // IO Speed optimizations
    // It is really hard to do without using
    // stdio for this question....
    // ios_base::sync_with_stdio(0);
	// cin.tie(0);
    //

    
    int datasets, i, j;
    datasets = 0;
    cin >> datasets;


    while (datasets--){
        cin >> i >> j;
        --i;
        --j;
        getchar(); // might not work without synch_stdio

        vector<string> graph;

        while (true){
            string line;
            getline(cin, line);
            if (line == "") break;
            graph.push_back(line);
            
            
        }

        cout << dfsSink(graph, i, j) << "\n";
        if (datasets) cout << "\n";
    }
    
    return 0;
}

