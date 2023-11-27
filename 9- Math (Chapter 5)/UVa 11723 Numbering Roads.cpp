#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;
#define INF 1e7

#define SUFFIX_NUMBER 26


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    //
    // T: Current test case
    // R: Number of roads
    // N: Number of integers allocated 
    int T, R, N; 
    T = 1;
    while (cin >> R >> N){
        if (R-- == 0 && N == 0) break; // End of input (cheeky substraction from R :D)
        //
        // If the number of roads divided by the number of integers allocated is greater than 26, 
        // then it is impossible to allocate the integers
        if (R / N > SUFFIX_NUMBER){
            cout << "Case " << T << ": impossible\n";
        } else {
            cout << "Case " << T << ": " << (R / N) << "\n";
        }
        ++T;
    }



    return 0;
}

