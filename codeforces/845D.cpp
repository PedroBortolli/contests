#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, t, x, speed = 99999, chaos = 0, allow = 1, prev = 99999, ans = 0;
	int curallow = 0, curspeed = 0; 
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &x);
			speed = x;
		}
		if (t == 2) {
			if (!allow) {
				ans += curallow;
			}
			curallow = 0;
		}
		if (t == 3) {
			scanf("%d", &x);
			if (!chaos && speed > x) {
				ans++;
			}
		}
		if (t == 4) {
			allow = 1;
			curallow = 0;
		}
		if (t == 5) {
			chaos = 1;
		}
		if (t == 6) {
			allow = 0;
			curallow++;
		}
	}	

	printf("%d\n", ans);
	return 0;
}