#include <stdio.h>
#include <windows.h>
#include <conio2.h>
#include <iostream>
#include <fstream>

using namespace std;
int fontc, backc;

void SetColorAndBackground(int ForgC, int BackC){ //mengubah foreground & background
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

void base(){ //textur background
     SetColorAndBackground(fontc,backc);
     system("cls");
     int x, y;

     gotoxy(1,1);cout << (char)201;
     gotoxy(80,1);cout << (char)187;
     gotoxy(1,25);cout << (char)200;
     gotoxy(80,25);cout << (char)188;

     gotoxy(2,2);cout << (char)188;
     gotoxy(79,2);cout << (char)200;
     gotoxy(2,24);cout << (char)187;
     gotoxy(79,24);cout << (char)201;

     for(x=2; x<=79; x++){
        y=1;
        gotoxy(x,y);cout << (char)205;
        y=25;
        gotoxy(x,y);cout << (char)205;
        }

     for(y=2; y<=24; y++){
        x=1;
        gotoxy(x,y);cout << (char)186;
        x=80;
        gotoxy(x,y);cout << (char)186;
        }

     gotoxy(1,2);cout << (char)204;
     gotoxy(1,24);cout << (char)204;
     gotoxy(80,2);cout << (char)185;
     gotoxy(80,24);cout << (char)185;

     gotoxy(2,1);cout << (char)203;
     gotoxy(79,1);cout << (char)203;
     gotoxy(2,25);cout << (char)202;
     gotoxy(79,25);cout << (char)202;
}

void menu_text(){ //menampilkan tulisan menu utama
     int x, y;
     for(x=30; x<=52; x++){
              for(y=8; y<=10; y++){
                       SetColorAndBackground(5,25);gotoxy(x,y);cout << " ";
              }
              for(y=11; y<=17; y++){
                       SetColorAndBackground(15,17);gotoxy(x,y);cout << " ";
              }
     }
     
     gotoxy(38,13);cout << "Save";
     gotoxy(38,14);cout << "Load";
     gotoxy(38,15);cout << "Credits";
     gotoxy(38,16);cout << "Exit";
     
     SetColorAndBackground(5,25);gotoxy(32,9);cout << "Unlimited C Fantasy";

     SetColorAndBackground(17,15);gotoxy(37,12);cout << "[Play]";
     gotoxy(60,23);cout << "Press h for hints";
}

void menu_text_play(){ //menampilkan tulisan menu utama
     int x, y;
     for(x=30; x<=52; x++){
              for(y=8; y<=10; y++){
                       SetColorAndBackground(18,35);gotoxy(x,y);cout << " ";
              }
              for(y=11; y<=17; y++){
                       SetColorAndBackground(4,18);gotoxy(x,y);cout << " ";
              }
     }
     
     gotoxy(36,13);cout << "Intro";
     gotoxy(36,14);cout << "Status";
     gotoxy(36,15);cout << "Shop";
     gotoxy(36,16);cout << "Back";
     
     SetColorAndBackground(18,35);gotoxy(32,9);cout << "     Game Mode     ";
     
     SetColorAndBackground(18,4);gotoxy(35,12);cout << "[ContinueStory]";
}

void status_model(){
     int x, y;
     fontc=14;
     backc=4;
     base();
     gotoxy(50,20);cout << (char)218;
     
     for(x=51; x<=79; x++){
        y=20;
        gotoxy(x,y);cout << (char)196;
     }
     
     for(y=21; y<=24; y++){
        x=50;
        gotoxy(x,y);cout << (char)179;
     }
     
     
     gotoxy(18,12);cout << (char)191;
     
     for(x=2; x<=17; x++){
        y=12;
        gotoxy(x,y);cout << (char)196;
     }
     
     for(y=13; y<=24; y++){
        x=18;
        gotoxy(x,y);cout << (char)179;
     }
     
     
     for(x=2; x<=79; x++){
        y=6;
        gotoxy(x,y);cout << (char)196;
     }
     
     for(y=2; y<=5; y++){
        x=20;
        gotoxy(x,y);cout << (char)179;
        x=40;
        gotoxy(x,y);cout << (char)179;
        x=60;
        gotoxy(x,y);cout << (char)179;
     }
     
     gotoxy(52,21);cout << "(====== Your Hero ======)";
     gotoxy(52,23);cout << "HP";
     gotoxy(52,24);cout << "MP";
     
     gotoxy(3,2);cout << "(== Enemy 01 ==)";
     gotoxy(3,4);cout << "HP";
     gotoxy(3,5);cout << "atk";
     
     gotoxy(22,2);cout << "(== Enemy 02 ==)";
     gotoxy(22,4);cout << "HP";
     gotoxy(22,5);cout << "atk";
     
     gotoxy(42,2);cout << "(== Enemy 03 ==)";
     gotoxy(42,4);cout << "HP";
     gotoxy(42,5);cout << "atk";
     
     gotoxy(62,2);cout << "(== Enemy 04 ==)";
     gotoxy(62,4);cout << "HP";
     gotoxy(62,5);cout << "atk";
}

void e_movement1(){
     char ketik[2][30];
     
     strcpy(ketik[0],"HEY THERE!!! what the **** are");
     strcpy(ketik[1],"you doing here!! Poofstzzhhh!!");
     for(int line=0;line<=1;line++){
     for(int cnt=0;cnt<=29;cnt++){
             gotoxy(57,13);cout << " " << (char)174 << (char)174 << (char)196 << (char)196 << (char)196 << (char)175 << (char)175 << " ";
             gotoxy(55,15);cout << (char)47 << "  ("<< (char)111 <<") ("<< (char)111 <<")  " << (char)92;
             gotoxy(48+cnt,10+line);cout << ketik[line][cnt];
             Sleep(75);
             gotoxy(57,13);cout << (char)174 << (char)174 << (char)174 << (char)196 << (char)196 << (char)196 << (char)175 << (char)175 << (char)175;
             gotoxy(55,15);cout << (char)47 << "  ("<< (char)155 <<") ("<< (char)155 <<")  " << (char)92;
             Sleep(75);
     }
     }
}

void e_movement2(){
     char ketik[3][30];
     
     strcpy(ketik[0],"hey mecha boy!!! who is that??");
     strcpy(ketik[1],"is that HUMAN here!? LET'S EAT");
     strcpy(ketik[2],"THEM ALL!!! BOINK~~ BOINK~~!!!");
     for(int line=0;line<=2;line++){
     for(int cnt=0;cnt<=29;){
             gotoxy(21,11);cout << (char)174 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)175;
             gotoxy(12+cnt,17+line);cout << ketik[line][cnt];
             Sleep(100);cnt++;
             gotoxy(12+cnt,17+line);cout << ketik[line][cnt];
             Sleep(100);cnt++;
             gotoxy(12+cnt,17+line);cout << ketik[line][cnt];
             Sleep(100);cnt++;
             gotoxy(21,11);cout << "  " << (char)174 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)175 << "  ";
             gotoxy(12+cnt,17+line);cout << ketik[line][cnt];
             Sleep(100);cnt++;
             gotoxy(12+cnt,17+line);cout << ketik[line][cnt];
             Sleep(100);cnt++;
             gotoxy(12+cnt,17+line);cout << ketik[line][cnt];
             Sleep(100);cnt++;
     }
     }
     gotoxy(1,1);
}

void enemy1(){
     gotoxy(56,17);cout << (char)179 << " " << (char)177 << " " << (char)177 << " " << (char)177 << " " << (char)177 << " " << (char)179;
     gotoxy(54,18);cout << (char)179 << " " << (char)179 << " " << (char)177 << " " << (char)177 << " " << (char)177 << " " << (char)177 << " " << (char)179 << " " << (char)179;
     gotoxy(54,19);cout << (char)179 << " " << (char)179 << " " << (char)177 << " " << (char)177 << " " << (char)177 << " " << (char)177 << " " << (char)179 << " " << (char)179;
     gotoxy(56,14);cout << (char)47 << "         " << (char)92;
     gotoxy(54,16);cout << (char)47 << "             " << (char)92;
     gotoxy(53,17);cout << (char)47 << "  "; gotoxy(67,17);cout << "  " << (char)92;
     gotoxy(57,13);cout << (char)174 << (char)174 << (char)174 << (char)196 << (char)196 << (char)196 << (char)175 << (char)175 << (char)175;
     gotoxy(55,15);cout << (char)47 << "  ("<< (char)155 <<") ("<< (char)155 <<")  " << (char)92;
     
     e_movement1();
}

void enemy2(){
     gotoxy(24,4);cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
     gotoxy(23,5);cout << (char)218 << "     "; gotoxy(29,5);cout << (char)191;
     gotoxy(22,6);cout << (char)218 << "       "; gotoxy(30,6);cout << (char)191;
     gotoxy(21,7);cout << (char)218 << "         "; gotoxy(31,7);cout << (char)191;
     gotoxy(20,8);cout << (char)218 << "           "; gotoxy(32,8);cout << (char)191;
     gotoxy(19,9);cout << (char)218 << "             "; gotoxy(33,9);cout << (char)191;
     gotoxy(18,10);cout << (char)218 << "               "; gotoxy(34,10);cout << (char)191;
     gotoxy(17,11);cout << (char)218 << "                 "; gotoxy(35,11);cout << (char)191;
     gotoxy(16,12);cout << (char)218 << "                   "; gotoxy(36,12);cout << (char)191;
     gotoxy(16,13);cout << (char)179 << "                   "; gotoxy(36,13);cout << (char)179;
     gotoxy(16,14);cout << (char)192 << "                   "; gotoxy(36,14);cout << (char)217;
     gotoxy(25,7);cout << (char)228 << " " << (char)228;
     gotoxy(25,9);cout << (char)178 << (char)178 << (char)178;
     gotoxy(21,11);cout << "  " << (char)174 << (char)220 << (char)220 << (char)220 << (char)220 << (char)220 << (char)175 << "  ";
     for(int x=17; x<=35; x++){
        int y=14;
        gotoxy(x,y);cout << (char)196;
        }
     
     e_movement2();
     
}

void ent_enemy2(){
     for(int cnt=0;cnt<=2;cnt++){
             Sleep(500);
             gotoxy(21,9);cout << "BOINKKK~~~!!!";
             gotoxy(21,10);cout << "             ";
             Sleep(500);
             gotoxy(21,9);cout << "             ";
             gotoxy(21,10);cout << "BOINKKK~~~!!!";
     }
}

/*void battlemot(){
     char ketik[3][31];
     fontc=14;
     backc=4;
     base();
     strcpy(ketik[0],">>>>>>>>>>>>>>>");
     strcpy(ketik[1],"BATTLE BEGIN!!!");
     strcpy(ketik[2],">>>>>>>>>>>>>>>");
     for(int line=0;line<=3;line++){
             gotoxy(33,10);Sleep(300);
             for(int x=0;x<=14;x++){
                     cout << ketik[line][x];
                     Sleep(75);
             }
     }
     
}*/

void character(){
     fontc=15;
     backc=5;
     base();
     
     SetColorAndBackground(10,17);
     enemy1();
     
     SetColorAndBackground(12,27);
     ent_enemy2();
     enemy2();
     
     Sleep(500);
}

