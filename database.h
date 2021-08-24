char buf[BUFSIZ];
char buf1[BUFSIZ];
char buf2[BUFSIZ];
char buf3[BUFSIZ];
char buf4[BUFSIZ];

FILE *file ;
FILE *ptr,*ptr1 ,*ptr2, *ptr3,*ptr4;

#define PATH "%SYSTEMROOT%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"
char *Command   = PATH  " systeminfo | findstr /B /C:OS";
char *Command1  = PATH  " wmic os get osarchitecture";
char *Command2  = PATH  " Get-ChildItem Env: || ft Key,Value";
char *Command3  = PATH  " wmic logicaldisk get caption,description,providername,Size";
char *Command4  = PATH  " wmic qfe";
char *Command5  = PATH  " $env:username";
char *Command6  = PATH  " WHOAMI /PRIV /FO TABLE";
char *Command7  = PATH  " net user";
char *Command8  = PATH  " Get-ChildItem C:\\Users -Force || select Name";













char *end  =  "________________________END________________________";
char *end1 = "_____________________________________________________";
char *line = "===================================";
