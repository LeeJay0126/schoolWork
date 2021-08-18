import java.io.IOException;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

public class Server implements Protocol {
    public static void main(String[] args) throws IOException {

        ServerSocket server = new ServerSocket(PORT);
        while(true){

            Socket s = server.accept();
            System.out.println("Client accepted");
            GameHandler game = new GameHandler(s);
            Thread t = new Thread(game);
            t.start();

        }
    }
}


class GameHandler extends Thread implements Protocol {

    private Socket client;
    private DataInputStream in;
    private DataOutputStream out;
    private int randomNumber = 0;
    int count = 0;

    public GameHandler(Socket client){

        this.client = client;

        int number = (int)(Math.random()*(50) + 1);
        this.randomNumber = number;

    }

    public void run(){

        try{
            in = new DataInputStream(client.getInputStream());
            out = new DataOutputStream(client.getOutputStream());
            doService();
        } catch (IOException exception) {
            exception.printStackTrace();
        }finally{
            try{
                client.close();
            }catch(IOException e){
                e.printStackTrace();
            }
        }
    }

    private void doService() throws IOException{

        try{
            int command = 0;
            int result = 0;

            while(count < 6){
                command = in.readInt();

                if(command == this.randomNumber){
                    out.writeInt(CORRECT);
                    out.flush();
                    count++;
                }else if(count > 4){
                    out.writeInt(LOST);
                    out.writeInt(this.randomNumber);
                    out.flush();
                    count++;
                }else if(command > this.randomNumber){
                    out.writeInt(WASHIGHER);
                    out.flush();
                    count++;
                }else if(command < this.randomNumber){
                    out.writeInt(WASLOWER);
                    out.flush();
                    count++;
                }

            }

        }catch(IOException exception){
            getStackTrace();
        }

    }

}