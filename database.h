char buf[BUFSIZ];
char buf1[BUFSIZ];
char buf2[BUFSIZ];
char buf3[BUFSIZ];
char buf4[BUFSIZ];
char buf5[BUFSIZ];
char buf6[BUFSIZ];
char buf7[BUFSIZ];
char buf8[BUFSIZ];
char buf9[BUFSIZ];
char buf10[BUFSIZ];
char buf11[BUFSIZ];

FILE *file ;
FILE *ptr,*ptr1 ,*ptr2, *ptr3,*ptr4;
FILE *ptr5,*ptr6,*ptr7,*ptr8,*ptr9,*ptr10,ptr11;

#define PATH "%SYSTEMROOT%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"

//windows info
char *Command   = PATH  " systeminfo | findstr /B /C:OS";
char *Command1  = PATH  " wmic os get osarchitecture";
char *Command2  = PATH  " Get-ChildItem Env: || ft Key,Value";
char *Command3  = PATH  " wmic logicaldisk get caption,description,providername,Size";
char *Command4  = PATH  " wmic qfe";
//use info command
char *Command5  = PATH  " $env:username";
char *Command6  = PATH  " WHOAMI /PRIV /FO TABLE";
char *Command7  = PATH  " net user";
char *Command8  = PATH  " Get-ChildItem C:\\Users -Force || select Name";
char *Command9  = PATH  " net accounts";
char *Command10 = PATH  " net user administrator";
char *Command11 = PATH  " net user %USERNAME%";
char *Command12 = PATH  " net localgroup administrators";
//network Command
char *Command13  = PATH " ipconfig /all";
char *Command14  = PATH  " Get-NetRoute -AddressFamily IPv4 || ft DestinationPrefix,NextHop,RouteMetric,ifIndex";
char *Command15  = PATH  " Get-NetNeighbor -AddressFamily IPv4 || ft ifIndex,IPAddress,LinkLayerAddress,State";
char *Command16  = PATH  " netstat -ano";
char *Command17  = PATH  " netsh firewall show config";
//char *Command18  = PATH  " $f=New-object -comObject HNetCfg.FwPolicy2;$f.rules ||  where {$_.action -eq '0'} || select name,applicationname,localports";
char *Command19  = PATH  " netsh advfirewall set allprofiles state off";
char *Command20  = PATH  " net share";
char *Command21  = PATH  " reg query HKLM\\SYSTEM\\CurrentControlSet\\Services\\SNMP /s";
char *Command22  = PATH  " type %WINDIR%\\System32\\drivers\\etc\\hosts";
// lines to give style txt file
char  *end   = "________________________END________________________";
char  *end1  = "___________________________________________________";
char  *line0 = "=================================================";
char  *line  = "==================================";
//func run get time and date
int time_c(){
      time_t timeNow;
      timeNow = time(NULL);
       char *TIMENOW= (ctime(&timeNow));
       file = fopen("./Enum_Win.txt", "w+");
       fprintf(file,"%s\n", line0);
       fprintf(file,"%s","Currant Time&Date : ");
       fprintf(file,"%s", TIMENOW);
       printf("%s\nCurrent Time&Date : %s",line0, TIMENOW);
}
