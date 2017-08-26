#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int seen[50005];
set <int> s;
int main() {
	int n, st, x, y, lul;
	srand(time(NULL));
	scanf("%d %d %d", &n, &st, &x);
	for (int i = 0; i < min(n, 1999); i++) {
		while (1) {
			y = rand()%n+1;
			if (!seen[y]) {
				seen[y] = 1;
				break;
			}
		}
		printf("? %d\n", y);
		fflush(stdout);
		scanf("%d %d", &y, &lul);
		s.insert(y);
	}

	printf("! %d\n", *s.lower_bound(x));
	return 0;
}