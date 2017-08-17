#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
int ans[100005];
set <int> s[100005];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int prev = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] >= v[i-1]) {
			//printf("Colocando de %d ate %d\n", prev, i-1);
			for (int j = prev; j <= i-1; j++) {
				//s[i-1-prev+1].insert(v[j]);
				printf("%d ", i-1-prev+1);
			}
			prev = i;
		}
	}

	//printf("Colocando de %d ate %d\n", prev, n-1);
	for (int i = prev; i < n; i++) {
		//s[n-1-prev+1].insert(v[i]);
		printf("%d ", n-1-prev+1);
	}

	return 0;
	for (int i = 100002; i >= 0; i--) {
		for (auto a : s[i]) {
			if (!ans[a]) ans[a] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[v[i]]);
	}

	printf("\n");
	return 0;
}