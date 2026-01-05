#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int cont = 1;
int query(int l, int r){
    cout << "? " << l << " " << r << endl;

    int x; cin >> x;
    return x;
}

void solve(){
    int n; cin >> n;

    int seg = query(1, n);

    int l = 1, r = n;
    if (seg == 1 || seg == n){

    }
    else {
        int left = query(1, seg);
        if (left == seg) r = seg;
        else l = seg;
    }

    int ant = seg;
    while(r - l > 1){
        int mid = l + (r-l)/2;

        int atual = 0;
        if (mid > ant) atual = query(l, mid);
        else atual = query(mid, r);

        if (atual != ant){
            if (mid > ant) {
                l = mid;
                ant = query(mid, r);
            }
            else {
                r = mid;
                ant = query(l, mid);
            }
        }
        else {
            if (mid > ant) r = mid;
            else l = mid;
        }
    }

    cout << "! " << (ant == l ? r : l) << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}