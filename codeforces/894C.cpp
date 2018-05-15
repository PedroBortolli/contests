#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[1005], mp[1000005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		mp[v[i]] = 1;
	}

	int ok = 1;
	for (int i = 0; i < n; i++) {
		int g = v[i];
		for (int j = i; j < n; j++) {
			g = __gcd(g, v[j]);
			if (!mp[g]) ok = 0;
		}
	}

	if (!ok) printf("-1\n");
	else {
		printf("%d\n", n);
		for (int i = 0; i < n; i++)
			printf("%d ", v[i]);
		printf("\n");
	}
	return 0;
}