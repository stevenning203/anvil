# Anvil

Anvil is an esoteric interpreted programming language written in C++. It is similar to BrainF but with an intention of making it more practical.

In the current version, Anvil has 16384 memory slots, each available with 1 32-bit integer.

Notably, the entire program must be written on the same line (no newline characters).

**Syntax:**

```@``` : reset the pointer head to 0.\
```#``` : clear the console and flush the output stream.\
```*``` : reset all memory to 0.\
```l``` : move the head one to the left.\
```r``` : move the head one to the right.\
```o``` : output the integer at the head as a char.\
```%``` : output the integer at the head.\
```i``` : increment the value at the pointer.\
```d``` : decrement the value at the pointer.\
```s``` : standard in a value at the pointer.\
```b``` : output a new line character.\
```a``` : add temporary memory to the value at the head.\
```q``` : set the temporary memory to the value at the head.\
```=``` : if the temporary memory is equal to the value at the head, jump to the value stored at position memory.\
```p``` : set the position value to the value at the head.\
```>``` : move the head 10 units to the right.\
```<``` : move the head 10 units to the left.\
```}``` : move the head 50 units to the right.\
```{``` : move the head 50 units to the left.\
```+``` : add 10 to the value at the head.\
```-``` : subtract 10 from the value at the head.\
```y``` : reset the value at the head to 0.\
```[``` : add the current position to the head stack\
```]``` : if the value at the head is above zero, jump to the position at the top of the stack and pop it.\
```f``` : store the value at the head into the return register.\
```F``` : return to the position pointed to by the return register.\
\
Here is an example for "Hello, World!":\
```+++++++iior++++++++++qiora+ddora+ddora+ior++++iiiio-ddo++++++dddddo++iiiioiiioddddddoddddddddor+++iiio```\
\
Here is an example for a for loop that prints numbers 0 to 9 with spaces in between:\
```+r+++++ddr+++iill[rorolild]```\
\
The general structure for a for loop is as follows:\
```+[d]```