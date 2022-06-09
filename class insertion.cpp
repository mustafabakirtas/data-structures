#include <iostream>
using namespace std;

class Insert_siralama
{
	public:
		int* diz1;	
		Insert_siralama( int);
		void Sirala ( int );
		void Ekle ( int );
		void Yazdir ( int );
		void Sil ();
};
Insert_siralama::Insert_siralama(int dizi_boyutu1)
{
	diz1 = new int[dizi_boyutu1];
}
void Insert_siralama::Ekle(int dizi_boyutu)
{
	cout<<"Elamanlari Girin: ";
	for ( int i = 0 ; i < dizi_boyutu ; i++ )
	{
		cin >> diz1[i];
	}
}
void Insert_siralama::Sirala(int dizi_boyutu2)
{
	int data1, mb;
	for (int i = 1; i < dizi_boyutu2; i++)
	{
	    data1 = diz1[i];
	    mb = i-1;
	    while ((mb >= 0) && (diz1[mb]  > data1))
	    {
	        diz1[mb+1] = diz1[mb];
	        mb--;
	    }
	    diz1[mb+1] = data1;
	}
}
void Insert_siralama::Yazdir(int dizi_boyutu)
{
	cout<<"Dizinin siralanamis hali ";
	for (int i = 0 ; i < dizi_boyutu ; i++ )
	{
		if(i == (dizi_boyutu - 1))
		{
			cout<<diz1[i];
		}
		else
		cout<<diz1[i]<<", ";
	}
}
void Insert_siralama::Sil()
{
	delete [] diz1;
}
int main()
{
	int dizi_boyutu,yanit;
	do
	{
		cout<<endl<<"Kac elmanli bir dizi gireceksiniz. ";
		cin>>dizi_boyutu;
		Insert_siralama dizi(dizi_boyutu);
		dizi.Ekle(dizi_boyutu);
		dizi.Sirala(dizi_boyutu);
		dizi.Yazdir(dizi_boyutu);
		dizi.Sil();
		cout<<"\n1-Devam etmek istiyorum. ";
		cout<<"\n2-Cikis ";
		cin>>yanit;
	}while (yanit==1);
	return 0;
}
