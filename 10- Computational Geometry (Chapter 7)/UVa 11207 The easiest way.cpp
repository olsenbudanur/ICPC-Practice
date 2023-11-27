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

    int w, h, T;
    while (1){
        //
        // Get the number of paper per test case.
        cin >> T;
        if (!T) break; // if 0, we are done.
        int caseNum = 1;
        double currMax = 0;
        for (int i = 0; i < T; i++){
            cin >> w >> h; // Get the width and height of the paper.
            //
            // Method 1: 
            // 3 horizontal cuts to create 4 squares.
            double method1 = min(w * 1.0, h/4.0);
            //
            // Method 1.5:
            // Method 1, but the other way around.
            double method2 = min(w/4.0, h * 1.0);
            //
            // Method 2:
            // 1 horizontal 1 vertical cut to create 4 squares.
            double method3 = min(w/2.0, h/2.0);

            //
            // Current max of the three methods.
            double answ = max(method1, max(method2, method3));

            //
            // If the current max is greater than the previous max, update the max.
            if (answ > currMax){
                currMax = answ;
                caseNum = i + 1;
            }
        }
        cout << caseNum << "\n";
    }


    return 0;
}

