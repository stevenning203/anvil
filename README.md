# Anvil

Anvil is an esoteric interpreted programming language written in C++. It is similar to BrainF but with an intention of making it more practical.

In the current version, Anvil has 32768 memory slots, each available with 1 32-bit integer.

End of line (```\n```) and all other non-token characters are ignored. However, position numbers when used DO include characters such as spaces and non-tokenized letters, but DO NOT include end of line characters.

To write functions, simply make a new line and start writing code. To call them, use the token ```f``` after storing the number of the function that you wish to call at the head. The number of the function corresponds with the line number. Hence, your first function will always be numbered ```2```.

Because all functions MUST end with ```F```, and they return after reading ```F```, you can write whatever you wish after the ```F```. Therefore, you may label the functions with a name after the ```F```.

Functions can be nested to any degree as long as there is still free memory. Each function is given 128 integer slots of unique memory. That is, they are unable to access the original memory, and there is no state, making every single function pure.

**Syntax:**

```?``` : set the value pointed to by the head to the value stored in the return register.\
```j``` : jump the tape to the position pointed to by the value stored in position.\
```!``` : debug output the location of the head and the data at the head location.\
```f``` : jump to the function pointed to by the value at the head.\
```F``` : return the value pointed to by the head in a function. The value is stored within the return register. Only available within functions.\
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
```=``` : if the temporary memory is not equal to the value at the head, skip the next instruction.\
```p``` : set the position value to the value at the head.\
```>``` : move the head 10 units to the right.\
```<``` : move the head 10 units to the left.\
```\\``` : move the head 50 units to the right.\
```/``` : move the head 50 units to the left.\
```+``` : add 10 to the value at the head.\
```-``` : subtract 10 from the value at the head.\
```y``` : reset the value at the head to 0.\
```[``` : add the current position to the head stack\
```]``` : if the value at the head is above zero, jump to the position at the top of the stack and pop it.\
\
Here is an example for "Hello, World!":\
```+++++++iior++++++++++qiora+ddora+ddora+ior++++iiiio-ddo++++++dddddo++iiiioiiioddddddoddddddddor+++iiio```\
\
Here is an example for a for loop that prints numbers 0 to 9 with spaces in between:\
```+r+++++ddr+++iill[rorolild]```\
\
The general structure for a for loop is as follows:\
```+[d]```\
Here is an example of a nested function:\
```iif?%
iiif?F
++F```\
This example will output 20 because the beginning first changes the value at the head to 2. Then a function call begins and the function on the second line is executed. This function increments the value at the head to 3 before calling another function. The last function stores a value of 20 at the head and then returns this value. The second function will store that value at the head before returning to the original tape. The original tape then stores the value that was returned and outputs it as a pure integer, yielding a value of 20.