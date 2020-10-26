struct RowData
{
	int time=0;
	int Sendpkt=-1;
	int SendByte=-1;
	int Revpkt=-1;
	int RevByte=-1;
	int PktNum=-1;
	double PktNumRate=-1;
	double AvgLength=-1;
	double IPEntropy=-1;
	double PortEntropy=-1;
	int ByteMid=-1;
	double IPRate=-1;
	int tag=0;//1ÊÇ¹¥»÷£¬0ÊÇ²»¹¥»÷ 
};
void initRowData(RowData &obj)
{
	obj.Sendpkt=-1;
	obj.SendByte=-1;
	obj.Revpkt=-1;
	obj.RevByte=-1;
	obj.PktNum=-1;
	obj.PktNumRate=-1;
	obj.AvgLength=-1;
	obj.IPEntropy=-1;
	obj.PortEntropy=-1;
	obj.ByteMid=-1;
	obj.IPRate=-1;
}
