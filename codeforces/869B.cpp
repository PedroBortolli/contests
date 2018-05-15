#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll fat = 1;
	string temp = "1";

	while (b > a) {
		string aux = to_string(b);
		int sze = (int)aux.length();
		ll x = aux[sze-1]-'0';
		fat *= x;
		b--;
		temp = to_string(fat);
		if (temp[(int)temp.length()-1] == '0') {
			printf("0\n");
			return 0;
		}
	}

	printf("%c\n", temp[(int)temp.length()-1]);

	return 0;
}