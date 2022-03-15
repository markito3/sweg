#!/bin/bash
rm -f patch_?.txt
diff -u original.txt with_edit_1.txt > patch_1.txt
diff -u original.txt with_edit_2.txt > patch_2.txt
diff -u original.txt with_edit_3.txt > patch_3.txt
rm -f test*
cp original.txt test.txt
patch test.txt < patch_1.txt
patch test.txt < patch_2.txt
patch test.txt < patch_3.txt
diff original.txt test.txt
