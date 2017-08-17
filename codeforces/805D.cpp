#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[1000005];
int main() {
	scanf(" %s", s);
	ll n = strlen(s);
	ll ans = 0;
	ll mod = 1000000007;

	ll b = 0;
	ll prev = 0;
	ll aux = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == 'b') b++;
		else {
			aux = ans+b;
			ans = (ans+b)%mod;
			b += (aux-prev);
			prev = aux;
		}
	}

	printf("%lld\n", ans%mod);
	return 0;
}