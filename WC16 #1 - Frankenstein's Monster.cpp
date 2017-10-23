/*
Woburn Challenge 2016-17 Round 1 - Junior Division

Frankenstein's Monster

http://wcipeg.com/problem/wc161j2

Frank is upset. "Frankenstein is so big and scary, Frankenstein this, Frankenstein that", he thinks to himself. "Doesn't anyone know that Frankenstein is the name of the scientist, and who they're actually referring to is Frankenstein's monster!?".

He's determined to remedy the situation once and for all. How? It's quite simple. Since everyone derives their knowledge entirely from the internet, Frank will just have to find every occurrence of the word "Frankenstein" on every website, and replace it with "Frankenstein's monster". Problem solved!

For starters, Frank is tackling a Universal Pictures monster fanfiction site. He's downloaded the raw text of one particular story, a string with at most 1000 characters. For convenience, every space has been replaced with a period. As such, the string contains no whitespace, and consists of only lower/uppercase letters, digits, and common punctuation.

A "word" is a maximal consecutive sequence of non-period characters in the string. That is, each word is either preceded by a period or is at the start of the string. Similarly, each word is followed by a period or is at the end of the string. Frank wants to replace each instance of the word "Frankenstein" with the two words "Frankenstein's" "monster" (separated by a period). Frank distinguishes uppercase and lowercase letters, so he doesn't want to replace the word "frankenstein", for example.

Input Format

The first and only line of input consists of a single string representing the content of the story.

Output Format

Output a single line consisting of a single string representing the "corrected" story.

Sample Input

Frankenstein.rose.from.his.slab.to.confront.the.evil.Dracula..The.vampire.swung.at.Frankenstein's.face,.but.at.the.last.moment,.Frankenstein.was.shielded.from.the.blow.by.his.ally,.the.mummy.Imhotep.
Sample Output

Frankenstein's.monster.rose.from.his.slab.to.confront.the.evil.Dracula..The.vampire.swung.at.Frankenstein's.face,.but.at.the.last.moment,.Frankenstein's.monster.was.shielded.from.the.blow.by.his.ally,.the.mummy.Imhotep.


*/
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
