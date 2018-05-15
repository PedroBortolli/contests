#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

map <int, int> mp;
int main() {
	int n, a = 0, b = 0, ans = 0;
	char x;
	scanf("%d", &n);
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &x);
		if (x == '1') a++;
		else b++;
		int dif = a-b;
		if (mp.find(dif) == mp.end()) mp[dif] = i;
		else ans = max(ans, i-mp[dif]);
	}
	printf("%d\n", ans);
	return 0;
}