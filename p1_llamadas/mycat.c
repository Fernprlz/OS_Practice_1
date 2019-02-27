#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <sys/types.h>          /* Cabeceras llamada al sistema open  */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             /* Cabecera llamadas al sistema read, write y close  */


int main(int argc, char *argv[])
{
     // open a file
     // read the content using 1024b intermediate buffer
     // write the content of the buffer in the standard output - use STDOUT_FILENO
     // close the descriptor.
	

int fd = open(argv[1], O_RDWR, 0666);
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

}


int open(const char *path, into flag
