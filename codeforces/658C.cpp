#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[100005];
int seen[100005];

void dfs(int x, int cont) {
	seen[x] = cont;
	for (auto a : v[x]) {
		if (!seen[a]) {
			dfs(a, cont+1);
		}
	}
}


int main() {
	int n, d, h, x = 0;
	scanf("%d %d %d", &n, &d, &h);

	if (d == h) {
		if (h < n-1) {
			printf("-1\n");
			return 0;
		}
		for (int i = 0; i < n-1; i++) {
			printf("%d %d\n", i+1, i+2);
		}
		return 0;
	}

	if (d > 2*h) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < h; i++) {
		x++;
		//printf("%d %d\n", i+1, i+2);
		v[i+1].pb(i+2);
		v[i+2].pb(i+1);
	}

	int prev = h+2;
	//printf("1 %d\n", prev);
	v[1].pb(prev);
	v[prev].pb(1);
	x++;
	for (int i = 1; i < d-h; i++) {
		x++;
		//printf("%d %d\n", prev, prev+1);
		v[prev].pb(prev+1);
		v[prev+1].pb(prev);
		prev++;
	}

	for (int i = 0; i < n-1-d; i++) {
		x++;
		v[1].pb(prev+1);
		v[prev+1].pb(1);
		prev++;
		//printf("1 %d\n", ++prev);
	}

	int ok = 0;
	dfs(1, 1);
	int mx = 0, id = 0;
	for (int i = 1; i <= n; i++) {
		if (seen[i] == h) ok = 1;
		if (seen[i] > mx) {
			mx = seen[i];
			id = i;
		}
	}
	memset(seen, 0, sizeof(seen));
	dfs(id, 1);
	mx = 0;
	for (int i = 1; i <= n; i++) {
		//printf("Seen[%d] = %d\n", i, seen[i]);
		mx = max(mx, seen[i]);
	}
	//printf("ok = %d  id = %d    mx = %d\n", ok, id, mx);
	if (!ok or mx-1 != d) {
		printf("-1\n");
		return 0;
	}




	for (int i = 0; i < h; i++) {
		x++;
		printf("%d %d\n", i+1, i+2);
	}

	prev = h+2;
	printf("1 %d\n", prev);
	x++;
	for (int i = 1; i < d-h; i++) {
		x++;
		printf("%d %d\n", prev, prev+1);
		prev++;
	}

	for (int i = 0; i < n-1-d; i++) {
		x++;
		printf("1 %d\n", ++prev);
	}

	//printf("x = %d\n", x);
	return 0;
}