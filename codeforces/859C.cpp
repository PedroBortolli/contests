#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pii dp[55][2];
int v[55], n;

pii go(int id, int t) {
	if (id == n) return {0,0};
	if (dp[id][t].first != -1) return dp[id][t];
	if (t == 0) {
		pii a = {v[id]+go(id+1, 1).first, go(id+1, 1).second};
		pii b = {go(id+1, 0).first, v[id]+go(id+1, 0).second};
		if (a.first >= b.first) return dp[id][t] = a;
		else return dp[id][t] = b;
	}
	else {
		pii a = {go(id+1, 0).first, v[id]+go(id+1, 0).second};
		pii b = {v[id]+go(id+1, 1).first, go(id+1, 1).second};
		if (a.second >= b.second) return dp[id][t] = a;
		else return dp[id][t] = b;	
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d %d\n", go(0, 0).second, go(0, 0).first);
	return 0;
}