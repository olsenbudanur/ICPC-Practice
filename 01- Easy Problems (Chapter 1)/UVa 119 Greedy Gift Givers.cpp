#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main(){
    //
    // Speed optimization
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //
    int curr_people;
    size_t first = 1;
    while (cin >> curr_people){
        if (first){
            first = 0;
            
        }
        else {
            cout << "\n";
        }
        unordered_map<string, int> accounts;
        vector<string> names;
        for (size_t i = 0; i < curr_people; i++){
            string name;
            cin >> name;
            names.push_back(name);
            accounts[name] = 0;
        }
        for (size_t i = 0; i < curr_people; i++){
            string name;
            int money;
            int num_given;
            cin >> name >> money >> num_given;
            if (num_given == 0) continue;

            //
            // Make sure we are dealing with integers.
            int pay_per = money / num_given;
            accounts[name] -= pay_per * num_given;
            
            string given_to;
            for (size_t j = 0; j < num_given; j++){
                
                cin >> given_to;
                accounts[given_to] += pay_per;
                
            }
        }

        for (size_t i = 0; i < curr_people; i++){
            cout << names[i] << " " << accounts[names[i]] << "\n";
        }

    }
    
    return 0;
}
