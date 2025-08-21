//Arquivo ListaDinEncad.h

struct escola{
    char estado[3]; // Sigla do estado
    int ID; // ID da escola
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct escola al);
int insere_lista_inicio(Lista* li, struct escola al);
int insere_lista_ordenada(Lista* li, struct escola al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);
int consulta_lista_mat(Lista* li, int mat, struct escola *al);
int consulta_lista_pos(Lista* li, int pos, struct escola *al);
