#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <sys/types.h>          /* Cabeceras llamada al sistema open  */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             /* Cabecera llamadas al sistema read, write y close  */

int main(int argc, char *argv[]){
     // open a file
     // read the content using 1024b intermediate buffer
     // write the content of the buffer in the standard output - use STDOUT_FILENO
     // close the descriptor
		 int fd = open(argv[1], O_RDWR, 0666);
		 if (argc==1) {															//If no arguments passed (argc==1) return -1 and end
			 		printf("No arguments received (-1 returned)\n");
			 		return -1;
		 }	else if (fd<0){													//Else if there is an error detecting file, return -1 and end
			 		printf("File could not be opened (-1 returned)\n");
			 		return -1;
		 }	else {																	//File detected correctly, reading and printing
			 		char buf[1024];												//Create buf string to read and print
					for (int i=0; i<=sizeof(buf); i++){		//Set all characters of the buf string to null, in case there is something
						buf[i]='\0';
							 }
		 			read(fd, buf, 1023);									//Read file: store in buf string
		 			write(STDOUT_FILENO, buf, sizeof(buf)-1);	//Print to standard output: terminal
	 	}
		 close(fd);																	//Close file

}
