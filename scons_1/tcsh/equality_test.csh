#!/bin/tcsh
set a=07
echo a = $a
if ( $a == 7 ) then
    echo equal to 7
else
    echo not equal to 7
endif

@ b=07
echo b = $b
if ( $b == 7 ) then
    echo equal to 7
else
    echo not equal to 7
endif

@ c=09
echo c = $c
if ( $c == 9 ) then
    echo equal to 9
else
    echo not equal to 9
endif

exit
