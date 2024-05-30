import socket
from myPackage.graphics import update_graph

def get_ip_address():
    # Crear un socket temporal
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        # No se necesita conectar a un servidor real, solo usarlo para obtener la IP
        s.connect(("8.8.8.8", 80))
        ip_address = s.getsockname()[0]
    except Exception as e:
        ip_address = "No se pudo obtener la IP"
        print(f"Error: {e}")
    finally:
        s.close()
    return ip_address

def getValues(msg):
    return tuple(map(int,msg.split(',')))

UDP_IP = "0.0.0.0"  # Escuchar en todas las interfaces
UDP_PORT = 4210  # Puerto que coincide con el del Arduino



# Crear un socket UDP
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

server_ip = get_ip_address()
print(f"Servidor UDP escuchando en {server_ip}:{UDP_PORT}")


print("Esperando mensajes UDP en el puerto", UDP_PORT)

while True:
    data, addr = sock.recvfrom(1024)  # Tamaño del buffer
    try:
        dataString =  data.decode('utf-8')
        tuplaValues = getValues(dataString)
        print(tuplaValues[0])
        update_graph(tuplaValues)
       # print("Desde:", addr)
    except UnicodeDecodeError:
        print("error")