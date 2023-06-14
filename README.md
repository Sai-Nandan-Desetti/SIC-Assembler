# SIC-Assembler
An assembler for the Simplified Instructional Computer written in C.

The Simplified Instructional Computer (SIC) is designed by Leland Beck and described in his book *System Software - An Introduction to Systems Programming*.

This program implements the Pass-1 of the two-pass assembler defined in that book.

### Example
For the file `s1.sic` in the `sample inputs` folder, the Symbol Table turns out to be:
```
SymTab details:

Label   Address
FIRST   1000
CLOOP   1003
ENDFIL  1015
EOF     102a
THREE   102d
ZERO    1030
RETADR  1033
LENGTH  1036
BUFFER  1039

Program length: 61 bytes
```
* The intermediate files are stored in `sample outputs`.
* The files are *intermediate* in the context of the complete two-pass assembler. They are, nevertheless, the *output* of the Pass-1 of the assembler.
