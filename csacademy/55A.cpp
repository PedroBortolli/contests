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
	int n, m, l, r;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		int cont = 0;
		for (int j = 0; j < m; j++) {
			if (v[j] >= l && v[j] <= r) cont++;
		}
		printf("%d\n", cont);
	}

	return 0;
}