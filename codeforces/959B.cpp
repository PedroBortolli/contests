#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[100005];
int v[100005], aux[100005], c[100005];
map <string, int> mp;
int main() {
	int n, k, m, x;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", s);
		string str = s;
		mp[str] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		int mn = INT_MAX;
		for (int j = 0; j < x; j++) {
			scanf("%d", &aux[j]);
			mn = min(mn, v[aux[j]-1]);
		}
		for (int j = 0; j < x; j++) {
			c[aux[j]-1] = mn;
		}
	}

	ll ans = 0;
	for (int i = 0; i < m; i++) {
		scanf(" %s", s);
		string str = s;
		ans += c[mp[str]];
	}

	printf("%lld\n", ans);
	return 0;
}