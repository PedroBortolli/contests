#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char v[11][11];
int main() {
	int x, y;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %c", &v[i][j]);
		}
	}
	scanf("%d %d", &y, &x);
	int dy, dx;

	if (y%3 == 1) dy = 0;
	else if (y%3 == 2) dy = 3;
	else dy = 6;

	if (x%3 == 1) dx = 0;
	else if (x%3 == 2) dx = 3;
	else dx = 6;

	int ok = 0;
	for (int i = dy; i < dy+3; i++) {
		for (int j = dx; j < dx+3; j++) {
			if (v[i][j] == '.') ok = 1;
		}
	}

	if (!ok) {
		for (int i = 0; i < 9; i++) {
			if (i > 0 && i%3 == 0) printf("\n");
			for (int j = 0; j < 9; j++) {
				if (j > 0 && j%3 == 0) printf(" ");
				if (v[i][j] == '.') printf("!");
				else printf("%c", v[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

	for (int i = dy; i < dy+3; i++) {
		for (int j = dx; j < dx+3; j++) {
			if (v[i][j] == '.') v[i][j] = '!';
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i > 0 && i%3 == 0) printf("\n");
		for (int j = 0; j < 9; j++) {
			if (j > 0 && j%3 == 0) printf(" ");
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}