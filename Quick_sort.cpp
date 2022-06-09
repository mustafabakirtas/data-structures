#include <iostream>
using namespace std;
class Hizli_siralama
{
	public:
		int* arr1;	
		Hizli_siralama(int);
		void Sirala(int, int);
		void Veri_gir(int);
		void Yazdir(int);
		void Eleman_sil();
};
Hizli_siralama::Hizli_siralama(int uzunluk)
{
	arr1 = new int[uzunluk];
}
void Hizli_siralama::Veri_gir(int k)
{
	cout<<"Dizi elemanlarini gir: ";
	for (int i = 0 ; i < k ; i++ )
	{
		cin>>arr1[i];
	}
}
void Hizli_siralama::Sirala(int alt1, int ust1)
{
	int yeni_alt= alt1, yeni_ust= ust1, temp0;
	int orta = arr1[(alt1 + ust1)/2];
	do{
		while (arr1[yeni_alt] < orta)
			yeni_alt++;
		while (arr1[yeni_ust] > orta)
			yeni_ust--;
		
		if (yeni_alt<= yeni_ust)
		{
			temp0 = arr1[yeni_alt];
			arr1[yeni_alt] = arr1[yeni_ust];
			arr1[yeni_ust] = temp0 ;
			yeni_alt++;
			yeni_ust--; 
		}
	}while (yeni_alt <= yeni_ust);
	
	if (alt1 < yeni_ust)
		Sirala(alt1, yeni_ust);
	
	if (yeni_alt < ust1)
		Sirala(yeni_alt, ust1);
}
void Hizli_siralama::Yazdir(int mb)
{
	cout<<"Dizinin siralanmis hali: ";
	for (int i = 0 ; i < mb ; i++ )
	{
		if(i == (mb - 1))
		{
			cout<<arr1[i];
		}
		else
		cout<<arr1[i]<<", ";
	}
}
void Hizli_siralama::Eleman_sil()
{
	delete [] arr1;
}
int main()
{
	int eleman_sayisi,secim;
	do
	{
		cout<<"\nDizi kac elemanli olsun: ";
		cin>>eleman_sayisi;
		Hizli_siralama siralama1(eleman_sayisi);
		
		siralama1.Veri_gir(eleman_sayisi);
		siralama1.Sirala(0, eleman_sayisi-1);
		siralama1.Yazdir(eleman_sayisi);
		siralama1.Eleman_sil();
		cout<<"\n1-Devam etmek istiyorum. ";
		cout<<"\n2-Cikis ";
		cout<<"\nSecim:";
		cin>>secim;
	}while (secim==1);
	
	return 0;
}
