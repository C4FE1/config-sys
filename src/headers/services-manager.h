#include "common.h"

//Inicia um serviço 100%
void start(char* &name){
    sprintf(cmd,"/var/service/%s",name);
    system(cmd);
}

//Desabilita serviços 100%
void disable(char* &name){
    int ret;
    sprintf(cmd,"/home/kohi/Sources/config-sys/%s", name);
    ret = remove(cmd);
    if(ret != 0){
        printf("Não foi possivel remover o arquivo %s\n",cmd);
    }
}

//Habilita serviços 100%
void enable(char* &name){
  //tenta executar o que está dentro
  try{
      sprintf(cmd,"/var/service/%s", name);
      sprintf(cmd2,"/etc/sv/%s",name);
      //usa um caminho do filesystem e declara como de
      filesystem::path de = cmd;
      filesystem::path para = cmd2;
      //cria um link simbolico do filesystem de para
      filesystem::create_symlink(de, para);
      //pega do filesystem o erro e transfere para erro
  }catch(filesystem::filesystem_error& erro){
      //pega qual (what) erro
      printf("ERRO: %s\n", erro.what());
  }
}
