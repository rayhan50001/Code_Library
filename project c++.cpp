#include<bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include <graphics.h>
using namespace std;
void colorPrint(int k)
{
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, k);
}
int question_set1(int n)
{
int cor=0,fal=0,total=0,a;
//EASY PORTION
if(n==1)
{
//1
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Noun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Louis\n2= Is\n3= A\n4= Football\n5= Player\n";
cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//2
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= She\n2= And\n3= Her\n4= Mother\n5= Have\n6= A\n7= Very\n8= Close\n9= Relationship\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>9)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//3
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Hasib\n2= Is\n3= In\n4= The\n5= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//4
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Am\n3= Spartacus\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//5
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Rocks\n2= Are\n3= Hard\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//6
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= There\n2= was\n3= Never\n4= Any\n5= Food\n6= In\n7= The\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//7
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Kamrul\n2= Is\n3= A\n4= Good\n5= Boy\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//8
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= That\n2= Must\n3= Be\n4= A\n5= Very\n6= Hot\n7= Fire\n";
cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>7)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==6)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//9
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Interjection ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Hurrah!\n2= We\n3= Have\n4= Won\n5= The\n6= Game\n";
cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//10
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= They\n2= Have\n3= Much\n4= Rice\n";
cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
}
//NORMAL PORTION
else if(n==2)
{
//1
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= People\n2= learn\n3= From\n4= Their\n5= Mistakes\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//2
cout<<endl;
cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Mother\n2= Gave\n3= Me\n4= A\n5= Card\n6= For\n7= My\n8= Birthday\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//3
cout<<endl;
cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= The\n2= New\n3= Mail\n4= Carrier\n5= Finally\n6= Arrived\n";cout<<"\t\t\t"; cin>>a;
cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//4
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Last\n2= Night,\n3= The\n4= Shone\n5= Brightly\n6= Over\n7= The\n8= Homes\n9= In\n10= My\n11= Neighborhood\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>11)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==5)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//5
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Neela\n2= Writes\n3=Slowly\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//6
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Few\n2= Candidates\n3= Were\n4= Selected\n5= For\n6= The\n7= Jobs\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>7)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//7
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Told\n3= Them\n4= To\n5= Come\n6= Here\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//8
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= she\n2= Is\n3= A\n4= Sleeping\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>4)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//9
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Conjunction ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= He\n2= Studied\n3= Hard\n4= And\n5= Passed\n6= The\n7= Examination\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>7)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//10
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= The\n2= Book\n3= Is\n4= On\n5= The\n6= Table\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
}
total=(cor-fal)*100;
//freopen("output.txt","w",stdout);
cout<<"\n\n\t\tCorrect Answer: "<<cor<<endl;
cout<<"\t\tWrong Answer: "<<fal<<endl;
return total;
}
//Question Set-2
int question_set2(int n)
{
int cor=0,fal=0,total=0,a;
//EASY PORTION
if(n==1)
{
//1
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Tuna's\n2= Dog\n3= Ate\n4= My\n5= Copy\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//2
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Your\n2= Father\n3= Is\n4= A\n5= Teacher\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//3
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Conjunction ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Can\n3= Read\n4= And\n5= Write\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//4
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Noun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Nisha\n2= Is\n3= A\n4= Good\n5= Girl\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//5
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Read\n3= In\n4= The\n5= Morning\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//6
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Have\n3= A\n4= Red\n5= Pendrive\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//7
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= He\n2= Is\n3= A\n4= bad\n5= Boy\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//8
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= They\n2= Live\n3= There\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//9
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Each\n2= Can\n3= Do\n4= It\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>4)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//10
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Noun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Man\n2= Is\n3= Mortal\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
}
//NORMAL PORTION
else if(n==2)
{
//1
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Last\n2= Night,\n3= The\n4= Shone\n5= Brightly\n6= Over\n7= The\n8= Homes\n9= In\n10= My\n11= Neighborhood\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>11)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==10)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//2
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= There\n2= Was\n3= Never\n4= Any\n5= Food\n6= In\n7= The\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==6)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//3
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Man\n2= Is\n3= Mortal\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//4
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Programmers\n2= Of\n3= 29th\n4= Intake\n5= Section\n6= 5\n7= Are\n8= Good\n9= Coder\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>9)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//5
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= The\n2= Book\n3= Is\n4= On\n5= The\n6= Table\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//6
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= There\n2= Was\n3= Never\n4= Any\n5= Food\n6= In\n7= The\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//7
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= He\n2= Seemed\n3= Sorry\n4= Since\n5= He\n6= Almost\n8= Immediately\n9= Apologized\n10= To\n11= Us\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>11)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//8
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Interjection ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Oh!\n2= What\n3= A\n4= Beautiful\n5= Flower\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//9
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Few\n2= Candidates\n3= Were\n4= Selected\n5= For\n6= The\n7= Jobs\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>7)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//10
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= The\n2= Garden\n3= Is\n4= In\n5= Front\n6= of\n7= My\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==7)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
}
//freopen("output.txt","w",stdout);
total=(cor-fal)*100;
cout<<"\n\n\t\tCorrect Answer: "<<cor<<endl;
cout<<"\t\tWrong Answer: "<<fal<<endl;
return total;
}
//Question Se-3
int question_set3(int n)
{
int cor=0,fal=0,total=0,a;
//EASY PORTION
if(n==1)
{
//1
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= There\n2= Was\n3= Never\n4= Any\n5= Food\n6= In\n7= The\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//2
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Read\n3= In\n4= The\n5= Morning\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//3
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= They\n2= Live\n3= There\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//4
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Man\n2= Is\n3= Mortal\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//5
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Sugar\n2= Is\n3= Sweet\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//6
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Am\n3= Spartacus\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//7
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Noun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Rahim\n2= Can\n3= Do\n4= It\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>4)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//8
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Pronoun ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= We\n2= Have\n3= Won\n4= The\n5= Game\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//9
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adverb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= There\n2= Was\n3= Never\n4= Any\n5= Food\n6= In\n7= The\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//10
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Many\n2= Man\n3= Attended\n4= In\n5= The\n6= Function\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
}
//NORMAL PORTION
else if(n==2)
{
//1
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Last\n2= Night,\n3= The\n4= Shone\n5= Brightly\n6= Over\n7= The\n8= Homes\n9= In\n10= My\n11= Neighborhood\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>11)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//2
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Conjunction ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Not\n2= Only\n3= Karim\n4= But\n5= Also\n6= His\n7= Brothers\n8= Have\n9= Done\n10= This\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>10)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//3
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Many\n2= Man\n3= Attended\n4= In\n5= The\n6= Function\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>6)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//4
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Adjective ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Am\n3= A\n4= Good\n5= Boy\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//5
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Verb ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= The\n2= New\n3= Mail\n4= Finally\n5= Arrived\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//6
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Interjection ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= Wow!\n2= The\n3= Girl\n4= is\n5= Look\n6= So\n8= Beautiful\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==1)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//7
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= He\n2= Seemed\n3= Sorry\n4= Since\n5= He\n6= Almost\n8= Immediately\n9= Apologized\n10= To\n11= Us\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>11)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==4)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//8
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= I\n2= Read\n3= In\n4= The\n5= Morning\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>5)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==3)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//9
cout<<"Is There Any Adverb In This Sentence?? Enter(1=Yes or 2=No)\n";
cout<<" Mom wanted the answer, but we had had no reply from our daughter or son"<<endl;
cout<<"1= Yes\n2= No\n"; cin>>a;
cout<<endl<<endl; while(a>2)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==2)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
//10
cout<<endl;cout<<"Choose ";colorPrint(15);cout<<"Preposition ";colorPrint(11);cout<<"from given words???"<<endl;
cout<<"1= There\n2= Was\n3= Never\n4= Any\n5= Food\n6= In\n7= The\n8= House\n";cout<<"\t\t\t"; cin>>a;cout<<endl; while(a>8)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>a;
}
if(a==6)
{
system("COLOR A2");system("COLOR A2");system("COLOR A2");system("COLOR A2");cor++;system("COLOR 0B");
}
else
{
system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");system("COLOR 4C");fal++;system("COLOR 0B");
}
}
total=(cor-fal)*100;
//freopen("output.txt","w",stdout);
cout<<"\t\tCorrect Answer: "<<cor<<endl;
cout<<"\t\tWrong Answer: "<<fal<<endl;
return total;
}
/*int question_set4(int n)
{
if(n==1){}
else if(n==2){}
else{}
}
int question_set5(int n)
{
if(n==1){}
else if(n==2){}
else{}
}
*/
int main()
{
time_t tim;
time_t star = 0;
time_t end = 0;
time_t elapsed = 0; //create variable of time_t
time(&tim);
int start,dif,p1=0,p2=0;
cout <<"\t\t\t\t\t\tCurrent Time:\n\t\t\t\t\t\t"<< ctime(&tim)<<endl<<endl;
star = time(NULL);
system("COLOR FC");
cout<<"\t\t\t###########################\t\t"<<endl<<endl;
cout<<"\t\t\t<###### POS GUIDE ######>\t\t\n"<<endl;
cout<<"\t\t\t###########################\t\t\n\n\n\n";
system("PAUSE");
system("cls");
system("COLOR 0B");
cout<<"\n\n\n\n\t\t\t Enter your Choice\t\t"<<endl;
cout<<"\t\t\t|-----------------------|\t\t"<<endl;
cout<<"\t\t\t|\t1=Start Game \t|\t\t"<<endl;
cout<<"\t\t\t|\t2=Instructions \t|\t\t"<<endl;
cout<<"\t\t\t|\t3=Exit \t\t|\t\t"<<endl;
cout<<"\t\t\t|-----------------------|\t\t"<<endl; cin>>start;
while(start>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>start;
}
system("cls");
system("color F0");
cout<<"\n\n\n\t\t\t Please wait while loading\n\n";
char f=177, g=219;
cout<<"\t\t\t\t";
for (int i=0;i<=15;i++)
cout<<f;
cout<<"\r";
cout<<"\t\t\t\t";
for (int i=0;i<=15;i++)
{
cout<<g;
for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
}

system("cls");
system("COLOR 0B");
char a[100],b[100],c[100];
int x,i,j,l[100],le[100],y,z,len[100],k,q,r,s,t,sum=0,sum1=0,sum2=0,p=0,flag=0;
while(1)
{
if(start==1)
{
cout<<"\n\n";
cout<<"\t\tYou Can Play Only Single or Dual Player\n";
cout<<"\t\tHow many player want to play??"<<endl; cin>>x;
while(x>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Play Only Single or Dual Player Not "<<x<<"\n"; cin>>x;
}
system("cls");
if(x==1)
{
cout<<"\n\n";
cout<<"\tEnter Player Name: "; cin>>a;
system("cls");
cout<<"\n\n";
colorPrint(14);
cout<<"\t\t\t+===============+\t\n";
cout<<"\t\t\t|1=Easy\t\t|\t\n";
cout<<"\t\t\t|2=Normal\t|\t\n";
cout<<"\t\t\t+===============+\t\n"; colorPrint(11); cin>>dif;
while(dif>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Choose From Given Numbers Not"<<dif<<"\n"; cin>>dif;
}
cout<<"\n\n";
system("cls");
y=strlen(a);
for(i=0; i<y; i++)
{
sum+=a[i];
}
//cout<<"Player : "<<sum<<endl;
if(sum%3==0)
{
//cout<<"Q1″<<endl;
p=question_set1(dif);
flag=3;
}
else if(sum%3==1)
{
//cout<<"Q2″<<endl;
p=question_set2(dif);
flag=3;
}
else
{
// cout<<"Q3″<<endl;
p=question_set3(dif);
flag=3;
}
break;
}
else if(x==2)
{
cout<<"\n\n";
//cout<<"CAPITAL LATTER IS BEST : "<<endl<<endl;
cout<<"\t\tEnter 1st Player Name :"; cin>>b;
cout<<"\n";
cout<<"\t\tEnter 2nd Player Name :"; cin>>c;
z=strlen(b);
j=strlen(c);
system("cls");
for(i=0; i<z; i++)
{
sum1=sum1+b[i];
}
for(i=0; i<j; i++)
{
sum2=sum2+c[i];
}
//cout<<"Player 1: "<<sum1<<endl;
//cout<<"Player 2: "<<sum2<<endl;
cout<<"\n\n"<<b<<"‘s Turn->\n\n";
colorPrint(14);
cout<<"\t\t\t+===============+\t\n";
cout<<"\t\t\t|1=Easy\t\t|\t\n";
cout<<"\t\t\t|2=Normal\t|\t\n";
cout<<"\t\t\t+===============+\t\n"; colorPrint(11); cin>>dif;
while(dif>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Choose Given Numbers Not"<<dif<<"\n"; cin>>dif;
}
system("cls");
if(sum1%3==0)
{

p1=question_set1(dif);
flag=1;
}
else if(sum1%3==2)
{

p1=question_set2(dif);
flag=1;
}
else
{
p1=question_set3(dif);
flag=1;
}
cout<<c<<"‘s Turn->\n";
colorPrint(14);
cout<<"\t+===============+\t\n";
cout<<"\t|1=Easy\t\t|\t\n";
cout<<"\t|2=Normal\t|\t\n";
cout<<"\t+===============+\t\n"; colorPrint(11); cin>>dif;
while(dif>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Choose Given Numbers Not"<<dif<<"\n"; cin>>dif;
}
system("cls");
if(sum2%3==2)
{
p2=question_set1(dif);
flag=2;
}
else if(sum2%3==1)
{
p2=question_set2(dif);
flag=2;
}
else
{
p2=question_set3(dif);
flag=2;
}
if(flag==3)
{
cout<<"\t\tTotal Score: "<<p<<endl;
}
else if(flag==1)
{
cout<<"\t\tTotal Score: "<<p1<<endl;
}
else if(flag==2)
{
cout<<"\t\tTotal Score: "<<p2<<endl; } system("PAUSE"); system("cls"); if(p1>p2)
{
colorPrint(10);
cout<<"\n\t\t"<<b<<" Win \3\3\n";
colorPrint(11);
}
else if(p1<p2)
{
colorPrint(10);
cout<<"\n\t\t"<<c<<" Win \3\3\n";
colorPrint(11);
}
else if(p1==p2)
{
colorPrint(10);
cout<<"\n\t\tDRAW!!!!!!!\n";
colorPrint(11);
}
}
break;
}
else if(start==2)
{
system("cls");
colorPrint(5);
cout<<"\n\n\t\t**Instruction**\t\t\n\n";
cout<<"To Play This Game You Should Choose Your Answer enter answer Number,This Game will Improve Your ‘Parts of speech' Skill"<<endl;
colorPrint(11);
break;
}
else
{
system("cls");
cout<<"\t\t\tThank You!!!\n";
cout<<"\t\tHope You Will Play This Game Again\n";
break;
}
}
end = time(NULL);
elapsed =abs( star - end);
cout<<"\n\t\tYou Played: ";colorPrint(15);cout<<elapsed;colorPrint(11);cout<<" Seconds"<<endl<<endl;
system("PAUSE");
system("cls");
int ctr;
cout<<"\t\tLets Try Again,Last Chance!!!\n";
cout<<"\t\t\Do You Want To Play Again\n\t\t\t1: Yes\n\t\t\t2: No \n"; while(cin>>ctr)
{
if(ctr==2)
{
system("cls");
cout<<"\t\t\tThank You!!!\n";
cout<<"\t\tHope You Will Play This Game Again\n";
break;
}
system("cls");
time_t tim;
time_t star = 0;
time_t end = 0;
time_t elapsed = 0; //create variable of time_t
time(&tim);
int start,dif,p1=0,p2=0;
cout <<"\t\t\t\t\t\tCurrent Time:\n\t\t\t\t\t\t"<< ctime(&tim)<<endl<<endl;
star = time(NULL);
system("COLOR FC");
cout<<"\t\t\t###########################\t\t"<<endl<<endl;
cout<<"\t\t\t<###### POS GUIDE ######>\t\t\n"<<endl;
cout<<"\t\t\t###########################\t\t\n\n\n\n";
system("PAUSE");
system("cls");
system("COLOR 0B");
cout<<"\n\n\n\n\t\t\t Enter your Choice\t\t"<<endl;
cout<<"\t\t\t|--------|\t\t"<<endl;
cout<<"\t\t\t|\t1=Start Game \t|\t\t"<<endl;
cout<<"\t\t\t|\t2=Instructions \t|\t\t"<<endl;
cout<<"\t\t\t|\t3=Exit \t\t|\t\t"<<endl;
cout<<"\t\t\t|--------|\t\t"<<endl; cin>>start;
while(start>3)
{
cout<<"Wrong Choice\n";
cout<<"Enter Valid Number From Given Numbers\n"; cin>>start;
}
system("cls");
system("color F0");
cout<<"\n\n\n\t\t\t Please wait while loading\n\n";
char f=177, g=219;
cout<<"\t\t\t\t";
for (int i=0;i<=15;i++)
cout<<f;
cout<<"\r";
cout<<"\t\t\t\t";
for (int i=0;i<=15;i++)
{
cout<<g;
for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
}
system("cls");
system("COLOR 0B");
char a[100],b[100],c[100];
int x,i,j,l[100],le[100],y,z,len[100],k,q,r,s,t,sum=0,sum1=0,sum2=0,p=0,flag=0;
while(1)
{
if(start==1)
{
cout<<"\n\n";
cout<<"\t\tSingle or Dual Player\n";
cout<<"\t\tHow many player want to play??"<<endl; cin>>x;
while(x>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Play Only Single or Dual Player Not "<<x<<"\n"; cin>>x;
}
system("cls");
if(x==1)
{
cout<<"\n\n";
cout<<"\tEnter Player Name: "; cin>>a;
system("cls");
cout<<"\n\n";
colorPrint(14);
cout<<"\t\t\t+===============+\t\n";
cout<<"\t\t\t|1=Easy\t\t|\t\n";
cout<<"\t\t\t|2=Normal\t|\t\n";
cout<<"\t\t\t+===============+\t\n"; colorPrint(11); cin>>dif;
while(dif>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Choose Given Numbers Not"<<dif<<"\n"; cin>>dif;
}
cout<<"\n\n";
system("cls");
y=strlen(a);
for(i=0; i<y; i++)
{
sum+=a[i];
}
//cout<<"Player : "<<sum<<endl;
if(sum%3==0)
{
//cout<<"Q1″<<endl;
p=question_set1(dif);
flag=3;
}
else if(sum%3==1)
{
//cout<<"Q2″<<endl;
p=question_set2(dif);
flag=3;
}
else
{
// cout<<"Q3″<<endl;
p=question_set3(dif);
flag=3;
}
system("cls");
break;
}
else if(x==2)
{
cout<<"\n\n";
//cout<<"CAPITAL LATTER IS BEST : "<<endl<<endl;
cout<<"\t\tEnter 1st Player Name :"; cin>>b;
cout<<"\n";
cout<<"\t\tEnter 2nd Player Name :"; cin>>c;
z=strlen(b);
j=strlen(c);

for(i=0; i<z; i++)
{
sum1=sum1+b[i];
}
for(i=0; i<j; i++)
{
sum2=sum2+c[i];
}
//cout<<"Player 1: "<<sum1<<endl;
//cout<<"Player 2: "<<sum2<<endl;
system("cls");
cout<<"\n\n"<<b<<"‘s Turn->\n\n";
colorPrint(14);
cout<<"\t+===============+\t\n";
cout<<"\t|1=Easy\t\t|\t\n";
cout<<"\t|2=Normal\t|\t\n";
cout<<"\t+===============+\t\n"; colorPrint(11); cin>>dif;
while(dif>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Choose Given Numbers Not"<<dif<<"\n"; cin>>dif;
}
if(sum1%3==0)
{

p1=question_set1(dif);
flag=1;
}
else if(sum1%3==2)
{

p1=question_set2(dif);
flag=1;
}
else
{

p1=question_set3(dif);
flag=1;
}
system("cls");
cout<<c<<"‘s Turn->\n";
colorPrint(14);
cout<<"\t+===============+\t\n";
cout<<"\t|1=Easy\t\t|\t\n";
cout<<"\t|2=Normal\t|\t\n";
cout<<"\t+===============+\t\n"; colorPrint(11); cin>>dif;
while(dif>2)
{
cout<<"Wrong Choice\n";
cout<<"You Can Choose Given Numbers Not"<<dif<<"\n"; cin>>dif;
}
if(sum2%3==2)
{
p2=question_set1(dif);
flag=2;
}
else if(sum2%3==1)
{

p2=question_set2(dif);
flag=2;
}
else
{

p2=question_set3(dif);
flag=2;
}
system("cls");
if(flag==3)
{
cout<<"\t\tTotal Score: "<<p<<endl;
}
else if(flag==1)
{
cout<<"\t\tTotal Score: "<<p1<<endl;
}
else if(flag==2)
{
cout<<"\t\tTotal Score: "<<p2<<endl; } system("PAUSE"); if(p1>p2)
{
colorPrint(10);
cout<<"\n\t\t"<<b<<" Win \3\3\n";
colorPrint(11);
}
else if(p1<p2)
{
colorPrint(10);
cout<<"\n\t\t"<<c<<" Win \3\3\n";
colorPrint(11);
}
else if(p1==p2)
{
colorPrint(10);
cout<<"\n\t\tDRAW!!!!!!!\n";
colorPrint(11);
}
system("cls");
}
break;
}
else if(start==2)
{
system("cls");
colorPrint(5);
cout<<"\n\n\t\t**Instruction**\t\t\n\n";
cout<<"To Play This Game You Should Choose Your Answer enter answer Number,This Game will Improve Your ‘Parts of speech' Skill"<<endl;
colorPrint(11);
break;
}
else
{
system("cls");
cout<<"\t\t\tThank You!!!\n";
cout<<"\t\tHope You Will Play This Game Again\n";
break;
}
}
end = time(NULL);
elapsed =abs( star - end);
cout<<"\n\t\tYou Played: ";colorPrint(15);cout<<elapsed;colorPrint(11);cout<<" Sec"<<endl<<endl;
system("PAUSE");
system("cls");
cout<<"\t\tDo You Want To Play Again\n\t\t\t1: Yes\n\t\t\t2: No ";
}
return 0;
}
