#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int buffSize = PATH_MAX;

int main(int argc, char *argv[]){
  int result = -1;
  // Only possible error is that an argument has been introduced.
  if (argc > 1){
    printf("mysize: Argument introduced\n");
  } else {
    // We open the current working directory.
    char buffer[buffSize];
    DIR *mydir = opendir(getcwd(buffer, buffSize));
    struct dirent *myfile;
    while((myfile = readdir(mydir)) != NULL){
      // Open the file using open. Read only because we won't modify it.
      int fd = open(myfile->d_name, O_RDONLY, 0666);
      // We only check the size of files, not directories.
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
