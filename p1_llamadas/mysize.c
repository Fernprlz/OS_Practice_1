#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

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
  int result = 0;
  if (argc > 1){
    printf("mysize: Error, argument introduced. errno: %i\n",strerror(errno));
    result = -1;
  } else {
    char buffer[PATH_MAX];
    DIR *mydir = opendir(getcwd(buffer, sizeof(buffer)));
    struct dirent *myfile;
    while((myfile = readdir(mydir)) != NULL){
      // Open the file using open
      int fd = open(myfile->d_name, O_RDWR, 0666);
      if (myfile->d_type == DT_REG){
        // Move the pointer to the end counting its size
        int fileSize = lseek(fd,0,SEEK_END);
        // close it (the file, not the dir)
        close(fd);
        // Print the data.
        printf("%s\t%i\r\n", myfile->d_name, fileSize);
      }
    }
    // Close the directory.
    closedir(mydir);
  }
  return result;
}
