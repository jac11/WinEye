
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
//#include "database.h"
#include <string.h>
#define PATH "%SYSTEMROOT%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"
char  *end   = "________________________END________________________";
char  *end1  = "___________________________________________________";
char  *line0 = "=================================================";
char  *line  = "==================================";
char buf[BUFSIZ];
FILE *file ;
FILE *ptr;

int time_c();
char dir_file();
char User_Enum();
char  route_network();
//int sys_info();
//int system_info();
char dir_file()
{
    char * log  = "=================================================\n"
                  "              + Windows Enumeration +            \n"
                  "=================================================\n"
                  " + Windows Version and Configuration + \n"
                  "=====================================\n\n";
    char info [5][150] = {
                    PATH  " systeminfo | findstr /B /C:OS",
                    PATH  " wmic os get osarchitecture",
                    PATH  " Get-ChildItem Env: || ft Key,Value",
                    PATH  " wmic logicaldisk get caption,description,providername,Size",
                    PATH  " wmic qfe"
                    };
          fprintf(file,"%s",log);
          printf("%s",log);
          for (int i =0 ;i<=5 ;i++){
             if (!file) abort();
             if ((ptr = popen(info[i], "r")) != NULL){
                  while ((fgets(buf,BUFSIZ,ptr) != NULL)){
                       fprintf(file,"%s", buf);
                       printf("%s",buf);
                  }
             }

              printf("\n%s\n",end);fprintf(file,"%s\n",end);
              printf("\n+ Configuration +\n%s\n",line);
              if (i==4)
                 break;
         }
  }
char User_Enmu()
  {
      char * log  = "=================================================\n"
                    "               + User  Enumeration +             \n"
                    "=================================================\n"
                    " + Get current username + \n"
                    "=============================\n";
      char info [8][200] = {
                      PATH  " $env:username",
                      PATH  " WHOAMI /PRIV /FO TABLE",
                      PATH  " net user",
                      PATH  " Get-ChildItem C:\\Users -Force || select Name",
                      PATH  " net accounts",
                      PATH  " net user administrator",
                      PATH  " net user %USERNAME%",
                      PATH  " net localgroup administrators"
                      };
            fprintf(file,"%s",log);
            printf("%s",log);
            for (int i =0 ;i<=8 ;i++){
               if (!file) abort();
               if ((ptr = popen(info[i], "r")) != NULL){
                    while ((fgets(buf,BUFSIZ,ptr) != NULL)){
                         fprintf(file,"%s", buf);
                         printf("%s",buf);
                    }
               }
                printf("\n%s\n",end);fprintf(file,"%s\n",end);
                printf("\n+ Configuration +\n%s\n",line);
                if (i==7)
                   break;
           }
    }
char route_network()
{
      char * log  = "=================================================\n"
                      "               + User  Enumeration +             \n"
                      "=================================================\n"
                      " + Get current username + \n"
                      "=============================\n";
      char info [9][200] = {
                        PATH  " ipconfig /all",
                        PATH  " Get-NetRoute -AddressFamily IPv4 || ft DestinationPrefix,NextHop,RouteMetric,ifIndex",
                        PATH  " Get-NetNeighbor -AddressFamily IPv4 || ft ifIndex,IPAddress,LinkLayerAddress,State",
                        PATH  " netstat -ano",
                        PATH  " netsh firewall show config",
                        PATH  " netsh advfirewall set allprofiles state off",
                        PATH  " net share"
                        PATH  " reg query HKLM\\SYSTEM\\CurrentControlSet\\Services\\SNMP /sf",
                        PATH  " type %WINDIR%\\System32\\drivers\\etc\\hosts"
                        };
              fprintf(file,"%s",log);
              printf("%s",log);
              for (int i =0 ;i<=9 ;i++){
                 if (!file) abort();
                 if ((ptr = popen(info[i], "r")) != NULL){
                      while ((fgets(buf,BUFSIZ,ptr) != NULL)){
                           fprintf(file,"%s", buf);
                           printf("%s",buf);
                      }
                 }
                  printf("\n%s\n",end);fprintf(file,"%s\n",end);
                  printf("\n+ Configuration +\n%s\n",line);
                  if (i==8)
                     break;
            }
            pclose(ptr);
            fclose(file);
            return 0;
}
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

int main(){
    time_c();
    dir_file();
    User_Enmu();
    route_network();
    return 0 ;
}
