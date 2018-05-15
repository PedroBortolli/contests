#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[100005];
int main() {
	int m;
	scanf("%d", &m);
	int ans = 0;
	for (int i = 5; i <= 500000; i++) {
		int x = i;
		while (x > 1) {
			if (x%5 == 0) {
				x /= 5;
				ans++;
			}
			else break;
		}
		if (ans > m) break;
		v[ans].pb(i);
	}
	printf("%d\n", (int)v[m].size());
	for (auto a : v[m])
		printf("%d ", a);
	printf("\n");
	return 0;
}