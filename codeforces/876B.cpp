#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
multiset <int> s[100005];
int main() {
	int n, k, m, x, id;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		s[x%m].insert(x);
	}

	for (int i = 0; i < 100005; i++) {
		if ((int)s[i].size() >= k) {
			int cont = 0;
			printf("Yes\n");
			for (auto a : s[i]) {
				printf("%d ", a);
				cont++;
				if (cont == k) break;
			}
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}