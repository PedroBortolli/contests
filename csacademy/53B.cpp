#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}


	int cont = 1, best = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] >= v[i-1]) {
			cont++;
		}
		else {
			best = max(best, cont);
			cont = 1;
		}
	}
	best = max(best, cont);
	cont = 1;
	
	for (int i = 1; i < n; i++) {
		if (v[i] <= v[i-1]) {
			cont++;
		}
		else {
			best = max(best, cont);
			cont = 1;
		}
	}

	best = max(best, cont);
	printf("%d\n", best);
	return 0;
}