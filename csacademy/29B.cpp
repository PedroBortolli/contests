#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[100005], xo[100005];
int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    if (n == 1ll) {
        printf("1\n");
        return 0;
    }

    xo[n-1] = v[n-1];
    for (ll i = n-2; i >= 0; i--) {
        xo[i] = v[i]^xo[i+1];
    }

   ll ans1 = 1, ans2 = 1;
    for (ll i = 0; i < n; i++) {
        if (xo[i] != 0ll) {
            ans1 = n-i;
            break;
        }
    }

    xo[0] = v[0];
    for (ll i = 1; i < n; i++) {
        xo[i] = v[i]^xo[i-1];
    }

    for (ll i = 0; i < n; i++) {
        if (xo[i] != 0ll) {
            ans2 = n-1;
            break;
        }
    }


    printf("%lld\n", max(ans1, ans2));
    return 0;
}