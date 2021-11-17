import socket
import asyncio

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 12345    # Port to listen on (non-privileged ports are > 1023)

def sendMsg(data):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(bytes(data, 'utf-8'))

async def sendAsyncMsg(data):
    reader, writer = await asyncio.open_connection(
        '127.0.0.1', PORT)

    print(f'Send: {data!r}')
    writer.write(data.encode())
    await writer.drain()
    writer.close()

async def test():
    await sendAsyncMsg("turn on")
    await sendAsyncMsg("turn off")

if __name__ == '__main__':
    #sendMsg("test")
    sendMsg("turn off")
    sendMsg("turn on")
    sendMsg("home")
    #loop = asyncio.get_event_loop()
    #loop.run_until_complete(sendAsyncMsg("turn off"))
    #loop.run_until_complete(sendAsyncMsg("turn on"))
    #loop.run_until_complete(sendAsyncMsg("home"))
