#!/bin/bash
date_in=$1
utime=`date -d $date_in +%s`
status=$?
echo status = $status
echo test 1 status ne 0
if [ $status -ne "0" ]
    then
    echo true
else
    echo false
fi
echo test 2 status \(not what you want\)
if [ $status ]
    then
    echo true
else
    echo false
fi
echo test 3 set utime
if utime=`date -d $date_in +%s`
    then
    echo true
else
    echo false
fi
echo test 3 not set utime
if ! utime=`date -d $date_in +%s`
    then
    echo true
else
    echo false
fi
echo test 5 string = 0
if [ "0" ]
    then
    echo true
else
    echo false
fi
echo test 6 string = 1
if [ "1" ]
    then
    echo true
else
    echo false
fi
echo test 7 null string
if [ "" ]
    then
    echo true
else
    echo false
fi
echo utime = $utime
