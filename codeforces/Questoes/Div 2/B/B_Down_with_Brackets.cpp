#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        queue<char> s; 
        string x; cin >> x;

        for (int i = 0; i < x.size(); i++){
            s.push(x[i]);
        }

        int frente = 0;
        int tras = 0;
        int dupla = 0;
        
        while(!s.empty()){
            if (s.front() == '('){
                frente++;
                s.pop();
            }
            else if(s.front() == ')'){
                tras++;
                s.pop();
            }
            if (frente == tras) {
                dupla++;
                frente = 0;
                tras = 0;
            }
        }

        if (dupla > 1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}