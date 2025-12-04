import java.net.*;
import java.util.Scanner;
import java.io.*;

public class Client_msg {

    public static void main(String[] args) {
        final String Server_ip = "192.168.60.173";
        final int Server_port = 12345;

        try {
            //creazione della socket
            Socket socket = new Socket(Server_ip, Server_port);
            Scanner input = new Scanner(System.in);

            //connessione più creazione degli writer e dei reader nella socket
            System.out.println("Connesso al server...");

            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            //inserimento della stringa e invio al server
            System.out.println("Inserisci una stringa: ");
            String msg = input.nextLine();

            writer.flush();

            writer.println(msg);

            //lettura e stampa della risposta
            String response = in.readLine();

            System.out.println("Ecco la risposta dal server: "+response);

            //chiusura della socket e dei writer/reader
            socket.close();
            in.close();
            writer.close();

        }catch(IOException e){
            System.out.println(e.getMessage());
        }

    }
}
