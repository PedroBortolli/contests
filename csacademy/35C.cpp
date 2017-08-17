#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[1005][1005];
int x[1005][1005];
int y[1005][1005];
int bany[1005];
int banx[1005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	int mx = 0;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += v[i][j];
		}
		for (int j = 0; j < n; j++) {
			x[i][j] = sum;
		}
		mx = max(mx, sum);
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += v[j][i];
		}
		for (int j = 0; j < n; j++) {
			y[j][i] = sum;
		}
		mx = max(mx, sum);
	}

	set <pair <int, pii>> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int aux = min(mx-x[i][j], mx-y[i][j]);
			if (aux == 0) continue;
			s.insert(make_pair(-aux, make_pair(i, j)));
		}
	}


	for (auto a : s) {
		int xx = a.second.second;
		int yy = a.second.first;
		//if (bany[yy] or banx[xx]) continue;
		v[yy][xx] += (-a.first);
		bany[yy] = 1;
		banx[xx] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}