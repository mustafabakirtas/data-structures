#include<iostream> 
using namespace std; 
class Dugum1 
{  
	public:
	  int veri;
	  Dugum1  * next; 
	  Dugum1 () 
	  {  	
	    veri = 0;
	    next = NULL;
	  }
	  Dugum1(int x) 
	  { 
	  	veri = x;
	  }
};
 
class Dairesel_kuyruk_kodu 
{
  public:
    Dugum1  * bas_node;
 
  Dairesel_kuyruk_kodu() 
  {
    bas_node = NULL;
  }
 
  void Node_ekle(Dugum1  * Yeni_node) 
  {
    if (bas_node == NULL) 
	  {
        bas_node = Yeni_node;
        Yeni_node -> next = bas_node;
        cout << "Node eklendi." << endl;
      } 
	  else 
	  {
        Dugum1  * ptr = bas_node;
        while (ptr -> next != bas_node) 
		{
          ptr = ptr -> next;
        }
        ptr -> next = Yeni_node;
        Yeni_node -> next = bas_node;
        cout << "Node eklendi." << endl;
      } 
  }
 
  void Node_sil() 
  {
    if (bas_node -> next == NULL) 
		{
          bas_node = NULL;
        } 
		else 
		{
			Dugum1  * ptr1 = bas_node;
            while (ptr1 -> next != bas_node) 
		    {
            ptr1 = ptr1 -> next;
            }
            bas_node=bas_node->next;
            ptr1->next=bas_node;
        } 
   }
  void Yazdir() 
  {
    if (bas_node == NULL) 
	{
      cout << "Liste bos.";
    } 
	else 
	{ 
      Dugum1  * gecici2 = bas_node;
 
      do 
	  {
        cout << "(" << gecici2 -> veri<< ") --> ";
        gecici2 = gecici2 -> next;
      } while (gecici2 != bas_node);
    } 
  } 
};
 
int main() 
{
 
  Dairesel_kuyruk_kodu  kuyruk1;
  int secim;
  int  data1;
  do {
    cout << "\n1. Node ekle." << endl;
    cout << "2. Node sil." << endl;
    cout << "3. Yazdir" << endl;
    cout << "Secim: " ; 
    cin >> secim;
    Dugum1  * dugum = new Dugum1 ();
 
    switch (secim) 
	{
	    case 0:
	      break;
	      
	    case 1:
	      cout << "Eklenecek veriyi girin:";
	      cin >> data1;
	      dugum -> veri = data1;
	      kuyruk1.Node_ekle(dugum);
	      break; 
	 
	    case 2:	 
	      cout << "Veri silindi:" ;
	      kuyruk1.Node_sil();	 
	      break;
	
	    case 3:
	      kuyruk1.Yazdir();	 
	      break;
	      
	    default:
	      cout << "Hatali giris. " << endl;
    }
 
  } while (secim != 0);
 
  return 0;
}

