import os
import sys

argumento = sys.argv[1]

lista=os.listdir(sys.argv[1])

for indice, arquivo in enumerate(lista):
    print(f"{indice + 1} - {arquivo}")