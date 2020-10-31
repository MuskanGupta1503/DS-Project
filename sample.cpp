#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<cmath>
using namespace std;

class Medicine
{
    int ID;
    int qty;
    char name[30];
    char cmpname[30];
    char supname[30];
    float unitCost;
    float saleCost;

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
    void OutDataForCustomer();
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

void Medicine::OutDataForCustomer()
{
        cout<<"Name: "<<name;
        cout<<endl<<"  Company name: "<<cmpname;
        cout<<endl<<"  Sale Cost: "<<saleCost;
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

void DELETION()
{
    int s;
    cout<<"\n Delete on the basis of :- ";
    cout<<"\n 1.ID";
    cout<<"\n 2.Name";
    cout<<"\n 3.Company Name";
    cout<<"\n 4.Supplier Name";
    cin>>s;

    switch(s)
    {
    case 1:
        DELETION1();
        break;
    case 2:
        DELETION2();
        break;
    case 3:
        DELETION3();
        break;
    case 4:
        DELETION4();
        break;
    }
}

void SORT_BY_ID()
{
    fstream f;
    f.open("med1.dat",ios::binary | ios::in);
    Medicine M[1000];

    if(!f)
    {
        cout<<"FILE DOESN'T EXISTS!!!!! ";
        return;
    }

    int n=0;
    while(f.read((char*)&M[n],sizeof(Medicine)))
        n++;

    Medicine temp;
    int choice;
    cout<<"Sort"<<endl;
    cout<<"1. Ascending"<<endl;
    cout<<"2. Descending"<<endl;
    cin>>choice;

    if(choice==1)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(M[j].retID()>M[j+1].retID())
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(M[j].retID()<M[j+1].retID())
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }

    }

    f.close();
    f.open("med1.dat",ios::binary | ios::out);
    int i=0;
    while(i<n)
    {
        f.write((char*)&M[i],sizeof(Medicine));
        ++i;
    }
    cout<<"\n FILE SORTED";
    f.close();
}

void SORT_BY_NAME()
{
    fstream f;
    f.open("med1.dat",ios::binary | ios::in);
    Medicine M[1000];

    if(!f)
    {
        cout<<"FILE DOESN'T EXISTS!!!!! ";
        return;
    }

    int n=0;
    while(f.read((char*)&M[n],sizeof(Medicine)))
        n++;

    Medicine temp;
    int choice;
    cout<<"Sort"<<endl;
    cout<<"1. Ascending"<<endl;
    cout<<"2. Descending"<<endl;
    cin>>choice;

    if(choice==1)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(strcmp(M[j].retName(),M[j+1].retName())>0)
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(strcmp(M[j].retName(),M[j+1].retName())<0)
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }

    f.close();
    f.open("med1.dat",ios::binary | ios::out);
    int i=0;
    while(i<n)
    {
        f.write((char*)&M[i],sizeof(Medicine));
        ++i;
    }
    cout<<"\n FILE SORTED";
    f.close();
}

void SORT_BY_CMPNAME()
{
    fstream f;
    f.open("med1.dat",ios::binary | ios::in);
    Medicine M[1000];

    if(!f)
    {
        cout<<"FILE DOESN'T EXISTS!!!!! ";
        return;
    }

    int n=0;
    while(f.read((char*)&M[n],sizeof(Medicine)))
        n++;

    Medicine temp;
    int choice;
    cout<<"Sort"<<endl;
    cout<<"1. Ascending"<<endl;
    cout<<"2. Descending"<<endl;
    cin>>choice;

    if(choice==1)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(strcmp(M[j].retCmpname(),M[j+1].retCmpname())>0)
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(strcmp(M[j].retCmpname(),M[j+1].retCmpname())<0)
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }


    f.close();
    f.open("med1.dat",ios::binary | ios::out);
    int i=0;
    while(i<n)
    {
        f.write((char*)&M[i],sizeof(Medicine));
        ++i;
    }
    cout<<"\n FILE SORTED";
    f.close();
}

void SORT_BY_SMPNAME()
{
    fstream f;
    f.open("med1.dat",ios::binary | ios::in);
    Medicine M[1000];

    if(!f)
    {
        cout<<"FILE DOESN'T EXISTS!!!!! ";
        return;
    }

    int n=0;
    while(f.read((char*)&M[n],sizeof(Medicine)))
        n++;

    Medicine temp;
    int choice;
    cout<<"Sort"<<endl;
    cout<<"1. Ascending"<<endl;
    cout<<"2. Descending"<<endl;
    cin>>choice;

    if(choice==1)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(strcmp(M[j].retSupname(),M[j+1].retSupname())>0)
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(strcmp(M[j].retSupname(),M[j+1].retSupname())<0)
                {
                    temp=M[j];
                    M[j]=M[j+1];
                    M[j+1]=temp;
                }
            }
        }
    }


    f.close();
    f.open("med1.dat",ios::binary | ios::out);
    int i=0;
    while(i<n)
    {
        f.write((char*)&M[i],sizeof(Medicine));
        ++i;
    }
    cout<<"\n FILE SORTED";
    f.close();
}

void SORT()
{
    int s;
    cout<<"\n Sort on the basis of :- ";
    cout<<"\n 1.ID";
    cout<<"\n 2.Name";
    cout<<"\n 3.Company Name";
    cout<<"\n 4.Supplier Name";
    cin>>s;

    switch(s)
    {
    case 1:
        SORT_BY_ID();
        break;
    case 2:
        SORT_BY_NAME();
        break;
    case 3:
        SORT_BY_CMPNAME();
        break;
    case 4:
        SORT_BY_SMPNAME();
        break;
    }
}

void ADMIN()
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
        cout<<"\n 6.Delete a record ";
        cout<<"\n 7.Sort all records";
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
            DELETION();
            break;
        case 7:
            SORT();
            break;

        }
        cout<<endl<<"\n Want to continue as ADMIN(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');

}

bool LOGIN()
{
    char username[30];
    char password[30];
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\n Enter Username  ";
    gets(username);
    cout<<"\n Enter Password  ";
    gets(password);

    if((strcmp(username,"admin")==0) && (strcmp(password,"Hello")==0))
    {
        return true;
    }

    return false;
}

void DISPLAY_FOR_CUSTOMER()
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
        cout<<endl<<++ctr<<")";
        m.OutDataForCustomer();
    }
    f.close();
}

void SEARCH_NAME_FOR_CUSTOMER()
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
            cout<<"INFORMATION OF THE MEDICINE : \n";
            cout<<"  ";
            m.OutDataForCustomer();
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

void CUSTOMER()
{
    //cout<<"Hello"<<endl;
    char ch1;
    int ch;

    do{
        cout<<"\n WELCOME TO MEDICAL STORE";
        cout<<"\n 1.Explore All Available Medicines";
        cout<<"\n 2.Search some Medicine name";
        cin>>ch;

        switch(ch)
        {
        case 1:
            DISPLAY_FOR_CUSTOMER();
            break;

        case 2:
            SEARCH_NAME_FOR_CUSTOMER();
            break;
        }
        cout<<endl<<"Want to continue as Customer(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');
}

int main()
{
    char ch1;
    int ch;

    do{
        cout<<"\n WELCOME TO MEDICAL STORE";
        cout<<"\n ENTER AS";
        cout<<"\n 1.ADMIN";
        cout<<"\n 2.CUSTOMER \n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            {
                bool b=LOGIN();
                if(b)
                {
                    ADMIN();
                }
                else
                {
                    cout<<"\n Wrong Username or Password \n";
                }
                break;
            }

        case 2:
            CUSTOMER();
            break;

        }
        cout<<endl<<"Want to continue in Medical Store(y/n)--";
        cin>>ch1;
    }while(ch1=='y' || ch1=='Y');
    return 0;
}
