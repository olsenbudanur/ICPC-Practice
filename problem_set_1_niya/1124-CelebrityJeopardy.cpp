#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
	while(getline(cin, line)){
		printf("%s\n",line.c_str());
	}
	return 0;
}