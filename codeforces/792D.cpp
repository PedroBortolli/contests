#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll find(ll x) {
	ll aux = (ll)1 << (ll)62;
	while (aux) {
		if (x-aux >= 0 && x%aux == 0) return aux;
		aux /= 2;
	}
}

char s[100005];
int main() {
	ll n, q, x, aux;
	scanf("%lld %lld", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%lld", &x);
		scanf(" %s", s);
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			aux = find(x);
			//printf("Num = %lld     find = %lld\n", x, aux);
			if (aux >= (n+1)/2 && s[i] == 'U') continue;
			if (aux == 1 && s[i] != 'U') continue;
			if (s[i] == 'L') x -= (aux/2);
			if (s[i] == 'R') x += (aux/2);
			if (s[i] == 'U') {
				if (find(x+aux) == 2*aux) x += aux;
				else x -= aux;
			}
		}
		printf("%lld\n", x);
	}

	return 0;
}