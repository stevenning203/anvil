# Anvil

Anvil is an esoteric interpreted programming language written in C++.

In the current version, Anvil has 16384 memory slots, each available with 1 32-bit integer.

**Syntax:**

@ : reset the pointer head to 0.\
\# : clear the console and flush the output stream.\
\* : reset all memory to 0.\
l : move the head one to the left.\
r : move the head one to the right.\
o : output the integer at the head as a char.\
% : output the integer at the head.\
i : increment the value at the pointer.\
d : decrement the value at the pointer.\
s : standard in a value at the pointer.\
b : output a new line character.\
a : add temporary memory to the value at the head.\
q : set the temporary memory to the value at the head.\
= : if the temporary memory is equal to the value at the head, jump to the value stored at position memory.\
p : set the position value to the value at the head.\
> : move the head 10 units to the right.\
< : move the head 10 units to the left.\
} : move the head 50 units to the right.\
{ : move the head 50 units to the left.\
\+ : add 10 to the value at the head.\
\- : subtract 10 from the value at the head.\
y : reset the value at the head to 0.\
; : if temporary memory is above 0, go to the position stored at position memory.\
: : decrement the temporary memory.\