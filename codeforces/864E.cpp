#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

pair <pii, pii> v[105];
int n, dp[105][2005];
const int inf = 2e9+5;
vector <int> ans;

int go(int id, int el) {
	if (id == n) return 0;
	if (dp[id][el] != -1) return dp[id][el];
	int t = v[id].second.first, d = v[id].first.first, p = v[id].second.second;
	int a = go(id+1, el), b = -inf;
	if (el+t < d) b = p + go(id+1, el+t);
	if (b > a) return dp[id][el] = b;
	else return dp[id][el] = a;
}

void build(int id, int el) {
	if (id == n) return;
	if (dp[id][el] == dp[id+1][el] or el+v[id].second.first >= v[id].first.first) build(id+1, el);
	else {
		ans.pb(v[id].first.second);
		build(id+1, el + v[id].second.first);
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &v[i].second.first, &v[i].first.first, &v[i].second.second);
		v[i].first.second = i+1;
	}
	sort(v, v+n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
	build(0, 0);
	printf("%d\n", (int)ans.size());
	for (auto a : ans)
		printf("%d ", a);
	printf("\n");
	return 0;
}