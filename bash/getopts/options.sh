#!/bin/bash
while getopts "abcd:e:f:" opt; do
    case "$opt" in
    a)
	a=thrown
        ;;
    b)  b=thrown
        ;;
    c)  c=thrown
        ;;
    d)  d=$OPTARG
        ;;
    e)  e=$OPTARG
        ;;
    f)  f=$OPTARG
    esac
done

echo a = $a
echo b = $b
echo c = $c
echo d = $d
echo e = $e
echo f = $f
exit
