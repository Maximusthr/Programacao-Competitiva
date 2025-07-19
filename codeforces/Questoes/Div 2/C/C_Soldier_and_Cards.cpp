#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    deque<int> p1, p2;

    int a; cin >> a;
    for (int i = 0; i < a; i++){
        int x; cin >> x;
        p1.push_back(x);
    }

    int b; cin >> b;
    for (int i = 0; i < b; i++){
        int x; cin >> x;
        p2.push_back(x);
    }

    int turnos = 0;
    while(!p1.empty() && !p2.empty()){
        int c_p1 = p1.front();
        int c_p2 = p2.front();

        p1.pop_front();
        p2.pop_front();

        if (c_p1 > c_p2){
            p1.push_back(c_p2);
            p1.push_back(c_p1);
        }
        else {
            p2.push_back(c_p1);
            p2.push_back(c_p2);
        }

        turnos++;

        if (turnos > 300){
            cout << -1 << "\n";
            return 0;
        }
    }

    if (p1.empty()){
        cout << turnos << " " << 2 << "\n";
    }
    else cout << turnos << " " << 1 << "\n";

}