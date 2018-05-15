#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, a, b, x;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a += x;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		b += x;
	}

	if (a > b) printf("1\n");
	else if (b > a) printf("2\n");
	else printf("0\n");

	return 0;
}