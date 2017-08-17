#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005], ans[100005];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		int aux = 0;
		if (v[i]%k != 0) aux++;
		aux += (v[i]/k);
		ans[i] = aux;
	}

	ll anss = 0;
	for (int i = 0; i < n; i++) {
		//printf("%d\n", ans[i]);
		anss += ans[i];
	}

	printf("%lld\n", anss/2ll + anss%2ll);
	return 0;
}