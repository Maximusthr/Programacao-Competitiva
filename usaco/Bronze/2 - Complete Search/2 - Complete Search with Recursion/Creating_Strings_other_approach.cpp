#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string s;
vector<string> perm;
int carac[26];

void search(const string &aux = ""){
    if (aux.size() == s.size()){
        perm.push_back(aux);
        return;
    }
    for (int i = 0; i < 26; i++){
        if (carac[i] > 0){
            carac[i]--;
            search(aux + (char)('a' + i));
            carac[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> s;
    for (auto i : s) carac[i - 'a']++;
    
    search();

    cout << perm.size() << "\n";
    for (int i = 0; i < perm.size(); i++){
        cout << perm[i] << "\n";
    }
}
