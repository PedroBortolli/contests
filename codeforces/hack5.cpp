#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n;
	cin >> n;
	int ro, re, oe;
	cin >> ro >> re >> oe;
	n--;
	int min1 = min(ro, min(re, oe));
	int max1 = max(ro, max(re, oe));
	int sum = 0;
	if (n > 0) {
		sum += min(ro, re);
		n--;
	}	

	while (n--) sum += min1;
	cout << sum << endl;
	return 0;
}