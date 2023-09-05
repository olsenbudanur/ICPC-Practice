#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

//
// Bouncing action, put in a function.
#define bounce(value) ((value + 3) % 4);

//
// Array for each movement, indexed by direction.
// 0 for increasing x (right), 1 for increasing y (up), 2 for decreasing x (left), and 3 for decreasing y (down)
int xMove[] = {1, 0, -1, 0};
int yMove[] = {0, 1, 0, -1};

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    //
    // Read the initial input.
    int m, n, wallCost, numBumpers;
    cin >> m >> n >> wallCost >> numBumpers;  
    
    //
    // Create a way to see if ball is on bumper, and the associeted values.
    bool bumpers[m][n];
    int bumperCost[m][n];
    int bumperValue[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            bumpers[i][j] = false;
            bumperCost[i][j] = 0;
            bumperValue[i][j] = 0;
        }
    }

    //
    // "num_bumpers" num of Bumpers with x position, y position, value, and cost.
    for (int i = 0; i < numBumpers; i++){
        int x, y, v, c;
        cin >> x >> y >> v >> c;
        //
        // We want to 0-index the coors.
        --x; --y;
        bumpers[x][y] = true;
        bumperCost[x][y] = c;
        bumperValue[x][y] = v;
    }    

    //
    // Balls, the initial x and y position of the ball, the direction of movement, and its lifetime
    int ballX, ballY, ballDir, ballLife;
    int totalScore = 0;
    //
    // Run for every ball.
    while (cin >> ballX >> ballY >> ballDir >> ballLife){
        //
        // We want to 0-index the coors.
        --ballX; --ballY;
        int ballScore = 0;
        while (--ballLife > 0){
            int newBallX = ballX + xMove[ballDir];
            int newBallY = ballY + yMove[ballDir];

            //
            // See if we hit a wall with this move.
            // The question says the walls are on the bounds, which was really misleading...
            if (newBallX == 0 || newBallY == 0 || newBallX == m - 1 || newBallY == n - 1){
                ballLife -= wallCost;
                ballDir = bounce(ballDir);
            }
            //
            // Or if we hit a bumper.
            else if (bumpers[newBallX][newBallY]){
                ballScore += bumperValue[newBallX][newBallY];
                ballLife -= bumperCost[newBallX][newBallY];
                ballDir = bounce(ballDir);
            }
            //
            // Otherwise, just move...
            else {
                ballX = newBallX;
                ballY = newBallY;
            }
        }
        totalScore += ballScore;
        cout << ballScore << "\n";
    }

    cout << totalScore << "\n";

    return 0;
}
