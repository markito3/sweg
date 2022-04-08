#!/bin/bash

a=3
echo a = $a
b=00007
echo b = $b
c=11
echo c = $c
d=13
echo d = $d
e=0
echo e = $e
f=""
echo f = $f
echo ==============
echo c
echo $c
if [ $c ]
then
    echo c is true
else
    echo c is false
fi
if [ $d ]
then
    echo d is true
else
    echo d is false
fi
if [ $e ]
then
    echo e is true
else
    echo e is false
fi
if [ $f ]
then
    echo f is true
else
    echo f is false
fi
echo $(( c ))
if [[ a -gt b ]]
then
    echo a -gt b is true
else
    echo a -gt b is false
fi
if [[ a -lt b ]]
then
    echo a -lt b is true
else
    echo a -lt b is false
fi
if [[ a -lt b && b -lt c ]]
then
    echo a -lt b \&\& b -lt c is true
else
    echo a -lt b \&\& b -lt c is false
fi
if [[ a -lt b && b -lt e ]]
then
    echo a -lt b \&\& b -lt e is true
else
    echo a -lt b \&\& b -lt e is false
fi
if [[ a -lt b || b -lt c && c -lt d ]]
then
    echo a -lt b \|\| b -lt c \&\& c -lt d is true
else
    echo a -lt b \|\| b -lt c \&\& c -lt d is false
fi
if [[ a -gt b || b -lt c && c -lt d ]]
then
    echo a -gt b \|\| b -lt c \&\& c -lt d is true
else
    echo a -gt b \|\| b -lt c \&\& c -lt d is false
fi
if [[ a -gt b || b -lt c && c -gt d ]]
then
    echo a -gt b \|\| b -lt c \&\& c -gt d is true
else
    echo a -gt b \|\| b -lt c \&\& c -gt d is false
fi
if [[ a -gt b || b -gt c && c -gt d ]]
then
    echo a -gt b \|\| b -gt c \&\& c -gt d is true
else
    echo a -gt b \|\| b -gt c \&\& c -gt d is false
fi
if [[ (a -lt b || b -lt c) && c -gt d ]]
then
    echo \(a -lt b \|\| b -lt c\) \&\& c -gt d is true
else
    echo \(a -lt b \|\| b -lt c\) \&\& c -gt d is false
fi
if [[ a -lt b || (b -lt c && c -gt d) ]]
then
    echo a -lt b \|\| \(b -lt c \&\& c -gt d\) is true
else
    echo a -lt b \|\| \(b -lt c \&\& c -gt d\) is false
fi
if [[ a -lt b || b -lt c && c -gt d ]]
then
    echo a -lt b \|\| b -lt c \&\& c -gt d is true
else
    echo a -lt b \|\| b -lt c \&\& c -gt d is false
fi
