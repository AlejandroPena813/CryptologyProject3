# CryptologyProject3
Exercise - 3: Experiment with S-P networks

Task 1: Write a program prog3_1 that reads from stdin and writes to stdout, and counts the number of each byte value present in the input. For each of the 256 byte values, it outputs the number of each value seen in the input to stdout. By default, it writes one value per line with the value in ASCII-coded hex, then a space, then the actual frequency count of that value. With the -n flag, the value and space are omitted. With the -c flag, the space is replaced with a comma. With the -L<N> flag, where N is an integer between 1 and 256, N values (or value pairs) are printed per line, with two hex characters per byte value and a constant number of characters per frequency or percent value (again, leading spaces), with a semicolon ';' and space after each entry (either a frequency or byte value-frequency pair).

Task 2:

Use your nybble substitution and byte transposition programs individually to encrypt at least three English text files, at least three source code files in the same language, and at least three executable files (or other file that is not text) and determine the frequency histograms for each, and the average frequency histograms.

Now run substitution followed by transposition and transposition followed by substitution and obtain histograms. 
