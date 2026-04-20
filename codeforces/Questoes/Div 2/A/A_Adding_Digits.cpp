#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll a, b, n; cin >> a >> b >> n;

    if (a % b == 0){
        cout << a;
        for (int i = 0; i < n; i++){
            cout << 0;
        }
        cout << "\n";
        return;
    }

    struct P {
        string valor;
        string s;
        int iter = 0;
    };

    queue<P> q;

    q.push({to_string(a), to_string(a), 0});

    string add;
    while(!q.empty()){
        string v = q.front().valor;
        string ori = q.front().s;
        int iter = 0;
        q.pop();

        if (iter == 10) continue;
        
        int num = stoi(v);
        if (num % b == 0) {
            add = ori;
            break;
        }

        for (int i = 0; i <= 9; i++){
            string aux = v;
            string aux2 = ori;
            aux.push_back(i + '0');
            aux2.push_back(i + '0');

            int x = stoi(aux) % b;
            if (x != 0) continue;
            q.push({to_string(x), aux2, iter + 1});
        }   
    }

    if (add.empty()){
        cout << -1 << "\n";
        return;
    }

    for (int i = add.size() - to_string(a).size(); i < n; i++){
        add.push_back('0');
    }

    cout << add << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}