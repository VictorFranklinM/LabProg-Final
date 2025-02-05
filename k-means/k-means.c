#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Kmeans(int lin, int col, int k);

struct pgm {
    int tipo;
    int c, r;
    int mv;
    unsigned char *pData;
};

int main(){
    struct pgm img;
    img.r = 3;
    img.c = 3;
    Kmeans(img.r,img.c,3);
}

void Kmeans(int lin, int col, int k){

    /* Centroids é o vetor que irá ser armazenar K tons de cinza para agrupar os pixels que se assemelham a cada cor central,
        vulgo centroide, em K conjuntos, vulgo clusters.
        Ex: Centroid[0] = 63 e Centroid[1] = 191.
        Pixels entre 0 e 127 irão ser clusterizados pelo centroid[0], enquanto pixels entre 128 e 255 irão ser
        clusterizados pelo centroid[1]. */
    unsigned char *centroids = (unsigned char*)calloc(k,sizeof(unsigned char));

    /* NewCentroids é o vetor utilizado para fazer a convergência dos valores centroides, fazendo com que 
        a cada interação os clusteres tenham um agrupamento mais preciso e o valor centroide represente melhor
        a média dos pixels associados.
        Ex: Temos um centroide de valor 50. Mas ao analisar a média dos pixels clusterizados, percebe-se que
        eles se aproximam mais ao tom "46", diante disso, o centroid 50 tem o seu valor alterado para 46,
        a realizar um agrupamento mais adequado, e esse processo se repete até que não haja mudança significativa.*/
    unsigned char *newCentroids = (unsigned char*)malloc(k * sizeof(unsigned char));

    /* ClusterSize irá contabilizar quantos pixels estão associados a cada centroid para que seja possivel
        calcular a média que será utilizada para determinar os centroides atualizados.*/
    int *clusterSize = (int*)calloc(k,sizeof(int));

    /* ClusterIndex é a variável utilizada para indicar qual cluster se aproxima mais ao pixel em questão.
        Utilizada para associar os pixels aos clusters correspondentes.*/
    int clusterIndex;

    /* Output é um vetor com as mesmas dimensões da imagem, aonde serão armazenados os dados dos pixels
        clusterizados para criar a imagem resultante.*/
    unsigned char *output = (unsigned char *)calloc((lin * col), sizeof(unsigned char));
    
    // Inicia os centroides com valores pseudo-aleatorios.
    srand(time(NULL));
    for(int i = 0; i<k; i++){
        *(centroids+i)=rand()%256;
    }

    /* A variável changed será usada em um laço while para checar se houve mudança ou não entre o novo centroide
        e o centroide anterior. O laço se repete enquanto changed for igual a 1, o que acontece sempre que a diferença
        entre os dois centroides é confirmada, fazendo a variavel receber o valor 0 no inicio do próximo loop.
        
        Threshold serve como um parâmetro para o encerramento do loop. Ao checar a diferença entre o centroide antigo
        e o novo centroide, caso a diferença seja menor que o valor de threshold, o loop se encerrará.

        A variável inter representa o número de interações realizadas para calcular o valor do centroide, e
        mx_inter é o número máximo de interações, interrompendo o loop caso o valor de inter o ultrapasse,
        servindo como uma segunda opção de interrupção do código fora o threshold. */
    int changed, threshold = 1, inter = 0, mx_inter = 100;
}
