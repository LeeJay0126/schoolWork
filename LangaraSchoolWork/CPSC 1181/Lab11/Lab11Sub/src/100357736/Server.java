import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.SQLOutput;

/**
 * public class server
 * implements Protocol
 */
public class Server implements Protocol{
    /**
     * main method that hosts the server
     * @param args
     * @throws IOException
     */
    public static void main(String[] args) throws IOException{

        Inventory inventory = new Inventory();
        ServerSocket server = new ServerSocket(PORT);

        while(true){
            System.out.println("Waiting for clients to connect");
            Socket client = server.accept();
            System.out.println("Client Connected.");
            Service service = new Service(client,inventory);
            Thread t = new Thread(service);
            t.start();
        }

    }
}

/**
 * Class Service
 * Extends Thread and implements Protocol
 */
class Service extends Thread implements Protocol{

    private Socket client;
    private DataInputStream in;
    private DataOutputStream out;
    private Inventory inventory;

    /**
     * Constructor for the server
     * @param client
     * @param inventory
     */
    public Service(Socket client, Inventory inventory){
        this.client = client;
        this.inventory = inventory;
    }

    /**
     * method that sets up DataInputStream/ DataOutputStream
     * puts the method around try/catch/finally as well
     */
    public void run(){
        try{
            in = new DataInputStream(client.getInputStream());
            out = new DataOutputStream(client.getOutputStream());
            doService();
        } catch (IOException e) {
            e.printStackTrace();
        }finally{
            try{
                client.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    /**
     * Method doService
     * Checks the message and does the action for each command
     * depending on the result of the switch method
     * takes info from client and sends back info
     * @throws IOException
     */
    private void doService() throws IOException{
        try {
            int command = 0;
            String itemName = "";
            int number = 0;
            int result = 0;
            String result2 = "";

            while (command != QUIT) {
                command = in.readInt();
                switch (command) {
                    case ADD_ITEM:
                        itemName = in.readUTF();
                        number = in.readInt();
                        inventory.addItem(itemName, number);
                        out.writeInt(SUCCEED);
                        out.flush();

                        break;

                    case CHECK_INVENTORY:
                        itemName = in.readUTF();
                        number = inventory.checkInventory(itemName);
                        out.writeInt(SUCCEED);
                        out.writeInt(number);
                        out.flush();
                        break;

                    case TAKE_ITEM:
                        itemName = in.readUTF();
                        number = in.readInt();
                        result = inventory.takeItem(itemName, number);
                        out.writeInt(SUCCEED);
                        out.writeInt(result);
                        out.flush();
                        break;

                    case GET_THRESHHOLD:
                        number = in.read();
                        result2 = inventory.getThreshold(number);
                        out.writeInt(SUCCEED);
                        out.writeUTF(result2);
                        out.flush();
                        break;

                    case QUIT:
                        out.writeInt(CLOSED);
                        out.flush();
                        break;

                }
            }
        }catch (IOException exception){
            out.writeInt(FAILED);
            out.flush();
        }
    }

}