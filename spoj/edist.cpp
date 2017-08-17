#include <bits/stdc++.h>
using namespace std;

int dp[2005][2005], lena, lenb;
char a[2005], b[2005];

int go(int ida, int idb) {
	if (ida == lena) return lenb-idb;
	if (idb == lenb) return lena-ida;
	if (dp[ida][idb] != -1) return dp[ida][idb];
	int x = a[ida] != b[idb];
	int ret = min(x+go(ida+1, idb+1), 1+go(ida, idb+1));
	ret = min(ret, 1+go(ida+1, idb));
	return dp[ida][idb] = ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf(" %s", a);
		scanf(" %s", b);
		lena = strlen(a), lenb = strlen(b);
		printf("%d\n", go(0,0));
	}

	return 0;
}