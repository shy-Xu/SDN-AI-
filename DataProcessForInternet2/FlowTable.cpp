#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<cmath>
#include<algorithm>

#include"utility.h"
using namespace std;

OneFlow GetOneFlow(string str); 
string PreProcess(string path,string switchid); //返回数据输出文件的路径 
void TableProcess(string path,string switchid); 

int main(int argc,char *argv[])
{
    if(argc!=3) return 0;
    string path=PreProcess(argv[1],argv[2]);
    TableProcess(path,argv[2]);
    return 0;
}
void TableProcess(string path,string switchid)
{
	ifstream in(path);
	string outpath="TODOdata/"+switchid+"_flow_result.txt";
	ofstream out(outpath);
	vector<OneFlow> VFlow;
	OneFlow tmpf;
	string str;
	int time=0,newtime;	
	float oldip=-1;
	//初始状态 
	getline(in,str);
	time=stoi(str.substr(0,10));	
	tmpf=ReadOneFlow(str);
	VFlow.push_back(tmpf);
	
	for(;getline(in,str);)
	{
		newtime=stoi(str.substr(0,10));
		tmpf=ReadOneFlow(str);
		if(newtime!=time)//计算并输出
		{
			int Sendpkt=0,Revpkt=0,SendB=0,RevB=0;
			float IPE=0,mid,IPrate=0,avg=0;
			vector<int> PakcetByte,IPNum;
			//收发数据包和字节 
			for(int i=0;i<VFlow.size();i++)
			{
				PakcetByte.push_back(VFlow[i].byte);
				if(VFlow[i].sip==192) {Revpkt+=VFlow[i].pkt;RevB+=VFlow[i].byte;}
				if(VFlow[i].dip==192) {Sendpkt+=VFlow[i].pkt;SendB+=VFlow[i].byte;IPNum.push_back(VFlow[i].pkt);}
			}
			//IP地址熵 
			for(int i=0;i<IPNum.size();i++)
			{
				float p=float(IPNum[i])/Sendpkt;
				IPE-=p*(log(p)/log(2));
			}
			//字节数中位数 
			sort(PakcetByte.begin(),PakcetByte.end());
			if(PakcetByte.size()%2==0) mid=(float(PakcetByte[PakcetByte.size()/2])+PakcetByte[PakcetByte.size()/2-1])/2;
			else mid=PakcetByte[PakcetByte.size()/2];
			//源IP地址增长率 
			if(oldip!=0&&oldip!=-1)IPrate=IPNum.size()/oldip;
			else if(oldip==0)IPrate=IPNum.size();
			//平均长度 
			if(Sendpkt!=0) avg=float(SendB)/Sendpkt;
			//输出到文件中 
			out<<time<<","<<Revpkt<<","<<Sendpkt<<","<<RevB<<","<<SendB<<","<<avg<<","<<IPE<<","<<IPE<<","<<mid<<","<<IPrate<<endl;
			//新值替代旧值 
			oldip=IPNum.size();time=newtime; 
			VFlow.clear();PakcetByte.clear();IPNum.clear();	
		}
		VFlow.push_back(tmpf);
	}
}

//一下模块对流表数据进行预处理，得到关键的数据并保存到文件中 
OneFlow GetOneFlow(string str)
{
	int cnt=0;
	OneFlow res;
//	cout<<"dfs";
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='=')
		{
			cnt++;
			switch(cnt)
			{
				case 4:res.pkt=stoi(GetNum(str,i+1));break;
				case 5:res.byte=stoi(GetNum(str,i+1));break;
				case 9:res.inport=stoi(GetNum(str,i+1));break;
				case 10:res.sip=stoi(GetNum(str,i+1));break;
				case 11:res.dip=stoi(GetNum(str,i+1));break;
				case 12:res.outport=stoi(GetNum(str,i+8));break;
			}
		}
	}
	return res;
}
Flowtable GetFlowtable(ifstream &in)
{
	Flowtable f;
	OneFlow tmpf;
	for(string str;getline(in,str);)
	{
		if(Isnum(str))//新时刻的流表到来 
		{
			f.time=stoi(str.substr(0,10));
			getline(in,str);getline(in,str);//两行没用的数据 
			getline(in,str);
		}
		int i=0,res=0;
		for(;i<str.size();i++)
		{
			if(str[i]=='=') res++;
		}
		if(res==12) tmpf=GetOneFlow(str);//标准的流表中有12个等号 
		else break;//最后一条流表 
		f.flow.push_back(tmpf);
	}
	return f; 
}
string PreProcess(string path,string switchid)
{
	ifstream in(path);
	string outpath="TODOdata/"+switchid+"_pre_flow_result.txt";
	ofstream out(outpath);
	Flowtable oldf,newf;
	OneFlow tmpf;
	int index;
	
	if(!in.eof()) newf=GetFlowtable(in);
	while(!in.eof())
	{
		oldf=newf;
		newf=GetFlowtable(in);
		for(int i=0;i<newf.flow.size();i++)
		{
			index=Find(oldf,newf.flow[i]);
			if(index==-1)
			{
				if(newf.flow[i].pkt!=0)
				out<<oldf.time<<" "<<newf.flow[i].sip<<" "<<newf.flow[i].dip<<" "<<newf.flow[i].inport<<" " \
				<<newf.flow[i].outport<<" "<<newf.flow[i].pkt<<" "<<newf.flow[i].byte<<endl;
			}
			else
			{
				if(newf.flow[i].pkt-oldf.flow[index].pkt!=0)
				out<<oldf.time<<" "<<newf.flow[i].sip<<" "<<newf.flow[i].dip<<" "<<newf.flow[i].inport<<" " \
				<<newf.flow[i].outport<<" "<<newf.flow[i].pkt-oldf.flow[index].pkt<<" "<<newf.flow[i].byte-oldf.flow[index].byte<<endl;
			}
		}
	}
	return outpath;
}
