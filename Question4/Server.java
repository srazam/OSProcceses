import java.io.*; 
import java.net.*; 
 
public class Server { 
    public static void main(String[] args) { 
        final int PORT = 8000; 
        String message = ""; 

        try (ServerSocket serverSocket = new ServerSocket(PORT)) { 
            System.out.println("Server is running..."); 
            
            // Wait for client connection 
            Socket clientSocket = serverSocket.accept(); 
            System.out.println("Client connected"); 

            // Set up input and output streams 
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true); 
            message = in.readLine(); 

            do{ 
                // Read client's messages
                System.out.println("Message from client: " + message); 

                // Send response to client=  
                out.println("Recieved message from client! It is: " + message);  

            } while((message = in.readLine())!=null && !(message.equals("Exit"))); 
            
            // Close connections 
            in.close(); 
            out.close(); 
            clientSocket.close(); 

        } catch (IOException e) { 
            System.err.println("Server exception: " + e.getMessage()); 
        } 

    } 

} 