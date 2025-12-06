
import socket

host = '127.0.0.1'
port = 13

request = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM)as s:
    s.connect(host, port)
    s.sendall(request.encode)

    data = s.recv(4096).decode

    print("Risposta dal server: ")
    print(data)