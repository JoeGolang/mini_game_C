#include <stdio.h>
#include <windows.h>
#include <conio2.h>
#include <iostream>
#include <fstream>
#include "char.cpp"
#include "Game_UnliCFan_Review.cpp"

using namespace std;

int money, level, hp, mp, atk, matk;

void menu_play();

class Play{ //class =D
      public:
      void setMoney(int tmon){money=tmon;}
      int getMoney(){return money;}
      void setLevel(int tlv){level=tlv;}
      int getLevel(){return level;}
      void sethp(int thp){hp=thp;}
      int gethp(){return hp;}
      void setmp(int tmp){mp=tmp;}
      int getmp(){return mp;}
      void setatk(int tatk){atk=tatk;}
      int getatk(){return atk;}
      void setmatk(int tmatk){matk=tmatk;}
      int getmatk(){return matk;}
      
};

void opening(){ //display opening
     char ketik[3][27];
     
     strcpy(ketik[0],"     1128 Gaming House     ");
     strcpy(ketik[1],"          present          ");
     strcpy(ketik[2],"    Unlimited C Fantasy    ");
     for(int line=0;line<=2;line++){
             gotoxy(27,10+line);
             for(int x=0;x<=26;x++){
                     cout << ketik[line][x];
                     Sleep(70);
             }
     }
     Sleep(500);
}

void setValue(){
     Play p;
     p.setMoney(0);
     p.setLevel(1);
     p.sethp(500);
     p.setmp(50);
     p.setatk(175);
     p.setmatk(50);
}

void fileSave(){ //menjalankan menu save
     Play p;
     FILE*ptrFile;
     
     ptrFile = fopen ("PlayGame.dat","w");
     fprintf(ptrFile, "%d#%d#%d#%d#%d#%d\n", p.getMoney(), p.getLevel(), p.gethp(), p.getmp(), p.getatk(), p.getmatk());

     fclose (ptrFile);
     
     SetColorAndBackground(5,27);
     
     base();
     
     gotoxy(5,3);cout << "data saved!!!";
     getch();
     
     base();
     menu_text();
}

void fileLoad(Play p){ //menjalankan menu load
     FILE*ptrFile;
     int money, level, hp, mp, atk, matk;
     
     ptrFile = fopen ("PlayGame.dat","r");
   if (ptrFile == NULL){
      SetColorAndBackground(5,27);
      
      base();
      
      gotoxy(5,3);cout << "no data found!!!";
      getch();
      
      base();
      menu_text();
   }
   else{
     while (1){
           if(feof(ptrFile))break;
           fscanf(ptrFile, "%d#%d#%d#%d#%d#%d\n", &money, &level, &hp, &mp, &atk, &matk);
           
           p.setMoney(money);
           p.setLevel(level);
           p.sethp(hp);
           p.setmp(mp);
           p.setatk(atk);
           p.setmatk(matk);
     }
     fclose (ptrFile);
     
     SetColorAndBackground(5,27);
     
     base();
     
     gotoxy(5,3);cout << "data loaded!!!";
     getch();
     
     base();
     menu_text();
   }
}

void credits(){ //menjalankan menu credits
     fontc=5; backc=27;
     
     base();
     
     gotoxy(30,12);cout << "wolfgangx2c@yahoo.co.id";
     gotoxy(31,13);cout << "wolfstarx2c@yahoo.com";
     gotoxy(32,14);cout << "Joelio 12110110087";
     getch();
     fontc=23; backc=5;
     base();
     menu_text();
}

int atkprog(int hp, int atk){
     hp -= atk;
     return hp;
}

int defprog(int hp, int atke, int matk){
     hp -= atke/2;
     hp += matk;
     return hp;
}

int pilihan_battle(){
    int y=15;
     gotoxy(6,15);cout << "Attack";
     gotoxy(6,17);cout << "M.Attack";
     gotoxy(6,19);cout << "Defense";
     gotoxy(6,21);cout << "Run";
     gotoxy(4,15);cout << (char)16;
     
     while(1){
              char input = getch();
              if(input == 80 && y == 15){
                          gotoxy(4,y);cout << " "; y+=2;
                          gotoxy(4,y);cout << (char)16;
              }
              else if(input == 80 && y == 17){
                          gotoxy(4,y);cout << " "; y+=2;
                          gotoxy(4,y);cout << (char)16;
              }
              else if(input == 80 && y == 19){
                          gotoxy(4,y);cout << " "; y+=2;
                          gotoxy(4,y);cout << (char)16;
              }
              else if(input == 80 && y == 21){
                          gotoxy(4,y);cout << " "; y-=6;
                          gotoxy(4,y);cout << (char)16;
              }
                          
              else if(input == 72 && y == 15){
                          gotoxy(4,y);cout << " "; y+=6;
                          gotoxy(4,y);cout << (char)16;
              }
              else if(input == 72 && y == 17){
                          gotoxy(4,y);cout << " "; y-=2;
                          gotoxy(4,y);cout << (char)16;
              }
              else if(input == 72 && y == 19){
                          gotoxy(4,y);cout << " "; y-=2;
                          gotoxy(4,y);cout << (char)16;
              }
              else if(input == 72 && y == 21){
                          gotoxy(4,y);cout << " "; y-=2;
                          gotoxy(4,y);cout << (char)16;
              }
              
              else if(input == 13)return y;
     }
}

void pilihan_serang(){
     int x = 1, y, money, level, hp, mp, atk, matk, hpe1, atke1, hpe2, atke2, hpe3, atke3, hpe4, atke4, ra;
     Play p;
     
     money = p.getMoney();
     level = p.getLevel();
     hp = p.gethp();
     hp += 120*level;
     mp = p.getmp();
     mp += 10*level;
     atk = p.getatk();
     atk += 20*level;
     matk = p.getmatk();
     matk += 15*level;
     ra=(rand()%4); hpe1 = (150+(ra*300))*level; 
     ra=(rand()%5); atke1 = ((ra*10)+30)*level;
     ra=(rand()%5); hpe2 = (150+(ra*300))*level;
     ra=(rand()%4); atke2 = ((ra*10)+30)*level;
     ra=(rand()%3); hpe3 = (150+(ra*300))*level;
     ra=(rand()%6); atke3 = ((ra*10)+30)*level;
     ra=(rand()%6); hpe4 = (150+(ra*300))*level;
     ra=(rand()%3); atke4 = ((ra*10)+30)*level;
     
     status_model();
     
     gotoxy(57,23);cout << hp; gotoxy(62,23);cout << "     atk    " << atk;
     gotoxy(57,24);cout << mp; gotoxy(62,24);cout << "     matk   " << matk;
     gotoxy(10,4);cout << hpe1;
     gotoxy(30,4);cout << hpe2;
     gotoxy(50,4);cout << hpe3;
     gotoxy(70,4);cout << hpe4;
     
     gotoxy(10,5);cout << atke1;
     gotoxy(30,5);cout << atke2;
     gotoxy(50,5);cout << atke3;
     gotoxy(70,5);cout << atke4;
     
     y = pilihan_battle();
     
     while(hp>=0){
          if( hp==0 ){gotoxy(55,23);cout << "You Dead!!!"; Sleep(700); getch(); fontc=16;backc=6;base();menu_text_play(); break;}
          if(y == 21){fontc=16;backc=6;base();menu_text_play();break;}
          else if(y == 19 && mp >= 20){mp-=20;gotoxy(57,24);cout << mp << "   ";
                           if(hpe1>0){hp = defprog(hp,atke1,matk);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                           if(hpe2>0){hp = defprog(hp,atke2,matk);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                           if(hpe3>0){hp = defprog(hp,atke3,matk);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                           if(hpe4>0){hp = defprog(hp,atke4,matk);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                           Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(4,y);cout << " "; y = pilihan_battle();}
                           
          else if(y == 19 && mp < 20){gotoxy(37,15);cout << "NOT ENOUGH MANA!!!";Sleep(550);gotoxy(37,15);cout << "                   ";gotoxy(4,y);cout << " "; y = pilihan_battle();}
          
          else while(y < 18){
              gotoxy(x*10,8);cout << (char)30;
              gotoxy(4,y);cout << " "; 
              char input = getch();
              
              if(input == 77 && x == 1){
                       gotoxy(x*10,8);cout << " "; x+=2;
                       gotoxy(x*10,8);cout << (char)30;
              }
              else if(input == 77 && x == 3){
                       gotoxy(x*10,8);cout << " "; x+=2;
                       gotoxy(x*10,8);cout << (char)30;
              }
              else if(input == 77 && x == 5){
                       gotoxy(x*10,8);cout << " "; x+=2;
                       gotoxy(x*10,8);cout << (char)30;
              }
              else if(input == 77 && x == 7){
                       gotoxy(x*10,8);cout << " "; x-=6;
                       gotoxy(x*10,8);cout << (char)30;
              }
              
              else if(input == 75 && x == 1){
                       gotoxy(x*10,8);cout << " "; x+=6;
                       gotoxy(x*10,8);cout << (char)30;
              }
              else if(input == 75 && x == 3){
                       gotoxy(x*10,8);cout << " "; x-=2;
                       gotoxy(x*10,8);cout << (char)30;
              }
              else if(input == 75 && x == 5){
                       gotoxy(x*10,8);cout << " "; x-=2;
                       gotoxy(x*10,8);cout << (char)30;
              }
              else if(input == 75 && x == 7){
                       gotoxy(x*10,8);cout << " "; x-=2;
                       gotoxy(x*10,8);cout << (char)30;
              }
              
              else if(input == 13 && x == 1 && y == 15 && hpe1 > 0){hpe1 = atkprog(hpe1, atk); gotoxy(x*10,4);if(hpe1 <= 0){
                                                            cout << "0       "; gotoxy(x*10-5,9);cout << "enemy drop 1000g"; money+=1000;} else{cout << hpe1 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              else if(input == 13 && x == 1 && y == 17 && mp >= 50 && hpe1 > 0){mp-=50;hp+=mp*2;gotoxy(57,24);cout << mp << "   "; hpe1 = atkprog(hpe1, matk); gotoxy(x*10,4);if(hpe1 <= 0){
                                                            cout << "0       "; gotoxy(x*10-5,9);cout << "enemy drop 1000g"; money+=1000;} else{cout << hpe1 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              
              else if(input == 13 && x == 1 && y == 17 && mp < 50){gotoxy(37,15);cout << "NOT ENOUGH MANA!!!";Sleep(550);gotoxy(37,15);cout << "                   ";gotoxy(x*10,8);cout << " "; y = pilihan_battle();break;}
              
              else if(input == 13 && x == 3 && y == 15 && hpe2 > 0){hpe2 = atkprog(hpe2, atk); gotoxy(x*10,4);if(hpe2 <= 0){
                                                            cout << "0       "; gotoxy(x*10-5,9);cout << "enemy drop 1200g"; money+=1200;} else{cout << hpe2 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              else if(input == 13 && x == 3 && y == 17 && mp >= 50 && hpe2 > 0){mp-=50;hp+=mp*2;gotoxy(57,24);cout << mp << "   "; hpe2 = atkprog(hpe2, matk); gotoxy(x*10,4);if(hpe2 <= 0){
                                                            cout << "0       "; gotoxy(x*10-5,9);cout << "enemy drop 1200g"; money+=1200;} else{cout << hpe2 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              
              else if(input == 13 && x == 3 && y == 17 && mp < 50){gotoxy(37,15);cout << "NOT ENOUGH MANA!!!";Sleep(550);gotoxy(37,15);cout << "                   ";gotoxy(x*10,8);cout << " "; y = pilihan_battle();break;}
              
              else if(input == 13 && x == 5 && y == 15 && hpe3 > 0){hpe3 = atkprog(hpe3, atk); gotoxy(x*10,4);if(hpe3 <= 0){
                                                            cout << "0       "; gotoxy(x*10-5,9);cout << "enemy drop 700g"; money+=700;} else{cout << hpe3 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              else if(input == 13 && x == 5 && y == 17 && mp >= 50 && hpe3 > 0){mp-=50;hp+=mp*2;gotoxy(57,24);cout << mp << "   "; hpe3 = atkprog(hpe3, matk); gotoxy(x*10,4);if(hpe3 <= 0){
                                                            cout << "0       "; gotoxy(x*10-5,9);cout << "enemy drop 700g"; money+=700;} else{cout << hpe3 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              
              else if(input == 13 && x == 5 && y == 17 && mp < 50){gotoxy(37,15);cout << "NOT ENOUGH MANA!!!";Sleep(550);gotoxy(37,15);cout << "                   ";gotoxy(x*10,8);cout << " "; y = pilihan_battle();break;}
              
              else if(input == 13 && x == 7 && y == 15 && hpe4 > 0){hpe4 = atkprog(hpe4, atk); gotoxy(x*10,4);if(hpe4 <= 0){
                                                            cout << "0       "; gotoxy(x*10-7,9);cout << "enemy drop 1800g"; money+=1800;} else{cout << hpe4 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              else if(input == 13 && x == 7 && y == 17 && mp >= 50 && hpe4 > 0){mp-=50;hp+=mp*2;gotoxy(57,24);cout << mp << "   "; hpe4 = atkprog(hpe4, matk); gotoxy(x*10,4);if(hpe4 <= 0){
                                                            cout << "0       "; gotoxy(x*10-7,9);cout << "enemy drop 1800g"; money+=1800;} else{cout << hpe4 << "   ";}
                                                            Sleep(700);gotoxy(37,15);cout << "enemy turn !!!";Sleep(700);
                                                            if(hpe1>0){hp = atkprog(hp, atke1);Sleep(550);gotoxy(37,15);cout << "enemy 1 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe2>0){hp = atkprog(hp, atke2);Sleep(550);gotoxy(37,15);cout << "enemy 2 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe3>0){hp = atkprog(hp, atke3);Sleep(550);gotoxy(37,15);cout << "enemy 3 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            if(hpe4>0){hp = atkprog(hp, atke4);Sleep(550);gotoxy(37,15);cout << "enemy 4 turn !!!";gotoxy(57,23);cout << hp << "   ";}
                                                            Sleep(550);gotoxy(37,15);cout << "                ";gotoxy(x*10,8);cout << " "; mp+=10;gotoxy(57,24);cout << mp << "   ";
                                                            if(hp<0){gotoxy(55,23);cout << "Overkilled!"; Sleep(700); gotoxy(37,15);cout << "You Dead!!! Game Over!!!";getch();
                                                            fontc=16;backc=6;base();menu_text_play();break;break;}y = pilihan_battle(); break;}
              
              else if(input == 13 && x == 7 && y == 17 && mp < 50){gotoxy(37,15);cout << "NOT ENOUGH MANA!!!";Sleep(550);gotoxy(37,15);cout << "                   ";gotoxy(x*10,8);cout << " "; y = pilihan_battle();break;}
              
              else if(input == 80){gotoxy(x*10,8);cout << " "; y = pilihan_battle();break;}
              }
          if(hpe1 <= 0 && hpe2 <= 0 && hpe3 <= 0 && hpe4 <= 0){gotoxy(32,15);cout << "You Win This Round!!! Level UP!!!";gotoxy(32,16);cout << "Multiplier Money got by Level & Remains HP!!!";
                                                                                  level++;money+=((2200*level)+hp);getch();p.setMoney(money);p.setLevel(level); fontc=16;backc=6;base();menu_text_play(); break;}
     }
}

void battlemot(){
     Play p;
     char ketik[5][16];
     fontc=14;
     backc=4;
     base();
     strcpy(ketik[0],">>>>>>>>>>>>>>>>");
     strcpy(ketik[1],"! BATTLE BEGIN !");
     strcpy(ketik[2],">>>>>>>>>>>>>>>>");
     strcpy(ketik[3],"!   LEVEL     !");
     strcpy(ketik[4],">>>>>>>>>>>>>>>>");
     for(int line=0;line<=4;line++){
             gotoxy(33,10);Sleep(180);
             for(int x=0;x<=15;x++){
                     cout << ketik[line][x];
                     Sleep(33);
             if(line==3 && x==10){gotoxy(44,10);cout<<p.getLevel();}
             }
     }
     
}

void battle(){
     
     Sleep(500);
     
     battlemot();
     
     Sleep(500);
     
     pilihan_serang();
     
}

void status(){
     Play p;
     int money, level, hp, mp, atk, matk;
     
     money = p.getMoney();
     level = p.getLevel();
     hp = p.gethp();
     hp += 120*level;
     mp = p.getmp();
     mp += 10*level;
     atk = p.getatk();
     atk += 20*level;
     matk = p.getmatk();
     matk += 15*level;
     
     base();
     
     gotoxy(5,3);cout << "money = " << money << endl;
     gotoxy(5,4);cout << "level = " << level << endl;
     gotoxy(5,5);cout << "hp    = " << hp << endl;
     gotoxy(5,6);cout << "mp    = " << mp << endl;
     gotoxy(5,7);cout << "atk   = " << atk << endl;
     gotoxy(5,8);cout << "matk  = " << matk << endl;
     gotoxy(5,10);system("pause");
     base();
     menu_text_play();
     
}

void shop(){
     Play p;
     int money, level, hp, mp, atk, matk;
     
     base();
     
     money = p.getMoney();
     level = p.getLevel();
     hp = p.gethp();
     mp = p.getmp();
     atk = p.getatk();
     matk = p.getmatk();

     while(1){
              gotoxy(5,3);cout << "Upgrade Power of Your Hero";
              gotoxy(5,4);cout << "your money : " << money << "       ";
              gotoxy(5,5);cout << "1. UP hp   = 500g" ;
              gotoxy(5,6);cout << "2. UP mp   = 200g" ;
              gotoxy(5,7);cout << "3. UP atk  = 3000g" ;
              gotoxy(5,8);cout << "4. UP matk = 4500g" ;
              gotoxy(5,9);cout << "0. Done" ;
              char input = getch();
              if(input == '1' && money >= 500){gotoxy(27,5);cout << "Suceed increasing hp by 120";hp+=120;money-=500;Sleep(400);gotoxy(27,5);cout << "                               ";}
              if(input == '2' && money >= 200){gotoxy(27,6);cout << "Suceed increasing mp by 20";mp+=20;money-=200;Sleep(400);gotoxy(27,6);cout << "                               ";}
              if(input == '3' && money >= 3000){gotoxy(27,7);cout << "Suceed increasing atk by 15";atk+=15;money-=3000;Sleep(400);gotoxy(27,7);cout << "                               ";}
              if(input == '4' && money >= 4500){gotoxy(27,8);cout << "Suceed increasing matk by 10";matk+=10;money-=4500;Sleep(400);gotoxy(27,8);cout << "                               ";}
              if(input == '0'){p.setMoney(money); p.sethp(hp); p.setmp(mp); p.setatk(atk); p.setmatk(matk); base();menu_text_play(); break;}
     }
}

void menu(){ //menjalankan menu utama
     int n = 12;
     char pilih;
     Play p;
     fontc=23; backc=5;
     base();
     menu_text();
     
     
     while(1){
              char input = getch();
              SetColorAndBackground(17,15);
              if(input == 80 && n == 12){n++; gotoxy(37,n);cout << "[Save]";
               SetColorAndBackground(15,17);gotoxy(37,n-1);cout << " Play ";}
              else if(input == 80 && n == 13){n++; gotoxy(37,n);cout << "[Load]";
               SetColorAndBackground(15,17);gotoxy(37,n-1);cout << " Save ";}
              else if(input == 80 && n == 14){n++; gotoxy(37,n);cout << "[Credits]";
               SetColorAndBackground(15,17);gotoxy(37,n-1);cout << " Load ";}
              else if(input == 80 && n == 15){n++; gotoxy(37,n);cout << "[Exit]";
               SetColorAndBackground(15,17);gotoxy(37,n-1);cout << " Credits ";}
              else if(input == 80 && n == 16){n=12; gotoxy(37,n);cout << "[Play]";
               SetColorAndBackground(15,17);gotoxy(37,n+4);cout << " Exit ";}
              
              else if(input == 72 && n == 12){n=16; gotoxy(37,n);cout << "[Exit]";
               SetColorAndBackground(15,17);gotoxy(37,n-4);cout << " Play ";}
              else if(input == 72 && n == 13){n--; gotoxy(37,n);cout << "[Play]";
               SetColorAndBackground(15,17);gotoxy(37,n+1);cout << " Save ";}
              else if(input == 72 && n == 14){n--; gotoxy(37,n);cout << "[Save]";
               SetColorAndBackground(15,17);gotoxy(37,n+1);cout << " Load ";}
              else if(input == 72 && n == 15){n--; gotoxy(37,n);cout << "[Load]";
               SetColorAndBackground(15,17);gotoxy(37,n+1);cout << " Credits ";}
              else if(input == 72 && n == 16){n--; gotoxy(37,n);cout << "[Credits]";
               SetColorAndBackground(15,17);gotoxy(37,n+1);cout << " Exit ";}
              
              else if(input == 13 && n== 12){n=12; menu_play();}
              
              else if(input == 13 && n== 13){n=12; gotoxy(60,13);cout << "are you sure?(y/n)";while(1){
                               char input = getche();
                               if(input == 'y'){fileSave();break;}
                               else if(input == 'n'){base();menu_text();break;}
                               else continue;}
                               }
              else if(input == 13 && n== 14){n=12; gotoxy(60,14);cout << "are you sure?(y/n)";while(1){
                               char input = getche();
                               if(input == 'y'){fileLoad(p);break;}
                               else if(input == 'n'){base();menu_text();break;}
                               else continue;}
                               }
              else if(input == 13 && n== 15){n=12; credits();}
              else if(input == 13 && n== 16)break;
              else if(input == 'h'){n=12; about();fontc=23; backc=5; base(); menu_text();}
     }        
}

void menu_play(){ //menjalankan menu play
     int n = 12;
     Play p;
     fontc=16; backc=6;
     base();
     menu_text_play();
     
     while(1){
              char input = getch();
              SetColorAndBackground(18,4);
              if(input == 80 && n == 12){n++; gotoxy(35,n);cout << "[Intro]";
               SetColorAndBackground(4,18);gotoxy(35,n-1);cout << " ContinueStory ";}
              else if(input == 80 && n == 13){n++; gotoxy(35,n);cout << "[Status]";
               SetColorAndBackground(4,18);gotoxy(35,n-1);cout << " Intro ";}
              else if(input == 80 && n == 14){n++; gotoxy(35,n);cout << "[Shop]";
               SetColorAndBackground(4,18);gotoxy(35,n-1);cout << " Status ";}
              else if(input == 80 && n == 15){n++; gotoxy(35,n);cout << "[Back]";
               SetColorAndBackground(4,18);gotoxy(35,n-1);cout << " Shop ";}
              else if(input == 80 && n == 16){n=12; gotoxy(35,n);cout << "[ContinueStory]";
               SetColorAndBackground(4,18);gotoxy(35,n+4);cout << " Back ";}
              
              else if(input == 72 && n == 12){n=16; gotoxy(35,n);cout << "[Back]";
               SetColorAndBackground(4,18);gotoxy(35,n-4);cout << " ContinueStory ";}
              else if(input == 72 && n == 13){n--; gotoxy(35,n);cout << "[ContinueStory]";
               SetColorAndBackground(4,18);gotoxy(35,n+1);cout << " Intro ";}
              else if(input == 72 && n == 14){n--; gotoxy(35,n);cout << "[Intro]";
               SetColorAndBackground(4,18);gotoxy(35,n+1);cout << " Status ";}
              else if(input == 72 && n == 15){n--; gotoxy(35,n);cout << "[Status]";
               SetColorAndBackground(4,18);gotoxy(35,n+1);cout << " Shop ";}
              else if(input == 72 && n == 16){n--; gotoxy(35,n);cout << "[Shop]";
               SetColorAndBackground(4,18);gotoxy(35,n+1);cout << " Back ";}
              
              else if(input == 13 && n== 12){n=12; battle();}
              else if(input == 13 && n== 13){n=12; character(); battlemot(); Sleep(500); pilihan_serang();}
              else if(input == 13 && n== 14){n=12; status();}
              else if(input == 13 && n== 15){n=12; shop();}
              else if(input == 13 && n== 16){n=12; fontc=23; backc=5; base(); menu_text(); break;}
     }        
}

int main(){
    srand(time(NULL));
    Play p;
    opening();
    setValue();
    menu();
}
     

