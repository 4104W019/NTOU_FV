#!/bin/sh
echo "[Step 1]: Makefie ..."
make clean
make

echo "[Step 2]: excute the application"
./$1 >/dev/null


echo "[Step 3]: gcov the source file"
gcov $1.c -a -b -f

echo "[Step 4]: lcov to output the info file"
lcov -c -o $1.info -d .

echo "[Step 5]: genhtml the html files using the info file"
genhtml $1.info -o result

echo "[Step 6]: open the result using browser APP "
firefox result/index.html &

echo "reference: http://rc0129.blogspot.com/2018/07/tools-gcov-lcov.html"

