import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class Client implements Protocol {
    public static void main(String[] args) {
        new Client("localhost");
    }
    public Client(String host) {

        try (Socket socket = new Socket(host, Protocol.PORT)) {

            DataInputStream in = new DataInputStream(socket.getInputStream());
            DataOutputStream out= new DataOutputStream(socket.getOutputStream());

            playGame(in, out);
        }
        catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
    public void playGame(DataInputStream in,DataOutputStream out) throws IOException {
        Scanner fromUser = new Scanner(System.in);
        boolean done = false;
        System.out.println("guess a number from 1 (inclusive) up to and including 50");
        do {
            System.out.print("> ");
            int guessNumber = fromUser.nextInt();
            out.writeInt(guessNumber);
            out.flush();
            switch (in.readInt()){
                case WASLOWER:
                    System.out.println(guessNumber+ " was lower than mysteryNum");
                    break;
                case WASHIGHER:
                    System.out.println(guessNumber+ " was higher than mysteryNum");
                    break;
                case LOST:
                    System.out.println("You lost; the number was "+in.readInt());
                    done = true;
                    break;
                case CORRECT:
                    int numOfTries = in.readInt();
                    System.out.println("You won after "+numOfTries+" tries");
                    done = true;
            }
        } while (!done);

    }
} 