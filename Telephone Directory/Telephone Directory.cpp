#include<bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;
typedef long long ll;
#define pb push_back
map<ll,string>mp;
map<ll,string>::iterator it;


//******** directory show ********//


ll show_sub_directory()
{

    mp.clear();
    ifstream f;
    f.open("directory.txt");
    string s;
    ll line_cnt=0;
    ll cnt=0;
    while(getline(f,s))
    {
        line_cnt++;
        if(line_cnt%5==1)
        {
            cnt++;
            mp[cnt]=s;
        }
    }
    if(!cnt)return cnt;
    else
        cout<<"\nTotal contact = "<<cnt<<endl<<endl;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        cout<< it->first<<"."<< it->second<<endl;
    }
    f.close();
    return cnt;
}

//******* get contact name *******//

string contact_name()
{
    //system("pause");
    ll view_directory_choice;
    string s;
    cin>>s;
    if(s[0]=='x' || s[0]=='X')return s;
    else
    {
        string chk;
        view_directory_choice=std::stoi(s);
        if(!view_directory_choice)
        {
            //search_vd=1;
            string y;
            cout<<"Enter First name : ";
            cin>>y;
            chk="Name : "+y+" ";
            cout<<"Enter Last name : ";
            cin>>y;
            chk+=y;
        }
        else
        {
            it=mp.find(view_directory_choice);
            if(it!=mp.end())chk=it->second;
        }
        return chk;
    }

}
//******** break system/sub-system ********//
ll break_function()
{
    char c;
    cin>>c;
    if(c=='y')return 0;
    else
        return 1;
}

//check user//

ll check_usr(string a,string b)
{
    ll cnt=0,chk=0;
    for(ll i=0,j=0; i<b.size(); i++)
    {
        if(a[j]==b[i])
        {
            cnt++;
            j++;
        }
        else
        {
            cnt=0;
            j=0;
        }
        if(cnt>=b.size())
        {
            chk=1;
            break;
        }
    }
    if(chk)return 1;
    else
        return 0;
}
//******** create new directory *********//
void create_new_directory()
{
    ofstream file2("directory.txt",ios::out |ios::app);
    for(;;)
    {
        system("cls");
        cout<<"              _______Creating new COntact_______\n\n\n\n\n";
        string x,first_last;
        cout<<"Enter First Name : ";
        cin>>x;
        first_last=x+" ";
        cout<<"Enter Last Name(if you want to skip pres x) : ";
        cin>>x;
        if(x[0]=='x' || x[0]=='X')
            file2<<"Name : "<<first_last<<endl;
        else
        {
            first_last+=x;
            file2<<"Name : "<<first_last<<endl;
        }
        cout<<"Enter Mobile Number : ";
        cin>>x;
        file2<<"Mobile : "<<x<<endl;
        cout<<"Enter E-mail(if you want to skip pres x) : ";
        cin>>x;
        if(x[0]=='x' || x[0]=='X')
            file2<<"E-mail : "<<endl;
        else
            file2<<"E-mail : "<<x<<endl;
        cout<<"Enter Date Of Birth (dd-mm-yyyy) (if you want to skip pres x) :";
        cin>>x;
        if(x[0]=='x' || x[0]=='X')
            file2<<"Date oF birth : "<<endl;
        else
        file2<<"Date oF birth : "<<x<<endl;
        cout<<"Category (if you want to skip pres x): ";
        cin>>x;
        if(x[0]=='x' || x[0]=='X')
            file2<<"Category : "<<endl;
        else
            file2<<"Category : "<<x<<endl;

        cout<<"\nContact added successfully\n\n";

        cout<<"Do you want to add another contact (y/n) : ";
        ll br=break_function();
        if(br)break;

    }
    file2.close();
}

//******* view dictionary *******//

void view_directory()
{
    ifstream f2("directory.txt");
    for(;;)
    {

        system("cls");
        cout<<"\n\n              _______View COntact_______\n\n\n\n\n";
        ll zero_cntkt=show_sub_directory();
        if(!zero_cntkt)
        {
            cout<<"There is no contact in the Directory.\n";
            cout<<"\nExit(y/n) : ";
            ll br1=break_function();
            if(!br1)break;
        }
        else
        {
            cout<<"\nPress 0 for search contact or enter index number or press x to go back: ";
            string chk,s;
            ll seach_choice;
            cin>>s;
            if(s[0]=='x' || s[0]=='X')break;
            else
                seach_choice=stoi(s);
            vector<string>map_alpha;
            map_alpha.clear();
            string str;
            if(!seach_choice)
            {
                cout<<"\nSearch Name : ";
                cin>>str;
                ll cnt=1;
                for(it=mp.begin(); it!=mp.end(); it++)
                {
                    string cmp=it->second,name;
                    ll i,ii;
                    for(ii=7; ii<cmp.size(); ii++)
                    {

                        for(i=0; i<str.size(); i++)
                        {
                            string k;
                            if(str[i]!=cmp[i+ii])
                            {
                                if(str[i]>='A' && str[i]<='Z')
                                {
                                    k+=str[i]+32;
                                    if(k[0]!=cmp[i+ii])break;
                                }
                                else if(str[i]>='a' && str[i]<='z')
                                {
                                    k+=str[i]-32;
                                    if(k[0]!=cmp[i+ii])break;
                                }
                            }
                        }
                        if(i==str.size())
                        {
                            for(ll j=7; j<cmp.size(); j++)name+=cmp[j];
                            map_alpha.pb(name);
                            break;
                        }

                    }
                }
                if(map_alpha.size()==0)
                {
                    cout<<"\nContact Not Found\n";
                }
                else
                {
                    sort(map_alpha.begin(),map_alpha.end());
                    cout<<'\n';
                    for(ll j=0; j<map_alpha.size(); j++)
                    {
                        cout<<j+1<<"."<<map_alpha[j]<<'\n';
                    }
                    ll index;
                    cout<<"\nChoose Index : ";
                    cin>>index;
                    chk="Name : "+map_alpha[index-1];
                }
            }
            else
            {
                it=mp.find(seach_choice);
                if(it!=mp.end())chk=it->second;
            }
            ll chk1=0,chk_cnt=0;
            string s2;
            cout<<"\n";
            while(getline(f2,s2))
            {
                if(chk==s2 || chk1)
                {
                    cout<<s2<<endl;
                    chk_cnt++;
                    if(chk_cnt==5)
                    {
                        cout<<"\n\n";
                        break;
                    }
                    chk1=1;
                }
            }
            cout<<"Want to view contact again (y/n) : ";
            ll br=break_function();
            if(br)break;
        }
        f2.close();
    }
}

//******* update directory *******//

void update_directory()
{
    for(;;)
    {
        system("cls");
        cout<<"\n\n              _______Update Contact_______\n\n\n\n\n";
        ll zero_cntkt=show_sub_directory();

        if(!zero_cntkt)
        {
            cout<<"There is no contact in the Directory.\n";
            cout<<"\nExit(y/n) : ";
            ll br1=break_function();
            if(!br1)break;
        }
        else
        {
            cout<<"\nPress 0 for search or enter index number for updating contact or press x to go back: ";
            //string chk=contact_name();
            string s,chk;
            ll search_choice,chk1=0;
            cin>>s;
            if(s[0]=='x' || s[0]=='X')break;
            else
                search_choice=stoi(s);
            vector<string>map_alpha;
            map_alpha.clear();
            string str;
            if(!search_choice)
            {
                cout<<"\nSearch Name : ";
                cin>>str;
                ll cnt=1;
                for(it=mp.begin(); it!=mp.end(); it++)
                {
                    string cmp=it->second,name;
                    ll i,ii;
                    for(ii=7; ii<cmp.size(); ii++)
                    {

                        for(i=0; i<str.size(); i++)
                        {
                            string k;
                            if(str[i]!=cmp[i+ii])
                            {
                                if(str[i]>='A' && str[i]<='Z')
                                {
                                    k+=str[i]+32;
                                    if(k[0]!=cmp[i+ii])break;
                                }
                                else if(str[i]>='a' && str[i]<='z')
                                {
                                    k+=str[i]-32;
                                    if(k[0]!=cmp[i+ii])break;
                                }
                            }
                        }
                        if(i==str.size())
                        {
                            for(ll j=7; j<cmp.size(); j++)name+=cmp[j];
                            map_alpha.pb(name);
                            break;
                        }
                    }

                }
                if(map_alpha.size()==0)
                {
                    cout<<"\nContact Not Found\n";
                    chk1=1;
                }
                else
                {
                    sort(map_alpha.begin(),map_alpha.end());
                    cout<<'\n';
                    for(ll j=0; j<map_alpha.size(); j++)
                    {
                        cout<<j+1<<"."<<map_alpha[j]<<'\n';
                    }
                    ll index;
                    cout<<"\nChoose Index : ";
                    cin>>index;
                    chk="Name : "+map_alpha[index-1];
                }
            }
            else
            {
                it=mp.find(search_choice);
                if(it!=mp.end())chk=it->second;
            }



            if(!chk1)
            {
                ifstream f2;
                f2.open("directory.txt");
                string s2;
                cout<<"\n";
                vector<string>v;
                ll cnt=0,chk2=0;

                system("cls");
                cout<<"\n\n              _______Update Contact_______\n\n\n\n\n";
                cout<<chk<<endl<<endl;

                cout<<"which one you want edit? \n\n1.Name\n\n2.Mobile\n\n3.E-mail\n\n4.Date of Birth\n\n5.Category\n\n";

                ll edn;
                cout<<"Enter number : ";
                cin>>edn;
                cout<<endl;

                while(getline(f2,s2))
                {
                    if(chk==s2 || (cnt>=0 && cnt<=4))
                    {
                        cnt++;
                        if(edn==cnt)
                        {
                            if(edn==1)
                            {
                                cout<<"Current "<<s2<<endl;
                                cout<<"First Name : ";
                                string name,s;
                                cin>>s;
                                name="Name : "+s+" ";
                                cout<<"Last Name : ";
                                cin>>s;
                                name+=s;
                                v.pb(name);
                            }
                            else if(edn==2)
                            {
                                cout<<"Current : "<<s2<<endl;
                                string name,s;
                                cout<<"Mobile number : ";
                                cin>>s;
                                name="Mobile : "+s;
                                v.pb(name);
                            }
                            else if(edn==3)
                            {
                                cout<<"Current "<<s2<<endl;
                                string name,s;
                                cout<<"E-mail : ";
                                cin>>s;
                                name="E-mail : "+s;
                                v.pb(name);
                            }
                            else if(edn==4)
                            {
                                cout<<"Current : "<<s2<<endl;
                                string name,s;
                                cout<<"Date of birth (dd-mm-yyyy) : ";
                                cin>>s;
                                name="Date of birth : "+s;
                                v.pb(name);
                            }
                            else if(edn==4)
                            {
                                cout<<"Current : "<<s2<<endl;
                                string name,s;
                                cout<<"Category : ";
                                cin>>s;
                                name="Category : "+s;
                                v.pb(name);
                            }
                        }
                        else
                            v.pb(s2);


                        chk2=1;
                    }
                    else
                        v.pb(s2);
                }
                f2.close();
                ofstream file2;
                file2.open("directory.txt");
                for(int i; i<v.size(); i++)
                {
                    file2<<v[i]<<endl;
                }
                file2.close();
                v.clear();
                if(!chk2)cout<<"Contact not found.\n";
                else
                    cout<<"Contact upadated\n";

                cout<<"\nWant to upadate another contact (y/n) : ";
                ll br=break_function();
                if(br)break;
            }
        }
    }
}

//******* Delete Directory *******//

void delete_directory()
{
    for(;;)
    {

        system("cls");
        cout<<"\n\n              _______Delete Contact_______\n\n\n\n\n";

        ll zero_cntkt=show_sub_directory();
        if(!zero_cntkt)
        {
            cout<<"There is no contact in the Directory.\n";
            cout<<"\nExit(y/n) : ";
            ll br1=break_function();
            if(!br1)break;
        }
        else
        {
            cout<<"\nPress 0 for search or enter index number for deleting contact or press x to go back: ";
            //string chk=contact_name();
            string s,chk;
            ll search_choice,chk1=0;
            cin>>s;
            if(s[0]=='x' || s[0]=='X')break;
            else
                search_choice=stoi(s);
            vector<string>map_alpha;
            map_alpha.clear();
            string str;
            if(!search_choice)
            {
                cout<<"\nSearch Name : ";
                cin>>str;
                ll cnt=1;
                for(it=mp.begin(); it!=mp.end(); it++)
                {
                    string cmp=it->second,name;
                    ll i,ii;
                    for(ii=7; ii<cmp.size(); ii++)
                    {

                        for(i=0; i<str.size(); i++)
                        {
                            string k;
                            if(str[i]!=cmp[i+ii])
                            {
                                if(str[i]>='A' && str[i]<='Z')
                                {
                                    k+=str[i]+32;
                                    if(k[0]!=cmp[i+ii])break;
                                }
                                else if(str[i]>='a' && str[i]<='z')
                                {
                                    k+=str[i]-32;
                                    if(k[0]!=cmp[i+ii])break;
                                }
                            }
                        }
                        if(i==str.size())
                        {
                            for(ll j=7; j<cmp.size(); j++)name+=cmp[j];
                            map_alpha.pb(name);
                            break;
                        }
                    }

                }
                if(map_alpha.size()==0)
                {
                    cout<<"\nContact Not Found\n";
                    chk1=1;
                }
                else
                {
                    sort(map_alpha.begin(),map_alpha.end());
                    cout<<'\n';
                    for(ll j=0; j<map_alpha.size(); j++)
                    {
                        cout<<j+1<<"."<<map_alpha[j]<<'\n';
                    }
                    ll index;
                    cout<<"\nChoose Index : ";
                    cin>>index;
                    chk="Name : "+map_alpha[index-1];
                }
            }
            else
            {
                it=mp.find(search_choice);
                if(it!=mp.end())chk=it->second;
            }




            if(!chk1)
            {
                ifstream f2;
                f2.open("directory.txt");
                string s2;
                cout<<"\n";
                vector<string>v;
                ll cnt=0,chk2=0;
                while(getline(f2,s2))
                {
                    if(chk==s2 || (cnt>=1 && cnt<=4))
                    {
                        cnt++;
                        chk2=1;
                    }
                    else
                        v.pb(s2);
                }
                f2.close();
                ofstream file2;
                file2.open("directory.txt");
                for(int i; i<v.size(); i++)
                {
                    file2<<v[i]<<endl;
                }
                file2.close();
                v.clear();
                if(!chk2)cout<<"Contact not found.\n";
                else
                    cout<<"contact deleted\n";

                cout<<"\nWant to delete another contact (y/n) : ";
                ll br=break_function();
                if(br)break;
            }
        }
    }
}

void directory()
{
    ll directory_choice;
    for(;;)
    {

        system("cls");
        cout<<"\n\n\n\n\n";
        cout<<"                     press 1 to create new contact : \n\n";
        cout<<"                     press 2 to view directory : \n\n";
        cout<<"                     press 3 to update directory : \n\n";
        cout<<"                     press 4 to delete contact : \n\n";
        cout<<"                     press 0 to exit : \n";

        cin>>directory_choice;

//******** create new directory *********//

        if(directory_choice==1)
        {
            create_new_directory();
        }

//******** view directory *********//

        else if(directory_choice==2)
        {
            view_directory();
        }

//******** update directory *******//

        else if(directory_choice==3)
        {
            update_directory();
        }

//******** delete directory *******//
        else if(directory_choice==4)
        {
            delete_directory();
        }
        else
            break;




        /*cout<<"\nwant to continue in directory(y/n) : ";
        ll br=break_function();
        if(br)break;
        //system("cls");*/
        system("cls");
        cout<<'\n';
    }
}
int main()
{

    while(1)
    {
        //system("cls");
        ll login_choice,check=0;
        ofstream file;
        file.open("account.txt",ios::out |ios::app);
        file.close();
        cout<<"\n\n\n............................Welcome to the Telephone Directory...........................\n\n\n\n\n\n";
        cout<<"1. Enter into Telephone Directory : \n\n"<<"2. Exit : \n\n";
        cin>>login_choice;

        if(login_choice==1)
        {

            directory();
        }

        else
        {
            break;
        }
        if(check)break;
        system("cls");
        cout<<'\n';
    }
}

