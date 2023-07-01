#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TAM = 3; // tamanho do tabuleiro
const int BOM = 2; // num de bombas

int ret_num_aleatorio(int);
void tabuleiroVazio(char n[TAM][TAM], int);
void imprimeTabuleiro(char n[TAM][TAM], int);
void criaBombas(char n[TAM][TAM], int BOM);
void calculaAdjacentes(char n[TAM][TAM], int TAM);
void pegaAdjacenteDaMascara(char n[TAM][TAM], char m[TAM][TAM], int TAM, int x, int y);
void trocaChar(char a, char b, char n[TAM][TAM], int TAM);
void passarValor(char n[TAM][TAM], char m[TAM][TAM], int TAM);
int checaVitoria(char n[TAM][TAM], char m[TAM][TAM], int TAM);

int main(void)
{
    srand(time(NULL));
    int vitoria = 0, x, y, x2, y2; // x,y para selecionar coordenada, x2,y2 para a bandeirinha;
    char tab[TAM][TAM], mascarado[TAM][TAM], copia_do_original[TAM][TAM], opcao,
        bandeira;
    tabuleiroVazio(tab, TAM);
    criaBombas(tab, BOM);
    calculaAdjacentes(tab, TAM);
    tabuleiroVazio(mascarado, TAM);
    passarValor(copia_do_original, tab, TAM);
    trocaChar('x', '0', tab, TAM);
    imprimeTabuleiro(copia_do_original, TAM); // Tire o comentario para ativar o hack
    do
    {
        printf("\nEscolha x y: ");
        scanf("%d %d", &x, &y);
        if (x > TAM - 1 || x < 0 || y > TAM - 1 || y < 0)
        {
            printf("\nAs coordenadas so vao de [0.0] ate [%d.%d]\n", TAM - 1, TAM - 1);
            continue;
        }
        pegaAdjacenteDaMascara(tab, mascarado, TAM, x, y);
        if (copia_do_original[x][y] == 'x')
            break;
        imprimeTabuleiro(mascarado, TAM);
        do
        {
            printf("\nDeseja colocar uma bandeirinha? s/n\n");
            scanf(" %c", &bandeira);
            printf("\n");
            if (bandeira == 's' || bandeira == 'S')
            {
                printf("\nEscolha x y da bandeira: ");
                scanf("%d %d", &x2, &y2);
                if (x2 > TAM - 1 || x2 < 0 || y2 > TAM - 1 || y2 < 0)
                {
                    printf("\nAs coordenadas so vao de [0.0] ate [%d.%d]\n", TAM - 1, TAM - 1);
                    continue;
                }
                mascarado[x2][y2] = '!';
            }
            else
                continue;
        } while (bandeira != 'n' && bandeira != 'N');
        imprimeTabuleiro(mascarado, TAM);
        if (checaVitoria(mascarado, copia_do_original, TAM) == 1)
        {
            vitoria = 1;
            break;
        }
    } while (copia_do_original[x][y] != 'x');
    if (vitoria == 0)
        printf("\nTinha uma bomba na coordenada %d %d!\n", x, y);
    if (vitoria == 1)
        printf("\nParabens, voce marcou todas as bombas!\n");
    printf("\nEsse era o tabuleiro!\n");
    imprimeTabuleiro(copia_do_original, TAM);
    return 0;
}

int ret_num_aleatorio(int limite)
{
    return rand() % (limite + 1) + 1;
} // func pra retornar num random

int checaVitoria(char n[TAM][TAM], char m[TAM][TAM], int TAM)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (m[i][j] == 'x' && n[i][j] != '!')
                return 0;
        }
    }
    return 1;
}

void tabuleiroVazio(
    char n[TAM][TAM],
    int TAM)
{ // func pra inicializar o tabuleiro com um monte de 0
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            n[i][j] = '0';
        }
    }
}

void imprimeTabuleiro(char n[TAM][TAM],
                      int TAM)
{ // func padrao pra imprimir o tabuleiro
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%c  ", n[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}

void criaBombas(char n[TAM][TAM], int BOM)
{
    int x, y, checa = 1;
    x = ret_num_aleatorio(TAM - 1);
    y = ret_num_aleatorio(TAM - 1);
    n[x - 1][y - 1] = 'x';
    while (checa < BOM)
    {
        x = ret_num_aleatorio(TAM - 1);
        y = ret_num_aleatorio(TAM - 1);
        if (n[x - 1][y - 1] != 'x')
        {
            n[x - 1][y - 1] = 'x';
            checa++;
        }
    }
}

void trocaChar(char a, char b, char n[TAM][TAM], int TAM)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (n[i][j] == a)
                n[i][j] = b;
        }
    }
}

void passarValor(char n[TAM][TAM], char m[TAM][TAM], int TAM)
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            n[i][j] = m[i][j];
        }
    }
}

void calculaAdjacentes(
    char n[TAM][TAM],
    int TAM)
{ // func para acessar os valores adjantes às bombas
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            if (n[i][j] == 'x')
            // daqui pra baixo eh pra bloquear que o programa modifique coordenadas
            // indesejadas
            {
                if (j != TAM - 1)
                { // n passar da ultima coluna
                    if (n[i][j + 1] != 'x')
                        n[i][j + 1] += 1;
                }
                if (j != 0)
                { // n passar da primeira coluna
                    if (n[i][j - 1] != 'x')
                        n[i][j - 1] += 1;
                }
                if (i != 0)
                { // n passar da primeira linha
                    if (n[i - 1][j] != 'x')
                        n[i - 1][j] += 1;
                }
                if (i != TAM - 1)
                { // n passar da ultima linha
                    if (n[i + 1][j] != 'x')
                        n[i + 1][j] += 1;
                }
                if (i != 0 &&
                    j != TAM - 1)
                { // n passar da primeira linha/ultima coluna
                    if (n[i - 1][j + 1] != 'x')
                        n[i - 1][j + 1] += 1;
                }
                if (i != TAM - 1 &&
                    j != 0)
                { // n passar da ultima linha/primeira coluna
                    if (n[i + 1][j - 1] != 'x')
                        n[i + 1][j - 1] += 1;
                }
                if (i != TAM - 1 && j != TAM - 1)
                { // n passar da ultima linha/coluna
                    if (n[i + 1][j + 1] != 'x')
                        n[i + 1][j + 1] += 1;
                }
                if (i != 0 && j != 0)
                { // n passar da primeira linha/coluna
                    if (n[i - 1][j - 1] != 'x')
                        n[i - 1][j - 1] += 1;
                }
            }
        }
    }
}

void pegaAdjacenteDaMascara(char n[TAM][TAM], char m[TAM][TAM], int TAM, int i,
                            int j)
{
    if (n[i][j] != 'x' && n[i][j] != '!')
    // daqui pra baixo eh pra bloquear que o programa modifique coordenadas
    // indesejadas
    {
        m[i][j] = n[i][j];
        if (m[i][j] == '0' || m[i][j] == 'x')
            m[i][j] = ' ';
        if (j != TAM - 1)
        { // n passar da ultima coluna
            m[i][j + 1] = n[i][j + 1];
            if (m[i][j + 1] == '0' || m[i][j + 1] == 'x')
                m[i][j + 1] = ' ';
        }
        if (j != 0)
        { // n passar da primeira coluna
            m[i][j - 1] = n[i][j - 1];
            if (m[i][j - 1] == '0' || m[i][j - 1] == 'x')
                m[i][j - 1] = ' ';
        }
        if (i != 0)
        { // n passar da primeira linha
            m[i - 1][j] = n[i - 1][j];
            if (m[i - 1][j] == '0' || m[i - 1][j] == 'x')
                m[i - 1][j] = ' ';
        }
        if (i != TAM - 1)
        { // n passar da ultima linha
            m[i + 1][j] = n[i + 1][j];
            if (m[i + 1][j] == '0' || m[i + 1][j] == 'x')
                m[i + 1][j] = ' ';
        }
        if (i != 0 && j != TAM - 1)
        { // n passar da primeira linha/ultima coluna
            m[i - 1][j + 1] = n[i - 1][j + 1];
            if (m[i - 1][j + 1] == '0' || m[i - 1][j + 1] == 'x')
                m[i - 1][j + 1] = ' ';
        }
        if (i != TAM - 1 && j != 0)
        { // n passar da ultima linha/primeira coluna
            m[i + 1][j - 1] = n[i + 1][j - 1];
            if (m[i + 1][j - 1] == '0' || m[i + 1][j - 1] == 'x')
                m[i + 1][j - 1] = ' ';
        }
        if (i != TAM - 1 && j != TAM - 1)
        { // n passar da ultima linha/coluna
            m[i + 1][j + 1] = n[i + 1][j + 1];
            if (m[i + 1][j + 1] == '0' || m[i + 1][j + 1] == 'x')
                m[i + 1][j + 1] = ' ';
        }
        if (i != 0 && j != 0)
        { // n passar da primeira linha/coluna
            m[i - 1][j - 1] = n[i - 1][j - 1];
            if (m[i - 1][j - 1] == '0' || m[i - 1][j - 1] == 'x')
                m[i - 1][j - 1] = ' ';
        }
    }
}