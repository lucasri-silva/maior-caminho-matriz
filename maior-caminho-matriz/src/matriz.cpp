#include "matriz.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int Matriz::maiorCaminhoMatriz(int sizeMatriz)
{
	preencherMatriz(sizeMatriz);
	int i=0, j=0;
	int soma=this->matriz[i][j];
	bool movAnteriorDireita=false, movAnteriorEsquerda=false;
	while(i != sizeMatriz-1 || j != sizeMatriz-1)
	{
		if(i == sizeMatriz-1)//se i for o ultimo elemento da linha
		{
			soma += this->matriz[i][j+1];
			j++;
		}
		else if(movAnteriorDireita)
		{
			if(j+1 < sizeMatriz && this->matriz[i][j+1] > this->matriz[i+1][j])
			{
				soma += this->matriz[i][j+1];
				j++;
			}
			else
			{
				soma += this->matriz[i+1][j];
				i++;
				movAnteriorDireita=false;
			}
		}
		else if(movAnteriorEsquerda)
		{
			if(j-1 >=0 && this->matriz[i][j-1] > this->matriz[i+1][j])
			{
				soma += this->matriz[i][j-1];
				j--;
			}
			else
			{
				soma += this->matriz[i+1][j];
				i++;
				movAnteriorEsquerda=false;
			}
		}
		else
		{

			if(j+1 < sizeMatriz && this->matriz[i][j+1] > this->matriz[i+1][j])
			{
				if(j-1 >= 0 && this->matriz[i][j-1] > this->matriz[i][j+1])
				{
					soma += this->matriz[i][j-1];
					j--;
					movAnteriorEsquerda=true;
					movAnteriorDireita=false;
				}
				else
				{
					soma += this->matriz[i][j+1];
					j++;
					movAnteriorDireita=true;
					movAnteriorEsquerda=false;
				}
			}
			else if(j-1 >= 0 && this->matriz[i][j-1] > this->matriz[i+1][j])
			{
				soma += this->matriz[i][j-1];
				j--;
				movAnteriorEsquerda=true;
				movAnteriorDireita=false;
			}
			else
			{
				soma += this->matriz[i+1][j];
				i++;
			}
		}
	}
	return soma;
}

void Matriz::preencherMatriz(int sizeMatriz)
{
	srand(time(NULL));
	for(int i=0; i < sizeMatriz; i++)
	{
		for(int j=0; j < sizeMatriz; j++)
		{
			this->matriz[i][j] = rand() % 100;
		}
	}
}

void Matriz::imprimeMatriz(int sizeMatriz)
{
	for(int i=0; i < sizeMatriz; i++)
	{
		for(int j=0; j < sizeMatriz; j++)
		{
			cout << this->matriz[i][j] << '\t';
		}
		cout << endl;
	}
}
