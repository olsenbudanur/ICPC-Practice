#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    //
    // Sigh, this fails since CPP doesn't have a BigInt class. 
    // Need to use Java for questions with ints larger than 64 bits
    // cust the CPP STD sux
    int curr, idx, negMin, posMax, answ, tmp;
    int nums[101];

    while (1){
        idx = 0;
        while (cin >> curr && curr != -999999) nums[idx++] = curr;
        if (!idx) break; // if we are done...
        negMin = posMax = answ = nums[0]; 
        for (int i = 1; i < idx; i++){
            curr = nums[i];
            tmp = posMax;
            posMax = max(curr, max(curr * tmp, curr * negMin));
            negMin = min(curr, min(curr * tmp, curr * negMin));
            answ = max(posMax, answ);
        }
        cout << answ << "\n";
    }

    
    return 0;
}