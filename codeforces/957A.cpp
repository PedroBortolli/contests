#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[105];
ll dp[105][505];
int n;

bool check(ll i, ll p) {
	if (s[i] == p) return 1;
	if (i < n-1) if (s[i] == s[i+1] && s[i] != '?') return 1;
	if (i > 0) if (s[i] == s[i-1] && s[i] != '?') return 1;
	return 0;
}

ll go(ll id, ll prev) {
	if (dp[id][prev] != -1) return dp[id][prev];
	//printf("Olhando pra %lld com prev = %lld\n", id, prev);
	if (id >= n) return 1;
	if (check(id, prev)) return 0; 
	ll ans = 0;
	if (id == 0 && s[id] == '?') {
		ans += go(id+1, 'C');
		ans += go(id+1, 'M');
		ans += go(id+1, 'Y');
	}
	else if (s[id] == '?') {
		if (prev == 'C') {
			ans += go(id+1, 'M');
			ans += go(id+1, 'Y');
		}
		else if (prev == 'M') {
			ans += go(id+1, 'C');
			ans += go(id+1, 'Y');
		}
		else if (prev == 'Y') {
			ans += go(id+1, 'C');
			ans += go(id+1, 'M');
		}
	}
	else ans = go(id+1, s[id]);
	return dp[id][prev] = ans;
}


int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	memset(dp, -1, sizeof(dp));
	ll x = go(0, 0);
	if (x >= 2) printf("Yes\n");
	else printf("No\n");
	return 0;
}