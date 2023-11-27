#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //


    int n, d, r, overtime;
    
    while (1){
        cin >> n >> d >> r;
        if (!n) break;
        int morning[n];
        int night[n];

        for (int i = 0; i < n; i++){
            cin >> morning[i];
        }
        for (int i = 0; i < n; i++){
            cin >> night[i];
        }

        sort(morning, n + morning);
        sort(night, n + night);

        overtime = 0;
        for (int i = 0; i < n; i++){
            int hrs = morning[i] + night[n - i - 1];
            hrs -= d;
            if (hrs > 0){
                overtime += hrs * r;
            }
        }

        cout << overtime << "\n";
    }

    
    return 0;
}