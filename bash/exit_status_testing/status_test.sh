#!/bin/bash
echo run exit0.sh
./exit0.sh
echo exit status = $?
echo ============================
echo run exit1.sh
./exit1.sh
echo exit status = $?
echo ============================
echo set a to exit1.sh
a=./exit1.sh
echo a = $a
echo ============================
echo set a to stdout of exit1.sh
a=$(./exit1.sh)
echo a = $a
echo ============================
echo set a to exit status of exit1.sh
./exit1.sh
a=$?
echo a = $a
echo ============================
echo set a to 0
a=0
echo a = $a
echo ============================
echo execute \[ \$a \]
[ $a ]
echo status = $?
echo ============================
echo testing \[ \$a \]
if [ $a ]
then echo true
else echo false
fi
echo ============================
echo set a to 1
a=1
echo a = $a
echo ============================
echo execute \[ \$a \]
[ $a ]
echo status = $?
echo ============================
echo testing \[ \$a \]
if [ $a ]
then echo true
else echo false
fi
echo ============================
echo set a to \'\'
a=''
echo a = $a
echo ============================
echo execute \[ \$a \]
[ $a ]
echo status = $?
echo ============================
echo testing \[ \$a \]
if [ $a ]
then echo true
else echo false
fi
echo ============================
echo testing ./exit0.sh
if ./exit0.sh
then echo true
else echo false
fi
echo ============================
echo testing ./exit1.sh
if ./exit1.sh
then echo true
else echo false
fi
echo ============================
echo negative testing ./exit0.sh
if ! ./exit0.sh
then echo true
else echo false
fi
echo ============================
echo negative testing ./exit1.sh
if ! ./exit1.sh
then echo true
else echo false
fi
