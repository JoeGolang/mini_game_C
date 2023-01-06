#include <stdio.h>
#include <windows.h>
#include <conio2.h>
#include <iostream>

using namespace std;

void about(){
     system("cls");
     cout << ">>Game Unlimited C Fantasy" << endl << endl;
     cout << "Game berbasis rpg dengan sistem level dan money sebagai elemen utama untuk" << endl;
     cout << "memperkuat karakter. Player diwajibkan untuk menyelesaikan suatu stage" << endl;
     cout << "stage dengan 4 lawan monster yang mempunyai status random. Status monster" << endl;
     cout << "dibuat semakin kuat seiring bertambahnya level player. Setelah player selesai" << endl;
     cout << "menyelesaikan suatu stage, player akan mendapat satu kenaikan level dan money " << endl;
     cout << "sejumlah yang telah ditentukan selain mendapat drop money dari monster yang" <<endl;
     cout << "dibunuh. Semakin besar level maka hadiah multiplier dari hadiah selesai stage" << endl;
     cout << "akan semakin akan besar. Money yang didapat digunakan untuk berbelanja di shop" <<endl;
     cout << "yang terdapat pada menu permainan." <<endl <<endl;
     cout << "Sistem pertarungan" << endl;
     cout << "Sistem yang digunakan dalam battle adalah turn. Player akan menyerang pertama" << endl;
     cout << "kali dan disusul oleh keempat monster. Player diperbolehkan menyerang ke salah" << endl;
     cout << "satu dari keempat monster sesuai dengan keinginan player dengan tujuan secepat" << endl;
     cout << "dan seefektif mungkin menghabisi keempat monster sebelum kehabisan HP & MP." << endl << endl;
     cout << "Atribut HP = banyaknya nyawa dari player, jika atribut ini habis maka Player" <<endl;
     cout << "kalah pada stage tersebut." <<endl << endl;
     cout << "Atribut MP = kekuatan tersembunyi Hero dalam bertarung, dalam hal ini kekuatan" << endl;
     cout << "untuk heal." <<endl << endl;
     cout << "Dapat diperhatikan bahwa atribut MP akan mendapatkan regenerasi setiap putaran" << endl;
     cout << "sebanyak 10 poin, sedangkan atribut hp tidak memberi regenerasi setiap putaran." << endl;
     cout << "Poin MP yang tersedia dapat dipakai untuk menambah poin HP dengan cara" << endl;
     cout << "defense/magic attack yang berfungsi sekaligus untuk healing." << endl;
     cout << "Terdapat juga sistem run untuk keluar dari pertarungan yang dapat berfungsi" << endl;
     cout << "juga untuk me-reset pertarungan. Sistem run ini tidak meng-save hasil dari drop" << endl;
     cout << "money monster yang dibunuh maupun level tambahan kepada Player." << endl << endl;
     cout << ">>Fitur" << endl;
     cout << "Dalam game ini sudah tersedia fitur save & load pada menu utama." << endl;
     cout << "Fitur ini akan menyimpan value dari money, level, maupun upgrade status" << endl;
     cout << "yang telah dilakukan oleh Player." << endl << endl;
     cout << ">>Hint" << endl;
     cout << "M.attack (50 mana) : heal sejumlah MPx2, lalu serang sejumlah matk." << endl;
     cout << "Defense (20 mana) : membuat shield sebesar matk untuk memblock attack lawan," << endl;
     cout << "jika block lebih besar maka heal hp sendiri." << endl << endl;
     system("Pause");
}

/*int main(){
    about();
    system("Pause");
}*/
