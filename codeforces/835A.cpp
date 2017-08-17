#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int s, v1, v2, t1, t2;
	scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);

	int a = s*v1+2*t1;
	int b = s*v2+2*t2;
	
	if (a < b) printf("First");
	else if (a > b) printf("Second");
	else printf("Friendship");
	printf("\n");
	return 0;
}