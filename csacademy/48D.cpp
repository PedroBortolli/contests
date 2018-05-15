#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5+5;
int bit[N];

void update(int id, int x) {
	if (!id) return;
	while (id < N) {
		bit[id] += x;
		id += id&-id;
	}
}

int query(int id) {
	int ans = 0;
	while (id > 0) {
		ans += bit[id];
		id -= id&-id;
	}
	return ans;
}

int main() {
	int n, x, y, z;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);
		update(y+, 1-z);
		update(x, z);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		printf("%d\n", query(x));
	}
	return 0;
}