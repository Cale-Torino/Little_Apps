#!/bin/sh
#Java home path
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-armhf
#Java class path
CLASSPATH=/usr/bin/a_java_app/gpiotest
#Class name
CLASSNAME=GPIOPinTestMain
##Run
echo "*********************"
echo "Starting pack_jar.sh"
echo "@Author: C.A Torino"
echo "@Author: 23 July 2021"
echo "*********************"
echo ""
## sudo chmod +x /usr/bin/a_java_app/gpiotest/pack_jar.sh
$JAVA_HOME/bin/jar cvfm $CLASSPATH/GPIOPinTestMain.jar $CLASSPATH/manifest.txt $CLASSPATH/GPIOPinTestMain.class
echo "Done"
exit 0