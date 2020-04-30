 #! /bin/zsh

rm -rf *.o

if [[ ! -d bin ]]; then
  mkdir bin;
fi

executablePath=${1/#/bin\/}
gcc -c *.c
gcc -o ${executablePath} *.o
rm -rf *.o
./${executablePath}