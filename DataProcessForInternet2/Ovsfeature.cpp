#include<iostream>
#include<fstream>

#include"utility.h"

using namespace std;

void DataPath_Process(ifstream &in,string switchid);
void DataUpcall_Process(ifstream &in,string switchid);
void TableTime_Process(ifstream &in,string switchid);
void UserUpcall_Process(ifstream &in,string switchid);
void Userspace_Process(ifstream &in,string switchid);

int main(int argc,char *argv[])//第一个参数是交换机的名称，第二个参数是 datapath_Gary文件路径，第三个参数是 datapath_upcall文件路径，第四个参数是 user_table_time
{                              //第五个参数是 user_upcall文件路径，第六个参数是 userspace文件路径 
	if(argc!=7)
	{
		cout<<"arguments number error"<<endl;
		return 0;
	}
	ifstream in_1(argv[2]),in_2(argv[3]),in_3(argv[4]),in_4(argv[5]),in_5(argv[6]);
	DataPath_Process(in_1,argv[1]);
	DataUpcall_Process(in_2,argv[1]);
	TableTime_Process(in_3,argv[1]);
	UserUpcall_Process(in_4,argv[1]);
	Userspace_Process(in_5,argv[1]);
}
void DataPath_Process(ifstream &in,string switchid)
{
	ofstream out("TODOdata/"+switchid+"_datapath_result.txt"),outtest("TODOdata/test.txt");
	string str;
	int fea1,fea2,fea3,fea4,fea5,fea6,fea7,fea8,fea9,fea10,fea11,sum=0,time,now,index=11;
	int nfea1,nfea2,nfea3,nfea4,nfea5,nfea6,nfea7,nfea8,nfea9,nfea10,nfea11,nsum;
	if(getline(in,str))
	{
		time=stoi(str.substr(0,10));Getsubstr(str,index);Getsubstr(str,index);Getsubstr(str,index);Getsubstr(str,index);
		fea1=stoi(Getsubstr(str,index));
		fea2=stoi(Getsubstr(str,index));
		sum=stoi(Getsubstr(str,index));
		fea3=stoi(Getsubstr(str,index));
		fea4=stoi(Getsubstr(str,index));
		fea5=stoi(Getsubstr(str,index));
		fea6=stoi(Getsubstr(str,index));
		fea7=stoi(Getsubstr(str,index));
		fea8=stoi(Getsubstr(str,index));
		fea9=stoi(Getsubstr(str,index));
		fea10=stoi(Getsubstr(str,index));
		fea11=stoi(Getsubstr(str,index));
	}
	outtest<<fea1<<","<<fea2<<","<<sum<<","<<fea3<<","<<fea4<<","<<fea5<<","<<fea6<<","<<fea7<<","<<fea8<<","<<fea9<<","<<fea10<<","<<fea11<<","<<endl;
	while(getline(in,str))
	{
		now=stoi(str.substr(0,10));
		index=11;Getsubstr(str,index);Getsubstr(str,index);Getsubstr(str,index);Getsubstr(str,index);
		nfea1=stoi(Getsubstr(str,index));
		nfea2=stoi(Getsubstr(str,index));
		nsum=stoi(Getsubstr(str,index));
		nfea3=stoi(Getsubstr(str,index));
		nfea4=stoi(Getsubstr(str,index));
		nfea5=stoi(Getsubstr(str,index));
		nfea6=stoi(Getsubstr(str,index));
		nfea7=stoi(Getsubstr(str,index));
		nfea8=stoi(Getsubstr(str,index));
		nfea9=stoi(Getsubstr(str,index));
		nfea10=stoi(Getsubstr(str,index));
		nfea11=stoi(Getsubstr(str,index));
		if(now==time)
		{
			sum+=nsum;
		}
		else
		{
			out<<time<<","<<nfea1-fea1<<","<<nfea2-fea2<<","<<sum<<","<<nfea3-fea3<<","<<nfea4-fea4<<","<<nfea5-fea5<<","<<nfea6-fea6<<","<<nfea7-fea7<< \
			","<<nfea8-fea8<<","<<nfea9-fea9<<","<<nfea10-fea10<<","<<nfea11-fea11<<endl;
			time=now;
			fea1=nfea1;
			fea2=nfea2;
			sum=nsum;
			fea3=nfea3;
			fea4=nfea4;
			fea5=nfea5;
			fea6=nfea6;
			fea7=nfea7;
			fea8=nfea8;
			fea9=nfea9;
			fea10=nfea10;
			fea11=nfea11;
			outtest<<fea1<<","<<fea2<<","<<sum<<","<<fea3<<","<<fea4<<","<<fea5<<","<<fea6<<","<<fea7<<","<<fea8<<","<<fea9<<","<<fea10<<","<<fea11<<","<<endl;
		}
	}
}
void DataUpcall_Process(ifstream &in,string switchid)
{
	ofstream out("TODOdata/"+switchid+"_dataupcall_result.txt");
	string str;
	int time,length,now,num=0,index=11;
	if(getline(in,str))
	{
		time=stoi(str.substr(0,10));Getsubstr(str,index);
		length=stoi(Getsubstr(str,index));
		num++;
	}
	while(getline(in,str))
	{
		now=stoi(str.substr(0,10));index=11;
		if(now==time)
		{
			Getsubstr(str,index);
			length+=stoi(Getsubstr(str,index));
			num++;
		}
		else
		{
			out<<time<<","<<num<<","<<float(length)/num<<endl;
			time=now;
			Getsubstr(str,index);
			length=stoi(Getsubstr(str,index));
			num=1;
		}
	}
}
void TableTime_Process(ifstream &in,string switchid)
{
	ofstream out("TODOdata/"+switchid+"_tabletime_result.txt");
	int time,table,num=0,now;
	string str;
	if(getline(in,str))
	{
		time=stoi(str.substr(0,10));
		table=stoi(str.substr(11,str.size()-11));
		num++;
	}
	while(getline(in,str))
	{
		now=stoi(str.substr(0,10));
		if(now==time)
		{
			table+=stoi(str.substr(11,str.size()-11));
			num++;
		}
		else
		{
			out<<time<<","<<float(table)/num<<endl;
			time=now;
			table=stoi(str.substr(11,str.size()-11));
			num=1;
		}
	}
}
void UserUpcall_Process(ifstream &in,string switchid)
{
	ofstream out("TODOdata/"+switchid+"_userupcall_result.txt");
	int time,upcall,num=0,now;
	string str;
	if(getline(in,str))
	{
		time=stoi(str.substr(0,10));
		upcall=stoi(str.substr(11,str.size()-11));
		num++;
	}
	while(getline(in,str))
	{
		now=stoi(str.substr(0,10));
		if(now==time)
		{
			upcall+=stoi(str.substr(11,str.size()-11));
			num++;
		}
		else
		{
			out<<time<<","<<float(upcall)/num<<endl;
			time=now;
			upcall=stoi(str.substr(11,str.size()-11));
			num=1;
		}
	}
}
void Userspace_Process(ifstream &in,string switchid)
{
	ofstream out("TODOdata/"+switchid+"_userspace_result.txt");
	string str;
	int time,now,index=11,revpkt,sendpkt,handler,hit,mainNum,item;
	int nrevpkt,nsendpkt,nhandler,nhit,nmainNum;
	if(getline(in,str))
	{
		time=stoi(str.substr(0,10));
		revpkt=stoi(Getsubstr(str,index));
		sendpkt=stoi(Getsubstr(str,index));
		handler=stoi(Getsubstr(str,index));
		hit=stoi(Getsubstr(str,index));
		stoi(Getsubstr(str,index));
		mainNum=stoi(Getsubstr(str,index));
	}
	while(getline(in,str))
	{
		now=stoi(str.substr(0,10));
		index=11;
		if(now!=time)
		{
			//cout<<time<<"   "<<str<<endl;
			nrevpkt=stoi(Getsubstr(str,index));
			nsendpkt=stoi(Getsubstr(str,index));
			nhandler=stoi(Getsubstr(str,index));
			nhit=stoi(Getsubstr(str,index));
			item=stoi(Getsubstr(str,index));
			nmainNum=stoi(Getsubstr(str,index));
		/*	out<<time<<","<<stoi(Getsubstr(str,index))<<" "<<revpkt<<","<<Getsubstr(str,index)<<" "<<sendpkt<<","<< \
			stoi(Getsubstr(str,index))<<" "<<handler<<","<<stoi(Getsubstr(str,index))<<" "<<hit<<","<<stoi(Getsubstr(str,index))<<","\
			<<stoi(Getsubstr(str,index))<<" "<<mainNum<<endl;*/
			out<<time<<","<<nrevpkt-revpkt<<","<<nsendpkt-sendpkt<<","<<nhandler-handler<<","<<nhit-hit<<","<<item<<","<<nmainNum-mainNum<<endl;
			
			time=now;
			revpkt=nrevpkt;
			sendpkt=nsendpkt;
			handler=nhandler;
			hit=nhit;
			mainNum=nmainNum;
		}
	}
}
