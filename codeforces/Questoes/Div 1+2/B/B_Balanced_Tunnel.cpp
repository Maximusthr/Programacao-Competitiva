#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    deque<int> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }

    queue<int> fila;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        fila.push(x);
    }

    vector<bool> id(n+1);

    int ans = 0;
    int cont = 0;
    while (!arr.empty()){
        int fr = arr.front();
        arr.pop_front();

        int x = fila.front();
        
        if (!id[fr] && x != fr){
            id[x] = true;
            fila.pop();
            arr.push_front(fr);
            ans++;
        } else {
            if (id[fr] && fr != x){
                while (!arr.empty() && arr.front() != x && id[arr.front()]) arr.pop_front();
            }
            else {
                id[fr] = true;
                fila.pop();
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}