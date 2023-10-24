#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

char graph[101][101];

map<char, vector<int>> directionMove = {
    {'N', {-1, 0}},
    {'S', {1, 0}},
    {'L', {0, 1}},
    {'O', {0, -1}},
};

map<char, vector<char>> directionChange = {
    {'N', {'O', 'L'}},
    {'S', {'L', 'O'}},
    {'L', {'N', 'S'}},
    {'O', {'S', 'N'}},
};

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    
    int N, M, S, currRow, currCol, nextRow, nextCol;
    char currDirection;

    while (1){
        cin >> N >> M >> S;
        if (N == 0) break;

        
        //
        // Find starting point, populate the graph.
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                char curr;
                cin >> curr;
                graph[i][j] = curr;

                if (curr == 'N' || curr == 'S' || curr == 'L' || curr == 'O'){
                    currRow = i;
                    currCol = j;
                    currDirection = curr;
                }
            }
        }
        

        char currInstruction;
        int score = 0;
        for (int i = 0; i < S; i++){
            cin >> currInstruction;
            
            if (currInstruction == 'D'){
                //
                // Turn right
                currDirection = directionChange[currDirection][1];
                
            }
            else if (currInstruction == 'E'){
                //
                // Turn left
                currDirection = directionChange[currDirection][0];
            }
            else if (currInstruction == 'F'){
                //
                // Move 1 cell
                
                vector<int> dirs = directionMove[currDirection];
                nextRow = currRow + dirs[0];
                nextCol = currCol + dirs[1];
                    

                //
                // If we are out of bounds or wall...
                if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || graph[nextRow][nextCol] == '#'){
                    continue;
                }

                //
                // If we see a sticker, increase score and remove it.
                if (graph[nextRow][nextCol] == '*'){
                    graph[nextRow][nextCol] = '.';
                    score++;
                }

                currRow = nextRow;
                currCol = nextCol;
            }
        }

        cout << score << endl;
    }
    
    return 0;
}

