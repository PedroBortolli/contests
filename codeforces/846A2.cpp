#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[111], dp[111][3], n;

int go(int id, int prev) {
	if (id == n+1) return 0;
	if (dp[id][prev] != -1) return dp[id][prev];
	int ans = go(id+1, prev);
	if (prev != 1 && v[id] == 0) ans = max(ans, 1+go(id+1, v[id]));
	else if (v[id] == 1) ans = max(ans, 1+go(id+1, v[id]));
	return dp[id][prev] = ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, -1));
	return 0;
}