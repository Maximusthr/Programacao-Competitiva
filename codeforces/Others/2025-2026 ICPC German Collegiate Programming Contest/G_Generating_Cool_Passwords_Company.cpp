#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void tipo(vector<string> &words, string s){
    // mudo do 3 tipo
    for (int k = 2; k < s.size(); k += 2){
        for (int i = 0; i < 26; i++){
            char c = 'a' + i;
            if (c == s[3]) continue;

            string copy = s;

            if (k == 2) copy[k] = 'A' + i;
            else copy[k] = 'a' + i;

            copy[k+1] = 'a' + i;

            words.push_back(copy);
        }
    }
    
}

void solve(){
    // a A ! 1
    // diferente em 2

    // 1!Aaaaaaaaaa
    // 1!Bbbbbbbbbb
    // 1!Cccccccccc
    // 1!Jjjjjjjjjj

    int n; cin >> n;
    vector<string> words;

    words.push_back("1!Aaaaaaaaaa");
    words.push_back("1!Bbbbbbbbbb");
    words.push_back("1!Cccccccccc");
    words.push_back("1!Dddddddddd");
    words.push_back("1!Eeeeeeeeee");
    words.push_back("1!Ffffffffff");
    words.push_back("1!Gggggggggg");
    words.push_back("1!Hhhhhhhhhh");
    words.push_back("1!Iiiiiiiiii");
    words.push_back("1!Jjjjjjjjjj");


    for (int i = 0; i < 12; i++){
        tipo(words, words[i]);
    }


    for (int i = 0; i < n; i++){
        cout << words[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}