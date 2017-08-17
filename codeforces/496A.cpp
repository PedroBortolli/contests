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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	int ans = INT_MAX;
	for (int i = 1; i < n-1; i++) {
		int prev = 0;
		int mx = 0;
		for (int j = 1; j < n; j++) {
			if (j == i) continue;
			int aux = v[j]-v[prev];
			mx = max(aux, mx);
			prev = j;
		}
		ans = min(ans, mx);
	}

	printf("%d\n", ans);
	return 0;
}