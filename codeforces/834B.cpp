#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1000005];
set <int> st[111];
map <char, int> need;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	scanf(" %s", s);
	for (int i = 0; i < n; i++) {
		st[s[i]].insert(i);
	}

	need[s[0]] = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		char prev = s[i-1];
		if (s[i] == prev) continue;
		if (st[prev].upper_bound(i) != st[prev].end()) need[s[i]] = 1;
		int cont = 0;
		for (char cc = 'A'; cc <= 'Z'; cc++) {
			if (need[cc] == 1) cont++;
		}
		ans = max(ans, cont);
		if (st[s[i]].upper_bound(i) == st[s[i]].end()) need[s[i]] = 0;
	}

	if (ans <= k) printf("NO\n");
	else printf("YES\n");
	return 0;
}