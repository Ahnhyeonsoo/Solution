#include <iostream>
#include <string>

using namespace std;

int rev(unsigned short n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

int main() {
	unsigned short n;
	cin >> n;
	cout << rev(n) << endl;
}