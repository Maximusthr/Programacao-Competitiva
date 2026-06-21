#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    string s; getline(cin >> ws, s);
    int n = s.size();

    stack<double> pilha;
    for (int i = 0; i < n; i++){

        string aux;
        bool entrou = false;
        while ((s[i]-'0' >= 0) && (s[i]-'0') <= 9){
            aux += s[i];
            i++;
            entrou = true;
        }

        if (entrou){
            int j = 0;
            int a = (aux[j++]-'0');
            while (j < aux.size()){
                a *= 10;
                a += (aux[j++]-'0');
            }
            pilha.push((double)a);
        }
        else {
            if (s[i] == '+'){
                double a = pilha.top();                
                pilha.pop();
                double b = pilha.top();
                pilha.pop();

                pilha.push(b + a);
            }
            else if (s[i] == '-'){
                double a = pilha.top();                
                pilha.pop();
                double b = pilha.top();
                pilha.pop();

                pilha.push(b - a);
            }
            else if (s[i] == '*'){
                double a = pilha.top();                
                pilha.pop();
                double b = pilha.top();
                pilha.pop();

                pilha.push(a*b);
            }
            else if (s[i] == '/'){
                double a = pilha.top();                
                pilha.pop();
                double b = pilha.top();
                pilha.pop();

                pilha.push(b / a);
            }
            else if (s[i] == '%'){
                double a = pilha.top();                
                pilha.pop();
                double b = pilha.top();
                pilha.pop();

                pilha.push((ll)b % (ll)a);
            }
            else if (s[i] == '^'){
                double a = pilha.top();                
                pilha.pop();
                double b = pilha.top();
                pilha.pop();

                pilha.push(pow(b, a));
            }
        }
    }

    cout << fixed << setprecision(5) << pilha.top() << "\n";
}