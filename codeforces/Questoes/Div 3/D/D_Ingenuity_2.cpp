#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;
    
    string mov;
    pair<int, int> H, R;
    
    bool Hel_E = false;
    bool Rov_E = false;
    bool Hel_foi = false;
    bool Rov_foi = false;

    for (int i = 0; i < n; i++){
        if (s[i] == 'N'){
            if (R.first >= H.first && (Hel_foi)){
                Rov_foi = true;
                R.first--;
                mov.push_back('R');
            } 
            else {
                Hel_foi = true;
                H.first--;
                mov.push_back('H');
            }
        }
        else if (s[i] == 'S'){
            if (R.first <= H.first && (Hel_foi)){
                Rov_foi = true;
                R.first++;
                mov.push_back('R');
            } 
            else {
                Hel_foi = true;
                H.first++;
                mov.push_back('H');
            }
        } 
        else if (s[i] == 'E'){
            if (R.second >= H.second && (Rov_E)){
                Hel_E = true;
                H.second++;
                mov.push_back('H');
            } 
            else {
                Rov_E = true;
                R.second++;
                mov.push_back('R');
            }
        }
        else if (s[i] == 'W'){
            if (H.second >= R.second && (Rov_E)){
                Hel_E = true;
                H.second--;
                mov.push_back('H');
            } 
            else {
                Rov_E = true;
                R.second--;
                mov.push_back('R');
            }
        }
        
    }

    if (H == R && (((Hel_E && Rov_E) || (Hel_foi && Rov_foi)) || ((Hel_E || Rov_E) && (Hel_foi || Rov_foi)))){
        cout << mov << "\n";
    }
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}