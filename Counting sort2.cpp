#include<iostream>
using namespace std;
class Counting_sort
{
	public:
		int *dizi1,*Sirali,en_buyuk,Dizi_boyutu;
		Counting_sort(int);
		void Eleman_ekle(int);
		void Elemanlari_sirala();
		void Yazdir();
};
void Counting_sort::Eleman_ekle(int Dizi_boyutu)
{
	cout<<"Elemanlari gir: \n";
	for(int t=1;t<=Dizi_boyutu;t++)
	{
		cout<<t<<". elaman:";
		cin>>dizi1[t];
		if(dizi1[t]>en_buyuk)
			en_buyuk=dizi1[t];
	}
}
void Counting_sort::Yazdir()
{
	for(int i=1;i<=Dizi_boyutu;i++)       
	{
		cout<<Sirali[i]<<"->";
	}
}
void Counting_sort::Elemanlari_sirala()
{
	int Temp[en_buyuk];
	for(int i=0;i<en_buyuk+1;i++)
	{
		Temp[i]=0;
	}
	for(int m=1;m<=Dizi_boyutu;m++)
	{
		Temp[ dizi1[m] ]++;			    
	}
	for(int i=1;i<=en_buyuk;i++)
	{
		Temp[i]+=Temp[i-1];            
	}
	for(int x=Dizi_boyutu;x>=1;x--)
	{
		Sirali[Temp[dizi1[x]]]=dizi1[x];          
		Temp[ dizi1[x]]=Temp[dizi1[x]]-1;		  
	}
	
}
Counting_sort::Counting_sort(int eleman_sayisi1)
{
	en_buyuk=0;
	Dizi_boyutu=eleman_sayisi1;
	dizi1=new int[Dizi_boyutu];
	Sirali=new int[Dizi_boyutu];
}
int main()
{
	int eleman_sayisi;
	cout<<"Eleman sayisini girin:";
	cin>>eleman_sayisi;
	Counting_sort siralama1(eleman_sayisi);
	siralama1.Eleman_ekle(eleman_sayisi);
	siralama1.Elemanlari_sirala();
	siralama1.Yazdir();
}
