/******************************************************************************

Pedro de Abreu Palma - 03/05/2023

Aplicação de bandas

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define TAMANHO 100   

    typedef struct{
             char nome[20];
             char estilo[20];
             int tamanho;
             int rank;
    } BANDA;

void buscarPorNome (BANDA*busca,int qt) {
    char estilo[20];
    int achou=0;
    printf("\nInforme o estilo: ");
    scanf ("%s", estilo);
    for (int i=0;i<qt;i++) {
        if(strcmp(busca[i].estilo,estilo)==0){
            printf("Nome: %s\n", busca[i].nome);
            printf("Ranking: %d\n", busca[i].rank);
            achou = 1;
        }
    }
    if (!achou) {
        printf("Não foi encontrada bandas com esse estilo %s\n\n", estilo);
    }

}
void exibeBANDA (BANDA*exib, int qt) {
    for(int i=0; i<qt; i++) {
        printf("Banda %d\n", i+1);
        printf("Nome: %s\n", exib[i].nome);
        printf("Ranking: %d\n", exib[i].rank);
        printf("Quantidade de integrantes: %d", exib[i].tamanho);
        printf("\n");
        }
    
}

int leBANDA (BANDA*v, int quant) {
    printf("\n.\n");
    for(int i=0;i<quant;i++) {
        printf("\nNome da banda: "); scanf("%s",v[i].nome);
        printf("Estilo musical: "); scanf("%s",v[i].estilo);
        printf("Qtnde de integrantes: "); scanf("%d", &v[i].tamanho);
        printf("Posicao no ranking"); scanf("%d",&v[i].rank);
    }
    return quant;
}
void menu () {
    BANDA v[TAMANHO]; 
    int op = 0, quant = 0;
    while (op != 9){
    printf("\n\n 1. Digitar as Bandas \n\n 2. Listar Todas as Bandas \n\n 3. Procurar pelo estilo musical \n\n 4. Definir qntde de bandas (max 100) \n\n 9. Encerrar \n\n");
    printf("\n\nDigite sua opção: ");
    scanf("%d", &op);
    
        
    if (op==1)
        leBANDA (v,quant);
    if (op==2) {
        printf("\n\nLISTAGEM DE TODAS AS BANDAS CADASTRADAS");
        exibeBANDA (v, quant);
    }
    if(op==3){
        buscarPorNome (v,quant);
    }
    if(op==4){
        printf("\n\nDigite a qtde de bandas: ");
        scanf("%d", &quant);
    };
} 

}
int main () {
    menu();
    return 0;
}
