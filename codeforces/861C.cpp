#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[3005];

int vowel(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return 1;
	else return 0;
}

int main() {
	scanf(" %s", s);
	int n = strlen(s);
	int c = 0;
	set <char> st;
	for (int i = 0; i < n; i++) {
		if (vowel(s[i])) {
			st.clear();
			c = 0;
		}
		else {
			c++;
			st.insert(s[i]);
		}
		if (c >= 3) {
			if (st.size() > 1) {
				printf(" ");
				st.clear();
				st.insert(s[i]);
				c = 1;
			}	
		}
		printf("%c", s[i]);
	}
	return 0;
}