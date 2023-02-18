#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 100

typedef struct tipo_cliente
{
    char nome[TAM];
    int RG;
    struct tipo_cliente *proximo;
}Tcliente;

void inserirNovoCliente(Tcliente **cabeca, int n, int *C, int *M);
void inserirNovoClienteSequencial(Tcliente **usuario, int n, int tam, int *C, int *M);
void retirarCliente(Tcliente **cabeca, int n, int *C, int *M);
void retirarClienteSequencial(Tcliente **usuario, int n, int tam, int *C, int *M);
void listarEncadeado(Tcliente *cabeca);
void imprimeEspecifico(Tcliente *cabeca, int *C, int *M);
void buscarCliente(Tcliente *usuario, int op, int inic, int tam, int RG, int *C, int *M);
void ordenarLista(Tcliente **usuario, int n, int tam, int *C, int *M);
void ordenarListaQuickSort(Tcliente **usuario, int inicio, int fim, int *C, int *M);
void ordenarListaMergeSort(Tcliente **usuario, int inicio, int fim, int *C, int *M);
void merge(Tcliente *usuario, int inicio, int meio, int fim, int *C, int *M);
void lerListaArquivo(FILE *fp, int n, Tcliente *cabeca);
void lerListaArquivoSequencial(FILE *fp, int n, int tam, Tcliente *usuario);

int main()
{
    FILE *fp, *fp2;//Abrir arquivo
    clock_t t;//Marca o tempo em milissegundos
    char info[TAM], arq[30], arq2[30];//Armazena Nome e RG
    char lista;//Define lista Sequencial ou Encadeada
    int op;//Opções de Menu
    int C = 0, M = 0, caractere, quant_linhas = 0;

    //printf("%d\n\n", 1/2);
    printf("Informe o nome do arquivo a ser lido: \n");
    gets(arq);
    strcpy(arq2, arq);

    fp = fopen(arq, "r");//abrir o arquivo
    fp2 = fopen(arq2, "r");
    if(NULL == fp)
    {
        printf("O arquivo nao pode ser aberto =(.\n");
        system("Pause");
        exit(1);
    }

    //printf("Linhas arq = %d", quant_linhas);

    do{
        printf("\nEscolha uma lista para ser formada:\nE para Lista Encadeada\nS para Sequencial\n");
        scanf("%c", &lista);
    }while(lista != 'E' && lista != 'S');

    if(lista == 'E'){
        Tcliente *careca = NULL; //Ponteiro para a cabeça da lista
        Tcliente *noAtual, *inicio = NULL, *anterior;
        FILE *file;

        char *nome, *RG;//Armazena Nome RG

        t = clock();
        while(fgets(info, 30, fp) != NULL){
            //careca = malloc(sizeof(Tcliente));
            careca = (Tcliente*) malloc(sizeof(Tcliente));
            nome = (char*) strtok(info, ",");
            strcpy(careca->nome, nome);
            RG = (char*) strtok (NULL, ",");
            careca->RG = atoi(RG);
            careca->proximo = NULL;
            if(inicio == NULL){
                inicio = careca;
            }
            else{
                anterior->proximo = careca;
            }
            anterior = careca;
        }//Cria uma Lista Encadeada
        t = clock() - t;
        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        fclose(fp);

        do{
            printf("\n\nOpcoes: \n1 -> inserir novo cliente no inicio da lista;\n2 -> inserir um novo cliente no final da lista;");
            printf("\n3 -> inserir novo cliente em alguma posicao especifica;\n4 -> retirar o primeiro cliente da lista;\n5 -> retirar o ultimo cliente da lista;");
            printf("\n6 -> retirar um cliente especifico;\n7 -> procurar alguem baseado em seu RG;\n8 -> ordenar a lista;\n9 -> imprimir a lista;\n10 -> salvar lista em um arquivo;");
            printf("\n11 -> ler lista de um arquivo;\n12 -> sair do sistema.\n");
            scanf("%d", &op);
            switch(op){
                case 1: t = clock();//Inserir cliente no início da lista
                        inserirNovoCliente(&inicio, 1, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 2: t = clock();//Inserir cliente no Final da Lista
                        inserirNovoCliente(&inicio, 2, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 3: t = clock();//Inserir Clientes em Outras Partes da Lista
                        inserirNovoCliente(&inicio, 3, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 4: t = clock();//Retirar Cliente do Inicio da Lista
                        retirarCliente(&inicio, 4, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 5: t = clock();//Retirar Cliente do Final da Lista
                        retirarCliente(&inicio, 5, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 6: t = clock();//Retirar Cliente de Outras Partes da Lista
                        retirarCliente(&inicio, 6, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 7: t = clock();//encontrar um cliente Em Especifico pelo RG
                        imprimeEspecifico(inicio, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 8: break;//Ordenar a lista

                case 9: listarEncadeado(inicio); break;//Imprimir Lista

                case 10: lerListaArquivo(file, 9, inicio);//Criar um Arquivo
                        break;

                case 11: lerListaArquivo(file, 10, inicio);//Imprimir Arquivo
                         break;

                case 12: continue;//Sair

                default: printf("\n\n Opcao nao valida\n");
            }
            system("pause");
            system("cls"); //Limpa o buffer de entrada
            C = 0; M = 0;
        }while (op != 12);

        noAtual = careca;
        while(noAtual != NULL){
            careca = noAtual->proximo;
            free(noAtual);
            noAtual = careca;
        }
        return 0;
    }
    //printf("\n%s\n%s\n%s\n%s\n", careca->nome, careca->proximo->nome, careca->proximo->proximo->nome, careca->proximo->proximo->proximo->nome);
    else{
        FILE *fileS;
        Tcliente *usuario;
        char info[2*TAM], *pedaco, nome[TAM];
        int tam = 0;
        int RGS, Encontrou = 0;
        int op8, op7;
        t = clock();

        while((caractere = fgetc(fp2)) != EOF){
            if(caractere == '\n')
                quant_linhas++;
        }

        usuario = (Tcliente*) malloc(sizeof(Tcliente)*quant_linhas);
        while((fgets(info, 30, fp))!= NULL){
        //O pedaço recolhe as informaçoes do arquivo dividindo o nome e o RG
            pedaco = (char*) strtok(info, ",");
            strcpy(usuario[tam].nome, pedaco);
            pedaco = (char*) strtok (NULL, ",");
            usuario[tam].RG = atoi(pedaco);
            usuario[tam].proximo = NULL;
            tam++;
        }
        t = clock() - t;
        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        C = 0; M = 0;
        do{
            printf("\n\nOpcoes: \n1 -> inserir novo cliente no inicio da lista;\n2 -> inserir um novo cliente no final da lista;");
            printf("\n3 -> inserir novo cliente em alguma posicao especifica;\n4 -> retirar o primeiro cliente da lista;\n5 -> retirar o ultimo cliente da lista;");
            printf("\n6 -> retirar um cliente especifico;\n7 -> procurar alguem baseado em seu RG;\n8 -> ordenar a lista;\n9 -> imprimir a lista;\n10 -> salvar lista em um arquivo;");
            printf("\n11 -> ler lista de um arquivo;\n12 -> sair do sistema.\n");
            scanf("%d", &op);
            switch(op){
                case 1: t = clock();
                        tam++;
                        usuario = (Tcliente*) realloc(usuario, sizeof(Tcliente)*tam);
                        inserirNovoClienteSequencial(&usuario, 1, tam, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 2: t = clock();
                        tam++;
                        usuario = (Tcliente*) realloc(usuario, sizeof(Tcliente)*tam);
                        inserirNovoClienteSequencial(&usuario, 2, tam, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 3: t = clock();
                        tam++;
                        usuario = (Tcliente*) realloc(usuario, sizeof(Tcliente)*tam);
                        inserirNovoClienteSequencial(&usuario, 3, tam, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 4: t = clock();
                        tam--;
                        retirarClienteSequencial(&usuario, 4, tam, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 5: t = clock();
                        tam--;
                        retirarClienteSequencial(&usuario, 5, tam, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 6: t = clock();
                        tam--;
                        retirarClienteSequencial(&usuario, 6, tam, &C, &M);
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 7: system("cls");
                        printf("Digite o RG da pessoa que deseja encontrar: \n");
                        scanf("%d", &RGS);
                        printf("Escolha a forma de busca: \nI -> Busca Sequecial \nII -> Busca Binaria(apenas apos ordenar a lista)\n");
                        scanf("%d", &op7);
                        t = clock();
                        switch(op7)
                        {
                            case 1: buscarCliente(usuario, op7, 0, tam, RGS, &C, &M); break;
                            case 2: buscarCliente(usuario, op7, 0, tam-1, RGS ,&C, &M); break;
                            default: printf("\n\n Opcao nao valida\n");
                        }
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 8: system("cls");
                        printf("Escolha uma das formas de ordenar a lista: \nI -> Selection Sort;\nII -> Insert Sort;\nIII -> Bubble Sort;\n");
                        printf("IV -> Shell Sort;\nV -> Quick Sort;\nVI -> Merge Sort\n");
                        scanf("%d", &op8);
                        t = clock();
                        switch(op8)
                        {
                            case 1: ordenarLista(&usuario, 1, tam, &C, &M); break;
                            case 2: ordenarLista(&usuario, 2, tam, &C, &M); break;
                            case 3: ordenarLista(&usuario, 3, tam, &C, &M); break;
                            case 4: ordenarLista(&usuario, 4, tam, &C, &M); break;
                            case 5: ordenarListaQuickSort(&usuario, 0, tam-1, &C, &M); break;
                            case 6: ordenarListaMergeSort(&usuario, 0, tam-1, &C, &M); break;
                            default: printf("\n\n Opcao nao valida\n");
                        }
                        t = clock() - t;
                        printf("C(n) = %d\nM(n) = %d\n", C, M);
                        printf("Tempo de execucao: %lfms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                        break;

                case 9: system("cls");
                        for(int i = 0; i < tam; i++)
                        {
                            printf("Nome: %s, ", usuario[i].nome);
                            printf("RG: %d e Posicao: %d\n\n", usuario[i].RG, i);
                        }
                        break;

                case 10: lerListaArquivoSequencial(fileS, 9, tam, usuario);
                        break;

                case 11:lerListaArquivoSequencial(fileS, 10, tam, usuario);
                        break;

                case 12: continue;
                default: printf("\n\n Opcao nao valida\n");
            }
            system("pause");
            system("cls"); //Limpa o buffer de entrada
            C = 0; M = 0;
        }while (op != 12);
        return 0;
    }

}

void inserirNovoCliente(Tcliente **cabeca, int n, int *C, int *M)
{
    Tcliente *novoNo;
    char nome[30];
    int RG;

    printf("Digite o nome do Cliente: \n");
    scanf("%s", nome);
    printf("Digite seu RG: \n");
    scanf("%d", &RG);
    //Criação de Novo Nó
    novoNo = (Tcliente*) malloc(sizeof(Tcliente));
    strcpy(novoNo->nome, nome);
    novoNo->RG = RG;
    novoNo->proximo = NULL;

    if(n == 1){//Insere primeiro elemento
        *C = 1;
        Tcliente *CabecaVelha;

        CabecaVelha = (*cabeca);
        (*cabeca) = novoNo;
        novoNo->proximo = CabecaVelha;
        *M = 3;
    }
    else if(n == 2){//Insere ultimo elemento
        Tcliente *ultimo = *cabeca;
        *C = 2;
        *M = 1;
        while(ultimo->proximo != NULL){
            ultimo = ultimo->proximo;
            *M = *M + 1;
            *C = *C + 1;
        }
        ultimo->proximo = novoNo;
        *M = *M + 1;
    }
    else{//Insere elmentos em outros lugares
        int ps;
        Tcliente *posicao1 = *cabeca;
        Tcliente *posicao2 = (*cabeca)->proximo;
        *C = 3;
        *M = 1;
        do{
            printf("Escolha a posicao que deseja incluir:\n");
            scanf("%d", &ps);//Baseado no Binario
        }while(ps < 1);

        for(int i = 1; i < ps; i++){
            posicao1 = posicao1->proximo;
            posicao2 = posicao2->proximo;
            *M = *M + 2;
        }
        posicao1->proximo = novoNo;
        novoNo->proximo = posicao2;
        *M = *M + 2;
    }
}

void inserirNovoClienteSequencial(Tcliente **usuario, int n, int tam, int* C, int *M)
{
    Tcliente pessoa;
    char nome[30];
    int RG;

    printf("Digite o nome do Cliente: \n");
    scanf("%s", nome);
    printf("Digite seu RG: \n");
    scanf("%d", &RG);

    if(n == 1){
        *C = 1;
        *M = 0;
        for(int i = tam-1; i > 0; i--){
            strcpy((*usuario)[i].nome, (*usuario)[i-1].nome);
            (*usuario)[i].RG = (*usuario)[i-1].RG;
            *M = *M + 1;
            *C = *C + 1;
        }
        strcpy((*usuario)[0].nome, nome);
        (*usuario)[0].RG = RG;
    }

    else if(n == 2){
        *C = 2;
        strcpy((*usuario)[tam-1].nome, nome);
        (*usuario)[tam-1].RG = RG;
    }

    else{
        int ps;
        *C = 3;
        *M = 0;

        do{
            printf("Escolha a posicao que deseja incluir:\n");
            scanf("%d", &ps);//Baseado no Binario
            *C = *C + 1;
        }while(ps < 0 && ps > tam-1);

        for(int i = tam-1; i > 0; i--){
            *C = *C + 2;
            if(i == ps)
                break;

            strcpy((*usuario)[i].nome, (*usuario)[i-1].nome);
            (*usuario)[i].RG = (*usuario)[i-1].RG;
            *M = *M + 1;
        }
        *C = *C + 1;

        strcpy((*usuario)[ps].nome, nome);
        (*usuario)[ps].RG = RG;
    }
}

void retirarCliente(Tcliente** cabeca, int n, int *C, int *M)
{

    if(n == 4)
    {
        *C = 1;
        Tcliente *tpm = (*cabeca)->proximo;
        (*cabeca) = tpm;
        *M = 2;

    }
    else if(n == 5)
    {
        Tcliente *ultimoNo, *penultimo;
        *C = 2;
        ultimoNo = *cabeca;
        *M = 1;
        while (ultimoNo->proximo != NULL)
        {
            *C = *C + 1;
            penultimo = ultimoNo;
            ultimoNo = ultimoNo->proximo;
            *M = *M + 2;
        }
        *C = *C + 1;

        free(ultimoNo);
        penultimo->proximo = NULL;
        *M = *M + 1;

    }
    else
    {
        int ps;
        Tcliente *posicao1 = *cabeca;
        Tcliente *posicao2 = (*cabeca)->proximo;
        *C = 3;
        *M = 2;

        do{
            printf("Escolha a posicao que deseja excluir:\n");
            scanf("%d", &ps);//Baseado no Binario
            *C = *C + 1;
        }while(ps < 1);

        //posicao2 = posicao2->proximo;
        for(int i = 0; i < ps; i++){
            *C = *C + 1;
            if(ps == (i+1)){
                posicao1->proximo = posicao2->proximo;
                *M = *M + 1;
                continue;
            }
            *M = *M + 2;
            posicao1 = posicao1->proximo;
            posicao2 = posicao2->proximo;
        }
    }
}

void retirarClienteSequencial(Tcliente **usuario, int n, int tam, int *C, int *M)
{
    if(n == 4){
        *C = 1;
        *M = 0;
        for(int i = 0; i < tam; i++){
            *C = *C + 1;
            *M = *M + 1;
            strcpy((*usuario)[i].nome, (*usuario)[i+1].nome);
            (*usuario)[i].RG = (*usuario)[i+1].RG;
        }
        (*usuario) = (Tcliente*) realloc((*usuario), sizeof(Tcliente)*tam);
    }
    else if(n == 5){
        *C = 2;
        *M = 0;
        (*usuario) = (Tcliente*) realloc((*usuario), sizeof(Tcliente)*tam);
    }
    else{
        int ps;

        do{
            printf("Escolha a posicao que deseja excluir:\n");
            scanf("%d", &ps);//Baseado no Binario
            *C = *C + 1;
        }while(ps < 0);

        for(int i = 0; i < tam; i++){
            if(i >= ps){
                strcpy((*usuario)[i].nome, (*usuario)[i+1].nome);
                (*usuario)[i].RG = (*usuario)[i+1].RG;
                *M = *M + 1;
            }
        }
        (*usuario) = (Tcliente*) realloc((*usuario), sizeof(Tcliente)*tam);
    }
}

void listarEncadeado (Tcliente *cabeca)
{
    int i = 0;
    while (cabeca != NULL){
        printf("\nCliente: %s, RG: %d, Posicao: %d\n", cabeca->nome, cabeca->RG, i);
        cabeca = cabeca->proximo; //faz cabeça apontar para o proximo nó
        i++;
    }
}

void imprimeEspecifico(Tcliente *cabeca, int *C, int *M)
{
    int RG, Encontrou = 0;
    int i = 0;

    printf("Digite o RG da pessoa que deseja encontrar: \n");
    scanf("%d", &RG);
    *C = 0;
    *M = 0;

    while(cabeca != NULL){
        *C = *C + 1;
        if(RG == cabeca->RG){
            Encontrou = 1;
            printf("Nome: %s, ", cabeca->nome);
            printf("RG: %d e Posicao: %d\n\n", cabeca->RG, i);
            break;
        }
        i++;
        cabeca = cabeca->proximo;
        *M = *M + 1;
    }

    if(Encontrou == 0)
        printf("Sinto muito, %d nao foi encontrado.\n\n", RG);
}

void buscarCliente(Tcliente *usuario, int op, int inic, int tam, int RG, int *C, int *M)
{
    int Encontrou = 0;

    if(op == 1){
        *C = 1;
        for(int i = 0; i < tam; i++){
            *C = *C + 2;
            *M = *M + 1;
            if(usuario[i].RG == RG){
                Encontrou = 1;
                printf("\n\nNome: %s, ", usuario[i].nome);
                printf("RG: %d e Posicao: %d\n\n", usuario[i].RG, i);
                break;
            }
        }
        *C = *C + 1;
         if(Encontrou == 0)
            printf("Sinto muito, %d nao foi encontrado.\n\n", RG);
    }
    else{
        int meio;
        *C = 3;
        while(inic <= tam){
            *C = *C + 1;
            *M = *M + 1;
            meio = (inic+tam)/2;
            if(usuario[meio].RG == RG){
                *C = *C + 1;
                Encontrou = 1;
                printf("\n\nNome: %s, ", usuario[meio].nome);
                printf("RG: %d e Posicao: %d\n\n", usuario[meio].RG, meio);
                break;
            }
            else if(usuario[meio].RG < RG){
                *C = *C + 2;
                *M = *M + 1;
                inic = meio+1;
            }
            else{
                *C = *C + 3;
                *M = *M + 1;
                tam = meio-1;
            }
        }
        *C = *C + 1;
        if(Encontrou == 0)
            printf("Sinto muito, %d nao foi encontrado.\n\n", RG);
    }
}

void ordenarLista(Tcliente **usuario, int n, int tam, int *C, int *M)
{
    if(n == 1)
    {
        *C = 1;
        *M = 0;
        int i, j;
        Tcliente menor;

        for(i = 0; i < tam; i++){
            menor = (*usuario)[i];
            *C = *C + 2;
            *M = *M + 1;
            for(j = i+1; j < tam; j++){
                *C = *C + 1;
                if(menor.RG > (*usuario)[j].RG){
                    menor = (*usuario)[j];
                    (*usuario)[j] = (*usuario)[i];
                    (*usuario)[i] = menor;
                    *M = *M + 3;
                }
            }
        }
    }
    else if(n == 2){
        *C = 2;
        *M = 0;
        int i, j;
        Tcliente elem;

        for(i = 1; i < tam; i++){
            *C = *C + 2;
            *M = *M + 1;
            j = i-1;
            elem = (*usuario)[i];
            while(elem.RG < (*usuario)[j].RG){
                (*usuario)[j+1] = (*usuario)[j];
                (*usuario)[j] = elem;
                j--;
                *M = *M + 2;
            }
        }
    }
    else if(n == 3){
        *C = 3;
        *M = 0;
        int i, j;
        Tcliente elem;

        for(i = 0; i < tam; i++){
            *C = *C + 2;
            for(j = 0; j < tam - i - 1; j++){
                if((*usuario)[j].RG > (*usuario)[j + 1].RG){
                    elem = (*usuario)[j];
                    (*usuario)[j] = (*usuario)[j+1];
                    (*usuario)[j+1] = elem;
                    *M = *M + 3;
                }
            }
        }
        *C = *C + 1;
    }
    else{
        *C = 4;
        *M = 0;
        int i, j, h = 1;
        Tcliente elem;

        while(h < tam){
            h = 3*h+1;
            *C = *C + 1;
        }
        *C = *C + 1;

        //h = tam/10;
        do{
            h = h/3;
            for(i = h; i < tam; i++){
                elem = (*usuario)[i];
                j = i - h;
                *C = *C + 1;
                *M = *M + 1;
                while(j >= 0 && elem.RG < (*usuario)[j].RG){
                   (*usuario)[j+h] = (*usuario)[j];
                   j = j - h;
                   (*usuario)[j+h] = elem;
                   *M = *M + 2;
                }
            }
            *C = *C + 2;
        }while(h > 1);
    }
}

void ordenarListaQuickSort(Tcliente **usuario, int inicio, int fim, int *C, int *M)
{
    int i, j, pivo, elemAux;
    char nomeAux[TAM];

    pivo = (*usuario)[(inicio + fim)/2].RG;
    //pivo = ((*usuario)[left].RG + (*usuario)[right].RG + (*usuario)[(left + right)/2].RG)/3;
    i = inicio;
    j = fim;

    do{
        *C = *C + 1;
        while((*usuario)[i].RG < pivo){
            i++;
            *C = *C + 1;
        }
        *C = *C + 1;
        while((*usuario)[j].RG > pivo){
            j--;
            *C = *C + 1;
        }
        *C = *C + 1;
        if(i <= j){
            elemAux = (*usuario)[i].RG;
            strcpy(nomeAux, (*usuario)[i].nome);

            (*usuario)[i].RG = (*usuario)[j].RG;
            strcpy((*usuario)[i].nome, (*usuario)[j].nome);

            (*usuario)[j].RG = elemAux;
            strcpy((*usuario)[j].nome, nomeAux);

            *M = *M + 3;

            i++;
            j--;
        }
    }while(i <= j);

    *C = *C + 2;
    if(j > inicio){
        ordenarListaQuickSort(&(*usuario), inicio, j, C, M);
    }
    if(i < fim){
        ordenarListaQuickSort(&(*usuario), i, fim, C, M);
    }
}

void ordenarListaMergeSort(Tcliente **usuario, int inicio, int fim, int *C, int *M)
{
    int metade;
    if(inicio < fim){
        *C = *C + 1;
        metade = inicio + (fim - inicio)/2;
        ordenarListaMergeSort(&(*usuario), inicio, metade, C, M);
        ordenarListaMergeSort(&(*usuario), (metade + 1), fim, C, M);
        merge((*usuario), inicio, metade, fim, C, M);
    }
}

void merge(Tcliente *usuario, int inicio, int meio, int fim, int *C, int *M)
{
    int i, j, k;
    int n1 = meio - inicio +1;
    int n2 = fim - meio;
    Tcliente *L, *R;

    L = (Tcliente*) malloc (sizeof(Tcliente)*n1);
    R = (Tcliente*) malloc (sizeof(Tcliente)*n2);

    for(i = 0; i < n1; i++){
        *C = *C + 1;
        *M = *M + 1;
        L[i] = usuario[inicio + i];
    }
    for(j = 0; j < n2; j++){
        *C = *C + 1;
        *M = *M + 1;
        R[j] = usuario[meio + 1 + j];
    }
    *C = *C + 2;

    i = 0;
    j = 0;
    k = inicio;
    while(i < n1 && j < n2){
        *C = *C + 1;
        if(L[i].RG <= R[j].RG){
            *C = *C + 1;
            *M = *M + 1;
            usuario[k] = L[i];
            i++;
        }
        else{
            *C = *C + 2;
            *M = *M + 1;
            usuario[k] = R[j];
            j++;
        }
        k++;
    }
    *C = *C + 1;
    while(i < n1){
        *C = *C + 1;
        *M = *M + 1;
        usuario[k] = L[i];
        i++;
        k++;
    }
    *C = *C + 1;
    while(j < n2){
        *C = *C + 1;
        *M = *M + 1;
        usuario[k] = R[j];
        j++;
        k++;
    }
    *C = *C + 1;
    free(L);
    free(R);
}

void lerListaArquivo(FILE *fp, int n, Tcliente *cabeca)
{
    char arq1[TAM], arq2[TAM];

    if(n == 9){
        printf("Informe o nome do arquivo a ser Escrito: \n");
        scanf("%s", arq1);
        fp = fopen(arq1, "w");
        while(cabeca->proximo != NULL){
            fprintf(fp, "%s,%d\n", cabeca->nome, cabeca->RG);
            cabeca = cabeca->proximo;
        }
        fprintf(fp, "%s,%d\n", cabeca->nome, cabeca->RG);
        fclose(fp);

    }
    else{
        char c;
        printf("Informe o nome do arquivo a ser lido: \n");
        scanf("%s", arq2);

        fp = fopen(arq2, "r");

        if(NULL == fp)
        {
            printf("O arquivo nao pode ser aberto =(.\n");
            system("Pause");
            exit(1);
        }
        printf("\nImprimindo...\n");
        c = fgetc(fp);
        while (!feof(fp)) {
            putchar(c);
            c = fgetc(fp);
        }

        fclose(fp);
    }
}

void lerListaArquivoSequencial(FILE *fp, int n,int tam,Tcliente *usuario)
{
    char arq1[TAM], arq2[TAM];

    if(n == 9)
    {
        printf("Informe o nome do arquivo a ser Escrito: \n");
        scanf("%s", arq1);
        fp = fopen(arq1, "w");

        for(int i = 0; i < tam; i++){
            fprintf(fp, "%s,%d\n", usuario[i].nome, usuario[i].RG);
        }
        fclose(fp);
    }
    else{
        char c;
        printf("Informe o nome do arquivo a ser lido: \n");
        scanf("%s", arq2);

        fp = fopen(arq2, "r");

        if(NULL == fp)
        {
            printf("O arquivo nao pode ser aberto =(.\n");
            system("Pause");
            exit(1);
        }
        printf("\nImprimindo...\n");
        c = fgetc(fp);
        while (!feof(fp)) {
            putchar(c);
            c = fgetc(fp);
        }
    }
}
