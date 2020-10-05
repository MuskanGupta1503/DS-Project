#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
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
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
     cout<<"Enter Medicine name \n";
     cin>>name;
     cout<<"Enter Company name \n";
     cin>>cmpname;
     cout<<"Enter Supplier name \n";
     cin>>supname;
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
     cout<<"Enter Qty \n";
     cin>>qty;
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
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

   string retCompname()
   {
       return cmpname;
   }

   string retSupname()
   {
       return supname;
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
    fs.open("med.txt",ios::out| ios::binary | ios::app |ios::in);
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
    fs.open("med.txt",ios::in| ios::binary | ios::out| ios::app );
    fs.seekg(0,ios::beg);
    if(!fs)
    {
        cout<<"FILE does not exists"<<endl;
        return;
    }
    while(fs.read((char*)&s,sizeof(s)))
    {
        s.display();
    }
    fs.close();
}

void append()
{
      fs.open("med.txt",ios::app|ios::binary | ios::out | ios::in);
      do{
        s.getdata();
        fs.write((char*)&s,sizeof(s));                              // object's' is written into the file
        cout<<"Do you want to enter another record (y/n)";
        cin>>rep;
      }while(rep=='y' || rep=='Y');
      fs.close();
}

void search_rec()
{
    int choice;
    fs.open("med.txt",ios::in|ios::binary| ios::out | ios::app);
    fs.seekg(0,ios::beg);
    if(!fs)
    {
        cout<<"File Reading Error"<<endl;
        return;
    }

    cout<<"Search on the basis of: "<<endl<<"1.ID"<<endl<<"2.Name"<<endl<<"3.Company Name"<<endl<<"4.Supplier Name"<<endl;
    cout<<"Enter Choice__";
    cin>>choice;
    int found=0;
    if(choice==1)
    {
        int id;
        cout<<"Enter ID to be searched---";
        cin>>id;

        while(fs.read((char*)&s,sizeof(s)))
        {
            if(s.retID()==id)
            {
                found=1;
                s.display();
                fs.seekg(0,ios::beg);
                return;
            }
        }
        if(found==0)
        {
            cout<<"No such ID found"<<endl;
        }
    }
        if(choice==2)
    {
        string nm;
        cout<<"Enter name to be searched---"<<endl;
        cin>>nm;
        while(fs.read((char*)&s,sizeof(s)))
        {
            if(s.retname()==nm)
            {
                found=1;
                s.display();
                break;
            }
        }
         if(found==0)
        {
            cout<<"No such ID found"<<endl;
        }
    }
        if(choice==3)
    {
        string cmp;
        cout<<"Enter Company name to be searched---"<<endl;
        cin>>cmp;
        while(fs.read((char*)&s,sizeof(s)))
        {
            if(s.retCompname()==cmp)
            {
                found=1;
                s.display();
//                break;
            }
        }
         if(found==0)
        {
            cout<<"No such ID found"<<endl;
        }
    }
        if(choice==4)
    {
        string smp;
        cout<<"Enter Supplier name to be searched---"<<endl;
        cin>>smp;
        while(fs.read((char*)&s,sizeof(s)))
        {
            if(s.retSupname()==smp)
            {
                found=1;
                s.display();
//                break;
            }
        }
         if(found==0)
        {
            cout<<"No such ID found"<<endl;
        }
    }
    fs.close();
}

void editrec()
{
    fs.open("med.txt",ios::app|ios::binary | ios::out | ios::in);
     if(!fs)
    {
        cout<<"File Reading Error"<<endl;
        return;
    }
    int id1;
    cout<<"Enter Medicine ID to be modified "<<endl;
    cin>>id1;
    int rec=0;
    int f=0;
    while(fs.read((char*)&s,sizeof(s)))
    {
        if(s.retID()==id1)
        {
            cout<<"Enter New Information "<<endl;
            s.getdata();
            fs.seekg(rec*sizeof(s),ios::beg);
            fs.write((char*)&s,sizeof(s));
            f=1;
            break;
        }
        rec++;
    }
    if(f==1)
    {
        cout<<endl<<" RECORD UPDATED "<<endl;
    }
    else
    {
        cout<<endl<<"RECORD NOT FOUND"<<endl;
    }

    fs.close();

}

void count_rec()
{
    fs.open("med.txt",ios::in|ios::binary);
     if(!fs)
    {
        cout<<"File Reading Error"<<endl;
        return;
    }
    int num=0;
    while(fs.read((char*)&s,sizeof(s)))
    {
        num++;
    }
    cout<<"Records in the file are-- "<<num;
    fs.close();
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
        cout<<"4.Count total records in a file"<<endl;
        cout<<"5.Search and display a record"<<endl;
        cout<<"6.Update a record on the basis of entered ID"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                dispfile();
                break;
            case 3:
                append();
                break;
            case 4:
                count_rec();
                break;
            case 5:
                search_rec();
                break;
            case 6:
                editrec();
                break;
        }
        cout<<endl<<"Want to continue(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');
    return 0;
}
