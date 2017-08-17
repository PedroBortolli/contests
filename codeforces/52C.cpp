#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 17917917917917917;
const int N = 2e5 + 5;

ll seg[4*N];
ll lazy[4*N];

void do_lazy(int root, int l, int r) {
    seg[root] += lazy[root];
    if (l != r) {
        lazy[2*root+1] += lazy[root];
        lazy[2*root+2] += lazy[root];
    }
    lazy[root] = 0;
}

ll update(int root, int l2, int r2, int l, int r, ll val) { //update values in range (l, r)
    do_lazy(root, l2, r2);
    if (r < l2 || l > r2) return seg[root];
    if (l2 >= l && r2 <= r) {
        lazy[root] += val;
        do_lazy(root, l2, r2);
        return seg[root];
    }
    return seg[root] = min(update(2*root+1, l2, (l2+r2)/2, l, r, val), update(2*root+2, (l2+r2)/2+1, r2, l, r, val));
}

ll query(int root, int l2, int r2, int l, int r) { //find minimum in range (l, r)
    do_lazy(root, l2, r2);
    if (r < l2 || l > r2) return inf;
    if (l2 >= l && r2 <= r) return seg[root];
    return min(query(2*root+1, l2, (l2+r2)/2, l, r), query(2*root+2, (l2+r2)/2+1, r2, l, r)); 
}

ll v[5];
int main() {
    ll n, x, q;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        update(0, 0, n-1, i, i, x);
    }
    cin >> q;
    getchar();
    while (q--) {
    	int l, r;
        scanf("%d %d", &l, &r);
        char c = getchar();
        ll k = 2;
        if (c != '\n') {
        	scanf("%lld", &x);
        	k = 3;
        }
        if (k == 3) {
            if (l > r) {
                update(0, 0, n-1, l, n-1, x);
                update(0, 0, n-1, 0, r, x);
            }
            else update(0, 0, n-1, l, r, x);
        }
        else {
       		if (l > r) printf("%lld\n", min(query(0, 0, n-1, 0, r), query(0, 0, n-1, l, n-1)));
        	else printf("%lld\n", query(0, 0, n-1, l, r));
        }
    }
    return 0;
}