#include <iostream>

using namespace std;

int main(){
    char c;
    bool first = true;

    while (cin.get(c)){
        if (c == '"'){
            if (first){
                cout << '`' << '`';
                first = false;
            }
            else {
                cout << '\'' << '\'';
                first = true;
            }
        }
        else {
            cout << c;
        }
        
    }
    
    return 0;
}
