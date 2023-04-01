#include "common.h"

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

//descobre o programa a configurar // 100%
void config(char* &arg){
    if(arg==NULL){
        printf("Falta arguementos após --config\n");
    }else{
        sprintf(cmd, "%s %s%s",editor, path, arg);
        system(cmd);
    }
}

//Remove das configurações // 100%
void remove_config(char* &arg){
    int ret;
    sprintf(cmd,"%s%s",path, arg);
    ret = remove(cmd);
    if(ret != 0){
        printf("Não foi possivel remover o arquivo %s\n",cmd);
    }
}
