#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int T, N, M, budget;
    cin >> T;

    int num = 1;
    
    while (T--){
        int dp[N + 1][M + 1], curr;
        cin >> N >> M >> budget;

        //
        // Create a column sum DP
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= M; j++){
                cin >> curr;
                dp[i][j] = curr + dp[i - 1][j];
            }
        }
        
        //
        // Go over every single 4 points that create a rectangle
        int currCost, currArea, area = 0, cost = 0, c1;
        for (int r1 = 1; r1 <= N; r1++){
            for (int r2 = r1; r2 <= N; r2++){
                c1 = 1;
                currCost = 0;
                for (int c2 = 1; c2 <= M; c2++){
                    //
                    // Calculate the cost of the curr rectangle using the dp array.
                    currCost += dp[r2][c2] - dp[r1 - 1][c2];

                    //
                    // Take a row off every time when we are over budget.
                    while (budget < currCost && c1 <= c2){
                        currCost -= dp[r2][c1] - dp[r1 - 1][c1];
                        c1++;
                    }

                    //
                    // Update answer.
                    currArea = (r2-r1+1)*(c2-c1+1);
                    if (currArea > area || (currArea == area && currCost < cost)){
                        area = currArea;
                        cost = currCost;
                    }
                }
            }
        }
        cout << "Case #" << num << ": " << area << " " << cost << "\n";
        num++;
    }
    
    return 0;
}