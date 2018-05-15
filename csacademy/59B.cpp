	#include <stdio.h>
	#include <bits/stdc++.h>
	using namespace std;
	#define pb(x) push_back(x)
	#define mp(x, y) make_pair(x, y)
	typedef long long ll;
	typedef pair <int, int> pii;
	typedef pair <long long, long long> pll;
	#define int long long

	main() {
		int g1, p1, g2, p2;
		scanf("%lld %lld %lld %lld", &g1, &p1, &g2, &p2);
		
		int w1 = 0, w2 = 0;
		if (p1 == 100) {
			w1 = g1;
			goto there;
		}
		for (int i = 0; i <= 200000000; i++) {
			if (100*i >= p1*g1) {
				w1 = i;
				break;
			}
		}

		there:
		if (p2 == 100) {
			w2 = g2;
			goto here;
		}
		for (int i = 0; i <= 200000000; i++) {
			//printf("x = %lld     cont = %lld\n", 100*i, p2*g2);
			if (100*i >= ((p2+1)*g2)) {
				w2 = i;
				break;
			}
		}

		here:
		printf("%lld\n", w2-1ll-w1);
		return 0;
	}