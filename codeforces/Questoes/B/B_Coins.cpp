#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    char F, S, oper;

    bool A_maior_B = false;
    bool A_menor_B = false;
    bool B_maior_C = false;
    bool B_menor_C = false;
    bool A_maior_C = false;
    bool A_menor_C = false;

    cin >> F >> oper >> S;

    if ((oper == '>' && F == 'A' && S == 'B') || (oper == '<' && F == 'B' && S == 'A')) A_maior_B = true;
    else if ((oper == '<' && F == 'A' && S == 'B') || (oper == '>' && F == 'B' && S == 'A')) A_menor_B = true;
    else if ((oper == '>' && F == 'B' && S == 'C') || (oper == '<' && F == 'C' && S == 'B')) B_maior_C = true;
    else if ((oper == '<' && F == 'B' && S == 'C') || (oper == '>' && F == 'C' && S == 'B')) B_menor_C = true;
    else if ((oper == '>' && F == 'A' && S == 'C') || (oper == '<' && F == 'C' && S == 'A')) A_maior_C = true;
    else if ((oper == '<' && F == 'A' && S == 'C') || (oper == '>' && F == 'C' && S == 'A')) A_menor_C = true;

    cin >> F >> oper >> S;

    if ((oper == '>' && F == 'A' && S == 'B') || (oper == '<' && F == 'B' && S == 'A')) A_maior_B = true;
    else if ((oper == '<' && F == 'A' && S == 'B') || (oper == '>' && F == 'B' && S == 'A')) A_menor_B = true;
    else if ((oper == '>' && F == 'B' && S == 'C') || (oper == '<' && F == 'C' && S == 'B')) B_maior_C = true;
    else if ((oper == '<' && F == 'B' && S == 'C') || (oper == '>' && F == 'C' && S == 'B')) B_menor_C = true;
    else if ((oper == '>' && F == 'A' && S == 'C') || (oper == '<' && F == 'C' && S == 'A')) A_maior_C = true;
    else if ((oper == '<' && F == 'A' && S == 'C') || (oper == '>' && F == 'C' && S == 'A')) A_menor_C = true;


    cin >> F >> oper >> S;

    if ((oper == '>' && F == 'A' && S == 'B') || (oper == '<' && F == 'B' && S == 'A')) A_maior_B = true;
    else if ((oper == '<' && F == 'A' && S == 'B') || (oper == '>' && F == 'B' && S == 'A')) A_menor_B = true;
    else if ((oper == '>' && F == 'B' && S == 'C') || (oper == '<' && F == 'C' && S == 'B')) B_maior_C = true;
    else if ((oper == '<' && F == 'B' && S == 'C') || (oper == '>' && F == 'C' && S == 'B')) B_menor_C = true;
    else if ((oper == '>' && F == 'A' && S == 'C') || (oper == '<' && F == 'C' && S == 'A')) A_maior_C = true;
    else if ((oper == '<' && F == 'A' && S == 'C') || (oper == '>' && F == 'C' && S == 'A')) A_menor_C = true;


    if (A_maior_B && B_maior_C && A_maior_C) cout << "CBA" << "\n";
    else if (A_maior_B && B_menor_C && A_maior_C) cout << "BCA" << "\n";
    else if (A_maior_B && B_menor_C && A_menor_C) cout << "BAC" << "\n";
    else if (A_menor_B && B_maior_C && A_maior_C) cout << "CAB" << "\n";
    else if (A_menor_B && B_maior_C && A_menor_C) cout << "ACB" << "\n";
    else if (A_menor_B && B_menor_C && A_menor_C) cout << "ABC" << "\n";
    else cout << "Impossible" << "\n";
}
