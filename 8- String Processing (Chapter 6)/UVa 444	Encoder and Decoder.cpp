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

    int ascii, idx;
    string curr, answ;
    while (getline(cin, curr)){
        answ = "";
        //
        // If it's digit, we reverse ascii. Else, we convert to ascii.
        if (isdigit(curr[0])){
            //
            // Re-reverse the string lol.
            reverse(curr.begin(), curr.end());

            idx = 0;
            while (idx < curr.length()){
                //
                // If it starts with 1, we have to check the next two digits.
                ascii = 0;
                if (curr[idx] == '1'){
                    for (int i = 0; i < 3; i++){
                        //
                        // Convert the next three digits to ascii.
                        ascii = ascii * 10 + (curr[idx] - '0');
                        ++idx;
                    }
                    answ += (char) ascii;
                }
                else {
                    for (int i = 0; i < 2; i++){
                        //
                        // Convert the next two digits to ascii.
                        ascii = ascii * 10 + (curr[idx] - '0');
                        ++idx;
                    }
                    answ += (char) ascii;
                }
            }
            
        }
        else {
            //
            // Convert to ASCII, and add to the answer string.
            for (int i = 0; i < curr.length(); i++){
                ascii = (int) curr[i];
                answ += to_string(ascii);
            }
            //
            // Reverse answ string.
            reverse(answ.begin(), answ.end());
        }
        cout << answ << "\n";
    }


    return 0;
}

