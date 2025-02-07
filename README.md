# Clusterização com K-means

Este é um projeto feito como trabalho final na cadeira de Laboratório de Programação.

O código é um algoritmo K-means, escrito na linguagem C, que lê imagens PGM (Portable Gray Map) dentro da pasta "images" e as clusteriza para um valor K, que deve ser determinado pelo usuário na hora da execução, gerando uma imagem PGM clusterizada ao fim do processo, que será guardada na pasta "results", dentro da pasta "images". O código também apresenta, no final, o tempo total necessário para clusterizar todas as imagens e a média do tempo necessário para clusterizar cada uma individualmente.

# Requisitos:

O código utiliza as bibliotecas "pgm.h" e "k-means.h". Antes de compilar e executar o programa, certifique-se de que as bibliotecas estão instaladas, respectivamente, dentro das pastas "pgm" e "k-means" e de que a pasta "images" existe, assim como a subpasta "results" dentro dela.

# Compilação:

Utilize um compilador para a linguagem C e digite "make" no terminal.

# Uso:

O programa recebe o valor K por linha de comando.

Ex: 
    ./nome_do_executavel 3
    
Esta execução fará com que todas as imagens dentro da pasta "images" sejam filtradas para apenas 3 tons de cinza, e as imagens filtradas poderão ser encontradas na subpasta "results". Além disso, o tempo de processamento será apresentado como mensagem no terminal.
