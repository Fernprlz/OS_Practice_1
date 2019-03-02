# OS_Practice_1

------

Practice about system calls and programs in C as Linux commands.

## Issues:
  - Is it necessary to put functions before the main?
  - How are function prototypes supposed to be used?
  <p style="text-align: center;">`Error: ..."undefined reference to 'functionName'.`</p>
  - Why in this code snippet at the moment of opening the files, if O_RDWR permission is given, the size of the file being executed (object mysize.o) is -1, while if the permission O_RDONLY outputs the correct size?
  <p style="text-align: center;">`// Open the file using open.
  int fd = open(myfile->d_name, O_RDONLY, 0666);`</p>


## Class Comments:

// EVERY TIME WE OPEN SET THE RIGHT PERMISSIONS FOR GUERNIKA\n
// ALWAYS CHECK RETURN VALUES TO DETECT IF STH WENT WRONG TO ACT ACCORDINGLY\n
// READ AND WRITE RETURN VALUES HAVE MORE INFO THAT IF IT'S GONE WRONG\n
// PASSING THE TEST SUITE IS THE BARE MINIMUM.\n

// TEST TEST TEST\n
// REFLECT THE TESTS IN THE REPORT\n
// COMMENT YOUR INTENTIONS, WHY YOU DO THINGS, HIGHLIGHT THE MOST\n
// DIFFICULT TECHNICAL PARTS OF THE CODE AND THE DECISIONS INVOLVED\n
// TESTS: MENTAL EXERCISE, WHAT COULD GO WRONG WITH MY CODE?\n
// TEST ID	INPUT	EXPECTED OUTPUT		VALIDATION** (DID IT PASS)\n
// CARE ABOUT OVERFLOWS, CONSIDER YOUR ARCHITECTURE.\n<p style="text-align: center;">V E R Y I M P O R T A N T</p>\n
// YOU DON'T NEED TO SUPPORT ALL THOSE CASES, BUT AT LEAST, START THINKING\n
// ABOUT THEM.\n

// TEST GUERNIKA
