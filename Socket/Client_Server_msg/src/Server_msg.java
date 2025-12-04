import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server_msg {
    public static void main(String[] args) {

        try{
            final int Server_port = 12345;

            ServerSocket server  = new ServerSocket(Server_port);

            System.out.println("server in ascolto sulla porta "+ Server_port);

            //accettazione connessione al client
            Socket clientSocket = server.accept();

            //inizalizzaione writer/reader
            PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            //lettura e stampa della stringa ricevuta dal client
            String receive = in.readLine();
            System.out.println("Ricevuto dal client: "+receive);

            //invio della risposta al client
            writer.println("Messaggio ricevuto!");


        }catch(IOException e){
            System.out.println(e.getMessage());
        }

    }
}