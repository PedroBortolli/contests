#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int a, b, f, fuel, k, pos = 0, ans = 0;
	scanf("%d %d %d %d", &a, &b, &f, &k);
	fuel = f;
	while (1) {
		if (pos == 0) {
			pos = a;
			//fuel -= a;
			if (fuel-a < 0) {
				if (b <= fuel) {
					ans++;
					fuel = f;
				} 
			}
		}
	}

	return 0;
}