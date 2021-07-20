#include "matriz.hpp"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
	system("cls||clear");
	setlocale(LC_ALL, "Portuguese");
	int maiorCaminho, sizeMatriz;
	Matriz m;
	
	cout << "Entre o tamanho da matriz quadrada: ";
	cin >> sizeMatriz;
	cin.ignore();
	maiorCaminho = m.maiorCaminhoMatriz(sizeMatriz);
	cout << "Valor do maior caminho = " << maiorCaminho << "\n\n";
	m.imprimeMatriz(sizeMatriz);

	return 0;
}
