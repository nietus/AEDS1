#include <stdio.h>

int main()
{
    float vc, vb;
    scanf("%f", &vc);
    scanf("%f", &vb);
    int qtd;
    scanf("%d", &qtd);
    float m[qtd];
    int zero = 0, um = 0, dois = 0, tres = 0;
    for (int i = 0; i < qtd; i++)
    {
        scanf("%f", &m[i]);
        if (m[i] == 0)
            zero++;
        if (m[i] == 1)
            um++;
        if (m[i] == 2)
            dois++;
        if (m[i] == 3)
            tres++;
    }
    float a = vc / (um + tres);
    float b = vb / (dois + tres);
    printf("%.2f\n", vc + vb);
    for (int i = 0; i < qtd; i++)
    {
        if (m[i] == 0)
            printf("0.00\n");
        else if (m[i] == 1)
            printf("%.2f\n", a);
        else if (m[i] == 2)
            printf("%.2f\n", b);
        else
            printf("%.2f\n", a + b);
    }
    return 0;
}