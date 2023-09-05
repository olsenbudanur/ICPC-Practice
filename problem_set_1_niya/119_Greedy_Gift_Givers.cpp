#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
    size_t curr_num = 1;

    int curr_N;
    while (cin >> curr_N){
        map<string, int> balance;
        vector<string> names;

        // initialize map for everyone
        // size_t object is guaranteed to be big enough for sizes, and takes less space than int
        for (size_t i = 0; i < curr_N; i++){
            string name;
            // cin stops reading when it sees a space
            cin >> name;
            balance[name] = 0;
            // add name to back of vector, vector::insert allows insertion at specific position in the vector
            names.push_back(name);
        }
        for (size_t i = 0; i < curr_N; i++){
            string name;
            cin >> name;
            int spent, nPeople;
            cin >> spent;
            cin >> nPeople;

            if (nPeople == 0){
                continue;
            }
            
            int moneyperperson = spent / nPeople;
            balance[name] -= moneyperperson * nPeople;

            string fr;
            for (size_t j = 0; j < nPeople; j++){
                cin >> fr;
                balance[fr] += moneyperperson;
            }
        }

        // The output for each group should be separated from other groups by a blank line.
        if (curr_num > 1){
            cout << endl;
        }
        curr_num ++;
        for( size_t i = 0; i < curr_N; i++){
            cout << names[i] << " " << balance[names[i]] << endl;
        }
    }
}