#include<iostream>
#include<stdlib.h>//int atoi(char *p)char����תint 
#include<vector>
#include<fstream>
#include<cstring>
#include<algorithm>

#include"TODO1.h"

using namespace std;

const int LastTime=20*3600;

vector<int> GetLabel(int begin,char *path);
void Link(vector<int> tag,string ppath,string fpath,int time,string switchid);

int main(int argc,char *argv[])//��һ�������ǽű���ʼִ��ʱ�䣬�ڶ���������labels�ļ���·��, ������������packetin�ļ���·��, ���ĸ�������flowtable�ļ���·��,������ǽ�����id�� 
{
	//���ݱ�ǩ�Ĵ��� 
	/*if(argc!=3) return 0;
	else
	{
		int BeginTime10=atoi(argv[1]);
		int BeginTime12=atoi(argv[2]);
	} 
	vector<int> TLable15,TLable12,TLable10,TLable1,TLable7,TLable9; 
	TLable10=GetLabel(BeginTime10,"field4_lable.txt");
	TLable12=GetLabel(BeginTime12,"field5_lable.txt");
	TLable15=TLable10;TLable15.insert(TLable15.end(),TLable12.begin(),TLable12.end());sort(TLable15.begin(),TLable15.end());*/
	if(argc!=6) return 0;
	vector<int> TLable10=GetLabel(atoi(argv[1]),argv[2]);
	Link(TLable10,argv[3],argv[4],atoi(argv[1]),argv[5]);
	//packerin�Ĵ���
	
} 
void Link(vector<int> tag,string ppath,string fpath,int time,string switchid)
{
	ifstream pin(ppath),fin(fpath);
	ofstream out("resultdata/"+switchid+"_final_out.csv");
	string pstr,fstr;
	int ptime,ftime,now=time;
	getline(pin,pstr);getline(fin,fstr);;
	ptime=stoi(pstr.substr(0,10));
	ftime=stoi(fstr.substr(0,10));
	while(ptime<time)
	{
		if(getline(pin,pstr))ptime=stoi(pstr.substr(0,10));
	}
	while(ftime<time)
	{
		if(getline(fin,fstr))ftime=stoi(fstr.substr(0,10));
	}
	for(int i=0;i<LastTime;i++,now++)
	{
		out<<now;
		if(now==ftime) {out<<","<<fstr.substr(11);if(getline(fin,fstr))ftime=stoi(fstr.substr(0,10));}
		else out<<",-1,-1,-1,-1,-1,-1,-1,-1,-1";
		if(now==ptime) {out<<","<<pstr.substr(11);if(getline(pin,pstr))ptime=stoi(pstr.substr(0,10));}
		//���Ĭ��ֵ 
		else out<<",-1,-1";
		if(find(tag.begin(),tag.end(),now)!=tag.end())out<<",1"<<endl;
		else out<<",0"<<endl;
	}
}
vector<int> GetLabel(int begin,char *path)//��һ�������ǽű���ʼִ��ʱ�䣬�ڶ���������labels�ļ���·���� 
{
	vector<int> A;
	ifstream in(path);
	for(string str="";getline(in,str);)
	{
		if(str.length()<=10)
		{
			A.push_back(stoi(str)+begin);
		}
		else
		{
			A.push_back(stoi(str.substr(0,10))+begin);
		}
	}
	return A;
}
