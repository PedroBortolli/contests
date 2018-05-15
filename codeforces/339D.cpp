#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 17) + 5;
int n, t[2*N], op[N];

void build() {
	for (int i = n-1; i > 0; i--) {
		if (!op[i]) t[i] = t[2*i] | t[2*i+1];
		else t[i] = t[2*i] ^ t[2*i+1];
	}
}

void update(int id, int x) {
	id += n;
	t[id] = x;
	id /= 2;
	for (int i = id; i > 0; i /= 2) {
		if (!op[i]) t[i] = t[2*i] | t[2*i+1];
		else t[i] = t[2*i] ^ t[2*i+1];
	}
}

int main() {
	int m, x, y;
	scanf("%d %d", &n, &m);
	int need = 1 << (n-1), now = 0;
	for (int i = (1 << n) - 1; i >= 1;) {
		for (int j = 0; j < need; j++) {
			op[i] = now;
			i--;
		}
		need /= 2;
		now++;
		now %= 2;
	}
	n = 1 << n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i+n]);
	}
	build();
	while (m--) {
		scanf("%d %d", &x, &y);
		update(x-1, y);
		printf("%d\n", t[1]);
	}
}