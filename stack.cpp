#include<iostrea
using namespace std;
class Stack
{
	public:
		int toplam,veri,*diz1,uzunluk;
		
		Stack(int m)
		{
			toplam=0;
			uzunluk=m;
			diz1=new int [uzunluk];
		}		
		void Stack_ekle(int m)
		{
			if(toplam==uzunluk)
			{
              cout<<"Doldu."<<endl;
            }
            else
       		{
	       		diz1[toplam]=m;
	       		toplam++;
       		}
		}
		void Stack_sil()
		{
			if(toplam<=0)	
			{
				cout<<"Stack bos."<<endl;
			}
			else
			{	
				
				cout<<diz1[toplam-1]<<". elemani silindi."<<endl;
				diz1[toplam-1]=NULL;
        		toplam-- ;
			}
		}
		void Stack_yazdir()
		{
		    if(toplam==0)
		    {
		    	cout<<"Stack boþ."<<endl;
			}        
		    else
		    {		    	
		        for(int i=0;i<toplam;i++)
		        {
		        	cout<<i+1<<". eleman : "<<diz1[i]<<endl;
				}		        
		    }	
		}
};
int main()
{
	int eleman_sayisi,secim,yeni_sayi;
	cout<<"Stack kac elemandan olusacak? : ";
	cin>>eleman_sayisi;
	Stack stack1(eleman_sayisi);
	do
	{
		cout<<"Secim Yapin."<<endl;
		cout<<"0-Cikis."<<endl;
		cout<<"1-Veri ekle."<<endl;
		cout<<"2-Veri sil."<<endl;
		cout<<"3-Stack'i yazdir."<<endl;
		cout<<"Secim:";
		cin>>secim;
		if(secim==1)
		{
			cout<<"Eklemek istediginiz sayiyi girin : ";
			cin>>yeni_sayi;
			stack1.Stack_ekle(yeni_sayi);	
			cout<<endl;	
		}
		else if(secim==2)
		{
			stack1.Stack_sil();
			cout<<endl;
		}
		else if (secim==3)
		{
			stack1.Stack_yazdir();
			cout<<endl;
		}		
		cout<<endl;
	}while(secim!=0);
}
