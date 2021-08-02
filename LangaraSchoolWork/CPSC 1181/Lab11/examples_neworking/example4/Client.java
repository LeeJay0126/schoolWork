import java.io.IOException;
import java.io.DataInputStream;
import java.io.OutputStream;
import java.io.DataOutputStream;
import java.net.Socket;
// Clinet side of one way connection
public class Client implements Protocol{
	public static void main( String[] args )  throws IOException {
	
		Socket client = null;
            
		try {
			client = new Socket( "localhost", PORT );
			DataOutputStream out = new DataOutputStream(client.getOutputStream( ));
			DataInputStream in = new DataInputStream(client.getInputStream( ));

			for( int i = 1; i <= 20; i++ ){
				out.writeInt(Protocol.NUMBER);
				out.writeInt(i);
				out.flush();
				if(in.readInt()==Protocol.RESULT)
					System.out.println(in.readInt());
			}	
			out.writeInt(Protocol.QUIT);
			out.flush();
		}
		catch( IOException e ) {
			System.out.println("Program terminated unexpectly!");
		}
		finally {
			System.out.println("End of request");
			client.close( );
		}

	}
}
  
 
