#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int count;
    string s;
	    
	cin >> count;

	while(count) {
		cin >> s;

		int len = s.length();

		if (s == "1" || s == "4" || s == "78"){
			cout << "+" << endl;
		}

		else if (len >=2 && s.substr(len-2, 2) == "35"){
			cout << "-" << endl;
		}

		else if (s[0] == '9' && s[len-1] == '4'){
			cout << "*" << endl;
		}

		else if(len >= 3 && s.substr(0, 3) == "190"){
			cout << "?" << endl;
		}

		count--;
	}

	return 0;
}