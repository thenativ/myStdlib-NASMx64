if [ $# -lt 1 ]; then
	echo "USAGE: make.sh <FILENAME WITHOUT EXTENSION>"
else
	filename=$(echo $1 | cut -f 1 -d '.')
	echo "Filename: $filename"
	echo "xxxxx Assembling... xxxxx"
	nasm -f elf64 $filename.asm
	echo "##### Linking... #####"
	ld $filename.o -o $filename
	chmod +x $1
	echo "@@@@@ Running... @@@@@"
	./$filename
	echo "????? Cleaning up... ?????"
	rm $filename.o
fi
