#include<bits/stdc++.h>
using namespace std;
class Medicine
{
private:
    int ID,qty;
    string name,cmpname,supname;
    float unitCost,saleCost;
public:

   void getdata()
   {
     cout<<"Enter Medicine ID \n";
     cin>>ID;
     cout<<"Enter Medicine name \n";
     cin>>name;
     cout<<"Enter Company marks \n";
     cin>>cmpname;
     cout<<"Enter Supplier marks \n";
     cin>>supname;
     cout<<"Enter Qty \n";
     cin>>qty;
     cout<<"Enter Unit Cost \n";
     cin>>unitCost;
     cout<<"Enter Sale Cost \n";
     cin>>saleCost;
   }
   void display()
   {
        cout<<endl<<"Medicine ID: "<<ID;
        cout<<endl<<"Name: "<<name;
        cout<<endl<<"Company name: "<<cmpname;
        cout<<endl<<"Supplier name: "<<supname;
        cout<<endl<<"Unit cost: "<<unitCost;
        cout<<endl<<"Sale Cost: "<<saleCost;
        cout<<endl<<"Quantity: "<<qty;
        cout<<endl;
   }
   string retname()
   {
       return name;
   }
   int retID()
   {
       return ID;
   }
};
char rep;
Medicine s,s1;
fstream fs,temp;
void create()
{
    fs.open("med.txt",ios::out| ios::binary);
    do{
        s.getdata();
        fs.write((char*)&s,sizeof(s));
        cout<<endl<<"Do you want to add more records"<<endl;
        cin>>rep;
    }while(rep=='y' || rep=='Y');
    fs.close();
}

void dispfile()
{
    fs.open("med.txt",ios::in| ios::binary);
    while(fs.read((char*)&s,sizeof(s)))
    {
        s.display();
    }
    fs.close();
}
void append()
{
      fs.open("med.txt",ios::app|ios::binary);
      do{
        s.getdata();
        fs.write((char*)&s,sizeof(s));                                                     // object's' is written into the file
        cout<<"Do you want to enter another record (y/n)";
        cin>>rep;
      }while(rep=='y' || rep=='Y');
      fs.close();
}
void search()
{
    int choice;
    fs.open("med.txt",ios::app|ios::binary);
    cout<<"Search on the basis of: "<<endl<<"1.roll no"<<endl<<"2.Name"<<endl;
    cout<<"Enter Choice__";
    cin>>choice;
    if(choice==1)
    {
    }
}
void editrec()
{

}
void count_rec()
{

}
int main()
{
    int ch;
    char ch1;
    do{
        cout<<"Menu"<<endl;
        cout<<"1.Create a file"<<endl;
        cout<<"2.Read a file"<<endl;
        cout<<"3.Append a file"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:create();
            break;
            case 2:dispfile();
            break;
            case 3:append();
            break;
        }
        cout<<endl<<"Want to continue(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');
    return 0;
}
