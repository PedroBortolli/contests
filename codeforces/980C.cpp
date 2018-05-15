#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5+5;
int p[288], w[288], v[N], mp[288], mn[288];

int find(int a) {
	return (p[a] == a) ? a : p[a] = find(p[a]);
}

void join(int a, int b) {
	int preva = a, prevb = b;
	if ((a = find(a)) == (b = find(b))) return;
	if (w[b] > w[a]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
	mn[a] = min(preva,mn[a]);
	mn[a] = min(prevb,mn[a]);
	mn[a] = min(mn[a],mn[b]);
	mn[a] = min(mn[a], a);
	mn[a] = min(mn[a], b);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= 255; i++) {
		p[i] = i;
		w[i] = 1;
		mn[i] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		for (int j = v[i]-1; j >= 0; j--) {
			if (find(j) == find(v[i])) continue;
			if (w[find(j)] + w[find(v[i])] > k) break;
			join(v[i], j);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", mn[find(v[i])]);
	}
	printf("\n");
	return 0;
}