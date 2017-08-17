#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char a[200005], b[200005];
int s0[200005], s1[200005];
int main() {
	scanf(" %s", a);
	scanf(" %s", b);
	int lena = strlen(a);
	int lenb = strlen(b);

	for (int i = 0; i < lenb; i++) {
		if (i == 0) {
			if (b[i] == '1') {
				s1[i] = 1;
				s0[i] = 0;
			}
			else {
				s1[i] = 0;
				s0[i] = 1;
			}
		}
		else {
			if (b[i] == '1') {
				s1[i] = s1[i-1]+1;
				s0[i] = s0[i-1];
			}
			else {
				s1[i] = s1[i-1];
				s0[i] = s0[i-1]+1;
			}
		}
	}

	ll ans = 0;

	for (int i = 0; i < lena; i++) {
		if (i == 0) {
			if (a[i] == '1') ans += s0[lenb-lena];
			else ans += s1[lenb-lena];
			continue;
		}
		if (a[i] == '1') {
			ans += (s0[lenb-lena+i]-s0[i-1]);
		}
		else ans += (s1[lenb-lena+i]-s1[i-1]);
	}	

	printf("%lld\n", ans);
	return 0;
}