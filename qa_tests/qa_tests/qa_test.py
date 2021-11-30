import socket
import asyncio
import time

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 12345    # Port to listen on (non-privileged ports are > 1023)

def sendMsg(data):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(bytes(data, 'utf-8'))

if __name__ == '__main__':
    sendMsg("turn on")
    time.sleep(1)

    sendMsg("turn off")
    sendMsg("home")
