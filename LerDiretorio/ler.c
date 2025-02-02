/*
 * C Program to List Files in Directory
	https://www.sanfoundry.com/c-program-list-files-directory/
 */
#include <dirent.h>
#include <stdio.h>
 
int main(void)
{
    // Inicio da medição do tempo
    DIR *d;
    int count = 0;
    struct dirent *dir;
    d = opendir("./images");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(dir->d_name[0]=='.'){
                continue;
            }
            count++;
            

            printf("%s\n", dir->d_name);

						// Leitura da Imagem -PGM

						
						
						// Saída.

             
        }
        closedir(d);
        printf("%d\n",count);
    }
    // Fim da medição do tempo           
    return(0);
}		