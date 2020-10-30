#include<iostream>
#include<stdlib.h>//int atoi(char *p)char数组转int 
#include<vector>
#include<fstream>
#include<cstring>
#include<algorithm>

using namespace std;

const int LastTime=20*3600;
void PrintColumName(ofstream &out)//在文件的第一行输出列名 
{
	out<<"S1_ReceivePacket,S1_SendPacket,S1_ReceiveByte,S1_SendByte,S1_AvgLength,S1_IPEntropy,S1_PortEntropy,S1_Mid,S1_IPRate,S1_PktNum,S1_PktRate,\
	S1_HitTable,S1_HitFailure,S1_FindFlowms,S1_OFCSNum,S1_OFCGNum,S1_OFCDNum,S1_OEANum,S1_HitMask,S1_FindMask,S1_HitFlowkey,S1_FindFlowkey,\
	S1_OPCENum,S1_UpcallNum,S1_UpcallLength,S1_FindUserFlow,S1_UpcallDelay,S1_RevPkt,S1_SendPkt,S1_UUHNum,S1_HitUserFlow,S1_UserTableItem,S1_MainNum,\
	\
	S7_ReceivePacket,S7_SendPacket,S7_ReceiveByte,S7_SendByte,S7_AvgLength,S7_IPEntropy,S7_PortEntropy,S7_Mid,S7_IPRate,S7_PktNum,S7_PktRate,\
	S7_HitTable,S7_HitFailure,S7_FindFlowms,S7_OFCSNum,S7_OFCGNum,S7_OFCDNum,S7_OEANum,S7_HitMask,S7_FindMask,S7_HitFlowkey,S7_FindFlowkey,\
	S7_OPCENum,S7_UpcallNum,S7_UpcallLength,S7_FindUserFlow,S7_UpcallDelay,S7_RevPkt,S7_SendPkt,S7_UUHNum,S7_HitUserFlow,S7_UserTableItem,S7_MainNum,\
	\
	S9_ReceivePacket,S9_SendPacket,S9_ReceiveByte,S9_SendByte,S9_AvgLength,S9_IPEntropy,S9_PortEntropy,S9_Mid,S9_IPRate,S9_PktNum,S9_PktRate,\
	S9_HitTable,S9_HitFailure,S9_FindFlowms,S9_OFCSNum,S9_OFCGNum,S9_OFCDNum,S9_OEANum,S9_HitMask,S9_FindMask,S9_HitFlowkey,S9_FindFlowkey,\
	S9_OPCENum,S9_UpcallNum,S9_UpcallLength,S9_FindUserFlow,S9_UpcallDelay,S9_RevPkt,S9_SendPkt,S9_UUHNum,S9_HitUserFlow,S9_UserTableItem,S9_MainNum,\
	\
	S10_ReceivePacket,S10_SendPacket,S10_ReceiveByte,S10_SendByte,S10_AvgLength,S10_IPEntropy,S10_PortEntropy,S10_Mid,S10_IPRate,S10_PktNum,S10_PktRate,\
	S10_HitTable,S10_HitFailure,S10_FindFlowms,S10_OFCSNum,S10_OFCGNum,S10_OFCDNum,S10_OEANum,S10_HitMask,S10_FindMask,S10_HitFlowkey,S10_FindFlowkey,\
	S10_OPCENum,S10_UpcallNum,S10_UpcallLength,S10_FindUserFlow,S10_UpcallDelay,S10_RevPkt,S10_SendPkt,S10_UUHNum,S10_HitUserFlow,S10_UserTableItem,S10_MainNum,\
	\
	S12_ReceivePacket,S12_SendPacket,S12_ReceiveByte,S12_SendByte,S12_AvgLength,S12_IPEntropy,S12_PortEntropy,S12_Mid,S12_IPRate,S12_PktNum,S12_PktRate,\
	S12_HitTable,S12_HitFailure,S12_FindFlowms,S12_OFCSNum,S12_OFCGNum,S12_OFCDNum,S12_OEANum,S12_HitMask,S12_FindMask,S12_HitFlowkey,S12_FindFlowkey,\
	S12_OPCENum,S12_UpcallNum,S12_UpcallLength,S12_FindUserFlow,S12_UpcallDelay,S12_RevPkt,S12_SendPkt,S12_UUHNum,S12_HitUserFlow,S12_UserTableItem,S12_MainNum,\
	S1_Tag,S7_Tag,S9_Tag,S10_Tag,S12_Tag"<<endl;
} 
int main(int argc,char *argv[])//第一个参数是脚本开始时间，取三个脚本的最小值，接下来的5个参数为5个文件的路径 
{
	if(argc!=7)
	{
		cout<<"参数数目错误！"<<endl;
		return 0;
	} 
	int now=atoi(argv[1]);
	ifstream in1(argv[2]),in7(argv[3]),in9(argv[4]),in10(argv[5]),in12(argv[6]);
	ofstream out("resultdata/s1-s12.csv");
	PrintColumName(out); 
	int time1=0,time7=0,time9=0,time10=0,time12=0;
	int tag1=0,tag7=0,tag9=0,tag10=0,tag12=0;
	string str1,str7,str9,str10,str12;
	getline(in1,str1);getline(in7,str7);getline(in9,str9);getline(in10,str10);getline(in12,str12);
	time1=stoi(str1.substr(0,10));time7=stoi(str7.substr(0,10));time9=stoi(str9.substr(0,10));time10=stoi(str10.substr(0,10));time12=stoi(str12.substr(0,10));
	for(int i=0;i<LastTime;i++,now++)
	{
		
		if(now==time1){tag1=stoi(str1.substr(str1.size()-1));out<<str1.substr(11,str1.size()-12);if(getline(in1,str1))time1=stoi(str1.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time7){tag7=stoi(str7.substr(str7.size()-1));out<<str7.substr(11,str7.size()-12);if(getline(in7,str7))time7=stoi(str7.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time9){tag9=stoi(str9.substr(str9.size()-1));out<<str9.substr(11,str9.size()-12);if(getline(in9,str9))time9=stoi(str9.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time10){tag10=stoi(str10.substr(str10.size()-1));out<<str10.substr(11,str10.size()-12);if(getline(in10,str10))time10=stoi(str10.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(now==time12){tag12=stoi(str12.substr(str12.size()-1));out<<str12.substr(11,str12.size()-12);if(getline(in12,str12))time12=stoi(str12.substr(0,10));}
		else out<<"-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,";
		if(tag1)out<<"1,";else out<<"0,";
		if(tag7)out<<"1,";else out<<"0,";
		if(tag9)out<<"1,";else out<<"0,";
		if(tag10)out<<"1,";else out<<"0,";
		if(tag12)out<<"1";else out<<"0";
		out<<endl;
	}
	return 0;
}
