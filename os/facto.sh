echo "Enter the number "
read n
fact=1
for((i=n;i>0;i--))
	do 
		fact=$((fact * i))
	done
echo $fact
