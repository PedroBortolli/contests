#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5+5;
int bit[11][11][5][N];
char s[N], e[11];

int get(char z) {
	if (z == 'A') return 0;
	if (z == 'T') return 1;
	if (z == 'G') return 2;
	if (z == 'C') return 3;
}

void update(int step, int start, int let, int pos, int x) {
	while (pos < N) {
		bit[step][start][let][pos] += x;
		pos += (pos&-pos);
	}
}

int query(int step, int start, int let, int pos) {
	int ans = 0;
	while (pos > 0) {
		ans += bit[step][start][let][pos];
		pos -= (pos&-pos);
	}
	return ans;
}

int main() {
	int n, q, t, l, r, x, y, aux;
	char c;
	scanf(" %s", s);
	n = strlen(s);
	aux = min(n, 10);
	for (int i = 1; i <= aux; i++) {
		for (int j = 0; j < aux; j++) {
			for (int k = j; k < n; k += i) {
				y = get(s[k]);
				update(i, j, y, k+1, 1);
			}
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d %c", &x, &c);
			y = get(s[x-1]);
			for (int i = 1; i <= aux; i++) {
				for (int j = 0; j < aux; j++) {
					update(i, j, y, x, -1);
				}
			}
			y = get(c);
			for (int i = 1; i <= aux; i++) {
				for (int j = 0; j < aux; j++) {
					update(i, j, y, x, 1);
				}
			}
		}
		else {
			scanf("%d %d %s", &l, &r, e);
			int len = strlen(e);
			int ans = 0;
			for (int i = 0; i < min(len, n); i++) {
				y = get(e[i]);
				x = query(len, l-1+i, y, r) - query(len, l-1+i, y, l-1);
				ans += x;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}