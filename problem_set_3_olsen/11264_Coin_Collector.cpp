#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //


    int T;
    cin >> T;
    ++T;

    int n;
    while (--T){
        cin >> n;


        int nums[n];
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int coins = n > 1 ? 2 : 1;
        int sum = nums[0];

        for (int i = 1; i < n - 1; i++){
            if (nums[i] + sum < nums[i+1]){
                sum += nums[i];
                ++coins;
            }
        }


        cout << coins << "\n";
    }


    return 0;
}
