#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[105];
int main() {
	int n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v, v+n);
	int cont = 0;
	for (int i = n-1; i >= 0; i--) {
		v[i] = x;
		cont++;
		if (cont == k) break;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += v[i];
	}
	printf("%d\n", ans);
	return 0;
}