#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

int bounce(int value){
    switch (value){
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            return -1;
    }
}

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //


    int m, n, wall_cost, num_bumpers;
    cin >> m >> n >> wall_cost >> num_bumpers;  
    
    //
    // "num_bumpers" num of Bumpers with x position, y position, value, and cost.
    vector<array<int, 4>> bumpers;
    for (int i = 0; i < num_bumpers; i++){
        int x, y, v, c;
        cin >> x >> y >> v >> c;
        array<int, 4> bump = {x, y, v, c};
        bumpers.push_back(bump);
    }    

    //
    // Balls, the initial x and y position of the ball, the direction of movement, and its lifetime
    // Directions: 
    // 0 for increasing x (right), 1 for increasing y (up), 2 for decreasing x (left), and 3 for decreasing y (down)
    // Create a list of balls. Last element is the score of the balls.
    vector<array<int, 5>> balls;
    int bx, by, bd, bl;
    while (cin >> bx >> by >> bd >> bl){
        array<int, 5> ball = {bx, by, bd, bl, 0};
        balls.push_back(ball);
    }

    //
    // Lights go out every iteration.
    // If ball alive, it turns the lights back on :D
    bool lights = true;

    while (lights){
        lights = false;
        //
        // Tick for every ball.
        for (array<int, 5> ball : balls){
            //
            // 0: x
            // 1: y
            // 2: dir
            // 3: life
            // 4: score

            //
            // If ball dead, move on.
            if (!ball[3]) continue;

            //
            // Take one life off for this iteration.
            ball[3] -= 1;

            //
            // Move the ball.
            switch (ball[2]){
                case 0:
                    ball[0] += 1;
                    break;
                case 1:
                    ball[1] += 1;
                    break;
                case 2:
                    ball[0] -= 1;
                    break;
                case 3:
                    ball[1] -= 1;
                    break;
            }

            //
            // Check if the ball hit a wall.
            if (ball[0] < 0){ // left wall
                ball[0] = 0;
                ball[2] = bounce(ball[2]);
                if (ball[3]) ball[3] -= wall_cost;
                continue;
            }
            else if (ball[0] == m){ // right wall
                ball[0] = m - 1;
                ball[2] = bounce(ball[2]);
                if (ball[3]) ball[3] -= wall_cost;
                continue;
            }
            else if (ball[1] < 0){ // bottom wall
                ball[1] = 0;
                ball[2] = bounce(ball[2]);
                if (ball[3]) ball[3] -= wall_cost;
                continue;
            } 
            else if (ball[1] == n){ // top wall
                ball[1] = n - 1;
                ball[2] = bounce(ball[2]);
                if (ball[3]) ball[3] -= wall_cost;
                continue;
            }

            //
            // Check if the wall hit a bumper.
            // This could be O(1) lookup but whatever
            for (array<int, 4> bumper : bumpers){
                //
                // We hit a bumper.
                if (bumper[0] == ball[0] && bumper[1] == ball[1]){
                    //
                    // Move the ball back, ball cannot overlap with bumper.
                    switch (ball[2]){
                        case 0:
                            ball[0] -= 1;
                            break;
                        case 1:
                            ball[1] -= 1;
                            break;
                        case 2:
                            ball[0] += 1;
                            break;
                        case 3:
                            ball[1] += 1;
                            break;
                    }

                    //
                    // Flip ball.
                    ball[2] = bounce(ball[2]);
                    
                    //
                    // If this isn't ball's last turn.
                    if (ball[3]){
                        ball[3] -= bumper[3];
                        ball[4] += bumper[2];
                    } 
                    break;
                }
            }

            //
            // Switch the lights on since the ball is still alive!
            if (ball[3] > 0) lights = true;


        }
    }



    //
    // Print out the scores of the balls.
    int total = 0;
    for (array<int, 5> ball : balls){
        cout << ball[4] << "\n";
        total += ball[4];
    }
    cout << total << "\n";


        
    return 0;
}
