#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char nome_medico[50];
    char data_nascimento[10];
    char sexo[10];
} Paciente;

void cadastro(Paciente **v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Cadastro paciente %d\n", i + 1);
        printf("==================\n");
        printf("Nome do paciente: ");
        scanf(" %[^\n]", v[i]->nome);
        printf("Nome do medico: ");
        scanf(" %[^\n]", v[i]->nome_medico);
        printf("Data de nascimento: ");
        scanf(" %[^\n]", v[i]->data_nascimento);
        printf("Sexo: ");
        scanf(" %[^\n]", v[i]->sexo);
        getchar();
    }
}

void verPacientes(Paciente **v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\nNome: %s | Nome do medico: %s | Data de nascimento: %s | Sexo: %s\n",
               v[i]->nome, v[i]->nome_medico, v[i]->data_nascimento, v[i]->sexo);
    }
}

void verPacientesCrescente(Paciente **v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (strcmp(v[i]->nome, v[j]->nome) > 0)
            {
                Paciente *aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printf("\nEM ORDEM CRESCENTE:\n");
    verPacientes(v, tam);
}

void verPacientesDescrescente(Paciente **v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (strcmp(v[i]->nome, v[j]->nome) < 0)
            {
                Paciente *aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printf("\nEM ORDEM DESCRESCENTE:\n");
    verPacientes(v, tam);
}

void excluirPaciente(Paciente **v, int *tam)
{
    char nome[50];
    printf("\nNome do paciente a ser excluido: ");
    scanf(" %[^\n]", nome);

    int x = -1;
    for (int i = 0; i < *tam; i++)
    {
        if (strcmp(v[i]->nome, nome) == 0)
        {
            x = i;
            break;
        }
    }

    if (x != -1)
    {
        free(v[x]);

        for (int i = x; i < *tam - 1; i++)
        {
            v[i] = v[i + 1];
        }

        (*tam)--;
    }
}

void excluirPorMedico(Paciente **v, int *tam)
{
    char nome[50];
    printf("\nNome do medico dos pacientes a serem excluido: ");
    scanf(" %[^\n]", nome);

    int x = -1;
    for (int i = 0; i < *tam; i++)
    {
        if (strcmp(v[i]->nome_medico, nome) == 0)
        {
            x = i;
            break;
        }
    }

    if (x != -1)
    {
        free(v[x]);

        for (int i = x; i < *tam - 1; i++)
        {
            v[i] = v[i + 1];
        }

        (*tam)--;
    }
}

int main()
{
    Paciente **x;
    int tam = 4;
    x = malloc(tam * sizeof(Paciente *));
    for (int i = 0; i < tam; i++)
        x[i] = malloc(sizeof(Paciente));
    cadastro(x, tam);
    verPacientesCrescente(x, tam);
    verPacientesDescrescente(x, tam);
    excluirPaciente(x, &tam);
    excluirPorMedico(x, &tam);
    verPacientes(x, tam);
    free(x);
    return 0;
}