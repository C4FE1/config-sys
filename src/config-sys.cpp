#include "headers/main.h"

int main(int argc, char *argv[]){
    //contador
    int i;

    //verifica a quantidade de argumentos
    if(argc<2){
        printf("Falta argumentos\n");
    }else if(argc>=2){
        if(string(argv[1]) == "--set"){
            set(argv[2], argv[3]);
        }else if(string(argv[1]) == "--list"){
            list(argv[2]);
        }else if(string(argv[1]) == "--config"){
            config(argv[2]);
        }else if(string(argv[1])=="--add"){
            add(argv[2], argv[3]);
        }else if(string(argv[1])=="--help"){
            help();
        }else if(string(argv[1])=="--remove"){
            remove(argv[2]);
        }else if(string(argv[1])=="--disable"){
            //disable(argv[2]);
            printf("função temporariamente removida\n");
        }else if(string(argv[1])=="--enable"){
            //enable(argv[2]);
            printf("função temporariamente removida\n");
        }else{
            if(argc>1){
                printf("Argumentos não encontrados:\n");
                for(i=1;i<argc;i++){
                    printf("%s ",argv[i]);
                }
                printf("\n");
            }else{
                printf("Argumento: %s não encontrado\n",argv[1]);
            }
        }
    }
    return 0;
}
