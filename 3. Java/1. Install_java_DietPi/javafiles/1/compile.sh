#!/bin/sh
#Java home path
#JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-armhf
#Java class path
#CLASSPATH=/usr/bin/a_java_app/apptest
#Class name
CLASSNAME=main
##Run
echo "*********************"
echo "Starting compile.sh"
echo "@Author: C.A Torino"
echo "@Author: 23 July 2021"
echo "*********************"
echo ""
## sudo chmod +x /usr/bin/a_java_app/apptest/compile.sh
javac $CLASSNAME.java
echo "Done"
exit 0