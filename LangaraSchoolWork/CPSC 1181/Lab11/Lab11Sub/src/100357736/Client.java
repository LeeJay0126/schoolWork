import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.util.Random;

/**
 * Public class Client
 * client server that runs 5 clientservice threads simulatneously
 */
public class Client extends Thread implements Protocol{

    public static void main(String[] args) throws IOException {

        ClientService clientService = new ClientService();
        ClientService clientService2 = new ClientService();
        ClientService clientService3 = new ClientService();
        ClientService clientService4 = new ClientService();
        ClientService clientService5 = new ClientService();

        clientService.start();
        clientService2.start();
        clientService3.start();
        clientService4.start();
        clientService5.start();

    }
}

/**
 * Client service class
 * extends Thread and implements Protocol
 */
class ClientService extends Thread implements Protocol{
    /**
     * Empty constructor
     */
    public ClientService(){

    }

    /**
     * run method
     * When executed, creates a socket
     * there will be a random delay (sleep) for 100 - 400 ms before it executes
     * Then it will execute hard coded commands
     */
    public void run(){
        try {
            int response = 0;
            String response2 = "";

            Socket client = new Socket("localhost", PORT);
            DataInputStream in = new DataInputStream(client.getInputStream());
            DataOutputStream out = new DataOutputStream(client.getOutputStream());

            Random random = new Random();
            long randomNumber = random.nextInt(400) + 100;

            Thread.sleep(randomNumber);
            System.out.println("Adding 15 mouse");
            out.writeInt(ADD_ITEM);
            out.writeUTF("Mouse");
            out.writeInt(15);
            out.flush();
            response = in.readInt();
            responder(response);

            System.out.println("Adding 12 Monitors");
            out.writeInt(ADD_ITEM);
            out.writeUTF("Monitors");
            out.writeInt(15);
            out.flush();
            response = in.readInt();
            responder(response);

            System.out.println("Checking Inventory for monitors");
            out.writeInt(CHECK_INVENTORY);
            out.writeUTF("Monitors");
            out.flush();
            response = in.readInt();
            responder(response);
            response = in.readInt();
            System.out.println(response + " in stock");

            System.out.println("Take 5 Monitors");
            out.writeInt(TAKE_ITEM);
            out.writeUTF("Monitors");
            out.writeInt(5);
            out.flush();
            response = in.readInt();
            responder(response);
            response = in.readInt();
            System.out.println(response);

            System.out.println("Adding 3 KeyBoard");
            out.writeInt(ADD_ITEM);
            out.writeUTF("Keyboard");
            out.writeInt(3);
            out.flush();
            response = in.readInt();
            responder(response);

            System.out.println("Adding 5 HeadPhones");
            out.writeInt(ADD_ITEM);
            out.writeUTF("HeadPhones");
            out.writeInt(5);
            out.flush();
            response = in.readInt();
            responder(response);

            System.out.println("Get Threshold 8");
            out.writeInt(GET_THRESHHOLD);
            out.writeInt(8);
            out.flush();
            response = in.readInt();
            responder(response);
            response2 = in.readUTF();
            System.out.println(response2);

            System.out.println("Take 24 Mouse");
            out.writeInt(TAKE_ITEM);
            out.writeUTF("Monitors");
            out.writeInt(24);
            out.flush();
            response = in.readInt();
            responder(response);
            response = in.readInt();
            System.out.println(response);

            System.out.println("Get Threshold 10");
            out.writeInt(GET_THRESHHOLD);
            out.writeInt(10);
            out.flush();
            response = in.readInt();
            responder(response);
            response2 = in.readUTF();
            System.out.println(response2);

            System.out.println("Quit");
            out.writeInt(QUIT);
            out.flush();
            response = in.readInt();
            responder(response);

            client.close();



        } catch (IOException | InterruptedException exception) {
            exception.printStackTrace();
        }
    }

    /**
     * method responder
     * Depending on the integer being passed as a parameter
     * prints SUCCEED or FAILED
     * @param response
     */
    public void responder(int response){
        if(response == 5){
            System.out.println("Received: SUCCEED");
        }else{
            System.out.println("Received: FAILED");
        }
        System.out.println();
    }

}
