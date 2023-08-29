#include <iostream>

using namespace std;

int main(){
    //
    // Speed optimization
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int k;
    cin >> k;
    while (k--){
        string curr;
        cin >> curr;
        int len = curr.length();
        if (curr == "1" || curr == "4" || curr == "78") cout << "+\n";
        else if (curr[0] == '9' && curr[len - 1] == '4') cout << "*\n";
        else if (curr[len - 2] == '3' && curr[len - 1] == '5') cout << "-\n";
        else cout << "?\n";
    }
    
    return 0;
}
