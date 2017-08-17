#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	if (n == 2) {
		printf("0\n");
		return 0;
	}

	ll ans = 1;
	ll mod = 1000000007;
	for (int i = 0; i < n/2 + (n%2); i++) {
		ans = (ans*k)%mod;
		k--;
	}
	
	return 0;
}