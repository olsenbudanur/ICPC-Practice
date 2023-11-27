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

    int T; // T is the number of test cases

    //
    // d: river width
    // v: river speed
    // u: boat speed
    double d, v, u, fastestTime, perpendicularTime, difference  ;
    cin >> T;
    for (int i = 1; i <= T; ++i){
        cin >> d >> v >> u;

        //
        // Explanation:
        // The boat can travel in any direction, so we need to find the time it takes to travel the distance of the river.
        fastestTime = d / u;
        //
        // Explanation:
        // The boat can only travel perpendicular to the river, so we need to find the time it takes to travel the distance of the river
        // perpendicular to the river. This is done by dividing the distance of the river by the speed of the boat perpendicular to the river.
        // sqrt(u * u - v * v) is the speed of the boat perpendicular to the river (Pythagorean theorem)
        perpendicularTime = d / sqrt(u * u - v * v);

        difference = abs(perpendicularTime - fastestTime);

        //
        // If the river speed is greater than or equal to the boat speed, then the boat can't cross the river.
        if (v >= u) {
            cout << "Case " << i << ": can't determine\n";
            continue;
        }

        //
        // If the times are equal, then the we can't determine the answer.
        if (fastestTime == perpendicularTime) {
            cout << "Case " << i << ": can't determine\n";
            continue;
        }

        cout << "Case " << i << ": " << fixed << setprecision(3) << difference << "\n";
    }



    return 0;
}

