

open cmd as administrator in directory then follow the instructions bellow:

1. create service in cmd

```
SC CREATE "WindowsService1" binpath= "C:\Users\User501\source\repos\WindowsService1\WindowsService1\bin\Release\WindowsService1.exe" DisplayName= "WindowsService1" start=auto
```

2. delete service in cmd

```
SC DELETE WindowsService1
```

