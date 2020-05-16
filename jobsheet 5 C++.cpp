#include <iostream>
#include <cstdlib>
using namespace std;

main (){
int nim1[2][2];
int nim2[2][2];
int jml [2][2];
int x, y;
cout<< "PERKALIAN NIM\n";
for (x = 0; x < 2; x++){
for (y = 0; y < 2; y++){
cout<< "Masukkan index " << x << "," << y << " = ";
cin>> nim1[x][y];
}
}
cout<<endl;
for (x = 0; x < 2; x++){
for (y = 0; y < 2; y++){
cout<< "Masukkan index " << x << "," << y << " = ";
cin>> nim2[x][y];
}
}
cout<<endl;
for (x = 0; x < 2; x++){
for (y = 0; y < 2; y++){
jml [x][y] = nim1[x][0]*nim2[0][y]+nim1[x][1]*nim2[1][y];
cout<<jml [x][y] <<" ";
}
cout<<endl;
}
}

