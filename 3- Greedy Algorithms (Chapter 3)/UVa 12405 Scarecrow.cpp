#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int T, n, seenDot, answ;
    char curr;
    int temp;
    cin >> T;
    ++T;

    temp = T;
    
    while (--T){
        cin >> n;
        char field[n + 2];
        for (int i = 0; i < n; i++){
            cin >> curr;
            field[i] = curr;
        }

        answ = 0;
        for (int i = 0; i < n; i++){
            if (field[i] == '.'){
                field[i] = '#';
                field[i + 1] = '#';
                field[i + 2] = '#';
                ++answ;
            }
        }
            
        cout << "Case " << temp - T << ": " << answ << "\n";
    }

    return 0;
}