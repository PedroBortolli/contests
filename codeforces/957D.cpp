#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll ans = 0;
	for (int i = 1; i < n-1; i++) {
		if (v[i] < v[i-1]) ans += (v[i+1]-1);
	}

	printf("%lld\n", ans);
	return 0;
}