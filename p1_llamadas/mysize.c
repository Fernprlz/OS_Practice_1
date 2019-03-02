#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

#include <stdlib.h>
#include <errno.h>

/*
* - Obtain the current directory with getcwd();
* - Read the entries of the directory using readdir
* - IF ENTRY IS A REGULAR FIL (d_type from dirent == DT_REG)
*   - Open the file using Open
*   - Move the pointer to the end of the file and obtain value with lseek
*   - Close file with Close
*   - Print the name of the file (d_name of the structure)
*   - Then followed by \t, size obtained and \r\n (End of line char).
TODO: CHECK FOR INPUT ERRORS, TEST, SEE REQUIREMENTS.
*/

int main(int argc, char *argv[]){
  int result = -1;
  if (argc > 1){
    printf("mysize: Argument introduced\n");
  } else {
    char buffer[PATH_MAX];
    DIR *mydir = opendir(getcwd(buffer, sizeof(buffer)));
    struct dirent *myfile;
    while((myfile = readdir(mydir)) != NULL){
      // Open the file using open.
      int fd = open(myfile->d_name, O_RDONLY, 0666);
      if (myfile->d_type == DT_REG){
        // Move the file pointer to the beginning of the file.
        lseek(fd, 0, SEEK_SET);
        // Move the pointer to the end of the file and count its size.
        int fileSize = lseek(fd,0,SEEK_END);
        // Close the file using the file descriptor.
        close(fd);
        // Print the data.
        printf("%s\t%i\n\0", myfile->d_name, fileSize);
        result = 0;
      }
    }
    // Close the directory.
    closedir(mydir);
  }
  exit(result);
  return result;
}
