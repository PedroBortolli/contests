#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[10005];
int main() {
	int n, m, l, r, x;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &l, &r, &x);
		int cont = 0;
		for (int j = l; j <= r; j++)
			if (v[j] < v[x]) cont++;
		if (x-l == cont) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}