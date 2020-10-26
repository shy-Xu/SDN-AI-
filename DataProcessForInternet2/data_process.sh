#！/bin/bash

right2time=1603447185 #s1 s7
left3time=1603447353 #s9 s10
left5time=1603447299 # s12 s15

tag1path=../labels/labels/field1_lable.txt
tag7path=../labels/labels/field2_lable.txt
tag9path=../labels/labels/field3_lable.txt
tag10path=../labels/labels/field4_lable.txt
tag12path=../labels/labels/field5_lable.txt
tag15path=../labels/labels/field6_lable.txt

flow1path=../dataJ/s1_2020-10-23_rtxpacket.txt
flow7path=../dataJ/s7_2020-10-23_rtxpacket.txt
flow9path=../dataJ/s9_2020-10-23_rtxpacket.txt
flow10path=../dataJ/s10_2020-10-23_rtxpacket.txt
flow12path=../dataJ/s12_2020-10-23_rtxpacket.txt
flow15path=../dataJ/s15_2020-10-23_rtxpacket.txt

packet1path=../dataJ/packetIn/openflow_1_pktin.txt
packet7path=../dataJ/packetIn/openflow_7_pktin.txt
packet9path=../dataJ/packetIn/openflow_9_pktin.txt
packet10path=../dataJ/packetIn/openflow_10_pktin.txt
packet12path=../dataJ/packetIn/openflow_12_pktin.txt
packet15path=../dataJ/packetIn/openflow_15_pktin.txt

./Packetin.out $packet1path s1
./Packetin.out $packet7path s7
./Packetin.out $packet9path s9
./Packetin.out $packet10path s10
./Packetin.out $packet12path s12
./Packetin.out $packet15path s15
echo "step1_over"
./FlowTable.out $flow1path s1
echo "s1_step2_over"
./FlowTable.out $flow7path s7
echo "s7_step2_over"
./FlowTable.out $flow9path s9
echo "s9_step2_over"
./FlowTable.out $flow10path s10
echo "s10_step2_over"
./FlowTable.out $flow12path s12
echo "s12_step2_over"
./FlowTable.out $flow15path s15
echo "s15_step2_over"
./link.out $right2time $tag1path TODOdata/s1_packetin_result.txt TODOdata/s1_flow_result.txt s1
./link.out $right2time $tag7path TODOdata/s7_packetin_result.txt TODOdata/s7_flow_result.txt s7
./link.out $left3time $tag9path TODOdata/s9_packetin_result.txt TODOdata/s9_flow_result.txt s9
./link.out $left3time $tag10path TODOdata/s10_packetin_result.txt TODOdata/s10_flow_result.txt s10
./link.out $left5time $tag12path TODOdata/s12_packetin_result.txt TODOdata/s12_flow_result.txt s12
./link.out $left5time $tag15path TODOdata/s15_packetin_result.txt TODOdata/s15_flow_result.txt s15
echo "step3_over"
#下面的这条命令的第一个参数选取三个时间中的最小值
./linkfive.out $right2time resultdata/s1_final_out.csv resultdata/s7_final_out.csv resultdata/s9_final_out.csv \
	resultdata/s10_final_out.csv resultdata/s12_final_out.csv
