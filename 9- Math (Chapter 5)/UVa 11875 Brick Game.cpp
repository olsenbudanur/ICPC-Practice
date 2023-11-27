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

    int T, n, curr;
    cin >> T; // T is the number of test cases
    for (int i = 1; i <= T; ++i){
        cin >> n; // n is the number of numbers in the test case
        curr = -1; // curr is the current number, initialized to -1 (just in case)
        for (int j = 0; j < n; ++j){
            //
            // Once we reach the middle, we have our answer!
            cin >> curr;
            if (j == (n / 2)) cout << "Case " << i << ": " << curr << "\n"; 
        }
    }

    return 0;
}

