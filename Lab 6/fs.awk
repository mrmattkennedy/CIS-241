#!/bin/gawk -f
BEGIN	{
	d = 0	#directory total
	f = 0	#files total
	l = 0	#links total
	t = 0	#overall total
	stor = 0
	}



$1 ~ /^d[rwxts-]{9}/	{d += 1} #directory, add 1
$1 ~ /^-[rwxts-]{9}/	{f += 1} #file, add 1
$1 ~ /^l[rwxts-]{9}/    {l += 1} #file, add 1
	t = d + f + l
	{stor += $5}



END	{print ""
	 print "Here is the summary of files under your home directory:"
	 print ""
	 print "directories   files     links      total       storage(Bytes)"
	 print "============================================================="
	 printf "%-13d %-9d %-11d %-10d %-10d\n\n", d, f, l, t, stor
	} 
