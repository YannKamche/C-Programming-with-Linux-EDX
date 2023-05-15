## Commands discussed in this video:

whoami
whoami --help
id
logname
echo hello
echo $0
hostname
uname
uname -a
history  //AND UP ARROW 
clear
uptime
cal
cal --help
cal -j
date
date +"%T"
date +"%A %d %B %Y"
man

# Commands discussed in this video:

top --help //how to quit + 
top  //q to quit
top  // ^+C to quit
htop
htop --help
htop // F1
nano // ^ = ctrl  carret (circumflex accent)
vim // :q and also escape then :q
//CTRL + C expanation (sometimes quits the program, but not always)

# Commands discussed in this vide:
hello
worm
firework
rain
hanoi
knight

# Commands discussed in this video:

ls
file program.c
nano f
hello!   (CTRL + O then ENTER then CTRL + X)
file f
realpath f
cd /
ls
file bin
cd bin
ls
file cat
file busybox
realpath cat
cd /sys/kernel
ls
file notes
file fscaps
which realpath
which cat
which which
which file

# Commands discussed in this video:
pwd
touch file
ls
rm file
ls
touch my file
ls
rm my
rm file
touch my\ file
ls
ls -l
rm my\ file
touch 'my file'
rm 'my file'
rm '
'  // OR CTRL + D (sometimes twice); or CTRL + Z (suspend); CTRL + C does not work
(
)  // OR CTRL + D (sometimes twice); or CTRL + Z (suspend) CTRL + C does not work
"
"
{
}
touch my_file (with underscore)
rm my_file

# Commands discussed in this video:

nano file.txt
here is a text file
with a second line
cat file.txt
echo "hello world"
echo "hello world" > file2.txt
cat file2.txt
cat file2.txt > file3.txt
cat file3.txt
cat > anotherfile.txt
this is anotherfile
with a new second also (CTRL + D twice!)
cat anotherfile.txt
cat /etc/services
cat /etc/services > listOfServices.txt
nano listOfServices.txt
cat /etc/services | more
cat /etc/services | less    (navigating: space bar, arrows or j,k, G, g)
more anotherfile.txt
less anotherfile.txt
ls /usr/bin
ls /usr/bin | less
searching: Forward Search
/ – search for a pattern which will take you to the next occurrence.
n – for next match in forward
N – for previous match in backward
Backward Search
? – search for a pattern which will take you to the previous occurrence.
n – for next match in backward direction
N – for previous match in forward direction
less --help  (see N and M options)
ls /usr/bin | less -NM

# Commands discussed in this video:

mkdir folder
ls
ls -l
cd folder
touch f1
touch f2
mkdir subfolder
ls
cd subfolder
pwd
touch f3
touch f4
touch f5
cd
pwd
rm folder   (error: is a directory)
rm -r folder
mkdir folder
cd folder
touch f1
touch f2
cd
rm -ri folder
y y y
mkdir folder
cd folder
touch f1
touch f2
cd
yes   (CTR + C)
ls
yes | rm -ri folder
mkdir D1/D2/D3/D4/D5
mkdir -p D1/D2/D3/D4/D5

# Commands discussed in this video:

get out of vim:
vim
i
insert some text
ESCAPE + :q or sometimes :q!
'
'
'  CTRL + D
"
"
"  CTRL + D
(
)
cat > file.txt
this is a file   CTRL + D twice
cat file.txt
cat > file2.txt
this is a file
CTRL + D  (only once because empty line)
cat file2.txt

worst case : kill a program
rain
open second terminal
htop  F9  send the SIGKILL signal 

# Commands discussed in this video:

touch f1
mkdir d1
mv f1 d1
mv d1/f1 .  (or mv ./d1/f1 .)
mkdir bigdir
mv d1 bigdir
cd bigdir/d1
ls
mv f1 ../..
ls ../..
mkdir ../../otherdir
mv ../../f1 ../../otherdir
pwd
mv . ../..    ERROR
cd
mv bigdir smalldir   (RENAMING)
mv otherdir/f1 f2    (MOVING AND RENAMING at the same time)
mv smalldir/d1 otherdir/d2   (MOVING AND RENAMING at the same time)
cat > f5
hello
CTRL + D
cat > f6
world
CTRL + D
cat f5
cat f6
mv f6 f5
f5 is lost ! BE CAREFUL
mv --help
mv -i   or  mv -n  TO NOT OVERWRITE! FOR MORE SECURITY

# Commands discussed in this video:

cat > f1
hello
CTRL + D
cp f1 f2
cat f1
cat f2
mkdir d1
mv f1 d1
cp d1 d2
cp -r d1 d2
cp -r d1 d2
cp -r d1 d2
cp --help
cp -ri d1 d2

# Commands discussed in this video:

locate file
updatedb
echo p*
echo /usr/bin/a*
echo /usr/bin/a??
echo /usr/bin/???
find
find /
find .
find . -name "program.c"
find . -name "prog*"
find / -name "hello"
find / -name "hello" 2>/dev/null
find / -name "*joe*" 2>/dev/null
find / -iname "*joe*" 2>/dev/null
find / -ipath "*joe*" 2>/dev/null
find / -ipath "*joe*" 2>/dev/null | less

# Commands discussed in this video:

./program
ls
file program.c
file program
cp program.c otherprogram.c
./otherprogram
ls

# Commands discussed in this video:
ls
gcc program.c
ls
file a.out
./a.out
gcc program.c -o program
ls
file program
./program
gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -o program

# Commands discussed in this video:

free --help
free
free -b
free -k
free -m
free -g
top --help
s
(VSZ - or VIRT for other top versions) : virtual size (memory quantity used by the program)  1496 KB used for top
htop
(visual representation)
(VIRT)
F6 (sort by) then choose M_SIZE (Memory_SIZE)

Code discussed in this video:

#include <stdio.h>

int main(){
    char arr[1000000];
    char c;
    printf("please enter to exit");
    scanf("%c",&c);
    return 0;
}

# Commands and changes discussed in this video:

go to the second terminal
htop
program is using 1800
quit htop
go back to the first terminal

change to int instead of char for arr
second terminal 
htop 
program is using 4728
quit htop
go back to the first terminal

change to double instead of char for arr
second terminal 
htop 
program is using 8632
quit htop
go back to the first terminal