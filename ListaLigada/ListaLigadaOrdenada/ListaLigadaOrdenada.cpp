#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		// procura o final da lista
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Digite o elemento que deseja excluir: " << endl;
	cin >> valor;
	NO* encontrado = posicaoElemento(valor);

	if (encontrado != NULL) {
		NO* aux = primeiro;
		NO* remover = NULL;

		if (aux->valor == valor) {
			remover = primeiro;
			primeiro = aux->prox;
			free(remover);
		}
		else if (aux->prox != NULL) {
			while (aux->prox->valor == valor) {
				remover = aux->prox;
				primeiro->prox = remover->prox;
				free(remover);
				break;
			}
		}
	}
	else {
		cout << "Elemento nao encontrado\n";
	}
}

void buscarElemento()
{
	int valor;
	cout << "Digite o elemento que deseja buscar: \n";
	cin >> valor;
	NO* encontrado = posicaoElemento(valor);
	NO* aux = primeiro;
	if (encontrado != NULL) {
		while (aux->prox->valor < valor) {
			aux = aux->prox;
		}
		NO* posicao = aux->prox;
		cout << "Elemento encontrado na posicao " << posicao << endl;
	}
	else {
		cout << "Elemento nao encontrado!\n";
	}
}

NO* posicaoElemento(int numero) {
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero) {
			break;
		}
		aux = aux->prox;
	}
	return aux;
}


