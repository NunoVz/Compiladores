typedef struct no{
    char tipo;
    char anotacao;
    struct no *filho;
    struct no *irmao;

    int linha;
    int coluna;
} no;