#include<bits/stdc++.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<ctype.h>
using namespace std;

class Medicine
{
    int ID,qty;
    char name[30],cmpname[30],supname[30];
    float unitCost,saleCost;
public:
    Medicine()
    {
        ID=0;
        qty=0;
        name[0]='\0';
        cmpname[0]='\0';
        supname[0]='\0';
        unitCost=0;
        saleCost=0;
    }
    Medicine(Medicine &M)
    {
        ID=M.ID;
        qty=M.qty;
        strcpy(name,M.name);
        strcpy(cmpname,M.cmpname);
        strcpy(supname,M.supname);
        unitCost=M.unitCost;
        saleCost=M.saleCost;
    }
    void indata();
    void outdata();
    int retID();
    char*retName();
    char*retCmpname();
    char*retSupname();
};

void Medicine::indata()
{
     cout<<"\n Enter Medicine ID ";
     cin>>ID;
     cout<<"\n Enter Qty ";
     cin>>qty;
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
     cout<<"\n Enter Medicine name ";
     gets(name);
     cout<<"\n Enter Company name ";
     gets(cmpname);
     cout<<"\n Enter Supplier name ";
     gets(supname);
     //cin.ignore(numeric_limits<streamsize>::max(),'\n');
     //cin.ignore(numeric_limits<streamsize>::max(),'\n');
     cout<<"\n Enter Unit Cost ";
     cin>>unitCost;
     cout<<"\n Enter Sale Cost ";
     cin>>saleCost;
}

void Medicine::outdata()
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

int Medicine::retID()
{
    return(ID);
}

char*Medicine::retCmpname()
{
    return(cmpname);
}

char*Medicine::retName()
{
    return(name);
}

char*Medicine::retSupname()
{
    return(supname);
}

void WRITE()
{
    ofstream f("med1.dat",ios::binary | ios::app);
    Medicine m;
    char reply;
    do
    {
        m.indata();
        f.write((char*)&m,sizeof(m));
        cout<<"Want to enter more records";
        cin>>reply;
    }while(toupper(reply)=='Y');
    f.close();
}
void READ()
{
    ifstream f("med1.dat",ios::binary | ios::in);
    Medicine m;
    if(!f)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    int ctr=0;
    while(f.read((char*)&m,sizeof(m)))
    {
        cout<<endl<<"Record: "<<++ctr;
        m.outdata();
    }
    f.close();
}

void SEARCH_ID()
{
    ifstream f("med1.dat",ios::in | ios::binary);
    char found='N';
     Medicine m;
    if(!f)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    int id1;
    cout<<"Enter ID whose record is to be searched: ";
    cin>>id1;
    while(f.read((char*)&m,sizeof(m)))
    {
        if(m.retID()==id1)
        {
            cout<<"INFORMATION OF THE MEDICINE :";
            m.outdata();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    f.close();
}

void SEARCH_NAME()
{
    ifstream f("med1.dat",ios::in | ios::binary);
    char found='N';
     Medicine m;
    if(!f)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    char nm[30];
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter name whose record is to be searched: ";
    gets(nm);
    while(f.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.retName(),nm)==0)
        {
            cout<<"INFORMATION OF THE MEDICINE :";
            m.outdata();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    f.close();
}

void SEARCH_CMPNAME()
{
    ifstream f("med1.dat",ios::in | ios::binary);
    char found='N';
     Medicine m;
    if(!f)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    char company[30];
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter company name whose record is to be searched: ";
    gets(company);
    while(f.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.retCmpname(),company)==0)
        {
            cout<<"INFORMATION OF THE MEDICINE :";
            m.outdata();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    f.close();
}

void SEARCH_SUPNAME()
{
    ifstream f("med1.dat",ios::in | ios::binary);
    char found='N';
     Medicine m;
    if(!f)
    {
        cout<<endl<<"FILE DOESN'T EXIST!!!!!";
        return;
    }
    char supply[30];
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter company name whose record is to be searched: ";
    gets(supply);
    while(f.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.retSupname(),supply)==0)
        {
            cout<<"INFORMATION OF THE MEDICINE :";
            m.outdata();
            found='Y';
            break;
        }
    }
    if(found=='N')
    {
        cout<<"NO SUCH RECORD FOUND"<<endl;
    }
    f.close();
}

void COUNT_REC()
{
    Medicine m;
    ifstream fs("med1.dat",ios::in|ios::binary);
     if(!fs)
    {
        cout<<"File Reading Error"<<endl;
        return;
    }
    int num=0;
    while(fs.read((char*)&m,sizeof(m)))
    {
        num++;
    }
    cout<<"Records in the file are-- "<<num;
    fs.close();
}
void SEARCH()
{
    int s;
    cout<<"\n Search on the basis of :- ";
    cout<<"\n 1.ID";
    cout<<"\n 2.Name";
    cout<<"\n 3.Company Name";
    cout<<"\n 4.Supplier Name";
    cin>>s;
    switch(s)
    {
    case 1:
        SEARCH_ID();
        break;
    case 2:
        SEARCH_NAME();
        break;
    case 3:
        SEARCH_CMPNAME();
        break;
    case 4:
        SEARCH_SUPNAME();
        break;
    }
}
int main()
{
    char ch1;
    int ch;
    do{
        cout<<"\n WELCOME TO MEDICAL STORE";
        cout<<"\n 1.Create a file";
        cout<<"\n 2.Read a file";
        cout<<"\n 3.Count total records in a file";
        cout<<"\n 4.Search some Record";
        cout<<"\n 5.Search on the basis of ID";
        cout<<"\n 6.Search on the basis of Name";
        cout<<"\n 7.Search on the basis of Company Name";
        cout<<"\n 8.Search on the basis of Supplier Name";
        cin>>ch;
        switch(ch)
        {
        case 1:
            WRITE();
            break;
        case 2:
            READ();
            break;
        case 3:
            COUNT_REC();
            break;
        case 4:
            SEARCH();
            break;
        case 5:
            SEARCH_ID();
            break;
        case 6:
            SEARCH_NAME();
            break;
        case 7:
            SEARCH_CMPNAME();
            break;
        case 8:
            SEARCH_SUPNAME();
            break;
        }
        cout<<endl<<"Want to continue(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');
    return 0;
}
