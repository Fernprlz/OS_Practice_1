#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <sys/types.h>          /* Cabeceras llamada al sistema open  */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             /* Cabecera llamadas al sistema read, write y close  */
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int buffSize = 1024;

int checkInvalid(char *argument, int myfile){
	int result = 0;
	// We create a stat so we can check if the argument is a file or a directory.
	struct stat statBuffer;
	// We fill the stat variable.
	stat(argument, &statBuffer);
	if (strlen(argument) > PATH_MAX){
		printf("mycat: Path is too long.\n");
	} else if (myfile < 0){
		printf("mycat: %s: No such file or directory\n", argument);
	} else if (S_ISDIR(statBuffer.st_mode)){
		printf("mycat: %s: Is a directory\n", argument);
	} else {
		// Argument is not invalid, therefore it's valid.
		result = -1;
	}
	return result;
}

int main(int argc, char *argv[]){
	int result = -1;

	// Check if there's an argument.
	if (argc == 1){
		printf("mycat: No arguments received\n");
	} else {
		// Traverse the argument array performing the cat for each one.
		for(int ii = 1; ii < argc; ii++){
			// Open the specified file
			int myfile = open(argv[ii], O_RDONLY);
			// If not invalid, perform the operation.
			if (checkInvalid(argv[ii], myfile) < 0){
				// An int holding the result of the read operation.
				int readContent;
				// With a buffer this size we can read up to 1kb at a time.
				char buffer[buffSize];
				do{
					// We empty the buffer on each interation.
					memset(buffer, '\0', buffSize);
					// We read the file and hold its content in the buffer.
					readContent = read(myfile, buffer, buffSize);
					// We write the output in the specified STDOUT_FILENO.
					write(STDOUT_FILENO, buffer, buffSize);
				}while(readContent > 0);
				// If we manage at least one valid execution, we call it a win.
				result = 0;
			}
			// We close the file and go to the next if it exists.
			close(myfile);
		}
	}
	// We close the process and its context.
	exit(result);
	return result;
}
