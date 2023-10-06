#!/bin/sh

exit_handler() {
    trap - EXIT
  
    test -r "$TMPFILE" && rm -f "$TMPFILE"
    test -r "$TMPFILE_COORDS" && rm -f "$TMPFILE_COORDS"
}

trap exit_handler EXIT HUP INT QUIT PIPE TERM

clear
TMPFILE="`mktemp`"
TMPFILE_COORDS="`mktemp`"
stty size 2> /dev/null | read LINES COLUMNS
IFS=''
while read f; do 
    echo $f | sed -e 's/\(.\)/\1\n/g' >> $TMPFILE
done

x=0
y=0

while read p; do
    echo $p $x $y >> $TMPFILE_COORDS
    x=$((x + 1))
    if [ -z "$p" ]; then
        x=0
        y=$((y + 1))
    fi
done <$TMPFILE

shuf $TMPFILE_COORDS > $TMPFILE
IFS=' '
while read p x y; do
    if [ -z "$y" ]; then
        tput cup "$x" "$p"; echo " "; tput cup $LINES $COLUMNS
    else
        tput cup "$y" "$x"; echo "$p"; tput cup $LINES $COLUMNS
    fi
    sleep ${1-"0.05"}
done <$TMPFILE
