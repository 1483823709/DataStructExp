#include "iostream"
#include "string"
#include "DLinkedList.h"
#include "windows.h"
#include "fstream"
using namespace std;

class Person{
public:
    string name;
    string road;
    string city;
    string nation;
    string phone;
    Person(){};
    Person(string name,string road,string city,string nation,string phone){
        this->name=name;
        this->road=road;
        this->city=city;
        this->nation=nation;
        this->phone=phone;
    }
};

DLinkedList<Person> d;

void Menu(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"��ӭ����ͨѶ¼����ϵͳ��"<<endl;
    cout<<"1��������Ϣ"<<endl;
    cout<<"2����ʾ��Ϣ"<<endl;
    cout<<"3��������������"<<endl;
    cout<<"4��ɾ����Ϣ"<<endl;
    cout<<"5����Ϣ�洢������"<<endl;
    cout<<"6����Ϣ���ļ�����"<<endl;
    cout<<"7���˳�ϵͳ"<<endl;
    cout<<"8�������������"<<endl;
    cout<<"____________________________________________________________"<<endl;
}
void Input(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"�������������ֵ������У����ң��绰���룬�ÿո���ָ�"<<endl;
    cout<<"��������Ϣ��"<<endl;
    string name,road,city,nation,phone;
    cin>>name>>road>>city>>nation>>phone;
    Person p=*new Person(name,road,city,nation,phone);
    bool isRepeat=false;
    for(int i=1;i<=d.length;i++){
        Person p1=d.get(i);
        if(p1.name==p.name){
            isRepeat=true;
            break;
        }
    }
    if(isRepeat){
        cout<<"ͬ����¼�Ѵ���"<<endl;
    }else{
        d.add(p);
        cout<<"��ӳɹ���"<<endl;
    }
    cout<<"____________________________________________________________"<<endl;
    Sleep(1000);
    system("cls");
    Sleep(300);
}
void PrintAll(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"����          �ֵ�          ����          ����          �ֻ���          "<<endl;
    for(int i=1;i<=d.length;i++){
        Person p=d.get(i);
        printf("%-14s%-14s%-14s%-14s%-14s\n",p.name.c_str(),p.road.c_str(),p.city.c_str(),p.nation.c_str(),p.phone.c_str());
    }
    cout<<"____________________________________________________________"<<endl;
    system("pause");
}
void Search(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"������Ҫ��ѯ������"<<endl;
    string name;
    cin>>name;
    bool find=false;
    Person p;
    for(int i=1;i<=d.length;i++){
        p=d.get(i);
        if(name==p.name){
            find=true;
            break;
        }
    }
    if(find){
        cout<<"���ǲ���Ҫ�ң�"<<endl;
        cout<<"������"<<p.name<<endl;
        cout<<"�ֵ���"<<p.road<<endl;
        cout<<"���У�"<<p.city<<endl;
        cout<<"���ң�"<<p.nation<<endl;
        cout<<"�ֻ��ţ�"<<p.phone<<endl;
        cout<<"____________________________________________________________"<<endl;
        system("pause");
    }else{
        cout<<"��Ҫ�ҵ��˲�����"<<endl;
        Sleep(3000);
    }
}
void Delete(){
    cout<<"____________________________________________________________"<<endl;
    cout<<"������Ҫɾ��������"<<endl;
    string name;
    cin>>name;
    bool find=false;
    Person p;
    int position=0;
    for(int i=1;i<=d.length;i++){
        p=d.get(i);
        if(name==p.name){
            find=true;
            position=i;
            break;
        }
    }
    if(find){
        cout<<"���ǲ���Ҫɾ����"<<endl;
        cout<<"������"<<p.name<<endl;
        cout<<"�ֵ���"<<p.road<<endl;
        cout<<"���У�"<<p.city<<endl;
        cout<<"���ң�"<<p.nation<<endl;
        cout<<"�ֻ��ţ�"<<p.phone<<endl;
        cout<<"���ٴ�ȷ���Ƿ�ɾ��y(Yes)  ����(No)"<<endl;
        char option;
        cin>>option;
        if(option=='y'){
            d.remove(position);
            cout<<"ɾ���ɹ���"<<endl;
        }else{
            cout<<"��ȡ���˲���"<<endl;
        }
    }else{
        cout<<"��Ҫɾ�����˲�����"<<endl;
    }
    cout<<"____________________________________________________________"<<endl;
    system("pause");
}
void Save(){
    cout<<"____________________________________________________________"<<endl;
    ofstream wFile("SavedFile.txt",ios::out);
    if(!wFile){
        cerr<<"�ļ�д��ʧ�ܣ��������д��Ȩ�޻���̻���!"<<endl;
    }else{
        for(int i=1;i<=d.length;i++){
            Person p=d.get(i);
            wFile<<p.name<<" "<<p.road<<" "<<p.city<<" "<<p.nation<<" "<<p.phone<<endl;
        }
        cout<<"�ѱ���"<<d.length<<"������"<<endl;
    }
    system("pause");
}
void InputFromFile(){
    cout<<"____________________________________________________________"<<endl;
    ifstream rFile("SavedFile.txt",ios::in);
    if(!rFile){
        cerr<<"�ļ���ȡʧ�ܣ���������ȡȨ�޻���̻���!"<<endl;
    }else{
        int i=0;
        for(;;i++){
            string name;
            string road;
            string city;
            string nation;
            string phone;
            rFile>>name>>road>>city>>nation>>phone;
            if(name==""){
                break;
            }
            Person p(name,road,city,nation,phone);
            d.add(p);
        }
        cout<<"�Ѷ�ȡ"<<i<<"����¼"<<endl;
        system("pause");
    }
}
void Clear(){
    cout<<"____________________________________________________________"<<endl;
    string confirm1;
    cout<<"��ȷ��Ҫ���������Ϣ��? y(YES) ����(NO)"<<endl;
    cin>>confirm1;
    if(confirm1!="y"){
        cout<<"�û�ȡ������"<<endl;
        return;
    }
    string confirm2;
    cout<<"\033[33;1m����ȷ�ϣ���ȷ��Ҫ���������Ϣ��? y(YES) ����(NO)\033[0m"<<endl;
    cin>>confirm2;
    if(confirm1!="y"){
        cout<<"�û�ȡ������"<<endl;
        return;
    }
    string confirm3;
    cout<<"\033[31;1m����ȷ�ϣ���ȷ��Ҫ���������Ϣ��? y(YES) ����(NO)\033[0m"<<endl;
    cin>>confirm3;
    if(confirm1!="y"){
        cout<<"�û�ȡ������"<<endl;
        return;
    }
    int size=d.length;
    d.clear();
    cout<<"�ɹ����"<<size<<"������"<<endl;
    Sleep(3000);
}
int main(){
    while(true){
        system("cls");
        Menu();
        int choose;
        cin>>choose;
        switch (choose) {
            case 1:
                system("cls");
                Input();
                break;
            case 2:
                system("cls");
                PrintAll();
                break;
            case 3:
                system("cls");
                Search();
                break;
            case 4:
                system("cls");
                Delete();
                break;
            case 5:
                system("cls");
                Save();
                break;
            case 6:
                system("cls");
                InputFromFile();
                break;
            case 7:
                system("cls");
                cout<<"��л����ʹ��"<<endl;
                system("pause");
                exit(0);
            case 8:
                system("cls");
                Clear();
                break;
            default:
                system("cls");
                cerr<<"�������ָ����������������"<<endl;
                system("pause");
                break;
        }
    }
}