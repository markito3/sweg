From ltest directory:

mkdir dir2
ln -s dir1/dir1.1/orig.txt dir2/link.txt
ln -s ../dir1.1/orig.txt dir2/link2.txt
ln -s ../dir1/dir1.1/orig.txt dir2/link3.txt

Only link3 works.
