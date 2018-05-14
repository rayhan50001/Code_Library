#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int i,j;
int main_exit;
void menu();
void closer();

struct date
{
    int month,day,year;
};
struct
{
    char name[60];
    int age;
    char city[60];
    char mail_id[30];
    char room_no[8];
    char father_name[60];
    int father_phone;
    int phone;
    char hostel_name[6];
    char roll_no[10];
    struct date dob;
}add,upd,check,rem,sortt;
void new_entry()
{
    int choice;
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    roll_no:
    cout<<"\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2";
    cout<<"\nEnter your roll number:";
    cin>>check.roll_no;
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
    {
        if (strcmp(add.roll_no,check.roll_no))
        {
             cout<<"Students roll no. already in used!\n";
             goto roll_no;
        }
    }

    strcpy(add.roll_no,check.roll_no);
    cout<<"\nEnter the name:";
    cin>>add.name;
    cout<<"\nEnter the date of birth(mm/dd/yyyy):";
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    cout<<"\nEnter the age:";
    cin>>add.age;
    cout<<"\nEnter the city:";
    cin>>add.city;
    cout<<"\nEnter the phone number: ";
    cin>>add.phone;
    cout<<"\nEnter your email id :";
    cin>>add.mail_id;
    cout<<"\nEnter your Father's name:";
    cin>>add.father_name;
    cout<<"\nEnter your Father's phone no.:";
    cin>>add.father_phone;
    cout<<"\nEnter your room no.:";
    cin>>add.room_no;
    cout<<"\nEnter your hostel name from BH-1, BH-2, BH-3, GH-1 :";
    cin>>add.hostel_name;
    fprintf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    fclose(ptr);
    cout<<"\nStudent added successfully!";
    add_invalid:
    cout<<"\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:";
    cin>>main_exit;

    if (main_exit==1)
        menu();
    else if(main_exit==0)
            closer();
    else
        {
            cout<<"\nInvalid!\a";
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;

    cout<<"\nROLL NO.\tNAME\t\t\tcity\t\t\tPHONE\n";

    while(fscanf(view,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t %d",add.roll_no,add.name,add.city,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {
            cout<<"\nNO RECORDS!!\n";}

    view_list_invalid:
     cout<<"\n\nEnter 1 to go to the main menu and 0 to exit:";
        cin>>main_exit;
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            cout<<"\nInvalid!\a";
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    cout<<"\nEnter the roll no. of the student whose info you want to change:";
    cin>>upd.roll_no;
    while(fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
    {
        if (add.roll_no==upd.roll_no)
        {   test=1;
            cout<<"\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):";
            cin>>choice;

            if(choice==1)
                {
                cout<<"Enter the new room no.:";
                cin>>upd.room_no;
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, upd.room_no, add.hostel_name);
                cout<<"Changes saved!";
                }
            else if(choice==2)
                {
                cout<<"Enter the new phone number:";
                cin>>upd.phone;
                fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
                cout<<"Changes saved!";
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {
            cout<<"\nRecord not found!!\a\a\a";
            edit_invalid:
              cout<<"\nEnter 0 to try again,1 to return to main menu and 2 to exit:";
              cin>>main_exit;

                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    closer();
                else if(main_exit==0)
                    edit();
                else
                    {
                    cout<<"\nInvalid!\a";
                    goto edit_invalid;
                    }
        }
    else
        {
        cout<<"\n\n\nEnter 1 to go to the main menu and 0 to exit:";
        cin>>main_exit;
        if (main_exit==1)
            menu();
        else
            closer();
        }
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    cout<<"Enter the roll np. of student whose data you want to delete:";
    cin>>rem.roll_no;
    while (fscanf(old,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
   {
        if(add.roll_no!=rem.roll_no)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);

        else
            {
            test++;
            cout<<"\nRecord deleted successfully!\n";
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            cout<<"\nRecord not found!!\a\a\a";
            erase_invalid:
              cout<<"\nEnter 0 to try again,1 to return to main menu and 2 to exit:";
              cin>>main_exit;

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    closer();
                else if(main_exit==0)
                    erase();
                else
                    {cout<<"\nInvalid!\a";
                    goto erase_invalid;}
        }
    else
        {cout<<"\nEnter 1 to go to the main menu and 0 to exit:";
        cin>>main_exit;

        if (main_exit==1)
            menu();
        else
            closer();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    cout<<"Do you want to check by\n1.Roll no\n2.Name\nEnter your choice:";
    cin>>choice;
    if (choice==1)
    {   cout<<"Enter the roll number:";
        cin>>check.roll_no;

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.roll_no,check.roll_no))
            {
                test=1;

                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",check.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }
    else if (choice==2)
    {   cout<<"Enter the name:";
        cin>>check.name;
        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",add.roll_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone, add.mail_id, add.father_name, &add.father_phone, add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {
                test=1;
                printf("\nROLL NO.:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%d \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%d \nRoom No:%s \nHostel:%s \n",add.roll_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone, add.mail_id, add.father_name, add.father_phone, add.room_no, add.hostel_name);
            }
        }
    }

    fclose(ptr);
     if(test!=1)
        {
            cout<<"\nRecord not found!!\a\a\a";
            see_invalid:
              cout<<"\nEnter 0 to try again,1 to return to main menu and 2 to exit:";
              cin>>main_exit;

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    closer();
                else if(main_exit==0)
                    see();
                else
                    {

                        cout<<"\nInvalid!\a";
                        goto see_invalid;}
        }
    else
        {
        cout<<"\nEnter 1 to go to the main menu and 0 to exit:";
        cin>>main_exit;
        }
        if (main_exit==1)
        {
          menu();
        }

        else
           {
             closer();
            }

}

void sortter(void)
{
    int choice;
    cout<<"Enter year choice:\n\n\t\t1. BH-1 \n\t\t2. BH-2 \n\t\t3. BH-3 \n\t\t4. GH-1 \n\n";
    cin>>choice;

    FILE *fp, *sortt1, *sortt2, *sortt3, *sortt4;
    fp=fopen("record.dat","r");
    int test=0;

    while(fscanf(fp,"%s %s %d/%d/%d %d %s %d %s %s %d %s %s\n",sortt.roll_no, sortt.name, &sortt.dob.month, &sortt.dob.day, &sortt.dob.year, &sortt.age, sortt.city, &sortt.phone, sortt.mail_id, sortt.father_name, &sortt.father_phone, sortt.room_no, sortt.hostel_name)!=EOF)
    {
        if(choice==1 && strcmp(sortt.hostel_name,"BH-1")==0)
        {
           sortt1=fopen("sorttBH-1.dat","a+");
           cout<<"\t\tFollowing are students of BH-1 hostel:";
           cout<<"\n\tROLL NO.\tROOM NO.\tNAME\n";
           printf("\n\t%8s\t %8s\t %s", sortt.roll_no, sortt.room_no, sortt.name);
           test++;
           fprintf(sortt1, "%s %s %s\n", sortt.roll_no, sortt.room_no, sortt.name);
           fclose(sortt1);
        }
        else if(choice==2 && strcmp(sortt.hostel_name,"BH-2")==0)
        {
           sortt2=fopen("sorttBH-2.dat","a+");
           cout<<"\t\tFollowing are students of BH-2 hostel:";
           cout<<"\n\tROLL NO.\tROOM NO.\tNAME\n";
           printf("\n\t%8s\t %8s\t %s", sortt.roll_no, sortt.room_no, sortt.name);
           test++;
           fprintf(sortt2, "%s %s %s\n", sortt.roll_no, sortt.room_no, sortt.name);
           fclose(sortt2);
        }
        else if(choice==3 && strcmp(sortt.hostel_name,"BH-3")==0)
        {
           sortt3=fopen("sorttBH-3.dat","a+");
           cout<<"\t\tFollowing are students of BH-3 hostel:";
           cout<<"\n\tROLL NO.\tROOM NO.\tNAME\n";
           printf("\n\t%8s\t %8s\t %s", sortt.roll_no, sortt.room_no, sortt.name);
           test++;
           fprintf(sortt3, "%s %s %s\n", sortt.roll_no, sortt.room_no, sortt.name);
           fclose(sortt3);
        }
        else if(choice==4 && strcmp(sortt.hostel_name,"GH-1")==0)
        {
           sortt4=fopen("sorttBH-4.dat","a+");
           cout<<"\t\tFollowing are students of GH-1 hostel:";
           cout<<"\n\tROLL NO.\tROOM NO.\tNAME\n";
           printf("\n\t%8s\t %8s\t %s", sortt.roll_no, sortt.room_no, sortt.name);
           test++;
           fprintf(sortt4, "%s %s %s\n", sortt.roll_no, sortt.room_no, sortt.name);
           fclose(sortt4);
        }
    }
    fclose(fp);
    if (test==0)
        {
        cout<<"\nNO RECORDS!!\n";}

sortt_list_invalid:
 cout<<"\n\nEnter 1 to go to the main menu and 0 to exit:";
    cin>>main_exit;

    if (main_exit==1)
        menu();
    else if(main_exit==0)
        closer();
    else
    {
        cout<<"\nInvalid!\a";
        goto sortt_list_invalid;
    }

}

void closer()
{
    cout<<"\n\n\n\nDeveloped by Zerin Khan\n\n\n";
}


void menu(void)
{   int choice;

    system("color 9");
    cout<<"\n\n\t\t\tHOSTEL DATA MANAGEMENT SYSTEM";
    cout<<"\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\n\t\t1.Enter new Student's data\n\t\t2.Update information of existing account\n\t\t3.Check the details of existing account\n\t\t4.View all Students of a particlar Hostel\n\t\t5.Removing existing account\n\t\t6.View all students list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;


    switch(choice)
    {
        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:sortter();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:closer();
        break;

    }



}
int main()
{
  menu();
  return 0;
}


