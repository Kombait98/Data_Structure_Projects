

#include <stdio.h>
#include <stdlib.h>

// struct "exemplo" possui dois campos
typedef struct exemplo
{
	int v; // inteiro "v"
	struct exemplo *prox; // ponteiro para o próximo elemento
} t_exemplo;


// variáveis ponteiros globais que guardam referência
// para a cabeça da lista e para o nó corrente
// cabeca da lista encadeada (começa com NULL)
t_exemplo *cabeca = NULL;
t_exemplo *corrente = NULL;


// função para criar uma lista
// recebe um valor inteiro e retorna um ponteiro do tipo t_exemplo
t_exemplo * criar_lista(int valor)
{
	// aloca espaço em memória
	t_exemplo * p = (t_exemplo*)malloc(sizeof(t_exemplo));

	// verifica se houve falha na alocação de memória
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	// se chegou aqui é porque foi feita a alocação com sucesso
	p->v = valor; // atribui o valor passado
	p->prox = NULL; // o próximo é NULL

	// faz a cabeca e o corrente apontar para p
	cabeca = corrente = p;
	// retorna o ponteiro alocado
	return p;
}


// função que adiciona um elemento à lista
// recebe a cabeca e o elemento a ser adicionado
// o elemento é inserido no FINAL da lista
t_exemplo* adicionar_lista(int v)
{
	// verifica se a cabeca é NULL (lista vazia), se for NULL,
	// então retorna o retorno da função criar_lista
	if(cabeca == NULL)
	{
		return criar_lista(v);
	}

	// se chegou aqui é porque a lista NÃO é vazia
	// aloca espaço em memória
	t_exemplo * p = (t_exemplo*)malloc(sizeof(t_exemplo));

	// verifica se houve falha na alocação de memória
	if(p == NULL)
	{
		printf("\nFalha ao alocar memoria\n");
		return NULL;
	}

	// atribui valores
	p->v = v;
	p->prox = NULL;

	// insere no FINAL da lista (obs.: também poderia ser no início)
	// aqui será feita a inserção no final,
	// a inserção no início fica como um desafio ;-)
	// para inserção no final, fazemos com que o próximo do nó
	// corrente aponte para o "p"
	corrente->prox = p;
	// o corrente passar a ser o "p"
	corrente = p;

	// retorna o ponteiro alocado
	return p;
}


// função que imprime a lista
void imprimir_lista()
{
	// variável ponteiro "aux" para percorrer a lista
	// inicialmente aponta para a "cabeca"
	t_exemplo *aux = cabeca;

	// enquanto "aux" for diferente de NULL
	while(aux != NULL)
	{
		// imprime o valor
		printf("%d\n", aux->v);
		// aponta para o próximo elemento da lista
		aux = aux->prox;
	}
}


// função para verificar se a lista está vazia
// retorna 1 se estiver vazia e 0 caso contrário
int lista_vazia()
{
	// se cabeca for NULL, então a lista está vazia
	if(cabeca == NULL)
		return 1;
	return 0;
}


// função para buscar um elemento na lista
// essa função recebe o valor a ser buscado e um ponteiro para ponteiro "ant"
// o "ant" servirá para guardarmos o anterior do elemento encontrado, pois
// iremos utilizar na remoção, assim fica mais otimizado para não ter que
// percorrer a lista novamente pois precisa-se do elemento anterior ao elemento
// que irá ser removido para ajustar corretamente a lista
// retorna o ponteiro para o elemento encontrado ou NULL se não encontrar
t_exemplo * buscar_elemento(int v, t_exemplo **ant)
{
	// se a lista estiver vazia, então não possui elementos,
	// portanto, retorna 0 indicando que NÃO achou.
	if(lista_vazia() == 1)
		return NULL;

	// variável "p" para percorrer a lista
	t_exemplo *p = cabeca;
	// variável "aux_ant" para guardar o anterior
	t_exemplo *aux_ant = NULL;
	// flag "achou" que indica se achou o elemento
	int achou = 0;

	// percorre a lista
	while(p != NULL)
	{
		// se achou, então retorna 1
		if(p->v == v)
		{
			achou = 1;
			break;
		}
		// atualiza o "aux_ant"
		aux_ant = p;
		// aponta para o próximo
		p = p->prox;
	}

	// verifica se achou
	if(achou == 1)
	{
		// se "ant" for diferente de NULL
		if(ant)
			*ant = aux_ant; // guarda "aux_ant"
		return p;
	}

	// se chegou aqui, então não achou
	return NULL;
}

// função que remove um elemento da lista
// retorna 1 se conseguiu remover e 0 caso contrário
int remover_elemento(int v)
{
	// variável que guarda a referência para o elemento anterior
	// do elemento que vai ser removido
	t_exemplo *ant = NULL;

	// busca pelo elemento a ser removido
	// passa a referência para o "ant" (ponteiro para ponteiro)
	// "elem" é o elemento que será removido
	t_exemplo * elem = buscar_elemento(v, &ant);

	// se for NULL, é porque não existe, então retorna 0
	if(elem == NULL)
		return 0;

	// se chegou aqui, é porque o elemento existe e será removido

	// se o anterior for diferente de NULL, então
	// faz o próximo do anterior apontar para o próximo
	// do elemento que será removido
	if(ant != NULL)
		ant->prox = elem->prox;

	// se o elemento a ser removido é igual ao corrente, ou seja,
	// é o último elemento, então faz o corrente apontar para o anterior
	if(elem == corrente)
		corrente = ant;

	// se o elemento a ser removido é igual a cabeca, ou seja,
	// é o primeiro elemento, então faz a cabeca apontar para o próximo
	// do elemento a ser removido
	if(elem == cabeca)
		cabeca = elem->prox;

	// por último, dá um free no elemento a ser removido "elem" e coloca para NULL
	free(elem);
	elem = NULL;

	// retorna 1 indicando que removeu com sucesso
	return 1;
}

// função que retorna o tamanho da lista
int tamanho_lista()
{
	if(lista_vazia())
		return 0;

	t_exemplo *aux = cabeca;
	int tam = 0;

	while(aux != NULL)
	{
		tam++;
		aux = aux->prox;
	}
	return tam;
}

// função principal
int main(int argc, char * argv[])
{
	// função que verifica se a lista está vazia
	if(lista_vazia() == 0)
		printf("A lista NAO esta vazia!!\n\n");
	else
		printf("Lista vazia!!\n\n");
	
	printf("Tamanho da lista: %d\n\n", tamanho_lista());

	// cria uma lista passando o valor
	printf("Criando uma lista...\n\n");
	criar_lista(10);

	// adiciona outros elementos à lista
	printf("Adicionando elementos na lista...\n\n");
	adicionar_lista(20);
	adicionar_lista(30);
	adicionar_lista(40);
	adicionar_lista(50);

	// chama a função para imprimir a lista
	printf("Imprimindo os elementos da lista:\n");
	imprimir_lista();

	if(lista_vazia() == 0)
		printf("\nA lista NAO esta vazia!!\n");
	else
		printf("\nLista vazia!!\n");
	
	printf("\nTamanho da lista: %d\n", tamanho_lista());

	// buscando um elemento na lista
	// retorna diferente de NULL se achou e NULL caso contrário
	if(buscar_elemento(10, NULL) != NULL)
		printf("\nElemento 10 encontrado!\n");
	else
		printf("\nElemento 10 NAO encontrado.\n");

	if(buscar_elemento(100, NULL) != NULL)
		printf("\nElemento 100 encontrado!\n");
	else
		printf("\nElemento 100 NAO encontrado.\n");

	// removendo um elemento 30 da lista
	// a função retorna 1 se conseguiu remover e 0 caso contrário
	if(remover_elemento(30))
		printf("\nElemento 30 removido com sucesso!\n");
	else
		printf("\nNAO foi possivel remover o elemento 30.\n");

	printf("\nImprimindo os elementos da lista:\n");
	imprimir_lista();
	
	printf("\nTamanho da lista: %d\n", tamanho_lista());

	return 0;
}
