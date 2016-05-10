#!/bin/bash
gcc -c -I../include/ ../app/cs1419-assign9-prog1.c -o cs1419-assign9-prog1.o
gcc -c -I../include/ ../src/cs1419-assign9-src-prog1.c -o cs1419-assign9-src-prog1.o
gcc cs1419-assign9-src-prog1.o cs1419-assign9-prog1.o -o prog
