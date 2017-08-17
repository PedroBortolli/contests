#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, x;
	scanf("%d", &n);
	x = n;
	int cont = 0;
	while (x >= 10) {
		cont++;
		x /= 10;
	}

	x++;
	for (int i = 0; i < cont; i++)
		x *= 10;

	printf("%d\n", x-n);
	return 0;
}