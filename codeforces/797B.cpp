#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll inf = 100000000000007;
int main() {
	ll n, x, smaller = -inf, bigger = inf;

	ll ans = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		if (x > 0) ans += x;
		if (x%2 != 0) {
			if (x > 0) bigger = min(bigger, x);
			else smaller = max(smaller, x);
		}
	}

	if (ans%2 != 0) {
		printf("%lld\n", ans);
		return 0;
	} 

	ll ans1 = ans;
	ll ans2 = ans;

	if (bigger != inf && smaller != inf) {
		printf("%lld\n", max(ans-bigger, ans+smaller));
		return 0;
	}
	if (bigger != inf) ans -= bigger;
	else ans += smaller;



	printf("%lld\n", ans);
	return 0;
}