#include<iostream>
#include<string.h>
using namespace std;

float n, k, t, ku, ut, ua, p, pp;
int i,x;
float a, b, c, d, e;
struct data{
char nama[100];
char nim[100];
char semester[100];
float absensi;
float tugas;
float kuis;
float uas;
float nilaiuts;
float nilaiakhir;
char nilai[100];}

wow[5000];

int duar(){
do{
cout << "\n===PERSENTASE PENILAIAN===\n";
cout << "Masukkan Persentase Kehadiran (%) : ";
	cin >> k;
cout << "Masukkan Persentase Tugas     (%) : ";
	cin >> t;
cout << "Masukkan Persentase Kuis      (%) : ";
	cin >> ku;
cout << "Masukkan Persentase nilaiuts       (%) : ";
	cin >> ut;
cout << "Masukkan Persentase UAS       (%) : ";
	cin >> ua;
	
pp = k + t + ku + ut + ua;

if(pp != 100){
cout << "(Persentase Penilaian Harus 100)\n";}
if(pp == 100){
cout << "Persentase Penilaian Sudah : " << pp << "%" << endl;}}
while(pp != 100);
cout << "\n----------------------------------\n";

cout << "\nMasukkan Total Pertemuan : ";
	cin >> p;

cout << "\nMasukkan banyak mahasiswa yang ingin di input : ";
	cin >> n;

for(i = 1; i <= n; i++){
cout << "\n" << i << ". Nama 	: ";
	fflush(stdin); 
	gets(wow[i].nama);
cout << "   NIM 		: ";
	cin >> wow[i].nim;
	cout << "   SEMESTER 		: ";
	cin >> wow[i].semester;
cout << "   Kehadiran    : ";
	cin >> wow[i].absensi;
cout << "   Nilai tugas 	: ";
	cin >> wow[i].tugas;
cout << "   Nilai kuis   : ";
	cin >> wow[i].kuis;
cout << "   Nilai nilaiuts 	: ";
	cin >> wow[i].nilaiuts;
cout << "   Nilai UAS 	: ";
	cin >> wow[i].uas;

a = ((wow[i].absensi / p) * (k / 100) * 100);
b = ((wow[i].tugas) * (t / 100));
c = ((wow[i].kuis) * (k / 100));
d = ((wow[i].nilaiuts) * (ut / 100));
e = ((wow[i].uas) * (ua / 100));

wow[i].nilaiakhir = a+b+c+d;
if(wow[i].nilaiakhir <= 100 && wow[i].nilaiakhir >= 80){
strcpy(wow[i].nilai, "A");}
else if(wow[i].nilaiakhir <= 79 && wow[i].nilaiakhir >= 60){
strcpy(wow[i].nilai, "B+");}
else if(wow[i].nilaiakhir <=59 && wow[i].nilaiakhir >= 55){
strcpy(wow[i].nilai, "B");}
else if(wow[i].nilaiakhir <= 54 && wow[i].nilaiakhir >= 50){
strcpy(wow[i].nilai, "C+");}
else if(wow[i].nilaiakhir <= 49 && wow[i].nilaiakhir >= 45){
strcpy(wow[i].nilai, "C");}
else if(wow[i].nilaiakhir <= 44 && wow[i].nilaiakhir >= 40){
strcpy(wow[i].nilai, "D+");}
else if(wow[i].nilaiakhir <= 39 && wow[i].nilaiakhir >= 35){
strcpy(wow[i].nilai, "D");}
else {strcpy(wow[i].nilai, "E");}}

cout << "\n______\n";
cout << "|No.|Nama Mahasiswa       | Kehadiran | Tugas | Kuis | nilaiuts | UAS | Nilai Akhir | Grade |\n";
for(i = 1; i <= n; i++){
cout << "|" << i << "  |" << wow[i].nama << "\t"<< wow[i].absensi << "\t" << wow[i].tugas << "\t" << wow[i].kuis << "\t" << wow[i].nilaiuts << "\t" << wow[i].uas << "\t" << wow[i].nilaiakhir << "\t" << wow[i].nilai;
cout << "\n---------------------------------------------------------------------------------\n";}
}

main(){
printf("---PROGRAM MENGHITUNG NILAI AKHIR---\n");
printf("Pilih mata kuliah: \n");
printf("1. bahasa indonesia\n");
printf("2. algoritma dan pemograman \n");
printf("Pilih mata kuliah: ");
	scanf("%d", &x);
printf("\n----------------------------------\n");
switch(x){

case 1:
duar();

break;

case 2:
duar();

break;
}


}
