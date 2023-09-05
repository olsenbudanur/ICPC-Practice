#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char s[200];

    bool open = true;

    while (cin.getline(s, 200)){
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '"'){
                if (open){
                    cout << "``";
                }
                else{
                    cout << "''";
                }
                open = !open;
            }
            else{
                cout << s[i];
            }
        }
        cout << endl;
    }

	return 0;
}