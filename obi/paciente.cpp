#include <bits/stdc++.h>
using namespace std; // Evitar usar em códigos grandes

int main()
{
    int a, b;
    cin >> a >> b;
    bool inf[a];
    for (int i = 0; i < a; i++)
    {
        inf[i] = true;
    }
    for (int i = 0; i < b; i++)
    {
        int p0, qtd, x;
        cin >> p0 >> qtd;
        for (int j = 0; j < qtd; j++)
        {
            cin >> x;
            inf[x - 1] = false;
        }
    }
    for (int i = 0; i < a; i++)
    {
        if (inf[i])
            cout << i + 1 << endl;
    }
    return 0;
}