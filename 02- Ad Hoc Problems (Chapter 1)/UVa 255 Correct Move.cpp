#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
#include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?

using namespace std;

void process_question(int king_state, int queen_state, int queen_move){
    //
    // king and queen same position
    if (king_state == queen_state) {
        cout << "Illegal state\n";
        return;
    }
    //
    // Move is not in same y or x axis as the queen.
    if ((queen_state / 8 != queen_move / 8 && (queen_move - queen_state) % 8 != 0) || queen_move == queen_state){
        cout << "Illegal move\n";
        return;
    }

    //
    // King and queen move are in the same y/y-axis
    if (((king_state - queen_state) % 8 == 0 && (king_state - queen_move) % 8 == 0) || (king_state / 8 == queen_state / 8 && king_state  / 8 == queen_move / 8)){
        //
        // If king_state is in the middle of queen and the move
        if (king_state >= min(queen_move, queen_state) && king_state <= max(queen_move, queen_state)){
            cout << "Illegal move\n";
            return;
        }
    }
    //
    // If the proposed move is in the king's boundaries
    int diff = max(king_state, queen_move) - min(king_state, queen_move);
        
    if (diff == 8 || (diff == 1 && king_state / 8 == queen_move / 8))
    {
        cout << "Move not allowed\n";
        return;
    }

    //
    // If the king can no longer move.
    if ((king_state == 0 && queen_move == 9) || (king_state == 7 && queen_move == 14) || (king_state == 56 && queen_move == 49) || (king_state == 63 && queen_move == 54)){
        cout << "Stop\n";
        return;
    }
    //
    // If it is okay.
    cout << "Continue\n";
}


int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    int king_state, queen_state, queen_move;
    while (cin >> king_state >> queen_state >> queen_move){
        process_question(king_state, queen_state, queen_move);
    }
    
    return 0;
}

