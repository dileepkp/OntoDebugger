#!/bin/bash

iterCount=2


#fixed code begins
regex1="1xxyy([0-9]+)"

filename="odb_parameters.txt"
#total=`eval wc -l $fileName`

 JAVA_HOME=/usr/lib/jvm/java-8-oracle 


# for each testcase
while read -r line; 
do
# echo $line
paramString=$line

command="/home/aidb/netbeans-8.2/java/maven/bin/mvn \"-Dexec.args=-classpath %classpath com.mycompany.ontodebugger.Main "$paramString" \" -Dexec.executable=/usr/lib/jvm/java-8-oracle/bin/java -DskipTests=true -Dmaven.test.skip org.codehaus.mojo:exec-maven-plugin:1.2.1:exec"

#echo $command
echo "" > debuggeroutput.txt
for (( e=0; e<$iterCount; e++ )) 
do
eval $command >> debuggeroutput.txt
done

outputString=`cat debuggeroutput.txt`
#echo $outputString

val=0
 while [[ $outputString =~ $regex1 ]]; do 
#      echo "${BASH_REMATCH[1]}"
val=`expr $val + ${BASH_REMATCH[1]}`
        outputString=${outputString#*"${BASH_REMATCH[1]}"}
    done

result=`expr $val / $iterCount`
echo $line "--" $result"."`expr $val % $iterCount`

#if [[ $outputString =~ $regex1 ]]
#then
#name=${BASH_REMATCH[1]}
#echo $name
#fi

done < "$filename"



