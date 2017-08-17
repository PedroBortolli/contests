#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


set <int> s[35], need;
int sum[33][100005];

void work(int x, int p) {
	string str = bitset<31>(x).to_string();
	for (int i = 0; i < 31; i++) {
		if (str[i] == '1') s[i].insert(p);
	}
}

int main() {
	int n, x;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		work(x, i);
	}

	/*
	for (int i = 0; i < 31; i++) {
		printf("Bit na pos %d:\n	", i);
		for (auto a : s[i]) {
			printf("%d ", a);
		}
		printf("\n");
	}*/

	for (int i = 0; i < 31; i++) {
		if (!s[i].empty()) need.insert(i);
	}

	for (int i = 0; i < 31; i++) {
		for (int j = 1; j <= n; j++) {
			int ok = 0;
			if (s[i].find(j) != s[i].end()) {
				ok = 1;
			}
			sum[i][j] = ok+sum[i][j-1];
		}
	}

	int l = 1, r = n, m;
	int ans = n;
	for (int i = 0; i < 22; i++) {
		m = (l+r)/2;
		int right = 0;
		for (int j = 1; j <= n-m+1; j++) {
			int ok = 1;
			for (auto a : need) {
				int y = sum[a][j+m-1] - sum[a][j-1];
				if (y == 0) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				right = 1;
				break;
			}
		}
		if (right) {
			ans = min(ans, m);
			r = m;
		}
		else l = m+1;	
	}
	
	printf("%d\n", ans);
	return 0;
}