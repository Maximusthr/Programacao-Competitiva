#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    char trump; cin >> trump;

    vector<string> C;
    vector<string> D;
    vector<string> H;
    vector<string> S;

    for (int i = 0; i < 2*n; i++){
        string s; cin >> s;

        if (s[1] == 'C') C.push_back(s);
        else if (s[1] == 'D') D.push_back(s);
        else if (s[1] == 'H') H.push_back(s);
        else S.push_back(s);
    }

    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    sort(H.begin(), H.end());
    sort(S.begin(), S.end());

    // olhos todos menos o naipe principal
    vector<string> ans;
    if (trump == 'C'){
        for (int i = 0; i < (int) D.size() - 1; i += 2){
            ans.push_back(D[i]);
            ans.push_back(D[i+1]);
        }
        if (D.size() % 2){
            if (C.size() > 0){
                ans.push_back(D[D.size() - 1]);
                ans.push_back(C[C.size() - 1]);
                C.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) H.size() - 1; i += 2){
            ans.push_back(H[i]);
            ans.push_back(H[i+1]);
        }
        if (H.size() % 2){
            if (C.size() > 0){
                ans.push_back(H[H.size() - 1]);
                ans.push_back(C[C.size() - 1]);
                C.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) S.size() - 1; i += 2){
            ans.push_back(S[i]);
            ans.push_back(S[i+1]);
        }
        if (S.size() % 2){
            if (C.size() > 0){
                ans.push_back(S[S.size() - 1]);
                ans.push_back(C[C.size() - 1]);
                C.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        if (C.size() % 2) {
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
        for (int i = 0; i < (int) C.size() - 1; i += 2){
            ans.push_back(C[i]);
            ans.push_back(C[i+1]);
        }

        for (int i = 0; i < (int) ans.size(); i += 2){
            cout << ans[i] << " " << ans[i+1];
            cout << "\n";
        }
    }
    else if (trump == 'D'){
        for (int i = 0; i < (int) C.size() - 1; i += 2){
            ans.push_back(C[i]);
            ans.push_back(C[i+1]);
        }
        if (C.size() % 2){
            if (D.size() > 0){
                ans.push_back(C[C.size() - 1]);
                ans.push_back(D[D.size() - 1]);
                D.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) H.size() - 1; i += 2){
            ans.push_back(H[i]);
            ans.push_back(H[i+1]);
        }
        if (H.size() % 2){
            if (D.size() > 0){
                ans.push_back(H[H.size() - 1]);
                ans.push_back(D[D.size() - 1]);
                D.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) S.size() - 1; i += 2){
            ans.push_back(S[i]);
            ans.push_back(S[i+1]);
        }
        if (S.size() % 2){
            if (D.size() > 0){
                ans.push_back(S[S.size() - 1]);
                ans.push_back(D[D.size() - 1]);
                D.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        if (D.size() % 2) {
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
        for (int i = 0; i < (int) D.size() - 1; i += 2){
            ans.push_back(D[i]);
            ans.push_back(D[i+1]);
        }

        for (int i = 0; i < (int) ans.size(); i += 2){
            cout << ans[i] << " " << ans[i+1];
            cout << "\n";
        }
    }
    else if (trump == 'H'){
        for (int i = 0; i < (int) C.size() - 1; i += 2){
            ans.push_back(C[i]);
            ans.push_back(C[i+1]);
        }
        if (C.size() % 2){
            if (H.size() > 0){
                ans.push_back(C[C.size() - 1]);
                ans.push_back(H[H.size() - 1]);
                H.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) D.size() - 1; i += 2){
            ans.push_back(D[i]);
            ans.push_back(D[i+1]);
        }
        if (D.size() % 2){
            if (H.size() > 0){
                ans.push_back(D[D.size() - 1]);
                ans.push_back(H[H.size() - 1]);
                H.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) S.size() - 1; i += 2){
            ans.push_back(S[i]);
            ans.push_back(S[i+1]);
        }
        if (S.size() % 2){
            if (H.size() > 0){
                ans.push_back(S[S.size() - 1]);
                ans.push_back(H[H.size() - 1]);
                H.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        if (H.size() % 2) {
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
        for (int i = 0; i < (int) H.size() - 1; i += 2){
            ans.push_back(H[i]);
            ans.push_back(H[i+1]);
        }

        for (int i = 0; i < (int) ans.size(); i += 2){
            cout << ans[i] << " " << ans[i+1];
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < (int) C.size() - 1; i += 2){
            ans.push_back(C[i]);
            ans.push_back(C[i+1]);
        }
        if (C.size() % 2){
            if (S.size() > 0){
                ans.push_back(C[C.size() - 1]);
                ans.push_back(S[S.size() - 1]);
                S.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) H.size() - 1; i += 2){
            ans.push_back(H[i]);
            ans.push_back(H[i+1]);
        }
        if (H.size() % 2){
            if (S.size() > 0){
                ans.push_back(H[H.size() - 1]);
                ans.push_back(S[S.size() - 1]);
                S.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        for (int i = 0; i < (int) D.size() - 1; i += 2){
            ans.push_back(D[i]);
            ans.push_back(D[i+1]);
        }
        if (D.size() % 2){
            if (S.size() > 0){
                ans.push_back(D[D.size() - 1]);
                ans.push_back(S[S.size() - 1]);
                S.pop_back();
            }
            else {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
        if (S.size() % 2) {
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
        for (int i = 0; i < (int) S.size() - 1; i += 2){
            ans.push_back(S[i]);
            ans.push_back(S[i+1]);
        }

        for (int i = 0; i < (int) ans.size(); i += 2){
            cout << ans[i] << " " << ans[i+1];
            cout << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}