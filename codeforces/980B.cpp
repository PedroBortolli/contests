#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char v[5][105];
int n, k;

void print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &k);
	memset(v, '.', sizeof(v));
	if (k%2 == 0) {
		printf("YES\n");
		for (int j = 1; j < n-1 && k; j++) {
			for (int i = 1; i < 3 && k; i++) {
				v[i][j] = '#';
				k--;
			}
		}
		print();
		return 0;
	}

	for (int i = 1; i < 3 && k; i++) {
		int b = n-2;
		for (int a = 1; a <= b && k; a++) {
			if (k == 1 && a != b) {
				b--;
				continue;
			}
			v[i][a] = '#';
			v[i][b] = '#';
			if (a == b) k--;
			else k -= 2;
			b--;
		}
	}
	printf("YES\n");
	print();
	return 0;
}