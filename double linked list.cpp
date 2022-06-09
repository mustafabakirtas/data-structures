#include<iostream> 
using namespace std; 
class Node 
{
  public:
	  int data_01;
	  Node *next_pointeri;
	  Node *prev_pointeri; 
  Node() 
  {
    data_01=0;
    next_pointeri=NULL;
    prev_pointeri=NULL;
  }
}; 
class Cift_bagli_liste 
{ 
  public:
    Node *head_01;
 
  Cift_bagli_liste() 
  {
    head_01=NULL;
  }
  Cift_bagli_liste(Node *n) 
  {
    head_01=n;
  } 
  Node *node_var_mi(int k) 
	{
	    Node *temp0=NULL;
	    Node *ptr=head_01;
	 
	    while (ptr!=NULL) 
		{
	      if (ptr->data_01==k) 
		  {
	        temp0=ptr;
	      }
	      ptr=ptr->next_pointeri;
	    } 
    	return temp0;
    } 
  void Sona_Node_ekle(Node *n) 
  {     
        if (head_01==NULL) 
	    {
        head_01=n;
        cout<<"Node ilk node olarak eklendi."<<endl;
        }         
	    else 
	    {
	        Node *ptr=head_01;
	        
	        while(ptr->next_pointeri!=NULL) 
			{
	          ptr=ptr->next_pointeri;
	        }
	        
	        ptr->next_pointeri=n;
	        n->prev_pointeri=ptr;
	        cout<<"Node eklendi"<<endl;
        }
   }
 
  void Basa_node_ekle(Node *n) 
   {
	    if (head_01==NULL) 
		{
	        head_01=n;
	        cout<<"Node ilk node olarak eklendi."<<endl;
	    } 
	    else 
		{
		    head_01->prev_pointeri=n;
		    n->next_pointeri=head_01;
		    head_01=n;
		    cout<<"Node eklendi"<<endl;
	    }
   }
 
  void Araya_node_ekle(int k,Node *n) 
  {
    Node *ptr=node_var_mi(k);
    if (ptr==NULL) 
	{
      cout<<"Bu degerde bir node yok: "<<k<<endl;
    } 
	else 
	{
        Node *nextNode=ptr->next_pointeri;
        if (nextNode==NULL) 
		{
          ptr->next_pointeri=n;
          n->prev_pointeri=ptr;
          cout<<"Node sona eklendi."<<endl;
        }
 
        else 
		{
          n->next_pointeri=nextNode;
          nextNode->prev_pointeri=n;
          n->prev_pointeri=ptr;
          ptr->next_pointeri=n;
 
          cout<<"Node araya eklendi."<<endl; 
        }
    }
  }
 
  void Node_sil(int k) 
  {
    Node *ptr=node_var_mi(k);
    if (ptr==NULL) 
	{
      cout<<"Bu degerde bir node yok: "<<k<<endl;
    } 
	else 
	{ 
      if (head_01->data_01==k) 
	  {
        head_01=head_01->next_pointeri;
        cout<<"Node silindi."<<endl;
      } 
	  else 
	  {
        Node *nextNode_1=ptr->next_pointeri;
        Node *prevNode_1=ptr->prev_pointeri;
        if(nextNode_1==NULL) 
		{ 
          prevNode_1->next_pointeri=NULL;
          cout<<"Node silindi."<<endl;
        } 
        else 
		{
          prevNode_1->next_pointeri=nextNode_1;
          nextNode_1->prev_pointeri=prevNode_1;
          cout<<"Node silindi."<<endl; 
        }
      }
    }
  } 
  void Node_guncelle(int k,int d) 
  { 
    Node *ptr=node_var_mi(k);
    if (ptr!=NULL) 
	{
      ptr->data_01=d;
      cout<<"Node verisi guncellendi."<<endl;
    } 
	else 
	{
      cout<<"Bu degerde bir node yok:"<<k<<endl;
    } 
  } 
  void yazdir() 
  {
    if(head_01==NULL) 
	{
      cout<<"Listeniz bos.";
    } 
	else 
	{
      cout<<endl<<"Listenizin degerleri :";
      Node *temp=head_01;
      int f=0;
      while (temp!=NULL) 
	  {
	  	if(f!=0)
	  	{
	  		cout<<"<-->";	
		}
        cout<<"("<<temp->data_01<<")";
        temp=temp->next_pointeri;
        f++;
      }
    } 
  } 
};
 
int main() 
{ 
  Cift_bagli_liste liste1;
  int secenek;
  int data1,new_data;
  do {
    cout<<"\nIslem secin.\nCikis icin 0."<<endl;
    cout<<"1.Sona node ekle."<<endl;
    cout<<"2.Basa node ekle."<<endl;
    cout<<"3.Araya node ekle."<<endl;
    cout<<"4.Nod'u sil."<<endl;
    cout<<"5.Nod'u guncelle."<<endl;
    cout<<"6.Hepsini yazdir."<<endl; 
    cout<<"Seciminiz:";
    cin >> secenek;
    Node *node1=new Node();
 
    switch (secenek) 
	{
	    case 0:
	      break;
	    case 1:
	      cout<<"Node'a eklenecek veriyi girin."<<endl;
	      cin>>data1;
	      node1->data_01=data1;
	      liste1.Sona_Node_ekle(node1);
	      break;
	 
	    case 2:
	      cout<<"Node'a eklenecek veriyi girin."<<endl;
	      cin>>data1;
	      node1->data_01=data1;
	      liste1.Basa_node_ekle(node1);	      
	      break;
	 
	    case 3:
	      cout<<"Hangi veriden sonra node ekleyeceksiniz ? "<<endl;
	      cin>>data1;
	      cout<<"Nod'a eklenecek veriyi girin." << endl;
	      cin>>new_data;
	      node1->data_01=new_data;
	 	  liste1.Araya_node_ekle(data1,node1);
	      break;
	 
	    case 4:	 
	      cout<<"Hangi veriye ait nodu sileceksiniz ? "<<endl;
	      cin>>data1;
	      liste1.Node_sil(data1);	 
	      break;
	      
	    case 5:
	      cout<<"Yeni veriyi girin."<<endl;
	      cin>>data1;
	      cout<<"Hangi veriye ait nodu güncelleyeceksiniz ?"<<endl;
	      cin>>new_data;
	      liste1.Node_guncelle(new_data,data1);
	      break;
	      
	    case 6:
	      liste1.yazdir();	
		  break;
	      
	    default:
	      cout<<"Yanlis rakam giriniz.\nYeniden deneyin. "<<endl;
    }
 
  } while(secenek!=0);
 
  return 0;
}
