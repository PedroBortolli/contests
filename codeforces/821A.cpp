#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[55][55];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int z = v[i][j];
			if (z == 1) continue;
			int ok = 0;
			for (int k = 0; k < n && !ok; k++) {
				if (k == i) continue;
				int x = v[k][j];
				for (int l = 0; l < n && !ok; l++) {
					if (l == j) continue;
					int y = v[i][l];
					if (x+y == z) ok = 1;
				}
			}
			if (!ok) {
				printf("No\n");
				return 0;
			}
		}
	}

	printf("Yes\n");
	return 0;
}