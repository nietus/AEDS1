#include <iostream>
#include <iomanip>
#include <string>

class Carro
{
    // private
    std::string montadora;
    std::string modelo;
    int ano;
    float qtd_combustivel;
    float consumo;
    float km, km_inicial;

public:
    Carro(std::string _montadora, std::string _modelo, int _ano, float _km,
          float _consumo)
    {
        montadora = _montadora;
        modelo = _modelo;
        ano = _ano;
        km = _km;
        km_inicial = km;
        qtd_combustivel = 0;
        consumo = _consumo;
    }

    void encher(float qtd, float *c)
    {
        qtd_combustivel += qtd;
        *c = qtd_combustivel * consumo;
    }
    void andar(float qtd)
    {
        km += qtd;
        qtd_combustivel -= qtd / consumo;
    }
    float calc_auto() { return qtd_combustivel * consumo; }
    float comb() { return qtd_combustivel; }
    float km_ini() { return km_inicial; }
    float km_total() { return km; }
};

int main()
{
    std::string montadora, modelo;
    int ano, qtd_abastecida, qtd_andada;
    float km, consumo, qtd, f;

    std::cin >> montadora;
    std::cin >> modelo;
    std::cin >> ano;
    std::cin >> km;
    std::cin >> consumo;

    Carro *c = new Carro(montadora, modelo, ano, km, consumo);

    std::cin >> qtd_abastecida;
    for (int i = 0; i < qtd_abastecida; i++)
    {
        std::cin >> qtd;
        (*c).encher(qtd, &f);
    }

    std::cin >> qtd_andada;
    for (int i = 0; i < qtd_andada; i++)
    {
        std::cin >> qtd;
        (*c).andar(qtd);
    }

    if ((*c).calc_auto() > 0)
    {
        std::cout << std::setprecision(2) << std::fixed << f << std::endl;
        std::cout << std::setprecision(2) << std::fixed << (*c).km_total() - (*c).km_ini() << std::endl;
        std::cout << std::setprecision(2) << std::fixed << (*c).comb() << std::endl;
        std::cout << std::setprecision(2) << std::fixed << (*c).km_total() << std::endl;
        std::cout << std::setprecision(2) << std::fixed << (*c).comb() * consumo << std::endl;
    }
    else
        std::cout << "gasolina insuficiente";

    return 0;
}