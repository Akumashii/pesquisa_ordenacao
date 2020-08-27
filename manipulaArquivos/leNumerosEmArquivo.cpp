#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Ordenacao.h"
#include <locale.h>
#include <time.h>
using namespace std;

typedef struct no {
	int dado;
	struct no *ant, *prox;
} CelulaD;

CelulaD *inserirDesordenadoLista(int valor, CelulaD *l) {
	CelulaD *novo;
	CelulaD *p;
	novo = (CelulaD *)malloc(sizeof(CelulaD));
	novo->dado = valor;
	novo->ant = NULL;
	novo->prox = NULL;
	
	if (!l) return novo;
	
	for (p = l; p->prox; p = p->prox);
	
	p->prox = novo;
	novo->ant = p;
	
	return l;	
}

void exibirLista(CelulaD *l) {
	if (!l) return;
	
	for (; l ; l = l->prox) {
		cout << l->dado << endl;
	}
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	CelulaD *lista = NULL;
	vector<int> vetor;
	
	//solicita pro usuario nome do arquivo origem
	char nomeArquivo[200];
	cout << "Informe nome do arquivo fonte com n�meros: ";
	cin >> nomeArquivo;
	
	//abrir arquivo para leitura
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ifstream procuradorArquivo; 
    procuradorArquivo.open(nomeArquivo); 
 
   		
	//le o arquivo capturando os numeros
	int valor;
	
	while (procuradorArquivo >> valor) {
		vetor.push_back(valor);
		lista = inserirDesordenadoLista(valor, lista);
		//cout << valor << endl;
	}
	procuradorArquivo.close();
	cout << "Arquivo lido com sucesso!\n";
	
	/*
	cout << "Exibindo a lista" << endl;
	exibirLista(lista);
	
	cout << "Exibindo o vetor" << endl;
	for (long long int i = 0; i < vetor.size(); i++) {
		cout << vetor[i] << endl;
	}
	*/
	
	//Ordenacao.selecaoVetor(vetor);
	
	return 1;
}
