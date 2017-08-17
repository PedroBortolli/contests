#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;


int main() {
	ll n, k, ans = 0;
	scanf("%lld %lld", &n, &k);
	if (k == 1) {
		printf("%lld\n", n);
		return 0;
	}

	for (ll i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			double sum = ((i+i+(k-1)*i)*(double)k)/2;
			ll dif = n-sum;
			if (dif >= 0 && dif%i == 0) ans = max(ans, i);

			sum = ((n/i+n/i+(k-1)*(n/i))*(double)k)/2;
			dif = n-sum;
			if (dif >= 0 && dif%(n/i) == 0) ans = max(ans, n/i);
		}
	}

	if (ans == 0) {
		printf("-1\n");
		return 0;
	}

	ll sum = 0, cont = 0;

	for (ll i = ans; ; i += ans) {
		printf("%lld ", i);
		sum += i;
		cont++;
		if (cont == k-1) {
			printf("%lld\n", n-sum);
			break;
		} 
	}
	return 0;
}