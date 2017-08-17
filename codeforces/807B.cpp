#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> s;
int test(int x) {
	s.clear();
	int y = (x/50)%475;
	for (int i = 0; i < 25; i++) {
		y = (y * 96 + 42)%475;
		s.insert(y+26);
	}
}

int main() {
	int p, x, y;
	scanf("%d %d %d", &p, &x, &y);
	int aux = x;
	while (aux >= y) {
		test(aux);
		if (s.find(p) != s.end()) {
			printf("0\n");
			return 0;
		}
		aux -= 50;
	}

	int ans = 0, cont = 0;
	while (1) {
		x += 50;
		cont++;
		if (cont%2) ans++;
		test(x);
		if (s.find(p) != s.end()) {
			printf("%d\n", ans);
			return 0;
		}
	}

	return 0;
}