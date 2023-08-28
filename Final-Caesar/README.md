This is a program that allows the user to input a string of most any length, depending on how 
much memory the user decides to allocate based on message length. The user will also choose a 
shift value. The program will shift the letters of the user's original sentence by a number 
equal to the shift value. For example, if the entered message is abcde and the shift value is 2, 
then the cyphered message is cdefg. This also includes a decypher option; for this, input the 
same shift as the original; no extra work needs to be done. 

[NOTE: The formula for the decode shift is: 26 - (shift % 26)]

As this program is designed for educational purposes, it contains many different c functions, 
such as dynamic memory allocation. Please note that this function would be simpler if you just 
used stack memory for the original string instead of heap memory. Honestly, the rationale was 
20% for educational purposes and 80% the fact that "dynamic memory allocation" sounds mega cool. 
I stand by my decision, future reader (probably just myself in the future).

v3.3

Bisshoy Anwar 
