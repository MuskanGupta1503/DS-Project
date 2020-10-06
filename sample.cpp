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

void MODIFY()
{
    fstream f("med1.dat", ios::in | ios::out | ios::binary);
    Medicine m;
    int id1;
    cout<<"\n Enter ID whose record is to be modified: ";
    cin>>id1;
    int rec_count=0;
    char found='N';
    while(f.read((char*)&m,sizeof(m)))
    {
        if(m.retID()==id1)
        {
            cout<<"\n Enter New Information";
            m.indata();
            f.seekg(rec_count*sizeof(Medicine),ios::beg);
            f.write((char*)&m,sizeof(Medicine));
            found='Y';
            break;
        }
        rec_count++;
    }
    if(found=='Y')
    {
        cout<<"\n Medicine Details Updated";
    }
    else
    {
        cout<<"\n Record Not Found!!!!";
    }
    f.close();
}

void DELETION1()
{
    ifstream fmain("med1.dat", ios::binary | ios::in);
    ofstream ftemp("temp.dat", ios::binary | ios::out);
    Medicine m;
    int id1;
    cout<<"Enter ID whose record is to be deleted:";
    cin>>id1;
    char found='N';
    while(fmain.read((char*)&m,sizeof(m)))
    {
        if(m.retID()!=id1)
        {
            ftemp.write((char*)&m,sizeof(m));
        }
        else
        {
            found='Y';
        }
    }
    if(found=='N')
    {
        cout<<"\n RECORD NOT FOUND!!";
    }
    else
    {
        cout<<"\n RECORD DELETED";
    }
    fmain.close();
    ftemp.close();
    remove("med1.dat");
    rename("temp.dat","med1.dat");
}

void DELETION2()
{
    ifstream fmain("med1.dat", ios::binary | ios::in);
    ofstream ftemp("temp.dat", ios::binary | ios::out);
    Medicine m;
   // int id1;
    //cout<<"Enter ID whose record is to be deleted:";
    //cin>>id1;
    char nm[30];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter Name whose record is to be deleted: ";
    gets(nm);
    char found='N';
    while(fmain.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.retName(),nm)!=0)
        {
            ftemp.write((char*)&m,sizeof(m));
        }
        else
        {
            found='Y';
        }
    }
    if(found=='N')
    {
        cout<<"\n RECORD NOT FOUND!!";
    }
    else
    {
        cout<<"\n RECORD DELETED";
    }
    fmain.close();
    ftemp.close();
    remove("med1.dat");
    rename("temp.dat","med1.dat");
}

void DELETION3()
{
    ifstream fmain("med1.dat", ios::binary | ios::in);
    ofstream ftemp("temp.dat", ios::binary | ios::out);
    Medicine m;
   // int id1;
    //cout<<"Enter ID whose record is to be deleted:";
    //cin>>id1;
    char nm[30];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter Name whose record is to be deleted: ";
    gets(nm);
    char found='N';
    while(fmain.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.retCmpname(),nm)!=0)
        {
            ftemp.write((char*)&m,sizeof(m));
        }
        else
        {
            found='Y';
        }
    }
    if(found=='N')
    {
        cout<<"\n RECORD NOT FOUND!!";
    }
    else
    {
        cout<<"\n RECORD DELETED";
    }
    fmain.close();
    ftemp.close();
    remove("med1.dat");
    rename("temp.dat","med1.dat");
}

void DELETION4()
{
    ifstream fmain("med1.dat", ios::binary | ios::in);
    ofstream ftemp("temp.dat", ios::binary | ios::out);
    Medicine m;
   // int id1;
    //cout<<"Enter ID whose record is to be deleted:";
    //cin>>id1;
    char nm[30];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter Name whose record is to be deleted: ";
    gets(nm);
    char found='N';
    while(fmain.read((char*)&m,sizeof(m)))
    {
        if(strcmp(m.retSupname(),nm)!=0)
        {
            ftemp.write((char*)&m,sizeof(m));
        }
        else
        {
            found='Y';
        }
    }
    if(found=='N')
    {
        cout<<"\n RECORD NOT FOUND!!";
    }
    else
    {
        cout<<"\n RECORD DELETED";
    }
    fmain.close();
    ftemp.close();
    remove("med1.dat");
    rename("temp.dat","med1.dat");
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
        cout<<"\n 5.Modify a record";
        cout<<"\n 6.Delete a record on the basis of ID";
        cout<<"\n 7.Delete a record on the basis of name";
        cout<<"\n 8.Delete a record on the basis of company name";
        cout<<"\n 9.Delete a record on the basis of supplier name";
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
            MODIFY();
            break;
        case 6:
            DELETION1();
            break;
        case 7:
            DELETION2();
            break;
        case 8:
            DELETION3();
            break;
        case 9:
            DELETION4();
            break;
        }
        cout<<endl<<"Want to continue(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');
    return 0;
}
