#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    deque<int> deq;
    int maior = -1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        maior = max(maior, x);
        deq.push_back(x);
    }

    vector<pair<int, int>> tipo;
    while(deq.front() != maior){
        int x = deq.front();
        deq.pop_front();
        int y = deq.front();
        deq.pop_front();
        
        tipo.push_back({x, y});
        if (x > y){
            deq.push_front(x);
            deq.push_back(y);
        }
        else {
            deq.push_front(y);
            deq.push_back(x);
        }
    }

    while(q--){
        ll x; cin >> x;
        if (x > tipo.size()){
            int rep = n-1;

            int pos = (x-tipo.size()) % rep;
            if (pos == 0) pos = n-1;    

            cout << maior << " " << deq[pos] << "\n";
        }
        else {
            x--;
            cout << tipo[x].first << " " << tipo[x].second << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}