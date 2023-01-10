This project comprises a simple communication program on the basis of UNIX signals. Two executables are involved:
>	'client': Transmits a string of characters by breaking every byte down into bits and sending a signal
	depending on whether the bit is set;
>	'server': Receives the signals sent by client, reencodes the character string and prints it. On successful
	reception, a signal is sent back to the client.
