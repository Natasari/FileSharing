#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MIN -99999
using namespace std;
int r[1000][3];

int cut(int p[], int l){	
	int max, temp=0, first=0, potong=0;
	r[0][0]=0;
	r[2][0]=0;
	for(int j=1; j<=l; j++){
		max=MIN;
		for(int i=1; i<=j; i++){
			potong=0;
			temp=p[i]+r[j-i][0];
			if(temp>max){
				max=temp;
				first=i;
			}
		}
		r[j][0]=max;
		r[j][1]=first;
	}
}

int main(){
	
	int price[1000];
	int inp, count=0, nilai=9999, ongkos, n;
	memset(r,0,10);
	memset(price,0,1000);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> price[i];
	}
	cin >>ongkos;
	cin >> inp;
	cut(price,inp);
	
	//cari jumlah potong
	int tmp =inp;
	for(int j=1; j<=inp; j++){
		nilai=j;
		for(int i=1; i<=j;i++){
			nilai=nilai-r[nilai][1];
			if(nilai==0){
				break;
			}
			else{
				count++;
			}
		}
		r[j][2] = count;
		count=0;
		nilai=9999;	
	}
	
	printf("potongan revenue pertama potong ongkos\n");
	for(int i=1; i<=inp; i++){
		//cout << "potongan ke:\t" << i << " revenue:\t" << r[i][0] << " pertama:\t" <<r[i][1] << " potong:\t" << r[i][2] << " ongkos:\t"<< r[i][0]-(r[i][2]*ongkos) << endl;
		printf("%4d %8d\t %4d\t %4d\t %3d\t\n", i, r[i][0],r[i][1],r[i][2],r[i][0]-(r[i][2]*ongkos));
	}
	
	cout << r[inp][0]-(r[inp][2]*ongkos) << endl;
	cout << r[inp][2]+1 << endl;
	while( inp>0){
		cout << r[inp][1] << " ";
		inp=inp-r[inp][1];
	}
	return 0;
}
