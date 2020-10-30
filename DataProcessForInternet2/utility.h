#include<iostream>
#include<string> 
#include<vector>
#include<sstream>
using namespace std;

struct OneFlow
{
	int pkt;
	int byte;
	int inport;
	int outport;
	int sip;
	int dip;
};
struct Flowtable
{
	int time;
	vector<OneFlow> flow;
};

bool Isnum(string s)  
{  
        stringstream sin(s);  
        double t;  
        char p;  
        if(!(sin >> t))   
            return false;  
        if(sin >> p)  
            return false;  
        else  
            return true;  
} 
int Find(Flowtable f,OneFlow of)//在流表中查询一条流，找到返回vector的下标，找不到返回-1 
{
	int i;
	for(i=0;i<f.flow.size();i++)
	{
		if(f.flow[i].sip==of.sip&&f.flow[i].dip==of.dip) return i;
	}
	return -1;
}
string Getsubstr(string str,int &i)
{
	string res="";
	for(;i<str.size();i++)
	{
		if(str[i]!=' ') res+=str[i];
		else break;
	}
	i++;
	if(Isnum(res)) return res;
	else return "0";
}
OneFlow ReadOneFlow(string str)
{
	OneFlow res;
	int index=11;
	res.sip=stoi(Getsubstr(str,index));
	res.dip=stoi(Getsubstr(str,index));
	res.inport=stoi(Getsubstr(str,index));
	res.outport=stoi(Getsubstr(str,index));
	res.pkt=stoi(Getsubstr(str,index));
	res.byte=stoi(Getsubstr(str,index));
	return res;
}


string GetNum(string str,int i)
{
	string res="";
	while(str[i]>='0'&&str[i]<='9')
	{
		res+=str[i];
		i++;
	}
	//cout<<res<<endl;
	return res;
}
