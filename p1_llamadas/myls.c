#include <stdio.h>              /* Cabecera llamada al sistema printf  */
#include <unistd.h>             /* Cabecera llamada al sistema gtcwd  */
#include <sys/types.h>          /* Cabeceras llamadas al sistema opendir, readdir y closedir  */
#include <dirent.h>             /* Header used for the structure dirent.*/
#include <string.h>             /* Header used for the utility function strlen.*/
#include <stdlib.h>

int buffSize = PATH_MAX;

int checkInvalid(DIR *mydir, char *argument){
  int result = 0;
  // If the directory doesn't exist or the path length is too long, input is invalid.
  if (mydir == NULL){
    printf("myls: %s: No such file or directory\n", argument);
  } else if(strlen(argument) > PATH_MAX) {
    printf("myls: Path is too long.\n");
  } else {
    result = -1;
  }
  return result;
}

void printFiles(DIR *mydir){
  // Pointer to a dirent structure that will "hold" each file.
  struct dirent *myfile;
  //readdir returns a pointer to the directory at the argument, positioning the
  //pointer to the next directory in the directory stream.
  while ((myfile = readdir(mydir)) != NULL){
    // myfile is a dirent structure, so we access the name of the file using
    // the arrow operator and the myfile pointer.
    printf("%s\n", myfile->d_name);
  }
  // Once the file names have been printed, we close the directory.
  closedir(mydir);
}

int main(int argc, char *argv[]){
  int result = -1;
  // Pointer to a DIR (directory) type of variable.
  DIR *mydir;
  // String that will hold the current working directory path.
  char buffer[buffSize];
  // If no argument is specified, we work with the current directory.
  if(argv[1] == NULL){
    mydir = opendir(getcwd(buffer, buffSize));
    printFiles(mydir);
  } else {
    // Iterates over the different arguments (directories) listing its content.
    for (int ii = 1; ii < argc; ii++){
      // Sets the directory to the specified one.
      mydir = opendir(argv[ii]);
      // Checks if the directory is invalid, ending the program in that case (return -1).
      if (checkInvalid(mydir, argv[ii]) < 0){
        // In case there are several arguments, prints an identifier (name) at the
        // beginning of the execution. Also print a newline between prints.
        if (argc > 2){
          if (ii > 1){
            printf("\n");
          }
          printf("%s:\n", argv[ii]);
        }
        printFiles(mydir);
        result = 0;
      }
    }
    // We close the process and its context.
    exit(result);
    // If there's at least one legal argument that has been printed, we consider it
    // a succesful execution.
    return result;
  }
}
