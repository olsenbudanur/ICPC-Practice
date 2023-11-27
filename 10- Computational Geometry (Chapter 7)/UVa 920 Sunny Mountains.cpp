#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;
#define INF 1e7


//
// point struct for 2D points
struct Point{
    double x, y;
};

//
// Euclidean distance 
// sqrt((x1 - x2)^2 + (y1 - y2)^2)
double dist(Point p1, Point p2){
    double a = p1.x - p2.x;
    double b = p1.y - p2.y;
    return sqrt((a * a) + (b * b));
}


//
// Given a line from p1 to p2, and a y coordinate, calculate the x coordinate on the line.
double calculateXGivenY(double y, Point p1, Point p2) {
    return p1.x + ((y - p1.y) * (p2.x - p1.x)) / (p2.y - p1.y);
}

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int T, N;
    cin >> T;
    
    while(T--){
        cin >> N;
        vector<Point> points;
        //
        // Read all the points
        for (int i = 0; i < N; ++i){
            Point p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }

        //
        // Sort the points by x coordinate
        sort(points.begin(), points.end(), [](Point p1, Point p2){
            return p2.x < p1.x;
        });

        /** 
         * Illustration credits:
         * https://github.com/ajahuang/UVa/blob/master/UVa%20920%20-%20Sunny%20Mountains.cpp
         * Credits to: ajahuang
         * 
           points[i].y
            \*
             \* ---  currentMaxY
              \
               \
               points[i - 1].y
        *
        * We are trying to find the length of the starred part of the line.
        */

        double maxY = 0;
        double totalLength = 0;
        for (int i = 1; i < points.size(); ++i){
            if (points[i].y > maxY){
                //
                // p2 is the point where the line intersects with the currentMaxY
                Point p2;
                p2.y = maxY;
                //
                // Calculate the x coordinate of p2
                p2.x = calculateXGivenY(maxY, points[i], points[i - 1]);

                //
                // The sun will shine on the line segment from p2 to points[i]
                totalLength += dist(points[i], p2);
                maxY = points[i].y; 
            }
        }

        cout << fixed << setprecision(2) << totalLength << "\n";
    }

    return 0;
}

