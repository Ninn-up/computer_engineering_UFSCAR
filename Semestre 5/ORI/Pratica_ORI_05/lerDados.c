#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h"

int main() {
    FILE *file = fopen("DadosEnem.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);

    }

    char line[1024]; 
    int IDs[30228]; // Array para armazenar os IDs
    Lista* states[27]; // Array de listas encadeadas para armazenar os estados 
    
    // Inicializa o array de estados
    for (int i = 0; i < 27; i++) {
        states[i] = cria_lista(); // Aloca memória para cada estado
        
        if (states[i] == NULL) {
            perror("Erro ao criar lista para o estado");
            exit(1);
        }
    }

    char statesOrdered[27][3] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"}; // Array para armazenar a ordem dos estados

    int index = 0;

    // Lê o arquivo linha por linha
    while (fgets(line, sizeof(line), file)) {
        // Lê até o \n
        char buffer[1024];// = strtok(line, "\n"); // Remove o caractere de nova linha no final da linha
        strncpy(buffer,line,strlen(line)-1);
        buffer[strlen(line)-1] = '\0'; // Garante que o buffer seja uma string terminada em nulo
        //printf("%s\n",buffer);
        
        // Usa strtok para dividir a linha pelo delimitador ';'
        char *info = strtok(buffer, ";");
        
        // Cria um struct escola para armazenar os dados
        struct escola es;

        // Verifica se a linha contém dados
        if (info == NULL) {
            continue; // Pula linhas vazias
        }

        // O primeiro token lido será o índice primário (ID)
        IDs[index] = atoi(info); 
        es.ID = IDs[index]; // Armazena o ID na estrutura escola
        index++;    

        // Lê o segundo token (será o índice secundário (região))
        info = strtok(NULL, ";");
        if (info == NULL) {
            es.estado[0] = '\0'; // Se não houver segundo token, define estado como vazio
            continue; // Pula se não houver segundo token
        }
        else {
            strcpy(es.estado, info); // Copia os dois primeiros caracteres do estado
            //es.estado[2] = '\0'; // Garante que o estado seja uma string terminada em nulo
        }
        
        // Verifica se o estado está na lista de estados ordenados
        int found = 0;
        int position = 0;
        for (int i = 0; i < 27 && !(found); i++) {
            if (strcmp(info, statesOrdered[i]) == 0) {
                found = 1;
                position = i; // Armazena a posição do estado encontrado
            }
        }

        // Se o estado foi encontrado, armazena na lista de estados
        if (found) {
            insere_lista_final(states[position], es); // Armazena o estado na posição correspondente (lista encadeada)
        } else {
            printf("Estado desconhecido: %s\n", info); // Exibe mensagem de erro se o estado não for encontrado
        }

    }

    // Busca
    int id;
    char estado[3];
    struct escola es;

    printf("Qual o estado em que deseja buscar? Forneça apenas a sigla (ex: SP): \nCaso deseje sair, digite 'sair'\n-> ");
    scanf("%s", estado);

    while (strcmp(estado, "sair") != 0) { // Continua buscando enquanto o usuário não digitar "sair"
        printf("Digite o ID da escola que deseja buscar: ");
        scanf("%d", &id);

        int found = 0;
        int pos = 0;

        // Busca na lista de estados
        for (int i = 0; i < 27 && !(found); i++) {
            if (strcmp(statesOrdered[i], estado) == 0) {
                pos = i; // Armazena a posição do estado encontrado
                found = 1;

            }
        }

        if (!found) {
            printf("Estado não encontrado! %s\n", estado);
            fclose(file);
            return 1; // Encerra o programa se o estado não for encontrado
        }

        // Busca o ID na lista do estado encontrado
        found = 0; // Reseta a variável para buscar o ID

        for (int i = 0; i < 27 && !(found); i++) {
            if (consulta_lista_mat(states[pos], id, &es)) { // Consulta o ID na lista do estado encontrado
                printf("Escola encontrada! ID = %d, Estado = %s\n", es.ID, es.estado);
                found = 1;
            }
        }

        if (!found) {
            printf("ID nao encontrado! %d no estado %s\n", id, estado);
        }

        printf("Qual o estado em que deseja buscar? Forneca apenas a sigla (ex: SP): \nCaso deseje sair, digite 'sair'\n-> ");
        scanf("%s", estado);
    }

    
    // Libera a memória alocada para cada lista de estados
    for (int i = 0; i < 27; i++) {
        //imprime_lista(states[i]);
        libera_lista(states[i]); // Libera a memória alocada para cada lista de estados
    }

    // Libera a memória alocada para o array de listas
    fclose(file);

    return 0;
}