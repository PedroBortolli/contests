#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, v[1005][1005][2], dp[1005][1005][2];
char to[1005][1005][2];

int go(int y, int x, int t) {
	if (dp[y][x][t] != -1) return dp[y][x][t];
	if (x == n-1 && y == n-1) return v[y][x][t];
	int ans = INT_MAX;
	if (x < n-1 && v[y][x][t]+go(y, x+1, t) < ans) {
		ans = v[y][x][t]+go(y, x+1, t);
		to[y][x][t] = 'R';
	}
	if (y < n-1 && v[y][x][t]+go(y+1, x, t) < ans) {
		ans = v[y][x][t]+go(y+1, x, t);
		to[y][x][t] = 'D';
	}
	return dp[y][x][t] = ans;
}

int main() {
	int x, y, zx = -1, zy = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			if (x == 0) {
				zx = j;
				zy = i;
				x = 10;
			}
			while (x > 0) {
				if (x%2 != 0) {
					if (x%5 != 0) break;
					else {
						x /= 5;
						v[i][j][1]++;
					}
				}
				else {
					x /= 2;
					v[i][j][0]++;
				}
			}
		}
	}
	memset(dp, -1, sizeof(dp));

	if (zx != -1) {
		if (go(0,0,0) != 0 && go(0,0,1) != 0) {
			x = 0, y = 0;
			printf("1\n");
			while (x != zx or y != zy) {
				if (x != zx) {
					x++;
					printf("R");
				}
				else {
					y++;
					printf("D");
				}
			}
			while (x != n-1 or y != n-1) {
				if (x != n-1) {
					x++;
					printf("R");
				}
				else {
					y++;
					printf("D");
				}
			}
			printf("\n");
			return 0;
		}
	}

	if (go(0,0,0) <= go(0,0,1)) {
		printf("%d\n", go(0,0,0));
		x = 0, y = 0;
		while (x < n-1 or y < n-1) {
			char c = to[y][x][0];
			printf("%c", c);
			if (c == 'D') y++;
			else x++;
		}
	}
	else {
		printf("%d\n", go(0,0,1));
		x = 0, y = 0;
		while (x < n-1 or y < n-1) {
			char c = to[y][x][1];
			printf("%c", c);
			if (c == 'D') y++;
			else x++;
		}
	}
	printf("\n");
	return 0;
}