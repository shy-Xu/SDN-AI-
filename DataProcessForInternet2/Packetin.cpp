#include<iostream>
#include<fstream>
using namespace std;

void PacketinProcess(string path,string switchid);

int main(int argc,char *argv[])
{
	if(argc!=3) return 0;
	PacketinProcess(argv[1],argv[2]);
	return 0;
}

void PacketinProcess(string path,string switchid)
{
	ifstream in(path);
	ofstream out("TODOdata/"+switchid+"_packetin_result.txt");
	int oldt,newt;
	float oldc=0,newc=0;
	string str;
	if(getline(in,str))
	{
		oldt=stoi(str.substr(5,10));
		newc=1;
	}
	
	for(string str;getline(in,str);)
	{
		newt=stoi(str.substr(5,10));
		if(newt==oldt) newc++;
		else 
		{
			if(oldc!=0)
			{
				out<<oldt<<","<<newc<<","<<newc/oldc<<endl;
			}
			oldc=newc;
			oldt=newt;
			newc=1;
		}
	}
}
