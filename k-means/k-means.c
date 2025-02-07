//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Victor Franklin Matias Silva
// Matricula : 20241045050170
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Caroline de Albuquerque Arrais
// Matricula : 20241045050260
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Lanai Giani Lima Oliveira
// Matricula : 20231045050351
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/
// Aluno : Kalebe Ribeiro Sousa
// Matricula : 20241045050421
// Avaliação 04 : Trabalho Final
// 04.505.23 − 2024.2 − Prof. Daniel Ferreira
// Compilador : gcc (MinGW.org GCC-6.3.0-1) 6.3.0
//∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗/

#include <stdio.h>
#include <stdlib.h>

void K_means(int k, int lin, int col, unsigned char *data){

    /* Centroids é o vetor que irá ser armazenar K tons de cinza para agrupar os pixels que se assemelham a cada cor central,
        vulgo centroide, em K conjuntos, vulgo clusters.
        Ex: Centroid[0] = 63 e Centroid[1] = 191.
        Pixels entre 0 e 127 irão ser clusterizados pelo centroid[0], enquanto pixels entre 128 e 255 irão ser
        clusterizados pelo centroid[1]. */
    int *centroids = (int*)malloc(k * sizeof(int));

    /* NewCentroids é o vetor utilizado para fazer a convergência dos valores centroides, fazendo com que 
        a cada interação os clusteres tenham um agrupamento mais preciso e o valor centroide represente melhor
        a média dos pixels associados.
        Ex: Temos um centroide de valor 50. Mas ao analisar a média dos pixels clusterizados, percebe-se que
        eles se aproximam mais ao tom "46", diante disso, o centroid 50 tem o seu valor alterado para 46,
        a realizar um agrupamento mais adequado, e esse processo se repete até que não haja mudança significativa.*/
    int *newCentroids = (int*)calloc(k, sizeof(int));
    
    /* ClusterSize irá contabilizar quantos pixels estão associados a cada centroid para que seja possivel
        calcular a média que será utilizada para determinar os centroides atualizados.*/
    int *clusterSize = (int*)calloc(k, sizeof(int));

    /* ClusterIndex é a variável utilizada para indicar qual cluster se aproxima mais ao pixel em questão.
        Utilizada para associar os pixels aos clusters correspondentes.*/
    int clusterIndex;

    /* Output é um vetor com as mesmas dimensões da imagem, aonde serão armazenados os dados dos pixels
        clusterizados para criar a imagem resultante.*/
    unsigned char *output = (unsigned char *)malloc((lin * col)* sizeof(unsigned char));

    // Evita execução caso não haja memória disponível.
    if(!(centroids && newCentroids && clusterSize && output)){
        puts("Memória indisponível.");
        exit(1);
    }
    
    // Inicia os centroides com valores proporcionais a K.
    for (int i = 0; i < k; i++) {
        *(centroids + i) = (255 * i) / (k - 1);
    }

    /* A variável changed será usada em um laço while para checar se houve mudança ou não entre o novo centroide
        e o centroide anterior. O laço se repete enquanto changed for igual a 1, o que acontece sempre que a diferença
        entre os dois centroides é confirmada, fazendo a variavel receber o valor 0 no inicio do próximo loop.
        
        Threshold serve como um parâmetro para o encerramento do loop. Ao checar a diferença entre o centroide antigo
        e o novo centroide, caso a diferença seja menor que o valor de threshold, o loop se encerrará.

        A variável inter representa o número de interações realizadas para calcular o valor do centroide, e
        mx_inter é o número máximo de interações, interrompendo o loop caso o valor de inter o ultrapasse,
        servindo como uma segunda opção de interrupção do código fora o threshold. */
    int changed, threshold = 1, iter = 0, max_iter = 100;

    /* Laço do...while: Executa pelo menos uma interação antes de checar o laço while, que confere se houve mudança no
        valor de centroide e se o número máximo de interações já foi atingido, caso na interação anterior o centroide tiver
        mudado e o número maximo de interações ainda não tiver sido atingido, percorre todos os pixels da imagem em
        forma de vetor e define a distância mínima inicial para 256
        (distância entre 0 e 255). */
    do {

        // Zera os vetores newCentroids e clusterSize antes de cada iteração.
        for (int i = 0; i < k; i++) {
            *(newCentroids + i) = 0;
            *(clusterSize + i) = 0;
        }

        /*Laço for: Calcula a distância entre a cor do pixel e a cor de cada um dos centroides, selecionando o que tem a
                menor distância para clusterizar o pixel em questão.
                Ex: minDist = 256 ; Pixel = 70 ; Centroide[0] = 90 ; Centroide[1] = 80
                    A distância entre o pixel e o centroide[0] será |70 - 90| = 20;
                    Como 20 é menor que minDist, a distância mínima se tornará 20 e clusterIndex será o número do cluster
                    o qual a subtração resultou nessa distância. Caso haja algum cluster que dê um resultado menor, tanto
                    minDist quanto clusterIndex serão substituidos novamente, até que o laço for percorra todos os valores
                    de K.*/
        for (int i = 0; i < (lin * col); i++) {
            int minDist = 256;
            for (int j = 0; j < k; j++) {
                int dist = abs(*(data + i) - *(centroids + j));
                if (dist < minDist) {
                    minDist = dist;
                    clusterIndex = j;
                }
            }

            /* Quando o laço for é encerrado, o vetor que será usado para criar a imagem resultante recebe a cor
                do centroide no qual o pixel foi clusterizado.*/
            *(output + i) = *(centroids + clusterIndex);

            /* NewCentroids recebe a cor do pixel alocado no cluster e soma o seu valor ao valor total do cluster. */
            *(newCentroids + clusterIndex) += *(data + i);

            /* ClusterSize recebe +1 no seu valor específico de cada cluste para cada pixel alocado. */
            (*(clusterSize + clusterIndex))++;
        }

        /* Define changed e totalChange para 0 e checa para cada centroide se há algum pixel associado a ele.
            Caso haja, divide o valor de newCentroids[i] (soma do valor de todos os pixels em i) pela quantidade
            de pixeis clusterizados para o centroide. Dessa forma, é possivel determinar a média dos pixels e
            definir um centroide mais preciso para o agrupamento. */
        changed = 0;
        int totalChange = 0;
        for (int i = 0; i < k; i++) {
            if (*(clusterSize + i) > 0) {
                *(newCentroids + i) /= *(clusterSize + i);
            } else {
                // Caso o cluster não tenha elementos, reposiciona para um valor aleatório dentro do intervalo.
                *(newCentroids + i) = rand() % 256;
            }

            /* TotalChange é a diferença entre o novo centroide e o antigo. Isso serve para checar o quanto o parametro
                mudou de um loop para o outro, servindo como condição de parada caso a mudança não seja significativa. */
            totalChange += abs(*(newCentroids + i) - *(centroids + i));

            /* Se o novo centroide é diferente do antigo, muda o valor de changed para 1, permitindo que o laço while
                seja continuado, ao mesmo tempo que muda o valor de centroide para aproximar ainda mais os valores. */
                if (*(newCentroids + i) != *(centroids + i)) {
                changed = 1;
                *(centroids + i) = *(newCentroids + i);
            }
        }

        // Para se a mudança total for menor que o threshold.
        if (totalChange < threshold) break;

    } while (changed && ++iter < max_iter);

    // Cria um vetor com os mesmos valores de centroids[k] para organizar as cores em ordem crescente.
    int *sortedCentroids = (int*)malloc(k * sizeof(int));

    // Evita execução caso não haja memória disponível.
    if(!(sortedCentroids)){
        puts("Memória indisponível.");
        exit(2);
    }

    for (int i = 0; i < k; i++){
        *(sortedCentroids+i) = *(centroids+i);
    }

    // Ordena os centróides em ordem crescente pelo método bubble sort.
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (*(sortedCentroids+i) > *(sortedCentroids+j)) {
                int temp = *(sortedCentroids+i);
                *(sortedCentroids+i) = *(sortedCentroids+j);
                *(sortedCentroids+j) = temp;
            }
        }
    }

    // Criar novos tons proporcionais a K distribuídos entre 0 e 255.
    int *newGrayLevels = (int*)malloc(k * sizeof(int));

    // Evita execução caso não haja memória disponível.
    if(!(newGrayLevels)){
        puts("Memória indisponível.");
        exit(3);
    }

    for (int i = 0; i < k; i++) {
        *(newGrayLevels+i) = (255 * i) / (k - 1);
    }

    /* Aplicar os novos tons de cinza proporcionalmente (Para cada pixel de output, se seu valor é igual a um centroide
    ordenado, substitui-o pelo tom correspondente.) */
    for (int i = 0; i < (lin * col); i++) {
        for (int j = 0; j < k; j++) {
            if (*(output + i) == *(sortedCentroids + j)) {
                *(output + i) = *(newGrayLevels + j);
                break;
            }
        }
    }

    // Salvar a imagem clusterizada
    for (int i = 0; i < lin * col; i++) {
        *(data + i) = *(output + i);
    }

    free(centroids);
    free(newCentroids);
    free(clusterSize);
    free(sortedCentroids);
    free(newGrayLevels);
    free(output);
}