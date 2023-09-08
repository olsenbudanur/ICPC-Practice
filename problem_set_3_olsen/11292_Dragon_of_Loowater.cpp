#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int headSize, knightSize, answ;
    cin >> headSize >> knightSize;

    while (1) {
        if (!headSize) break;
        
        int heads[headSize];
        int knights[knightSize];

        for (int i = 0; i < headSize; i++) cin >> heads[i];

        for (int i = 0; i < knightSize; i++) cin >> knights[i];

        if (headSize > knightSize){
            cout << "Loowater is doomed!" << "\n";
            cin >> headSize >> knightSize;
            continue;
        }

        sort(heads, heads + headSize);
        sort(knights, knights + knightSize);

        answ = 0;
        int i, j;
        i = 0; j = 0;
        while (i < knightSize && j < headSize){
            if (knights[i] >= heads[j]){
                answ += knights[i];
                ++j;
            }
            ++i;
        }
        
        //
        // Ran out of knights.
        if (i >= knightSize && j < headSize){
            cout << "Loowater is doomed!" << "\n";
        }
        else {
            cout << answ << "\n";
        }

        cin >> headSize >> knightSize;
    }

    
    return 0;
}