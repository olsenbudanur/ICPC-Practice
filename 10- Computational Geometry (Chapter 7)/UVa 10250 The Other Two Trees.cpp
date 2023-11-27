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

    double x1, x2, y1, y2;
    double xMid, yMid;
    double x1ToMid, y1ToMid;
    double x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2){
        //
        // Finding midpoint between the two trees
        xMid = (x1 + x2) / 2.0;
        yMid = (y1 + y2) / 2.0;
        
        //
        // Distance between the midpoint and the first tree
        x1ToMid = xMid - x1;
        y1ToMid = yMid - y1;

        //
        // Coordinate of the third tree, using the distance between the midpoint and the first tree
        // Rotate the vector 90 degrees
        x3 = xMid - y1ToMid;
        y3 = yMid + x1ToMid;

        //
        // Coordinate of the fourth tree, using the distance between the midpoint and the first tree
        // Rotate the vector 90 degrees
        x4 = xMid + y1ToMid;
        y4 = yMid - x1ToMid;

        cout << fixed << setprecision(10) << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    }


    return 0;
}

