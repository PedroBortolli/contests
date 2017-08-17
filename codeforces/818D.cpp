#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> app[1000005];
int where[1000005];
int v[100005];
int main() {
	int n, a;
	scanf("%d %d", &n, &a);
	for (int i = 1; i <= 1000000; i++) {
		if (i != a) app[0].insert(i);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	//return 0;
	for (int i = 0; i < n; i++) {
		if (v[i] != a) {
			if (where[v[i]] == -1) continue;
			app[where[v[i]]].erase(v[i]);
			where[v[i]]++;
			app[where[v[i]]].insert(v[i]);
		}
		else {
			for (auto it : app[where[a]]) {
				//printf("it = %d\n", it);
				where[it] = -1;
			}
			app[where[a]].clear();
			where[a]++;
		}
	}
	int x = where[a];
	for (int i = x; i <= 1000003; i++) {
		if (app[i].empty()) continue;
		else {
			printf("%d\n", *app[i].begin());
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}