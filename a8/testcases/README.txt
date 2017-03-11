I. LEGAL INPUT TEST CASES

Because of the many different ways in which the spellcheck and myls programs
can be invoked (e.g., with or without some of the arguments which have default
values, and -- in the case of the spellcheck program -- with command-line
options specified in any order), each test case is set up as a small 
shell-script, test*.cmd.  The ".cmd" file extension is simply to emphasize
that each of these files should be executed as a command, and has no
additional significance beyond that.

Each of these command files takes four arguments:

   argument 1:	valgrind option (use '-v' if you want to test the extra-credit
   		requirement, -q otherwise)
   argument 2:  file to put stdout of your program into
   argument 3:  file to put stderr of your program into
   argument 4:  file to put exit status of your program into

The command file assumes that it's being run in the directory that contains
the executable file "spellcheck" that is being tested.

EXAMPLE: If you want to run your program on test016.cmd without checking 
for the extra credit, with the program's stdout going into fileA, its stderr
going into fileB, and its exit status going into fileC, then the command you
should run is:

   test016.cmd '-q'  fileA  fileB  fileC

If you had wanted to run this command with the same file names but for the
extra credit portion of the assignment (i.e., to check whether there are
any memory leaks), you would run

   test016.cmd '-v'  fileA  fileB  fileC

II. ERROR INPUT TEST CASES
Error tests are command files err*.cmd.  Like the legal test case commands,
these are shell scripts.  Unlike the legal test case commands, the error
commands don't take a valgrind command as an argument.  Thus, each error
command files takes three arguments:

   argument 1:	file to put stdout of your program into
   argument 2:  file to put stderr of your program into
   argument 3:  file to put exit status of your program into

The command file assumes that it's being run in the directory that contains
the executable file "spellcheck" that is being tested.

