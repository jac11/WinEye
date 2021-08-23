#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define PATH "%SYSTEMROOT%\\System32\\WindowsPowerShell\\v1.0\\powershell.exe"

FILE *file ;
void style();
int dir_file();
int if_config();
int route_ptint();
int system_info();
int dir_file()
   {
           char *Command   = PATH " systeminfo | findstr /B /C:OS";
           char *Command1  = PATH " wmic os get osarchitecture";
           char *Command2  = PATH " Get-ChildItem Env: || ft Key,Value";
           char *Command3  = PATH " wmic logicaldisk get caption,description,providername,Size";
           char *Command4  = PATH " wmic qfe";
           char buf[BUFSIZ];
           char buf1[BUFSIZ];
           char buf2[BUFSIZ];
           char buf3[BUFSIZ];
           char buf4[BUFSIZ];
           FILE *ptr,*ptr1 ,*ptr2, *ptr3,*ptr4;
           char * log  = "=================================================\n"
                         "              + Windows Enumeration +            \n"
                         "=================================================\n"
                         " + Windows Version and Configuration + \n"
                         "=====================================\n\n";
          file = fopen("./somefile.txt", "w+");
          if (!file) abort();

          if ((ptr = popen(Command, "r")) != NULL)
          {
                   fprintf(file,"%s",log);
                   printf("%s",log);
                   while ((fgets(buf,BUFSIZ,ptr) != NULL)){
                         fprintf(file,"%s", buf);
                         printf("%s",buf);
                         style();
                   }
          printf("%s","+ ARCHITECTURE +\n=========================\n");
          if ((ptr1 = popen(Command1, "r")) != NULL){
                  fprintf(file,"%s","+ ARCHITECTURE +\n==========================\n");
                   while ((fgets(buf1,BUFSIZ,ptr1) != NULL)){
                         fprintf(file,"%s",buf1);
                         printf("%s",buf1);
                   }
                   style();
          }

          printf("%s","\n + List all env variables + \n===================================\n");
          fprintf(file,"%s","\n + List all env variables + \n===================================\n");
          if ((ptr2 = popen(Command2, "r")) != NULL){
                   while ((fgets(buf2, BUFSIZ,ptr2) != NULL)){
                         fprintf(file, "%s",buf2);
                         printf("%s",buf2);
                  }
                  style();
          }
          printf("%s","\n + List all drives + \n===================================\n");
          fprintf(file,"%s","\n + List all drives + \n===================================\n");
          if ((ptr3 = popen(Command3, "r")) != NULL){
               while ((fgets(buf3,BUFSIZ,ptr3) != NULL)){
                  fprintf(file, "%s",buf3);
                  printf("%s",buf3);
               }
               style();
          }
          printf("%s","\n + Extract patchs and updates + \n===================================\n");
          fprintf(file,"%s","\n + Extract patchs and updates + \n===================================\n");
          if ((ptr4 = popen(Command4, "r")) != NULL){
               while ((fgets(buf4,BUFSIZ,ptr4) != NULL)){
                  fprintf(file, "%s",buf4);
                  printf("%s",buf4);
               }
          }
               pclose(ptr);
          }
          fclose(file);
   }
int if_config()
{
           char *Command = "ipconfig /all";
           char buf[BUFSIZ];
           FILE *ptr, *file;
           char * log  = "=================================================\n"
                         "    Network  Enumeration  \n"
                         "==============================\n"
                         "Interface\n"
                         "===================\n\n";
           file = fopen("./somefile.txt", "a");
           fprintf(file, "%s", log);
           if (!file) abort();
           printf("%s",log);
           if ((ptr = popen(Command, "r")) != NULL) {
                   while (fgets(buf, BUFSIZ, ptr) != NULL){
                           printf("%s",buf);
                           fprintf(file, "%s", buf);
                  }
                   pclose(ptr);
           }
           fclose(file);
}

int route_ptint()
{
           char * log  = "=================================================\n"
                         "router table \n"
                         "===================\n\n";
           char *Command = "route print";
           char buf[BUFSIZ];
           FILE *ptr, *file;

           file = fopen("./somefile.txt", "a");
           fprintf(file,"%s\n",log );
           if (!file) abort();
           printf("%s,log");
           if ((ptr = popen(Command, "r")) != NULL) {
                   while (fgets(buf, BUFSIZ, ptr) != NULL){
                           printf("%s",buf);
                           fprintf(file, "%s", buf);
                  }
                   pclose(ptr);
           }
           fclose(file);
}
int system_info(){
    char *Command = "systeminfo";
    char buf[BUFSIZ];
    FILE *ptr, *file;

           file = fopen("./somefile.txt", "a");
           if (!file) abort();
           if ((ptr = popen(Command, "r")) != NULL) {
                   while (fgets(buf, BUFSIZ, ptr) != NULL){
                           printf("%s",buf);
                           fprintf(file, "%s", buf);
                  }
                   pclose(ptr);
           }
           fclose(file);
}
void style(){
  fprintf(file,"%s","_____________________________________________________\n");
  printf("%s","___________________________________________________________\n");
}
int main(){
    time_t tm;
    time(&tm);
    printf("\n--------------------------------\n\nCurrent Date&Time %s",\
     ctime(&tm),"\n--------------------------\n");
    dir_file();
    if_config();
    route_ptint();
    system_info();

return 0 ;
}
