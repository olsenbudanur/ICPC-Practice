#include <iostream>

using namespace std;

int main(){
    int a, b, c, d;
    int curr;
    while(1){
        cin >> a >> b >>  c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        curr = 1080 + ((a - b + 40) % 40 + (c - b + 40) % 40 + (c - d + 40) % 40) * 9;
        cout << curr << "\n";

    }
    
    return 0;
}
