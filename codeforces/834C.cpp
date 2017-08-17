#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int np[100005];
vector <int> v;
int main() {
	int n, a, b;
	scanf("%d", &n);

	for (int i = 2; i <= 100000; i++) {
		for (int j = i+i; j <= 100000; j += i) {
			np[j] = 1;
		}
	}

	int sze = 0;
	for (int i = 2; i <= 100000; i++) {
		if (!np[i]) {
			v.pb(i);
			sze++;
		}
	}

	while (n--) {
		scanf("%d %d", &a, &b);
		if (a == 1 && b == 1) {
			printf("Yes\n");
			continue;
		}
		else if (a == 1 && b > 1) {
			printf("No\n");
			continue;
		}
		else if (a > 1 && b == 1) {
			printf("No\n");
			continue;
		}
		int k = 0;
		map <int, int> mpa;
		map <int, int> mpb;
		while (a > 1) {
			int p = v[k];
			
			if (a%p == 0) {
				mpa[p]++;
				a /= p;
			}
			else {
				k++;
				if (k >= sze or v[k] > a) {
					mpa[a]++;
					break;
				}
			}
		}

		k = 0;
		while (b > 1) {
			int p = v[k];
			if (b%p == 0) {
				mpb[p]++;
				b /= p;
			}
			else {
				k++;
				if (k >= sze or v[k] > b) {
					mpb[b]++;
					break;
				}
			}
		}

		for (auto a : mpa) {
			if (a.second >= 2) {
				if (mpa[a.first]*2 == mpb[a.first]) {
					mpa[a.first] = 0;
					mpb[a.first] = 0;
				}
				else if (mpa[a.first] == mpb[a.first]*2) {
					mpa[a.first] = 0;
					mpb[a.first] = 0;	
				}
				else if (mpa[a.first]%3 == 0 && mpb[a.first]%3 == 0) {
					mpa[a.first] = 0;
					mpb[a.first] = 0;		
				}
			}
		}

		for (auto a : mpb) {
			if (a.second >= 2) {
				if (mpa[a.first]*2 == mpb[a.first]) {
					mpa[a.first] = 0;
					mpb[a.first] = 0;
				}
				else if (mpa[a.first] == mpb[a.first]*2) {
					mpa[a.first] = 0;
					mpb[a.first] = 0;	
				}
				else if (mpa[a.first]%3 == 0 && mpb[a.first]%3 == 0) {
					mpa[a.first] = 0;
					mpb[a.first] = 0;		
				}
			}
		}

		int ok = 1;
		for (auto a : mpa) {
			//printf("mpa[%d] = %d\n", a.first, a.second);
			if (a.second != 0) {
				ok = 0;
				break;
			}
		}

		if (!ok) goto here;

		for (auto a : mpb) {
			//printf("mpb[%d] = %d\n", a.first, a.second);
			if (a.second != 0) {
				ok = 0;
				break;
			}
		}

		here:;

		if (ok) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}