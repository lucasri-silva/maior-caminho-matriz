#ifndef __MATRIZ_HPP
#define __MATRIZ_HPP
#define N 5

using namespace std;

class Matriz
{
	private:
		int matriz[N][N];
	public:
		int maiorCaminhoMatriz(int sizeMatriz);
		void preencherMatriz(int sizeMatriz);
		void imprimeMatriz(int sizeMatriz);
};

#endif
