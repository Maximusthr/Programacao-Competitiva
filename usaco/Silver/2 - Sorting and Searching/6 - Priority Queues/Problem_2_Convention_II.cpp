#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Cow{
    int cheg, dur;
    int id;
    bool operator>(const Cow& other) const{
        return id > other.id;
    }
};

void solve(){
    int n; cin >> n;

    vector<Cow> arr;

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr.push_back({x, y, i});
    }

    sort(arr.begin(), arr.end(), [&](Cow &x, Cow &y){
        if (x.cheg != y.cheg) return x.cheg < y.cheg;
        return x.dur <= y.dur;
    });

    priority_queue<Cow, vector<Cow>, greater<Cow>> pq;
    pq.push(arr[0]);

    int i = 1;
    ll ans = 0, time = arr[0].cheg;

    while (!pq.empty()){
        Cow v = pq.top();
        pq.pop();
        
        ans = max(ans, time - v.cheg);

        if (time < v.cheg) time = v.cheg + v.dur;
        else time += v.dur;

        while(i < n && arr[i].cheg <= time){
            pq.push(arr[i]);
            i++;
        }

        if (pq.empty() && i < n){
            pq.push(arr[i]);
            i++;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    solve();
}