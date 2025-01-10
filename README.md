# Minitalk

## Summary
Minitalk is a simple messaging application that allows communication between a client and a server using UNIX signals. The project is divided into two main parts: the mandatory part and the bonus part.

## Mandatory Part
The mandatory part of the project involves creating a client and a server. The server must be able to receive messages from the client and display them. The client sends the messages to the server using UNIX signals (SIGUSR1 and SIGUSR2). The server must be able to handle and reconstruct the messages sent by the client.

## Bonus Part
The bonus part of the project includes additional features to enhance the functionality of the Minitalk application. These features may include:
- Handling Unicode characters.
- Implementing a more efficient way of sending and receiving messages.
- Adding acknowledgments from the server to the client to confirm message receipt.
- Implementing a timeout mechanism to handle cases where the server does not respond.

## Usage
To use the Minitalk application, follow these steps:

1. **Compile the project:**
   ```sh
   make
   ```

2. **Start the server:**
   Run the server program to start listening for incoming messages.
   ```sh
   ./server
   ```

   The server will display its process ID (PID), which you will need to provide to the client.

3. **Send a message from the client:**
   Use the client program to send a message to the server. You need to provide the server's PID and the message you want to send.
   ```sh
   ./client [server_pid] [message]
   ```

   Replace `[server_pid]` with the PID of the server and `[message]` with the message you want to send.

4. **Example:**
   ```sh
   ./client 12345 "Hello, Minitalk!"
   ```

   This command sends the message "Hello, Minitalk!" to the server with PID 12345.

5. **Server Output:**
   The server will receive the message and display it in the terminal.

## Resources

### Mandatory Part
- [UNIX Signals](https://man7.org/linux/man-pages/man7/signal.7.html): Comprehensive documentation on UNIX signals.
- [Signal Handling in C](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html): Guide on how to handle signals in C.

### Bonus Part
- [Unicode in C](https://www.cl.cam.ac.uk/~mgk25/unicode.html): Information on handling Unicode characters in C.
- [Efficient Signal Handling](https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-sigaction-examine-change-signal-action): Techniques for efficient signal handling.
- [Timeout Mechanisms](https://www.gnu.org/software/libc/manual/html_node/Setting-an-Alarm.html): Implementing timeout mechanisms using alarms.
- [Acknowledgment Protocols](https://en.wikipedia.org/wiki/Acknowledgement_(data_networks)): Understanding acknowledgment protocols in data communication.
