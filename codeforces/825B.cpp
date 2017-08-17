#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n = 10;
char v[111][111];

int check(int y, int x) {
	for (int i = y-4; i <= y; i++) {
		int cont = 0, ponto = 0;
		for (int j = i; j <= i+4; j++) {
			if (v[j][x] == 'X') cont++;
			else if (v[j][x] == '.') ponto++;
		}
		if (cont == 4 && ponto == 1) return 1;
	}
	for (int i = x-4; i <= x; i++) {
		int cont = 0, ponto = 0;
		for (int j = i; j <= i+4; j++) {
			if (v[y][j] == 'X') cont++;
			else if (v[y][j] == '.') ponto++;
		}
		if (cont == 4 && ponto == 1) return 1;
	}
	int pp = y-4, aux = 0;
	for (int i = x-4; i <= x; i++) {
		int cont = 0;
		int ponto = 0;
		int p = pp+aux;
		aux++;
		for (int j = i; j <= i+4; j++) {
			if (v[p++][j] == 'X') cont++;
			else if (v[p-1][j] == '.') ponto++;
		}
		if (cont == 4 && ponto == 1) return 1;
	}
	pp = y-4;
	aux = 0;
	for (int i = x+4; i >= x; i--) {
		int cont = 0;
		int ponto = 0;
		int p = pp+aux;
		aux++;
		for (int j = i; j >= i-4; j--) {
			if (v[p++][j] == 'X') cont++;
			else if (v[p-1][j] == '.') ponto++;
		}
		if (cont == 4 && ponto == 1) return 1;
	}
	return 0;
}

int main() {
	memset(v, '!', sizeof(v));
	for (int i = 10; i < 2*n; i++) {
		for (int j = 10; j < 2*n; j++) {
			scanf(" %c", &v[i][j]);
		}
	}

	for (int i = 10; i < 2*n; i++) {
		for (int j = 10; j < 2*n; j++) {
			if (v[i][j] == '.') {
				if (check(i, j)) {
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}