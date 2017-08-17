#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[105], l[105];
map <int, int> mp;
int main() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &l[i]);
	}

	for (int i = 0; i < m-1; i++) {
		if (l[i+1] > l[i]) x = l[i+1]-l[i];
		else x = n-l[i]+l[i+1];
		if (l[i+1] == l[i]) x = n;
		if (v[l[i]] && v[l[i]] != x) {
			printf("-1\n");
			return 0;
		}
		v[l[i]] = x;
	}


	for (int i = 1; i <= n; i++) {
		mp[v[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (mp[v[i]] > 1 && v[i] != 0) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			for (int j = 1; j <= n; j++) {
				if (mp[j] == 0) {
					v[i] = j;
					mp[j]++;
					break;
				}
			}
		}
		printf("%d ", v[i]);
	}

	printf("\n");
	return 0;
}