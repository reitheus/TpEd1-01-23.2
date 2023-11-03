# ifndef grafo_h
# define grafo_h
 
//protótipos das funções 
 
int** alocarGrafo(int **cidades, int n);

int** desalocarGrafo(int **cidades, int n);

int** leGrafo(int **cidade, int n);

int encontraCaminho(int **cidade, int n, int menorvalor, int aux, int n2, int distancia); 
 
void imprimeCaminho(int **cidades, int n, int distancia); 

# endif



