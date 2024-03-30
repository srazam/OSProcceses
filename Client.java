import java.io.*; // InputStream and BufferRead 
import java.net.*; 

public class Client { 
    public static void main(String[] args) { 
	  // InputStream and BufferRead 
        final String SERVER_ADDRESS = "localhost"; 
        final int PORT = 8000; 

        try (Socket socket = new Socket(SERVER_ADDRESS, PORT)) { 
            // Set up input and output streams 
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true); 
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));  
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in)); 
            
            // Allow user to enter message  
            System.out.println("Enter a message: "); 
            String userInput; 

            //while loop that only exits if input is null or the message is ‘Exit’ 
            while(((userInput = stdIn.readLine())!=null) && !(userInput.equals("Exit"))){ 
                out.println(userInput); 
                // echo and instructions for continuing/quitting 
                System.out.println("echo: " + in.readLine()); 
                System.out.println("Continue if you would like, but if you would like to leave, type 'Exit'"); 
            } 
        } 
         catch (UnknownHostException e) { 
            System.err.println("Unknown host: " + SERVER_ADDRESS); 

        } catch (IOException e) { 
            System.err.println("Client exception: " + e.getMessage()); 
        } 

    } 

} 