1) VERY IMPORTANT-makefile/compilation: when in the directory in the terminal, you type make(thus creating the makefile).
  -DO NOT click the test executable "loco", for it will only print statements and not do anything.
  -DO type "./loco" in the terminal(after typing make) which will run the code properly.

2) All parts of the code are up and running,
  though there are a few bugs:
  -For the transposition output, it seems to record a 0 after each n bytes so the final proper digit is not displayed
  -Also for transposition, i used getline and it was having trouble/was buggy when you feed it multiple lines,
      it works but can sometimes be undefined. With one really long line(no \n char), it works fine.
  -The biggest bug, or i should say quirk, is that the frequency, nybble sub, and transposition programs must
    be run one at a time, 2 or more in the main will lead to the program not working properly(seg fault).

    To run multiple functions---->>the nybble program outputs data to nybbleOutput.txt and transposition program outputs it to transpositionOutput.txt
          these may be used to feed nybble and transposition output into the other 2 programs. 
          To run i comment out the other 2 programs(in main) not currently in use, and just run each program one at at a time.
          The frequency program prints out data to terminal and the freq program has no known bugs, although it works fully i did not get to implement flags.



Note: Transposition testing input were primarily char values separated by 1 space in between.
