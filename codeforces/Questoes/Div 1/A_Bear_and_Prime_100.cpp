// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 e 97 (25 primos)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool isPrime(int n){
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0) return false;
    }

    return true;
}

int query(){
    string s; cin >> s;

    if (s == "yes") return 1;
    return 0;
}

void ask(int num){
    cout << num << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    vector<int> primos;
    for (int i = 2; i < 51; i++){
        if (isPrime(i)){
            primos.push_back(i);
        }
    }

    
    int p = 0;
    for (int i = 0; i < primos.size(); i++){
        ask(primos[i]);
        p += query();
        
        if (p == 2){
            cout << "composite" << endl;
            return 0;
        }
    }
    
    // 4 9 16 25 49 121
    vector<int> extra = {4, 9, 16, 25, 49};
    for (int i = 0; i < extra.size(); i++){
        ask(extra[i]);
        p += query();
        
        if (p == 2){
            cout << "composite" << endl;
            return 0;
        }
    }

    cout << "prime" << endl;
}