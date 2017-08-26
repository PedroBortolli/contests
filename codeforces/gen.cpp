#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int f(int x) {
	int ans = 1;
	for (int i = 2; i <= x; i++) {
		ans *= i;
	}
	return ans;
}
int main() {
	int n = 10, ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (f(n)/(f(n-i)*f(i)));
	}

	printf("%d\n", ans);
	return 0;
}