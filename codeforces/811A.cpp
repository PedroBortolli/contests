#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int x = 1;
	for (int i = 0; i <= 100000; i++) {
		if (i%2) b -= x;
		else a -= x;
		if (a < 0) {
			printf("Vladik\n");
			return 0;
		}
		else if (b < 0) {
			printf("Valera\n");
			return 0;
		}
		x++;
	}

	return 0;
}