#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "database.h"

void time_c();
int dir_file();
int User_Enum();
//int route_ptint();
//int system_info();
int dir_file()
   {
           char * log  = "=================================================\n"
                         "              + Windows Enumeration +            \n"
                         "=================================================\n"
                         " + Windows Version and Configuration + \n"
                         "=====================================\n\n";
          file = fopen("./Enum_Win.txt", "w+");
          if (!file) abort();

          if ((ptr = popen(Command, "r")) != NULL)
          {
                   fprintf(file,"%s",log);
                   printf("%s",log);
                   while ((fgets(buf,BUFSIZ,ptr) != NULL)){
                         fprintf(file,"%s", buf);
                         printf("%s",buf);
                         printf("%s\n",end1);fprintf(file,"%s\n",end1);
                   }
          printf("+ ARCHITECTURE +\n%s\n",line);
          if ((ptr1 = popen(Command1, "r")) != NULL){
                  fprintf(file,"\n%s\n%s\n","+ ARCHITECTURE +",line);
                   while ((fgets(buf1,BUFSIZ,ptr1) != NULL)){
                         fprintf(file,"%s",buf1);
                         printf("%s",buf1);
                   }
                   printf("\n%s\n",end);fprintf(file,"%s\n",end);
          }

          printf("+ List all env variables +\n%s\n ",line);
          fprintf(file,"\n%s\n%s\n","+ List all env variables +",line);
          if ((ptr2 = popen(Command2, "r")) != NULL){
                   while ((fgets(buf2, BUFSIZ,ptr2) != NULL)){
                         fprintf(file, "%s",buf2);
                         printf("%s",buf2);
                  }
                  printf("\n%s\n",end);fprintf(file,"%s\n",end);
          }
          printf("+ List all drives +\n%s\n",line);
          fprintf(file,"\n%s\n%s\n","+ List all drives +",line);
          if ((ptr3 = popen(Command3, "r")) != NULL){
               while ((fgets(buf3,BUFSIZ,ptr3) != NULL)){
                  fprintf(file, "%s",buf3);
                  printf("%s",buf3);
               }
               printf("\n%s\n",end);fprintf(file,"%s\n",end);
          }
          printf("+ Extract patchs and updates  +\n%s\n",line);
          fprintf(file,"\n%s\n%s\n","+ Extract patchs and updates +",line);
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

int User_Enmu()
{
          // char buf2[BUFSIZ];
           char * log  = "=================================================\n"
                         "             + User  Enumeration +               \n"
                         "=================================================\n"
                         " + Get current username + \n"
                         "=============================\n";
           file = fopen("./Enum_Win.txt", "a");
           fprintf(file, "%s", log);
           if (!file) abort();
           printf("%s",log);
           if ((ptr = popen(Command5, "r")) != NULL) {
                   while (fgets(buf,BUFSIZ, ptr) != NULL){
                           printf("%s",buf);
                           fprintf(file,"%s",buf);
                  }
                printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ Privilege +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ Privilege +",line);
            if((ptr1 = popen(Command6 ,"r"))!=NULL){
                  while(fgets(buf1,BUFSIZ,ptr1)!=NULL){
                     printf("%s",buf1);
                     fprintf(file,"%s",buf1);
                  }
                  printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ List Of the Users +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ List Of the Users +",line);
            if((ptr2 = popen(Command7 ,"r"))!=NULL){
                   while(fgets(buf2,BUFSIZ,ptr2)!=NULL){
                           printf("%s",buf2);
                           fprintf(file,"%s",buf2);
                  }
                  printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ Users Directory +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ Users Directory +",line);;
            if((ptr3 = popen(Command8 ,"r"))!=NULL){
                   while(fgets(buf3,BUFSIZ,ptr3)!=NULL){
                          printf("%s",buf3);
                          fprintf(file,"%s",buf3);
                    }
                     printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ logon requirements +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ logon requirements +",line);;
            if((ptr4 = popen(Command9 ,"r"))!=NULL){
                     while(fgets(buf4,BUFSIZ,ptr4)!=NULL){
                            printf("%s",buf4);
                            fprintf(file,"%s",buf4);
                      }
                      printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ Administrator accont +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ Administrator accont +",line);;
            if((ptr5 = popen(Command10 ,"r"))!=NULL){
                       while(fgets(buf5,BUFSIZ,ptr5)!=NULL){
                              printf("%s",buf5);
                              fprintf(file,"%s",buf5);
                       }
                       printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ User accont +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ User accont +",line);
            if((ptr7 = popen(Command11 ,"r"))!=NULL){
                  while(fgets(buf7,BUFSIZ,ptr7)!=NULL){
                        printf("%s",buf7);
                        fprintf(file,"%s",buf7);
                  }
                  printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            printf("+ localgroup administrators +\n%s\n",line);
            fprintf(file,"\n%s\n%s\n","+ localgroup administrators +",line);
            if((ptr8 = popen(Command12 ,"r"))!=NULL){
                  while(fgets(buf8,BUFSIZ,ptr8)!=NULL){
                        printf("%s",buf8);
                        fprintf(file,"%s",buf8);
                  }
                  printf("\n%s\n",end);fprintf(file,"%s\n",end);
            }
            pclose(ptr);

           fclose(file);
}
int route_ptint()
{
           char * log  = "\n=================================================\n"
                         "router table \n"
                         "===================\n\n";
}           
int main(){
    time_c();
    dir_file();
    User_Enmu();
    route_ptint();


return 0 ;

}
