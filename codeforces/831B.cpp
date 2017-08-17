#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s1[1111];
char s2[1111];
char s[1111];
map <char, char> mp;
int main() {
	scanf(" %s", s1);
	scanf(" %s", s2);
	int n = strlen(s1);

	for (int i = 0; i < n; i++) {
		mp[s1[i]] = s2[i];
	}


	scanf(" %s", s);
	n = strlen(s);

	int ok;
	for (int i = 0; i < n; i++) {
		char c = s[i];
		char temp = c;
		c = tolower(c);
		if (mp.find(c) == mp.end()) {
			printf("%c", c);
			continue;
		}
		if (temp == c) ok = 0;
		else ok = 1;
		if (ok) printf("%c", toupper(mp[c]));
		else printf("%c", mp[c]);
		//printf("%c", mp[s[i]]);
		
	}

	return 0;
}