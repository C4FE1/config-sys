import os
import sys
import locale

if sys.argv[1]=="locale":
    # obtem as chaves do dicionario de alias de localizacao
    keys = locale.locale_alias.keys()

    # concatena as chaves separadas por quebra de linha e imprime na tela
    print('\n'.join(keys))
else:
    lista=os.listdir(sys.argv[1])
    for indice, arquivo in enumerate(lista):
        print(f"{indice + 1} - {arquivo}\n")

'''
argumento = sys.argv[1]

lista=os.listdir(sys.argv[1])

for indice, arquivo in enumerate(lista):
    print(f"{indice + 1} - {arquivo}")
'''