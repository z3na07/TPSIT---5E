import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {
    static void main() {
        try{
            //creazione della socket
            Socket s =  new Socket("localhost", 13);

            //inizalizzazione del bufferedreader
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(s.getInputStream(), "ISO-8859-1")
            );

            //lettura della risposta dal server
            String Risposta = in.readLine();

            //stampa della risposta e chiusura
            System.out.println("Risposta dal server: "+Risposta);

            in.close();
            s.close();

        }catch(Exception e){
            e.printStackTrace();
        }
    }
}