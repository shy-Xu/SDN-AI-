#include<iostream>
#include<stdlib.h>//int atoi(char *p)char数组转int 
#include<vector>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<set>

#include"linkflowpkt.h"

using namespace std;

const int LastTime=20*3600;

vector<int> GetLabel(int begin,char *path);
void Link(vector<int> tag,int time,string ppath,string fpath,string switchid,string datapath,string upcallpath,string tabletimepath,string userpath,string spacepath);
void PrintColumName(ofstream &out)//在文件的第一行输出列名 
{
	out<<"time,S15_SendPacket,S15_ReceivePacket,S15_SendByte,S15_ReceiveByte,S15_AvgLength,S15_IPEntropy,S15_PortEntropy,S15_Mid,S15_IPRate,S15_PktNum,S15_PktRate,\
	S15_HitTable,S15_HitFailure,S15_FindFlowms,S15_OFCSNum,S15_OFCGNum,S15_OFCDNum,S15_OEANum,S15_HitMask,S15_FindMask,S15_HitFlowkey,S15_FindFlowkey,\
	S15_OPCENum,S15_UpcallNum,S15_UpcallLength,S15_FindUserFlow,S15_UpcallDelay,S15_RevPkt,S15_SendPkt,S15_UUHNum,S15_HitUserFlow,S15_UserTableItem,S15_MainNum,S15_Tag"<<endl;
}

int main(int argc,char *argv[])//第一个参数是脚本开始执行时间，第二个参数是labels文件的路径, 第三个参数是packetin文件的路径, 第四个参数是flowtable文件的路径 
{							   //第五个是交换机id。第六个是datapath_Gary文件路径，第七个参数是 datapath_upcall文件路径，第八个参数是 user_table_time 文件路径
 							   //第九个参数是 user_upcall文件路径，第十个参数是 userspace文件路径 
	if(argc!=11) return 0;
	vector<int> TLable=GetLabel(atoi(argv[1]),argv[2]);
	Link(TLable,atoi(argv[1]),argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10]);
	//packerin的处理
	
} 
void Link(vector<int> tag,int time,string ppath,string fpath,string switchid,string datapath,string upcallpath,string tabletimepath,string userpath,string spacepath)
{
	ifstream pin(ppath),fin(fpath),in_fea1(datapath),in_fea2(upcallpath),in_fea3(tabletimepath),in_fea4(userpath),in_fea5(spacepath);
	ofstream out("resultdata/"+switchid+"_final_out.csv");
	if(switchid=="s15") PrintColumName(out); 
	string pstr,fstr,str_fea1,str_fea2,str_fea3,str_fea4,str_fea5;
	int ptime,ftime,now=time,time_fea1,time_fea2,time_fea3,time_fea4,time_fea5;
	getline(pin,pstr);getline(fin,fstr);getline(in_fea1,str_fea1);getline(in_fea2,str_fea2);getline(in_fea3,str_fea3);getline(in_fea4,str_fea4);getline(in_fea5,str_fea5);
	ptime=stoi(pstr.substr(0,10));
	ftime=stoi(fstr.substr(0,10));
	time_fea1=stoi(str_fea1.substr(0,10));
	time_fea2=stoi(str_fea2.substr(0,10));
	time_fea3=stoi(str_fea3.substr(0,10));
	time_fea4=stoi(str_fea4.substr(0,10));
	time_fea5=stoi(str_fea5.substr(0,10));
	while(ptime<time)
	{
		if(getline(pin,pstr))ptime=stoi(pstr.substr(0,10));
	}
	while(ftime<time)
	{
		if(getline(fin,fstr))ftime=stoi(fstr.substr(0,10));
	}
	while(time_fea1<time)
	{
		if(getline(in_fea1,str_fea1))time_fea1=stoi(str_fea1.substr(0,10));
	}
	while(time_fea2<time)
	{
		if(getline(in_fea2,str_fea2))time_fea2=stoi(str_fea2.substr(0,10));
	}
	while(time_fea3<time)
	{
		if(getline(in_fea3,str_fea3))time_fea3=stoi(str_fea3.substr(0,10));
	}
	while(time_fea4<time)
	{
		if(getline(in_fea4,str_fea4))time_fea4=stoi(str_fea4.substr(0,10));
	}
	while(time_fea5<time)
	{
		if(getline(in_fea5,str_fea5))time_fea5=stoi(str_fea5.substr(0,10));
	}
	
	for(int i=0;i<LastTime;i++,now++)
	{
		out<<now;
		if(now==ftime) {out<<","<<fstr.substr(11);if(getline(fin,fstr))ftime=stoi(fstr.substr(0,10));}
		else out<<",-1,-1,-1,-1,-1,-1,-1,-1,-1";
		if(now==ptime) {out<<","<<pstr.substr(11);if(getline(pin,pstr))ptime=stoi(pstr.substr(0,10));}
		//输出默认值 
		else out<<",-1,-1";
		if(now==time_fea1){out<<","<<str_fea1.substr(11);if(getline(in_fea1,str_fea1))time_fea1=stoi(str_fea1.substr(0,10));}
		else out<<",-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1";
		if(now==time_fea2){out<<","<<str_fea2.substr(11);if(getline(in_fea2,str_fea2))time_fea2=stoi(str_fea2.substr(0,10));}
		else out<<",-1,-1";
		if(now==time_fea3){out<<","<<str_fea3.substr(11);if(getline(in_fea3,str_fea3))time_fea3=stoi(str_fea3.substr(0,10));}
		else out<<",-1";
		if(now==time_fea4){out<<","<<str_fea4.substr(11);if(getline(in_fea4,str_fea4))time_fea4=stoi(str_fea4.substr(0,10));}
		else out<<",-1";
		if(now==time_fea5){out<<","<<str_fea5.substr(11);if(getline(in_fea5,str_fea5))time_fea5=stoi(str_fea5.substr(0,10));}
		else out<<",-1,-1,-1,-1,-1,-1";
		if(find(tag.begin(),tag.end(),now)!=tag.end())out<<",1"<<endl;
		else out<<",0"<<endl;
	}
}
vector<int> GetLabel(int begin,char *path)//第一个参数是脚本开始执行时间，第二个参数是labels文件的路径。 
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
	//对向量A中的元素去重 
	set<int> tempS(A.begin(),A.end());
	A.assign(tempS.begin(),tempS.end());
	return A;
}
