Work toward this behavior:

Start with three files:

 a.txt
 b.txt
 c.txt

and create derived files:

 a.txt.made
 b.txt.made
 c.txt.made

by doing, for example,

 cp -v a.txt a.txt.made

v1 does it for one file, without generating dependecies
v2 does it for one file, with dependencies
v3 does it for multiple files, with dependencies
v4 does it for multiple files, with dependencies, from inside a subdirectory
