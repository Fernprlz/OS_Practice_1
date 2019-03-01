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

// EVERYTIME WE OPEN SET THE RIGHT PERMISSIONS FOR GUERNIKA
// ALWAYS CHECK RETURN VALUES TO DETECT IF STH WENT WRONG TO ACT ACCORDINGLY
// READ AND WRITE RETURN VALUES HAVE MORE INFO THATN IF IT'S GONE WRONG
// PASSING THE TEST SUITE IS THE BARE MINIMUM.

// TEST TEST TEST
// REFLECT THE TESTS IN THE REPORT
// COMMENT YOUR INTENTIONS, WHY YOU DO THINGS, HIGHLIGHT THE MOST
// DIFFICULT TECHNICAL PARTS OF THE CODE AND THE DECISIONS INVOLVED
// TESTS: MENTAL EXERCISE, WHAT COULD GO WRONG WITH MY CODE?
// TEST ID	INPUT	EXPECTED OUTPUT		VALIDATION** (DID IT PASS)
// CARE ABOUT OVERFLOWS, CONSIDER YOUR ARCHITECTURE. V E R Y I M P O R T A N T
// YOU DON'T NEED TO SUPPORT ALL THOSE CASES, BUT AT LEAST, START THINKING
// ABOUT THEM.

// TEST GUERNIKA
