#!/bin/bash
echo a
grep 12.34 file.txt
echo b
grep '12.34' file.txt
echo c
grep '12\.34' file.txt
echo d
grep '12 34' file.txt
echo e
grep '12.\.34' file.txt
echo f
grep '12\.\.34' file.txt
echo g
grep '12..34' file.txt
echo h
grep 12..34 file.txt
