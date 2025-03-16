שלום גדי

מצרף כאן הנחיות ונקודות קריטיות להרצת התוכנית והבנתה.
ההוראות באנגלית מכיוון שזה הרבה יותר נוח וויזואלית לקריאה וכתיבה

If you are having problems with running the 'make' command, it might be because of line 4 in make file.

LDFLAGS = -lfl
LDFLAGS = -L/C/msys64/usr/lib -lfl	

In my computer I had to direct it to lfl with the correct path (on my end) (C/msys64/usr/lib).
If it is configured probably on your end, -lfl should suffice.

In order to run properly:
In terminal type the commands: 
1) make
2) cpq [file name]
    - Make sure [file name] is without .ou 
3) If you wish to run multiple tests at once, you can run the 'make tests' command. 
   Make sure to put your tests in dir/tests folder.
   Results will be printed to .qud files in tests folder.

!! Critical Notes !!:
0) The statements are printed with an 'empty command' between the blocks - for better readability.
   If you are interested in REMOVING THIS, you can go to the file src/AST/Base/QuadGenerator.cpp and note or remove line #39

1) Dividing a number with 0, returns 0 or 0.0 - deppending on variable type (int/float)

2) For every immediate value in the program, there is a temporary assigned to it. 

3) Temporary variables for the program are t[0-9]* and are kept as unassignables in the lexer.

4) Temporaries do not change type throughout the program. 
    Example: if t1 is assigned 2 and t2 is assigned 3.0, t1 will stay an int and t2 will stay a float
             for the entirety of the program.
    Temporaries can and will be re-used.

5) Commands <cast_float>3.0 or <cast_int>3 have no effect, but will be run anyways.

6) Expressions that include different variables, such as int+float, will transfer the int value to a float (momentarily in a temp), in order to be calculated.
    (Same happens when calculating binary operators such as && || with float numbers)

7) Assigning a float to an int is possible, the int value will be kept (x = 7.5 -> x = 7).  

8) If you are interested in printing the symbol table / scope , you can place the command globalScope.printTable() anywhere throughout the code.

9) The QUAD code is not optimized.



