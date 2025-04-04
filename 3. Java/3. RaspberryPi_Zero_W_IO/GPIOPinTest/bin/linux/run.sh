#!/bin/sh
#Java home path
JAVA_HOME=/usr/lib/jvm/java-1.8.0-openjdk-armhf
#Java class path
CLASSPATH=/usr/bin/a_java_app/gpiotest
#Class name
CLASSNAME=GPIOPinTestMain
##Run
echo "*********************"
echo "Starting run.sh"
echo "@Author: C.A Torino"
echo "@Author: 23 July 2021"
echo "*********************"
echo ""
## nohup * * * * * /usr/bin/a_java_app/gpiotest/run.sh &
## sudo chmod +x /usr/bin/a_java_app/gpiotest/run.sh
## crontab -l
## reboot
$JAVA_HOME/bin/java -cp $CLASSPATH $CLASSNAME
echo "Done"
exit 0