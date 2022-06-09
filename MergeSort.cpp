#include <iostream>
using namespace std;

class Merge
{
	public: 
		int* arr1;	
		Merge(int);
		void Siralama_kaydet(int, int);
		void Sirala(int, int, int);
		void Ekle(int);
		void Yazdir(int);
		void Sil();
};
void Merge::Ekle(int dizi_boyutu)
{
	cout<<"Elemanlari gir: ";
	for (int k = 0 ; k < dizi_boyutu ; k++ )
	{
		cin >> arr1[k];
	}
}
void Merge::Yazdir(int dizi_boyutu)
{
	cout<<"Dizinin siralanmis hali: ";
	for (int m = 0 ; m < dizi_boyutu ; m++ )
	{
		if(m == (dizi_boyutu - 1)){
			cout << arr1[m];
		}
		else
		cout << arr1[m] << ", ";
	}
}
Merge::Merge(int dizi_boyutu)
{
	arr1 = new int[dizi_boyutu];
}
void Merge::Siralama_kaydet(int bas, int son)
{
	if (bas<son)
	{
		int orta= (bas+son)/2;
		Siralama_kaydet(bas, orta);
		Siralama_kaydet(orta+1, son);
		Sirala(bas, orta, son);
	}
}
void Merge::Sirala(int bas, int orta, int son)
{
	int* temp = new int[son];
	for (int i=bas; i<= son ; i++)
	{
		temp[i] = arr1[i];
	}
	
	int ax = bas;
	int to = orta+1;
	int mb = bas;
	
	while (ax <= orta && to <= son )
	{
		if (temp[ax]<=temp[to])
		{
			arr1[mb++] = temp [ax++];
		}
		else
		{
			arr1[mb++] = temp[to++];
		}
		
	}
	
	while (ax <= orta)
	{
		arr1[mb++] = temp[ax++];
	}
	delete [] temp;
}
void Merge::Sil()
{
	delete [] arr1;
}
int main()
{
	int dizi_boyutu,secim;
	do
	{
		cout<<"Dizi kac elmanli olacak?: ";
		cin>>dizi_boyutu;
		Merge siralama1(dizi_boyutu);
		siralama1.Ekle(dizi_boyutu);
		siralama1.Siralama_kaydet(0, dizi_boyutu-1);
		siralama1.Yazdir(dizi_boyutu);
		siralama1.Sil();
		cout<<"\n1-Devam etmek istiyorum. ";
		cout<<"\n2-Cikis ";
		cout<<"\nSecim:";
		cin>>secim;
	}while (secim==1);
	
	return 0;
}
