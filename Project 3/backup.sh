#!/usr/bin/env bash
mkdir -p ~/.backup/

if [ $# -eq 0 ]; then
	echo "The usage of this command is: backup.sh [options] targetFileList"
fi

for cmd in $@; do
	if [ $cmd == "-l" ]; then
		echo ".backup has the following files:"
		ls ~/.backup/
	elif [ $cmd == "-n" ]; then
		echo ".backup has the following amount of files: "
		ls -1 ~/.backup/ | wc
	elif [ $cmd == "-nl" ] || [ $cmd == "-ln" ]; then 
		echo .backup has the following amount and list of files
		ls ~/.backup/ 		# do both
		ls -1 ~/.backup/ | wc -l
		echo .backup and the contents take up the following amount of memory:
		du -hb --total ~/.backup
	elif [ $cmd == "--help" ]; then
		echo input any file/directory names to back them up in /home/.backup
		echo input -l to list the files and directories in /home/.backup
		echo input -n to get the number of file and directories in /home/.backup
		echo input -nl or -ln to get both -l and -n
	elif [ -f $cmd ]; then
		cp $cmd ~/.backup/$cmd
	elif [ -d $cmd ]; then
		cp -R $cmd  ~/.backup/$cmd
	fi
done
