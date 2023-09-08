#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include "../stdc++.h" // Compilation time is not counted. So why bother writing all the imports?
// #include <bits/stdc++.h>
using namespace std;

int bounce(int value){
    switch (value){
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return -1;
    }
}

const int NumMoves = 4;
int xChange[] = {1, 0, -1, 0};
int yChange[] = {0, 1, 0, -1};

const int MaxGridSize = 52;

// All are indexed [y][x]
bool hasBumper[MaxGridSize][MaxGridSize];
int bumperCost[MaxGridSize][MaxGridSize];
int bumperScore[MaxGridSize][MaxGridSize];


int main(){

    int m, n;
    cin >> m >> n;
    int wallCost, numBumper;
    cin >> wallCost >> numBumper;


    for (int y = 0; y < n; y++)
    {
        for (int x  = 0; x < m; x++)
            hasBumper[x][y] = false;
    }

    while (numBumper--){
        int bump_x, bump_y;
        cin >> bump_x >> bump_y;
        // switch to 0 index
        bump_x--;
        bump_y--;
        // store bumper location, score, and cost
        hasBumper[bump_x][bump_y] = true;
        cin >> bumperScore[bump_x][bump_y] >> bumperCost[bump_x][bump_y];
    }
    int overallScore = 0;

    int ball_x, ball_y, dir, ball_life;

    while (cin >> ball_x >> ball_y >> dir >> ball_life){
        // switch to 0 index
        ball_x--;
        ball_y--;
        int ball_score = 0;

        // move while life-1 is positive
        while (ball_life > 1){
            int new_x = ball_x + xChange[dir];
            int new_y = ball_y + yChange[dir];

            // if hitting a wall
            // cout << "From " << ball_x + 1 << ' ' << ball_y + 1<< " attempting " << new_x + 1<< ' ' << new_y+ 1 << " with " << ball_life << '\n';
            if (new_x <= 0 || new_x >= m - 1 || new_y <= 0 || new_y >= n-1){
                // turn right
                dir = bounce(dir);
                ball_life -= wallCost;
            } 
            // if htting a bumper
            else if (hasBumper[new_x][new_y]){
                dir = bounce(dir);
                // cout << "Hitting number at " << new_x + 1 << new_y +1 << " Score " << bumperScore[new_x][new_y] << '\n';
                ball_score += bumperScore[new_x][new_y];
                ball_life -= bumperCost[new_x][new_y];
            }
            // didn't hit anything
            else{
                ball_x = new_x;
                ball_y = new_y;
            }

            ball_life--;
        }
        cout << ball_score << endl;
        overallScore += ball_score;
    }
    cout << overallScore << '\n';

}