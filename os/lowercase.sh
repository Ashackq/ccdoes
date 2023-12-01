read s
lowerstr=$(echo $s | tr '[:upper:]' '[:lower:]')
upperstr=$(echo $s | tr '[:lower:]' '[:upper:]')
lko=${s,,}
uko=${s^^}
echo "Original  String : $s"
echo "Lowercase String : $lko"
echo "Uppercase Strring : $uko"
