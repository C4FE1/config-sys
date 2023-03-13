import sys
import os
import psutil

# nome do processo a ser finalizado
process_name = sys.argv[1]

# percorre todos os processos em execução
for proc in psutil.process_iter():
    try:
        # verifica se o nome do processo corresponde ao nome procurado
        if proc.name() == process_name:
            # finaliza o processo
            proc.terminate()
            print(f"O processo {process_name} foi finalizado com sucesso!")
    except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
        pass
