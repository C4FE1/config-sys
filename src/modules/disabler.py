import sys
import os
import psutil


# obtém o processo com PID 1
process = psutil.Process(1)

# exibe as informações do processo
#print(f"PID: {process.pid}")
#print(f"Nome: {process.name()}")
#print(f"Status: {process.status()}")
if process.name() == "systemd":
    print("sistemad")
    os.system("systemctl disable {}" .format(sys.argv[1]))
elif process.name() == "runit" :
    print("run it")
    os.system("rm /var/service/{}" .format(sys.argv[1]))
else:
    print("init system não reconhecido")