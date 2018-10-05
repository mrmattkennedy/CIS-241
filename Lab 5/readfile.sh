while read -r field1 field2
do
	echo $field1
	mkdir -p "$field1"
	touch "$field1/$field2"
done < "classes"

