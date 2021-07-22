#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//#include<dos.h>
HANDLE screen ;
void add_contact();
void edit();
void delete_contact();
void list_contact();
void change_password(); 
struct contact
{
   int sno ;
   char category[20] ;
   char name[20] ;
   char gender ;
   char ph_no[11];
   char address[50];
} person ;

void main()
{
   int c;
   c=220;
   char pass[10],origin[10],ch,choice ;
   int i ;
   FILE*fp ;
   system("COLOR 4F");
   for(i=0;i<5;i++)
   {

      printf("\n\n\n\n           ..............................welcome..............................................\n");
      Sleep(500);
      system("cls");
      Sleep(500);
   }  
   system("cls");
   system("COLOR 70");
   
   
      printf("\n\n-----------------------------------------------ENTER PASSWORD------------------------------------------------");
      


   
   i=0;
   while(1)
   {
      
      ch=getch();
      if(ch=='\r')
      {
         pass[i]='\0';
          break ;
      }
      pass[i++]= ch ;
      printf("*");
   }
  printf("\n\n ****************************************YOU ENTERED %s*************************************\n",pass);
  fp=fopen("password.dat","r");
  fgets(origin,10,fp);
  //printf(" origin is :%s",origin);
  fclose(fp);
  if(strcmp(origin,pass)!=0)
  {
     for(i=0;i<5;i++)
     {
        system("COLOR 50");
        printf("\n---------------------------------YOUR ENTERED PASSWORD IS INCORRECT--------------------------------------");
        Sleep(500);
        system("cls");
        Sleep(500);
     }

  }
  else
  {
     system("COLOR B0");
     printf("\n\n\n    ********************************************************* CORRECT *************************************************");
     system("cls");
     system("COLOR E3") ;
      screen= GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(screen,57);
      printf("******************************************* CONTACT MANAGEMENT ***********************************************");
      printf("\n\n\n");
      printf("                   ||||||||||***************     FRONTEND :   VISUAL STUDIO CODE     *************|||||||||||");
      printf("\n\n\n");
      printf("                   ||||||||||***************     BACKEND : FILE HANDLING             ************||||||||||||");
      printf("\n\n\n");
      printf("                   ||||||||||***************     DEVELOPED BY : GARIMA JAIN          ************||||||||||||");
      printf("\n\n\n");
      getch(); //press any key
      printf("    PLEASE WAIT  ");
      for(i=0;i<40;i++)
      {
         printf(" %c",c);
         Sleep(30);
      }
      system("cls");
      system("COLOR 8F");
      printf("\n\n\n                        MAIN MENU                              ");
      printf("\n          ____________________________________________________________");
      // SetConsoleTextAttribute(screen,18);
       printf("\n\n\n");
       printf("           1.  ADD A NEW CONTACT       \n\n");
       printf("           2.  EDITING            \n\n");
       printf("           3.  DELETE A CONTACT    \n\n");
       printf("           4.  LIST OF ALL CONTACT  \n\n");
       printf("           5.  CHANGE A PASSWORD  \n\n");
       printf("           6.  EXIT                \n\n");
       printf("\n\n       _______________________________________________________________");
       printf(" \n\n\n");
       getch(); //press any key
       for(i=0;i<5;i++)
       {
             printf("      ENTER  YOUR  CHOICE..................  ");
                Sleep(500);
                system("cls");
                Sleep(500);
       }
       choice= getche();
       switch (choice)
       {
       case'1' :
        add_contact();
          break;
      /* case'2':
         edit();
         break ;
       case '3':
         delete_contact();
         break ;*/
       case'4' :
          list_contact();
          break ;
      /* case'5':
          change_password();
          break ;
       case'6':
         exit(0); */  
       }
       getch();
  }

}

void add_contact()
{
   FILE*fp ;
   int i ;
   system("cls");
   system("COLOR 8F");
   printf("n\n\n                                               ADD A NEW CONTACT");
   printf("\n\n");
   for(i=0;i<80;i++)
   {
          printf("- ");
   }
   printf("\n ENTER SERIAL NUMBER :\n");
   scanf("%d",&person.sno);
   fflush(stdin);
   printf(" \n ENTER CATEGORY :\n");
   gets(person.category);
   fflush(stdin);
   printf("\n ENTER NAME :\n");
   gets(person.name);
   fflush(stdin);
   printf("\n ENTER GENDER : \n");
   scanf("%c",&person.gender);
   fflush(stdin);
   printf("\n ENTER PHONE NO: \n");
   gets(person.ph_no);
   fflush(stdin);
   printf("\n ENTER ADDRESS :\n");
   gets(person.address);
   fflush(stdin);

   fp = fopen("info.dat","ab");
   fwrite(&person,sizeof(person),1,fp);
   fclose(fp);

   for(i=0;i<5;i++)
   {
      printf("\n\n\n      <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CONTACT SAVED SUCCESSFULLY  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
       Sleep(500);
        system("cls");
       Sleep(500); 
   }
   getch();

}

void list_contact()
{
   FILE*fp ;
   int i ;
   system("cls");
   system("COLOR 9f");
   for(i=0;i<74;i++)
   printf("- ");
   
   printf("\n S.NO\t\t  CATEGORY\t\t  NAME\t\t  GENDER\t\t   ADDRESS\t\t   PHONE_NUMBER\t\t\n");
    
    for(i=0;i<74;i++)
      printf("- ");
      fp=fopen("info.dat","r");

      while(fread(&person,sizeof(person),1,fp)!=NULL)//reading of data from info binary file.
      {
        printf("\n %d  \t\t  %s    \t\t %s  \t\t%c    \t\t%s    \t\t %s \n",person.sno,person.category,person.name,person.gender,person.address,person.ph_no);
      } 
      fclose(fp);
}



