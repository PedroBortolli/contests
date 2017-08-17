#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1000005], t[1000005];
int mp[222];
multiset <char> st;
int main() {
	int ava = 0;
	scanf(" %s", s);
	scanf(" %s", t);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') ava++;
		else mp[s[i]]++;
	}
	int len = strlen(t);
	int k = 0;
	while (1) {
		char need = t[(k++)%len];
		if (mp[need] > 0) mp[need]--;
		else {
			if (ava > 0) {
				ava--;
				st.insert(need);
			}
			else break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (st.empty()) printf("a");
			else {
				char x = *(st.begin());
				printf("%c", x);
				st.erase(st.find(x));
			}
		}
		else printf("%c", s[i]);
	}
	return 0;
}