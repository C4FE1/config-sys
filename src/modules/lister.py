import os
import sys
import locale
import psutil

if sys.argv[1]=="locale":

    
    # abre o arquivo locale.gen e lê todas as linhas
    with open('/etc/locale.gen', 'r') as f:
        lines = f.readlines()

    # itera sobre as linhas e extrai os locais que já foram gerados
    generated_locales = []
    for line in lines:
        if not line.startswith('#') and line.strip() != '':
            locale_name = line.strip()
            generated_locales.append(locale_name)

    # imprime os locais gerados na tela
    lista=generated_locales
    for indice, arquivo in enumerate(lista):
        print(f"{indice + 1} - {arquivo}\n")
elif sys.argv[1]=="services":
    print("placeholder") 
    # Cria uma lista vazia para os serviços em execução e parados
    running_services = []
    stopped_services = []

    # Itera sobre todos os processos do sistema
    for proc in psutil.process_iter():
        try:
            # Obtém as informações do processo
            process_info = proc.as_dict(attrs=['name', 'status'])
            # Se o processo for um serviço do sistema, adiciona-o à lista apropriada
            if process_info['name'] == 'systemd':
                if process_info['status'] == 'running':
                    running_services.append(process_info)
                else:
                    stopped_services.append(process_info)
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass

    # Imprime os serviços em execução
    print("Serviços em execução:")
    for service in running_services:
        print(service['name'])

    # Imprime os serviços parados
    print("Serviços parados:")
    for service in stopped_services:
        print(service['name'])  
else:
    lista=os.listdir(sys.argv[1])
    for indice, arquivo in enumerate(lista):
        print(f"{indice + 1} - {arquivo}\n")
