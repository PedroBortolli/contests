#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <char, int> mp, got;
char s[111];
int main() {
	int n;
	char ch;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &ch);
		mp[ch]++;
	}

	scanf(" %s", s);
	int len = strlen(s);
	set <char> st;
	for (int i = 0; i < len; i++) {
		st.insert(s[i]);
		got[s[i]]++;
	}

	int ans = 0;
	for (auto a : st) {
		if (got[a] > mp[a]) ans += (got[a]-mp[a]);
	}

	printf("%d\n", ans);
	return 0;
}