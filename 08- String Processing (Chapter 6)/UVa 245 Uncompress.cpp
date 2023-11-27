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
    string buffer, curr;
    vector<string> words;

    while (1){
        getline(cin, buffer);
        //
        // If we are at the end of the input, break
        if (buffer[0] == '0') break;
        for (int i = 0; i < buffer.length(); i++){
            //
            // If this is a regular character, we print it and add it to word list.
            if (isalpha(buffer[i])){ 
                curr = "";
                while (isalpha(buffer[i])) {
                    curr += buffer[i];
                    ++i;
                } --i; // We need to decrement i because we incremented it one too many times.
                
                //
                // Add the word to the word list, and print it.
                words.push_back(curr);
                cout << curr;
            }
            //
            // If this is a digit, we print the word at the index of the digit. 
            else if (isdigit(buffer[i])){
                int idx = 0;
                while (isdigit(buffer[i])){
                    idx = idx * 10 + (buffer[i] - '0');
                    ++i;
                } --i; // We need to decrement i because we incremented it one too many times.

                //
                // If the index is greater than the size of the word list, we just print the last word.
                curr = words[words.size() - idx];

                //
                // Remove the word at the index of the digit, and add the current word to the end of the list.
                words.erase(words.end() - idx);
                words.push_back(curr);
                cout << curr;
            }
            //
            // If not a digit, we just print it.
            else {
                cout << buffer[i];
            }
        }
        cout << "\n";
    }

    return 0;
}

