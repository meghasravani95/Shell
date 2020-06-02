Name: Megha Sravani Lavu
CSU ID:2762646
Project description: Implemented the basic shell that runs in interactive and batch mode.

Compiling Instruction:
                   gcc project.c

For interactive mode:
                   ./a.out shell
For batch mode:
               ./a.out shell <path to file>

  

Sample Test Run:

For Interactive mode:

1) No command:
      it will prompt again

2) One Command: ls -l

Output:

Prompt$:
Prompt$:ls -l
total 64
-rw-rw-r--@ 1 meghasravani  staff    406 Jun  1 14:32 Readme.txt
-rwxr-xr-x  1 meghasravani  staff  13440 Jun  1 14:33 a.out
-rw-rw-r--@ 1 meghasravani  staff     40 Jun  1 14:33 batchfile.txt
-rw-rw-r--@ 1 meghasravani  staff     67 Apr 22 15:41 cat.txt
-rw-r--r--  1 meghasravani  staff   3156 Jun  1 13:37 project.c

3) Two commands:

Prompt$:ls -l;cat cat.txt    
You fit into me
like a hook into an eye,
a fish hook
an open eyetotal 64
-rw-rw-r--@ 1 meghasravani  staff   1200 Jun  1 14:36 Readme.txt
-rwxr-xr-x  1 meghasravani  staff  13440 Jun  1 14:33 a.out
-rw-rw-r--@ 1 meghasravani  staff     40 Jun  1 14:33 batchfile.txt
-rw-rw-r--@ 1 meghasravani  staff     67 Apr 22 15:41 cat.txt
-rw-r--r--  1 meghasravani  staff   3156 Jun  1 13:37 project.c
Prompt$:

4) Three commands:

Prompt$:ls -l;cat cat.txt;grep eye cat.txt
You fit into me
like a hook into an eye,
a fish hook
an open eyelike a hook into an eye,
an open eye
total 64
-rw-rw-r--@ 1 meghasravani  staff   1250 Jun  1 14:37 Readme.txt
-rwxr-xr-x  1 meghasravani  staff  13440 Jun  1 14:33 a.out
-rw-rw-r--@ 1 meghasravani  staff     40 Jun  1 14:33 batchfile.txt
-rw-rw-r--@ 1 meghasravani  staff     67 Apr 22 15:41 cat.txt
-rw-r--r--  1 meghasravani  staff   3156 Jun  1 13:37 project.c
Prompt$:

5) quit:

Prompt$:quit;cat cat.txt
You fit into me
like a hook into an eye,
a fish hook
an open eyeMeghas-MacBook-Pro:melavu meghasravani$ 

For batch mode: batch file contains

cat cat.txt;grep hook cat.txt
pwd;ls -l

Output:

~/Desktop/melavu% ./a.out shell /home/student/melavu/Desktop/melavu/batchfile.txt
batchfile Line:cat cat.txt;grep hook cat.txt
You fit into me
like a hook into an eye,
a fish hook
an open eyelike a hook into an eye,
a fish hook
batchfile Line:pwd;ls -l
/home/student/melavu/Desktop/melavu
total 32
-rwxr-xr-x 1 melavu users 13446 Jun  1 17:54 a.out
-rw-r--r-- 1 melavu users    40 Jun  1 14:33 batchfile.txt
-rw-r--r-- 1 melavu users    67 Apr 22 15:41 cat.txt
-rw-r--r-- 1 melavu users  3276 Jun  1 17:54 project.c
-rw-r--r-- 1 melavu users  3712 Jun  1 16:25 Readme.txt

Others:

Improper command:

Prompt$:lskf
command doesn't exist
Prompt$:


Command more than 512 characters:

Prompt$:lslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslslsls
cmd exceeded 512 characters
Readme.txt	a.out		batchfile.txt	cat.txt		project.c
Prompt$:

File doesn't exist:

Meghas-MacBook-Pro:melavu meghasravani$ ./a.out shell batch.txt
Unable to open the file or file doesn't exist
Meghas-MacBook-Pro:melavu meghasravani$ 

Incorrect number of arguments:

Meghas-MacBook-Pro:melavu meghasravani$ ./a.out shell batch.txt mk
Incorrect number of arguments at command line or Incorrect format; usage: shell [batchfile]
Meghas-MacBook-Pro:melavu meghasravani$



Existing Bugs:(none)