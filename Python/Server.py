
import socket

host = '127.0.0.1'
port = 13

html = """\
HTTP/1.1 200 ok 
Content-Type: text/html; charset = utf-8

<!DOCTYPE HTML>
<html>
<head>
    <title>Pagina ricevuta dal server<title>
</head>
<body>
    <h1> Bella fra </h1>
    <p> Questa è la pagina ricevuta dal server </p>
</body>
</html>
"""

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(host, port)
    s.listen(5)
    print("Server in ascolto...")

    while true:
        conn, addr = s.accept()

        with conn: 
            print("Connessione effettuata.")
            request = conn.recv(1024).deocode()
            
            conn.sendall(html.encode)