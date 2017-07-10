#include <bits/stdc++.h>

#include <iostream>
using namespace std;
string s;
int main() {
	cin >> s;
	s = "." + s + "."; // Pad with periods for convenience.
	while (true) {
		int i = s.find(".Frankenstein.");
		if (i == string::npos) break; // No more occurences found.
		s = s.substr(0, i) + ".Frankenstein's.monster." + s.substr(i + 14);
	}
	// Output the string with the padded periods removed.
	cout << s.substr(1, s.length() - 2) << endl;
	return 0;
}