/**
* @file h.cpp
*
* Created on 2025-09-06 at 09:10:52
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string m, n; 

vector<string> pm, pn; // possibilidades para m e para n

void get_m(int i, string &curr) {
    if (i == m.size()) {
        pm.pb(curr);
        return;
    }

    if (m[i] == '*') {
        curr.pb('1');
        get_m(i + 1, curr);
        curr.pop_back();
        curr.pb('0');
        get_m(i + 1, curr);
        curr.pop_back();
    } else {
        curr.pb(m[i]);
        get_m(i + 1, curr);
        curr.pop_back();
    }
}

void get_n(int i, string &curr) {
    if (i == n.size()) {
        pn.pb(curr);
        return;
    }
    
    if (n[i] == '*') {
        curr.pb('1');
        get_n(i + 1, curr);
        curr.pop_back();
        curr.pb('0');
        get_n(i + 1, curr);
        curr.pop_back();
    } else {
        curr.pb(n[i]);
        get_n(i + 1, curr);
        curr.pop_back();
    }
}

int decc(string &s, int l, int r) {
    int ret = 0;
    int pot = 1;
    for (int i = r; i >= l; i--) {
        ret += (s[i] - '0') * pot;
        pot *= 2;
    }
    return ret; 
}

int modBinary(const string &bits, int y) {
    int rem = 0;
    for (char c : bits) {
        int b = c - '0';        // assumes only '0'/'1'
        rem = ((rem << 1) + b) % y;
    }
    return rem;
}

int main() { _
    cin >> m >> n;

    string mm, nn;
    get_m(0, mm);
    get_n(0, nn);

    // cout << 'm' << endl;
    // for (int i = 0; i < pm.size(); i++) {    
    //     for (auto k : pm[i]) {
    //         cout << k;
    //     }
    //     cout << endl;
    // }
    
    // cout << 'n' << endl;
    // for (int i = 0; i < pn.size(); i++) {  
    //     for (auto k : pn[i]) {
    //         cout << k;
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < pm.size(); i++) {
        for (int j = 0; j < pn.size(); j++) {
            int Y = decc(pn[j], 0, pn[j].size() - 1);
            int X = modBinary(pm[i], Y);
            if (X % Y == 0) {
                cout << pm[i] << endl;
                return 0;
            }
        }
    }   
}