::INSTALL THE SERVICE
::RUN AS ADMINISTRATOR FOR IT TO WORK
ECHO ON
start cmd /k ServiceConsoleApp.exe install start
::WHEN RUNNING THE SCRIPT FROM A DIFFERENT DRIVE ADD THE `/D` SWITCH TO YOUR CD COMMAND
::CD /D C:\Software\python\Lib\site-packages\FreeTAKServer-UI
pause