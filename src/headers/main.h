#include "common.h"

//auxilia o usuario mostrando uma ajuda // 100%
void help(){
    printf("Argumentos disponíveis:\n");
    printf("--help\t\tExibe essa tela de ajuda\n");
    printf("--add\t\tAdiciona um arquivo de configuração\n");
    printf("--config\tConfigura um arquivo de configuração\n");
    printf("--set\t\tConfigurações do sistema ex:kernel,fstab,etc...\n");
    printf("--list\t\tLista os arquivos de configuração\n");
    printf("--enable\tHabilita um serviço\n");
    printf("--disable\tDesabilita um serviço\n");
    printf("--start\tInicia um serviço\n");
}

//descobre o programa a iniciar ou habilitar // 50%
void set(char* &arg, char* &arg2){
    if(string(arg)=="fstab"){
        sprintf(cmd,"%sgensfatb -U %s", modules, arg2);
        system(cmd);
    }else if(string(arg)=="kernel"){
    }else if(string(arg)=="locale"){

    }else if(string(arg)=="editor"){

      sprintf(cmd,"python %seditor.py %s",modules,arg2);
      system(cmd);
    }else{
        printf("Argumento: %s invalido\n",arg);
    }
}

//descobre o programa a listar // 100%
void list(char* &arg){
    if(string(arg)=="settings"){
        sprintf(cmd,"ls %s",path);
        printf("As opções são:\n");
        system(cmd);
    }else if(string(arg)=="services"){
        sprintf(cmd,"python %slister.py %s",modules,"services");
        system(cmd);
    }else if(string(arg)=="locale"){
        sprintf(cmd,"python %slister.py %s",modules,"locale");
        system(cmd);
    }else if(string(arg)=="kernel"){
        sprintf(cmd,"python %slister.py %s", modules, linux_src);
        system(cmd);
    }else{
        printf("Falta argumentos após --list\n");
        exit(0);
    }
}
