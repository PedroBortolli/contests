#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
#define end endd

const int N = 3e5+5;
int p[N], w[N], end[N], v[N];

int find(int a) {
	return (p[a] == a) ? a : p[a] = find(p[a]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b=find(b))) return;
	if (w[b] > w[a]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		w[i] = 1;
		p[i] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		v[x] = 1;
		if (v[x-1] and v[x+1]) {
			if (!end[find(x+1)]) ans -= (w[find(x-1)] + w[find(x+1)]);
			else ans -= (w[find(x-1)]);
			end[find(x-1)] = end[find(x+1)];
			join(x-1, x+1);
			join(x-1, x);
			end[find(x)] = end[find(x+1)];
			if (!end[find(x)]) ans += w[find(x)];
		}
		else if (v[x-1]) {
			int lul = 0;
			if (x == n) lul = 1;
			if (!end[find(x-1)]) ans -= w[find(x-1)];
			end[find(x-1)] = lul;
			join(x-1, x);
			end[find(x)] = lul;
			if (!end[find(x)]) ans += w[find(x)];
		}
		else if (v[x+1]) {
			if (!end[find(x+1)]) ans -= w[find(x+1)];
			end[find(x)] = end[find(x+1)];
			join(x, x+1);
			if (!end[find(x)]) ans += w[find(x)];
		}
		else {
			if (x < n) ans++;
			else end[x] = 1;
		}
		if (i == 1) printf("1 ");
		printf("%d ", ans+1);
	}

	printf("\n");
	return 0;
}