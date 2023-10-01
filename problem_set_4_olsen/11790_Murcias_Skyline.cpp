#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int T, N;
    cin >> T;

    for (int cases = 0; cases < T; cases++) {
        cin >> N;
        int heights[N], widths[N], dpIncreasing[N], dpDecreasing[N];
        for (int i = 0; i < N; i++) cin >> heights[i];
        for (int i = 0; i < N; i++) cin >> widths[i];
        for (int i = 0; i < N; i++){
            dpIncreasing[i] = widths[i];
            dpDecreasing[i] = widths[i];
        }

        for (int i = 0; i < N; i++){
            for (int j = i + 1; j < N; j++){
                //
                // Increasing
                if (heights[j] > heights[i] && dpIncreasing[j] < dpIncreasing[i] + widths[j]){
                    dpIncreasing[j] = dpIncreasing[i] + widths[j];
                }
                //
                // Decreasing
                if (heights[j] < heights[i] && dpDecreasing[j] < dpDecreasing[i] + widths[j]){
                    dpDecreasing[j] = dpDecreasing[i] + widths[j];
                }
            }
        }

        int decMax = 0, incMax = 0;
        for (int i = 0; i < N; i++){
            decMax = max(decMax, dpDecreasing[i]);
            incMax = max(incMax, dpIncreasing[i]);
        }


        if(decMax <= incMax)
            cout << "Case " << cases + 1 << ". Increasing (" << incMax << "). Decreasing (" << decMax << ").\n";
        else
            cout << "Case " << cases + 1 << ". Decreasing (" << decMax << "). Increasing (" << incMax << ").\n";
    }

    
    return 0;
}