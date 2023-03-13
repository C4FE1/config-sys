#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <ctype.h>
#include <filesystem>
#include <unistd.h>

#define EDITOR "nano"

#define PATH "/home/kohi/Sources/config-sys/configs/"
#define MODULES "/home/kohi/Sources/config-sys/modules/"
#define LINUX_SRC "/home/kohi/Sources/config-sys/src/Linux/"
//#define SRC "/home/kohi/Sources/config-sys/src/"
#define RIAMU "/home/kohi/Sources/riamu/"

using namespace std;

char cmd[200];
const char* path = PATH ;
const char* modules = MODULES ;
//const char* src = SRC ;
const char* editor = EDITOR ;
const char* linux_src = LINUX_SRC ;
const char* riamu = RIAMU ;

//Desabilita serviços 0%
void disable(char* &name){
    sprintf(cmd,"python %sdisabler.py %s", modules, name);
    system(cmd);
}

//Habilita serviços 0%
void enable(char* &name){

}

//Remove das configurações // 100%
void remove(char* &arg){
    int ret;
    sprintf(cmd,"%s%s", path, arg);
    ret = remove(cmd);
    if(ret != 0){
        printf("Não foi possivel remover o arquivo %s\n",cmd);
    }
}

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
}

//descobre o programa a iniciar ou habilitar // 10%
void set(char* &arg, char* &arg2){
    if(string(arg)=="fstab"){
        sprintf(cmd,"%sgensfatb",modules);
        system(cmd);
    }else if(string(arg)=="kernel"){
        //placeholder
        //printf("kenele\n");
    }else if(string(arg)=="locale"){

    }else if(string(arg)=="editor"){
        sprintf(cmd,"python %seditor.py %s",modules,arg2);
        system(cmd);
        memset(cmd, '\0', sizeof(cmd)); //Limpa a vareavel cmd
    }else{
        printf("Argumento: %s invalido\n",arg);
    }
}

//descobre o programa a configurar // 100%
void config(char* &arg){
    if(arg==NULL){
        printf("Falta arguementos após --config\n");
    }else if(arg=="kernel"){
        //sprintf(cmd,"%s make menuconfig",linux_src);
        system(cmd);
    }else if(arg=="riamu"){

    }else{
        //sprintf(cmd," %s%s", path, arg);
        //execvp(editor,cmd);
        sprintf(cmd, "%s %s%s",editor, path, arg);
        //asprintf(cmd,"%s %s%s",editor, path, arg); //ideal
        //execvp(cmd);
        system(cmd);
        //printf("%s\n",cmd);
    }
}

//descobre o programa a listar // 10%
void list(char* &arg){
    if(string(arg)=="settings"){
        sprintf(cmd,"ls %s",path);
        printf("As opções são:\n");
        system(cmd);
    }else if(string(arg)=="services"){
        //system("systemctl list-units");
        //system("");
        printf("serviço\n");
    }else if(string(arg)=="locale"){
        system("locale -a ");
    }else if(string(arg)=="kernel"){
        sprintf(cmd,"python %slister.py %s", modules, linux_src);
        system(cmd);
    }else{
        printf("Falta argumentos após --list\n");
        exit(0);
    }
}

//faz os links simbolicos // 100%
void add(char* &arg, char* &name){
    //tenta executar o que está dentro
    try{
        sprintf(cmd,"%s%s", path, name);
        //usa um caminho do filesystem e declara como de
        filesystem::path de = arg;
        filesystem::path para = cmd;
        //cria um link simbolico do filesystem de para
        filesystem::create_symlink(de, para);
        //pega do filesystem o erro e transfere para erro
    } catch(filesystem::filesystem_error& erro){
        //pega qual (what) erro
        printf("ERRO: %s\n", erro.what());
    }
}
