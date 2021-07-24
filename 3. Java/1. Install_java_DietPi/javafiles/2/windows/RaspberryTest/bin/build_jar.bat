::START THE APPLICATION
@ECHO OFF
"C:\Program Files\Java\jdk-16.0.2\bin\jar" cvfm RaspberryTestMain.jar manifest.txt RaspberryTestMain.class LoggerClass.class HTTP_RequestsClass.class
pause