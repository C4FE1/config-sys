#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
// código de definição da constante aqui
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <ctype.h>
#include <filesystem>
#include <unistd.h>
#include <locale.h>

using namespace std;

//Constantes
const char editor[sizeof("nano")+1] = "nano";
const char linux_src[40] = "/home/kohi/Sources/config-sys/testing/";
const char path[40] = "/home/kohi/Sources/config-sys/configs/";
const char modules[39] =  "/home/kohi/Sources/config-sys/modules/";
const char config_sys_paths[57] = "/home/kohi/Sources/config-sys/configs/config-sys.config";
const char riamu[26] = "/home/kohi/Sources/riamu/";

//Variaveis
int i;
char cmd[300];
char cmd2[50];
#endif // COMMON_H_INCLUDED