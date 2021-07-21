<h1 align="center">Maior Caminho Matriz</h1>

<p align="center">Programa percorre matriz gerada a partir de números aleatórios através do maior caminho possível.</p>

- Compilador
                
       gcc version 9.3.0
- OS
       
       Ubuntu 20.04.2 LTS

- Executar
 
        terminal:
        ./maior-caminho-matriz/
        ./make clean
        ./make
        ./make run

<h4>Custo computacional do algoritmo desenvolvido: n^2</h4>

<p>(6n^2 + 10n + 5) + (2 + 1 + 2) + (n + n + n + n) + (n + 2n + n + n + n + n + n) + (n + 2n + n + n + n + n + n) + (2n + 2n + n + n + n + n + n + n + n + n) + (2n + n + n + n + n + n + n) + 1 = 6n^2 + 50n + 11 = n^2</p>

	int Matriz::maiorCaminhoMatriz(int sizeMatriz)
		preencherMatriz(sizeMatriz); // 4n^2 + 9n + 5

	  int i=0, j=0; // 2
		int soma=this->matriz[i][j]; // 1
		bool movAnteriorDireita=false, movAnteriorEsquerda=false; // 2

	  while(i != sizeMatriz-1 || j != sizeMatriz-1) // n
	    if(i == sizeMatriz-1) // n 
				soma += this->matriz[i][j+1]; // n
				j++; // n

	    else if(movAnteriorDireita) // n
				if(j+1 < sizeMatriz && this->matriz[i][j+1] > this->matriz[i+1][j]) // 2n
					soma += this->matriz[i][j+1]; // n
					j++; // n
				else
					soma += this->matriz[i+1][j]; // n
					i++; // n
					movAnteriorDireita=false; // n

	    else if(movAnteriorEsquerda) // n
				if(j-1 >=0 && this->matriz[i][j-1] > this->matriz[i+1][j]) // 2n
					soma += this->matriz[i][j-1]; // n
					j--; /n
				else
					soma += this->matriz[i+1][j]; // n
					i++; // n
					movAnteriorEsquerda=false; // n

			else
				if(j+1 < sizeMatriz && this->matriz[i][j+1] > this->matriz[i+1][j]) // 2n
					if(j-1 >= 0 && this->matriz[i][j-1] > this->matriz[i][j+1]) // 2n
						soma += this->matriz[i][j-1]; // n
						j--; // n
						movAnteriorEsquerda=true; // n
						movAnteriorDireita=false; // n
					else
						soma += this->matriz[i][j+1]; // n
						j++; // n
						movAnteriorDireita=true; // n
						movAnteriorEsquerda=false; // n

				else if(j-1 >= 0 && this->matriz[i][j-1] > this->matriz[i+1][j]) // 2n
					soma += this->matriz[i][j-1]; // n
					j--; // n
					movAnteriorEsquerda=true; // n
					movAnteriorDireita=false; // n
				else
					soma += this->matriz[i+1][j]; // n
					i++; // n
		return soma; // 1

	void Matriz::preencherMatriz(int sizeMatriz) // 1 + (2 + 2n)(2 + 2n + n) = 6n^2 + 10n + 5
		srand(time(NULL)); // 1
		for(int i=0; i < sizeMatriz; i++) // 2 + 2n
			for(int j=0; j < sizeMatriz; j++) // 2 + 2n
				this->matriz[i][j] = rand() % 100; // n
