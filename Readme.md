# minitalk

## Introduction

This project comprises a simple communication program on the basis of UNIX signals. Two executables are involved:
+ `client`: Transmits a string of characters.
+ `server`: Receives and prints character strings.

### Compiling

After cloning the repository (don't neglect to also fetch the `libft` and `libftprintf` submodules), run `make` to compile both programs. You can also compile the executables separately by running `make server` or `make client`.

### Project overview

#### Mandatory features

The server displays its own process identifier (PID) on startup and should from that point onward be able to receive any number of successive strings of arbitrary size. The server displays the string once it has been received in its entirety. The client is used to send strings to the server, using only UNIX signals.

The project only allows the use of the following libc functions: `write()`, `signal()`, `sigemptyset()`, `sigaddset()`, `sigaction()`, `kill()`, `getpid()`, `malloc()`, `free()`, `pause()`, `sleep()`, `usleep()`, `exit()`. In addition to that, there can be only a single `global` variable assigned for either executable.

#### Bonus features

1. The server sends a confirmation signal back to the client once it has received the entire message.
2. The message can contain any number of bytes of any value: as a consequence, Unicode characters are supported -- in principle, depending on whether the terminal supports them as well.

## Usage

### server

The program takes no arguments. Once it's been started, it will run indefinitely, waiting to receive messages. Press Ctrl+C to shutdown the server. For example:  
```
./server  
Welcome to Minitalk! PID: [960]
``` 
```
Als Gregor Samsa eines Morgens aus unruhigen Träumen erwachte, fand er sich in seinem Bett zu einem ungeheuren Ungeziefer verwandelt.
```

### client

The program takes two arguments: `./server <pid> <message>`, where `<pid>` denotes the server's PID and `<message>` denotes the message to be sent to the server. For example:
```
./client 960 "Als Gregor Samsa eines Morgens aus unruhigen Träumen erwachte, fand er sich in seinem Bett zu einem ungeheuren Ungeziefer verwandelt."
```
```
Message acknowledged.
```  
The program will not attempt to transmit data if `<pid>` is by any measure invalid or equal to -1 (a negative value is otherwise treated as its absolute counterpart). Apart from that, it's not wise to supply any value for `<pid>` other than the server's actual PID: doing this will likely cause unintended termination of unrelated processes.
```
./client 999999999 "This will cause an error."  
Error: invalid server PID
./client "I'm a PID!" "No, you're not."
Error: invalid server PID
```  
The client will wait for confirmation for five seconds after transmission finishes. If no confirmation is received within that time (which will likely only happen if the server crashes or is shut down during transmission), it will display an error message and exit.

Attempting to send messages to the same server from multiple clients simultaneously will most certainly cause the server to crash. Don't do it.

## Function

Internally, the client transmits the message by evaluating every bit that's in it, sending a `SIGUSR_1` signal for an unset bit and `SIGUSR_2` for a set bit. The actual message is preceded by a header segment containing the client's own PID and the number of bytes in the message (this data is required for reception acknowledgement and memory allocation on part of the server, respectively). Reception acknowledgement amounts to just a single `SIGUSR_1` sent back to the client.

## Other

On slower systems, it may be necessary to increase the interval between signals sent by the client in order to prevent the server from crashing. To do this, adjust the value of the USLEEP\_SEND macro in ./header/comm.h accordingly.
