#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    deque<ll> deq, deq_inv;
    ll sum = 0;
    
    ll oder = 0;
    ll inver = 0;

    while(n--){
        int x; cin >> x;
        if (x == 1){
            oder += sum;
            oder -= deq.back()*(ll)deq.size();
    
            inver -= sum;
            inver += deq_inv.front()*(ll)deq_inv.size();

            deq.push_front(deq.back());
            deq.pop_back();
            deq_inv.push_back(deq_inv.front());
            deq_inv.pop_front();
        }
        else if (x == 2){
            swap(oder, inver);
            swap(deq, deq_inv);
        }
        else {
            ll y; cin >> y;
            deq.push_back(y);
            deq_inv.push_front(y);
            sum += y;
            oder += y*(ll)deq.size();
            inver += sum;
        }

        cout << oder << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}