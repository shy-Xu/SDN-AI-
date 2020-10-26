#include<iostream>
#include<stdlib.h>//int atoi(char *p)char数组转int 
#include<vector>
#include<fstream>
#include<cstring>
#include<algorithm>

using namespace std;

const int LastTime=20*3600;

int main(int argc,char *argv[])//第一个参数是脚本开始时间，去三个脚本的最小值，接下来的5个参数为5个文件的路径 
{
	if(argc!=7)
	{
		cout<<"参数数目错误！"<<endl;
		return 0;
	} 
	int now=atoi(argv[1]);
	ifstream in1(argv[2]),in7(argv[3]),in9(argv[4]),in10(argv[5]),in12(argv[6]);
	ofstream out("resultdata/s1-s12.csv");
	int time1=0,time7=0,time9=0,time10=0,time12=0;
	int tag1=0,tag7=0,tag9=0,tag10=0,tag12=0;
	string str1,str7,str9,str10,str12;
	getline(in1,str1);getline(in7,str7);getline(in9,str9);getline(in10,str10);getline(in12,str12);
	time1=stoi(str1.substr(0,10));time7=stoi(str7.substr(0,10));time9=stoi(str9.substr(0,10));time10=stoi(str10.substr(0,10));time12=stoi(str12.substr(0,10));
	for(int i=0;i<LastTime;i++,now++)
	{
		
		if(now==time1){tag1=stoi(str1.substr(str1.size()-1));out<<str1.substr(11,str1.size()-12);if(getline(in1,str1))time1=stoi(str1.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time7){tag7=stoi(str7.substr(str7.size()-1));out<<str7.substr(11,str7.size()-12);if(getline(in7,str7))time7=stoi(str7.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time9){tag9=stoi(str9.substr(str9.size()-1));out<<str9.substr(11,str9.size()-12);if(getline(in9,str9))time9=stoi(str9.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time10){tag10=stoi(str10.substr(str10.size()-1));out<<str10.substr(11,str10.size()-12);if(getline(in10,str10))time10=stoi(str10.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time12){tag12=stoi(str12.substr(str12.size()-1));out<<str12.substr(11,str12.size()-12);if(getline(in12,str12))time12=stoi(str12.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(tag1)out<<"1,";else out<<"0,";
		if(tag7)out<<"1,";else out<<"0,";
		if(tag9)out<<"1,";else out<<"0,";
		if(tag10)out<<"1,";else out<<"0,";
		if(tag12)out<<"1";else out<<"0";
		out<<endl;
	}
	return 0;
}
