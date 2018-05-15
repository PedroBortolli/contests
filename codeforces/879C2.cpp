#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

const int N = 1e5+5;
char op[N];
int v[N];

int main() {
	int n, x;
	char oop;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %d", &op[i], &v[i]);
		if (i == 0) {
			x = v[i];
			oop = op[i];
			continue;
		}
		if (op[i] == '&') x &= v[i];
		else if (op[i] == '|') x |= v[i];
		else x ^= v[i];

	}

	printf("%d\n", x);


	return 0;
}