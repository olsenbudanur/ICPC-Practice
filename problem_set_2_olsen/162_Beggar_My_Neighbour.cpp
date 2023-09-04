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
    // Face card values.
    unordered_map<char, int> faceCards;
    faceCards['J'] = 1;
    faceCards['Q'] = 2;
    faceCards['K'] = 3;
    faceCards['A'] = 4;

    
    //
    // There can be multiple games...
    while (1){
        //
        // Distribute the cards to the players.
        int turn = 0;
        string curr;
        vector<deque<int>> players(2);

        //
        // Read the cards for this game.
        for (int i = 0; i < 52; i++, turn = !turn){
            //
            // Read from stdin
            cin >> curr;
            //
            // If we see #, then we are at the end of the input.
            if (curr[0] == '#') return 0;

            //
            // If this card is a face card...
            if (faceCards.count(curr[1])){
                players[turn].push_front(faceCards[curr[1]]);
            }
            else {
                players[turn].push_front(0);
            }
        }

        //
        // Init the var for table, and keep track of if game is done.
        // ps: turn should be 0 at this point, players turn.
        list<int> table; // The table
        bool done = true; // if the game is done... Assume done unless otherwise.

        //
        // Until one of the players is empty...
        while (!players[turn].empty()){
            //
            // Pop from the current player, add to the table.
            int currCardVal = players[turn].front();
            players[turn].pop_front();
            table.push_back(currCardVal);

            //
            // Pass the turn over.
            turn = !turn;

            //
            // While the card is a faceval...
            while (currCardVal--){
                // 
                // If the current player ran out of cards, we are done...
                if (players[turn].empty()) {
                    done = true;
                    break;
                } else {
                    done = false;
                }

                //
                // Take the card, put it into game.
                int potentialCardVal = players[turn].front();
                players[turn].pop_front();
                table.push_back(potentialCardVal);

                //
                // If this card is a face card...
                if (potentialCardVal){
                    turn = !turn;
                    currCardVal = potentialCardVal;
                }
            }

            //
            // If we are not done, add the cards to the winner of
            // the face-off :D
            if (!done){
                done = true; // assume done unless otherwise proven. #TODO fix this logic
                turn = !turn; // Switch to the winner.
                while (!table.empty()){
                    int currCard = table.front();
                    table.pop_front();
                    players[turn].push_back(currCard);
                }
            }


        }

        if (players[0].empty()){
            cout << "1 ";
            if (players[1].size() < 10) cout << " "; // dumb io requirement by the question.
            cout << players[1].size();
            cout << "\n";
        }
        else {
            cout << "2 ";
            if (players[0].size() < 10) cout << " "; // dumb io requirement by the question.
            cout << players[0].size();
            cout << "\n";
        }


    }


    return 0;
}
