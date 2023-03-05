#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <ctype.h>
#include <dirent.h>

//altere nano para o editor de texto de sua preferencia 
#define EDITOR "nano"

#define PATH "/usr/bin/config-sys/modules/"

#define SRC "/usr/bin/config-sys/src/"

using namespace std;

//descobre o programa a executar
void set(char* &arg, bool &flagA, bool &flagB, bool &flagC){
    const char* path = PATH ;
    const char* src = SRC ;
    char cmd[100];
    if(flagA == true){

    }else if(flagB == true){
        sprintf(cmd,"%s",src);
    }else if(flagC == true){

    }else{
        printf("Argumento invalido\n");
    }
}

//descobre o programa a configurar
void config(char* &arg,int argc){
    const char* editor = EDITOR ;
    const char* path = PATH ;
    char cmd[100];
    sprintf(cmd, "%s %s%s",editor, path, arg);
    system(cmd); 
}

//descobre o programa a listar
void list(char* &arg, int argc, bool &flagA, bool &flagB, bool &flagC){
    if(flagA == true){
        char cmd[100];
        const char* path = PATH ;
        sprintf(cmd,"ls %s",path);
        printf("As opções são:\n");
        system(cmd);
    }else if(flagB == true){
        system("systemctl list-units");
    }else if(flagC == true){
        system("locale -a ");
    }else{
        printf("Argumento Invalido\n");
        exit(0);
    }
}

//faz os links simbolicos
void add(char* &arg,int argc, char* &name){
    const char* path = PATH ;
    char cmd[100];
    sprintf(cmd, "ln -s %s %s%s", arg, path, name);
    system(cmd);
}

int main(int argc, char *argv[]){
    int i;

    //opções
    bool flag_set = false;
    bool flag_list = false;
    bool flag_conf = false;
    bool flag_add = false;
    bool flag_editor = false;
    bool flag_settings = false;
    bool flag_services = false;
    bool flag_fstab = false;
    bool flag_kernel = false;
    bool flag_locale = false;

    //verifica a quantidade de argumentos
    if(argc<=2){
        printf("ERRO:Falta argumentos\n");
    }else if(argc>=2){

        //altera o valor das opções de acordo com os argumentos
        for (i = 1; i < argc; i++){
            
            //printf("Argumentos: %s\n",argv[i]);

            if(string(argv[i]) == "--set"){
                flag_set=true;
            }
            else if(string(argv[i]) == "--list"){
                flag_list=true;
            }else if(string(argv[i-1])== "--config"){
                flag_conf=true;
            }else if(string(argv[i])=="--config"){
                flag_conf=true;
            }else if(string(argv[i])=="--add"){
                flag_add=true;
            }
        }
        //verifica qual argumento será usado e executa a devida função
        if(flag_set == true){
            if(string(argv[2])=="fstab"){
                flag_fstab=true;
            }else if(string(argv[2])=="kernel"){
                flag_kernel=true;
            }else if(string(argv[2])=="locale"){
                flag_locale=true;
            }
            set(argv[2],flag_fstab,flag_kernel,flag_locale);
            //printf("selecionei %s \n",argv[2]);
        }else if(flag_list == true){
            //verifica se o 3 argumento é "settings"
            if(string(argv[2])=="settings"){
                flag_settings=true;
            }else if(string(argv[2])=="services"){
                flag_services=true;
            }else if(string(argv[2])=="kernel"){

            }
            else if(string(argv[2])=="locale"){
                flag_locale=true;
            }
            list(argv[2],argc,flag_settings,flag_services,flag_locale);

        }else if(flag_conf == true){
            config(argv[2],argc);
        }else if(flag_add == true){
            add(argv[2],argc,argv[3]);
        }else{
            printf("Argumento não encontrado\n");
        }
    }
    
    return 0;
}
