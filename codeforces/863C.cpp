#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll A[5][5], B[5][5], seen[5][5];
pll pt[10000005];
int main() {
	ll k, a, b;
	scanf("%lld %lld %lld", &k, &a, &b);
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%lld", &A[i][j]);
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%lld", &B[i][j]);
		}
	}

	ll pta = 0, ptb = 0, cont = 1, loop = 0, ok = 0;
	while (1) {
		if (cont > k) {
			ok = 1;
			break;
		}
		if (seen[a][b]) {
			loop = seen[a][b];
			break;
		}
		seen[a][b] = cont;
		if (a != b) {
			if (a == 3 && b == 2) pta++;
			if (a == 2 && b == 1) pta++;
			if (a == 1 && b == 3) pta++;
			if (b == 3 && a == 2) ptb++;
			if (b == 2 && a == 1) ptb++;
			if (b == 1 && a == 3) ptb++;
		}
		pt[cont] = {pta, ptb};
		ll auxa = a;
		ll auxb = b;
		a = A[auxa][auxb];
		b = B[auxa][auxb];
		cont++;
	}

	if (ok) {
		printf("%lld %lld\n", pt[k].first, pt[k].second);
		return 0;
	}

	cont--;
	//printf("Loop eh de %lld ate %lld\n", loop, cont);
	pll ans = {0, 0};
	ans.first += pt[loop-1].first;
	ans.second += pt[loop-1].second;
	//printf("Ans antes do loop =   %lld , %lld\n", ans.first, ans.second);
	ll len = cont-loop+1;
	pll gain = {pt[cont].first-pt[loop-1].first, pt[cont].second-pt[loop-1].second};
	//printf("Gain = %lld , %lld       tamanho do ciclo = %lld\n", gain.first, gain.second, len);
	//de loop ate cont = loopao de tamanho len de ganho gain

	ll left = k-loop+1;
	ll cycles = left/len;
	ll rem = left%len;
	//printf("Left = %lld      Cycles = %lld     Rem = %lld\n", left, cycles, rem);
	ans.first += cycles*gain.first;
	ans.second += cycles*gain.second;
	//printf("%lld  %lld\n", ans.first, ans.second);
	
	pta = 0, ptb = 0;
	
	while (1) {
		if (!rem) break;
		rem--;
		if (a != b) {
			if (a == 3 && b == 2) pta++;
			if (a == 2 && b == 1) pta++;
			if (a == 1 && b == 3) pta++;
			if (b == 3 && a == 2) ptb++;
			if (b == 2 && a == 1) ptb++;
			if (b == 1 && a == 3) ptb++;
		}
		ll auxa = a;
		ll auxb = b;
		a = A[auxa][auxb];
		b = B[auxa][auxb];
	}

	printf("%lld %lld\n", ans.first+pta, ans.second+ptb);
	return 0;
}