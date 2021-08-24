char buf[BUFSIZ];
char buf1[BUFSIZ];
char buf2[BUFSIZ];
char buf3[BUFSIZ];
char buf4[BUFSIZ];
char buf5[BUFSIZ];
char buf6[BUFSIZ];
char buf7[BUFSIZ];
char buf8[BUFSIZ];

FILE *file ;
FILE *ptr,*ptr1 ,*ptr2, *ptr3,*ptr4;
FILE *ptr5,*ptr6,*ptr7,*ptr8,*ptr9,*ptr10;

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
char *Command9  = PATH  " net accounts";
char *Command10 = PATH  " net user administrator";
char *Command11 = PATH  " net user %USERNAME%";
char *Command12 = PATH  " net localgroup administrators";
//char *Command14 = PATH  " $env:username";











char *end  =  "________________________END________________________";
char *end1 = "_____________________________________________________";
char *line = "===================================";
void time_c(){
      time_t tm;
      time(&tm);
       printf("\n--------------------------------\n\nCurrent Date&Time %s",\
       ctime(&tm),"\n--------------------------\n");
}
