# ifndef grafo_h
# define grafo_h
 
//protótipos das funções 
typedef struct grafo Grafo;
 
Grafo** alocarGrafo(int n);

Grafo** desalocarGrafo(Grafo **cidades, int n);

Grafo** leGrafo(Grafo **cidade, int n);

Grafo* encontraCaminho(Grafo **cidade, int n, int menorvalor, int aux, int n2, Grafo *d, Grafo *trajeto); 
 
void imprimeCaminho(int n, Grafo *d, Grafo *trajeto); 

# endif



