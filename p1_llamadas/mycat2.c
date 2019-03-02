#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <sys/types.h>          /* Cabeceras llamada al sistema open  */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             /* Cabecera llamadas al sistema read, write y close  */
#include <string.h>

#include <dirent.h>
/*
* - Open a file from the arguments.
* - Read using 1024 immediate buffer.
* - Write the content of the buffer in the stdout
* using STDOUT_FILENO.
* - Close de descriptor.
* -- Show whole contents of the file
* -- Match exactly the output of a cat execution
* -- Return -1 if no argument
* -- Return -1 if errors on opening (file doesn't exist)
* TODO:
*		- Support more than one argument.
*		- Return the correct error.
*		- ?
*/

int checkInvalid(char *argument, int myfile){
	int result = 0;
	/* Erroneous input:
	* - No argument.
	* - Argument is a directory.
	* - Path is too long
	*
	*/
	if (strlen(argument) > PATH_MAX){
		printf("mycat: Path is too long.\n");
	} else if (myfile < 0){
		printf("mycat: %s: No such file or directory\n", argument, myfile);
	} /*else if (/*Argument is a directory){
		printf("mycat: %s: Is a directory\n", argument);
	} */else {
	result = -1;
	}
return result;
}

int main(int argc, char *argv[]){
	int result = -1;

	if (argc <= 1){
		printf("mycat: No arguments received\n");
	} else {
		for (int ii = 1; ii < argc; ii++){
			// Open the file.
			int myfile = open(argv[ii], O_RDWR, 0666);
			// If not invalid, perform the operation.
			if (checkInvalid(argv[ii], myfile) < 0){
				// Malloc? Allocate a buffer for the content of the file.
				// We can read up to 1kb files.
				char buffer[1024];
				// Truncate the buffer. Is there another way?
				for(int jj = 0; jj < sizeof(buffer); jj++){
					buffer[jj] = '\0';
				}
				// We read the file and hold its content in the buffer.
				read(myfile, buffer, sizeof(buffer));
				// We write the output in the specified STDOUT_FILENO.
				write(STDOUT_FILENO, buffer, sizeof(buffer));
				// We close the file and go to the next if it exists.
				close(myfile);
				// If we manage at least one valid execution, we call it a win.
				result = 0;
			}
		}
		return result;
	}

	/*
	// Check for validity
	if (argc == 1) {															//If no arguments passed (argc==1) return -1 and end
	printf("No arguments received (-1 returned)\n");
	return -1;
}	else if (fd<0){
int fd = open(argv[1], O_RDWR, 0666);										//Else if there is an error detecting file, return -1 and end
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
*/
}
