# Clusterização com K-means

O programa implementa o algoritmo **K-means** em C para processar imagens no formato **PGM (Portable Gray Map)**. Ele agrupa os pixels das imagens em **K** clusters, onde **K** é um valor definido pelo usuário na execução. As imagens de entrada devem estar dentro da pasta **"images"**, e as imagens processadas serão salvas na subpasta **"results"**. Além disso, são gerados histogramas das imagens na subpasta **"histogram"**. O programa também exibe o tempo de processamento total e a média de tempo de processamento por imagem.

## Estrutura do Projeto

```
LabProg-Final/
│── k-means/
│   ├── k-means.h
│   ├── k-means.c
│── pgm/
│   ├── pgm.h
│   ├── pgm.c
│── pgm-histogram/
│   ├── histogram.h
│   ├── histogram.c
│── images/
│   ├── (imagens de entrada)
│   ├── results/
│   ├── histogram/
│── main.c
│── Makefile
│── README.md
```

# Requisitos:

> [!WARNING]
> Informações sobre possíveis problemas na compilação.

Antes de compilar e executar o programa, certifique-se de que as pastas e arquivos necessários estão presentes:

1. **Pasta "pgm"**
   - Contém `pgm.h` e `pgm.c`
2. **Pasta "k-means"**
   - Contém `k-means.h` e `k-means.c`
3. **Pasta "pgm-histogram"**
   - Contém `histogram.h` e `histogram.c`
4. **Pasta "images"**
   - Contém as imagens de entrada
   - Contém a subpasta **"results"** para armazenar as imagens processadas
   - Contém a subpasta **"histogram"** para armazenar os histogramas gerados

# Compilação:

Para compilar o programa, em um compilador para a linguagem C, utilize o comando:

```
make
```

Isso gerará um executável chamado `prog.exe`.

Caso queira limpar os arquivos-objeto e as imagens processadas, utilize:

```
make clean
```

# Uso:

O programa recebe o valor **K** como argumento na linha de comando:

```
./nome_do_executável $${\color{green}3}$$
```
> [!NOTE]
> Caso o executável seja gerado pelo comando **"make"**, o nome padrão do executável será: **"prog.exe"**

Esta execução fará com que todas as imagens dentro da pasta **"images"** sejam clusterizadas em **3** tons de cinza. As imagens processadas serão salvas em **"images/results"**, e os histogramas serão salvos em **"images/histogram"**. Além disso, o tempo de processamento será apresentado como mensagem no terminal.
