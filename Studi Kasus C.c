#include <stdio.h>
#include <iostream>

float skor (int kehadiran,int tugas,int quiz,int uts,int uas);
void matkul (float skor, int sks, int *kehadiran, int *tugas, int *quiz, int *uts, int *uas, char *grade, int *point, int *jml);

typedef struct
{
    char namamhs[32],NIM[32],namamk[32],grade;
    int Nmk,kehadiran,tugas,quiz,uts,uas,point,sks,jml,tsks,tjml;
    float skor,IP;
}mahasiswa;

main()
{
    int x,y,NIM,Nmhs,LOOP;
    char ans;
    mahasiswa mhs[32][12];
    y=1;
    printf("Masukkan Berapa banyak mahasiswa : ");
    scanf("%d",&Nmhs);
     getchar();
    for(x=1;x<=Nmhs;x++)
    {
        printf("\nMasukkan Nama Mahasiswa ke-%d: ",x);
        gets(mhs[x][0].namamhs);
        y=1;
        printf("NIM : ");
        scanf("%d",&NIM);
        gets(mhs[x][0].NIM);
        mhs[x][0].Nmk=1;
        mhs[x][0].tsks=0;
        mhs[x][0].tjml=0;
        LOOP:
        printf("--------------------\n");
        printf("Masukkan Nama Matkul ke-%d : ",y);gets(mhs[x][y].namamk);
        printf("Masukkan Nilai Matkul %s\n",gets(mhs[x][y].namamk));
        printf("----Kehadiran : ");scanf("%d", &mhs[x][y].kehadiran);
        printf("----Tugas : ");scanf("%d", &mhs[x][y].tugas);
        printf("----QUIZ : ");scanf("%d", &mhs[x][y].quiz);
        printf("----UTS   : ");scanf("%d", &mhs[x][y].uts);
        printf("----UAS   : ");scanf("%d", &mhs[x][y].uas);
        printf("Masukkan Jumlah SKS Matkul %s : ",mhs[x][y].namamk);scanf("%d", &mhs[x][y].sks);
        getchar();
        mhs[x][y].skor=skor(mhs[x][y].kehadiran, mhs[x][y].tugas, mhs[x][y].quiz, mhs[x][y].uts, mhs[x][y].uas);
        matkul(mhs[x][y].skor, mhs[x][y].sks, &mhs[x][y].kehadiran, &mhs[x][y].tugas, &mhs[x][y].quiz, &mhs[x][y].uts, &mhs[x][y].uas, &mhs[x][y].grade, &mhs[x][y].point, &mhs[x][y].jml);
        mhs[x][0].tsks+=mhs[x][y].sks;
        mhs[x][0].tjml+=mhs[x][y].jml;
        printf("Apakah anda mau menambahkan matkul lainnya (Y/N) : ");
        scanf("%c",&ans);
        if (ans == 'Y'|| ans == 'y'){fflush(stdin); y++; mhs[x][0].Nmk++; goto LOOP;}
        mhs[x][0].IP=mhs[x][0].tjml/mhs[x][0].tsks;
        getchar();
    }
    system("cls");
    for(x=1;x<=Nmhs;x++)
    {
        y=1;
        printf(" %s\n",mhs[x][0].namamhs);
        printf(" %s\n",mhs[x][0].NIM);
        printf("===========================================================================\n");
        printf("| No |   Mata kuliah  |Kehadiran|Tugas|QUIZ|UTS|UAS|Grade|Point|SKS|Jumlah|\n");
        printf("|====|================|=========|=====|====|===|===|=====|=====|===|=======\n");
        for(y=1;y<=mhs[x][0].Nmk;y++)
        {
            printf("| %02d | %14s |   %3d   | %3d |%3d |%3d|%3d|%3c  |%3d  |%2d |%4d  |\n",y, mhs[x][y].namamk, mhs[x][y].kehadiran, mhs[x][y].tugas, mhs[x][y].quiz, mhs[x][y].uts,
                   mhs[x][y].uas, mhs[x][y].grade, mhs[x][y].point, mhs[x][y].sks, mhs[x][y].jml);
        }
        printf("|==========================================================================\n");
        printf("|Total =                                                       |%2d | %4d |\n",mhs[x][0].tsks,mhs[x][0].tjml);
        printf("===========================================================================\n");
        printf("     Index Prestasi : %f",mhs[x][0].IP);
        printf("\n\n");
    }
}

float skor (int kehadiran,int tugas,int quiz, int uts,int uas)
{
    return kehadiran*0.1 + tugas*0.15 + quiz*0.15  + uts*0.3 + uas*0.3;
}
 
 void matkul (float skor, int sks, int *kehadiran, int *tugas, int *quiz, int *uts, int *uas, char *grade, int *point, int *jml)
{
    if (skor >= 85)
    {
        *grade='A';
        *point=4;
    }
    else if (skor >=71 && skor <85)
    {
        *grade='B';
        *point=3;
    }
    else if (skor >=56 && skor <71)
    {
        *grade='C';
        *point=2;
    }
    else if (skor >=45 && skor < 56)
    {
        *grade='D';
        *point=1;
    }
    else if (skor <45)
    {
        *grade='E';
        *point=0;
    }
    *jml=*point*sks;
}
