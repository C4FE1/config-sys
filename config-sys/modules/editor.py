import fileinput
import sys

# Pega o valor do terceiro argumento passado para o programa em C
new_value = sys.argv[1]

# Altera a linha que define a definição EDITOR no arquivo.c
for line in fileinput.input('headers/main.h', inplace=True):
    if line.startswith('#define EDITOR'):
        line = f'#define EDITOR "{new_value}"\n'
    print(line, end='')
