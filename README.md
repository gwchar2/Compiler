num/0 -> 0 or 0.0 deppending on num type

for every immediate value in the program, there is a temporary assigned to it. But the assign does not show in the commands. (I noted it so that the program wont get to long)

if a float is casted to float, or an int to int, nothing happens.

all vars marked t[0-9]* are saved for temporaries.

temporary variables stay as they are assigned, int or float, and do not change throughout the program.

expressions that include different variables, such as int+float , the int is transfered momentarily (to a temp) as a float, and than canculated. Same for actions such as GTE or EQ (while the result is an int 1:0).

if we assign float to int, we will cast it first automatically. 

quad code is not really optimized, but at least it has clarity, so it is easily tracable. 
