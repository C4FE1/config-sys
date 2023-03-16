import sys
import os
import psutil


# obtém o processo com PID 1
process = psutil.Process(1)
if len(sys.argv)<2:
    print("erro")
    exit()
if process.name() == "systemd":
    print("sistemad")
    os.system("systemctl enable {}" .format(sys.argv[1]))
elif process.name() == "runit" :
    print("run it")
    if os.path.exists(f"/var/service/{sys.argv[1]}"):
        # verifica se o arquivo é um link simbólico
        if os.path.islink(f"/var/service/{sys.argv[1]}"):
            print(f"{nome_arquivo} é um link simbólico.")
            #os.system("ln -s /etc/sv/{} /var/service/{}" .format(sys.argv[1],sys.argv[1]))
            print(f"O serviço {sys.argv[1]} já foi habilitado")
        else:
            print(f"{nome_arquivo} existe, mas não é um link simbólico.")
            #os.system("ln -s /etc/sv/{} /var/service/{}" .format(sys.argv[1],sys.argv[1]))
            print(f"O serviço {sys.argv[1]} já foi habilitado")
    else:
        print(f"{sys.argv[1]} não foi encontrado no diretório /var/service/.")
        os.system("ln -s /etc/sv/{} /var/service/{}" .format(sys.argv[1],sys.argv[1]))
else:
    print("init system não reconhecido")