#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;
#define INF 1e7


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int ascii;
    string curr;
    while (cin >> curr){
        for (int i = 0; i < curr.length(); ++i){
            ascii = (int) curr[i]; // Convert to ascii
            ascii -= 7; // Subtract 7 from the ascii value, questions "secret formula"
            cout << (char) ascii; // Convert back to char and print
        }
        cout << "\n";
    }

    return 0;
}

