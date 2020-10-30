#！/bin/bash
g++ Packetin.cpp -o Packetin.out
g++ FlowTable.cpp -o FlowTable.out
g++ Ovsfeature.cpp -o ovsfeature.out
g++ linkflowpkt.cpp -o link.out
g++ LinkFive.cpp -o linkfive.out

right2time=1603877880 #s1 s7
left3time=1603877577 #s9 s10
left5time=1603877577 # s12 s15

tag1path=../labels/labels/field1_lable.txt
tag7path=../labels/labels/field2_lable.txt
tag9path=../labels/labels/field3_lable.txt
tag10path=../labels/labels/field4_lable.txt
tag12path=../labels/labels/field5_lable.txt
tag15path=../labels/labels/field6_lable.txt

flow1path=../dataJ/s1_2020-10-28_rtxpacket.txt
flow7path=../dataJ/s7_2020-10-28_rtxpacket.txt
flow9path=../dataJ/s9_2020-10-28_rtxpacket.txt
flow10path=../dataJ/s10_2020-10-28_rtxpacket.txt
flow12path=../dataJ/s12_2020-10-28_rtxpacket.txt
flow15path=../dataJ/s15_2020-10-28_rtxpacket.txt

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
echo "packetin_step_over"

./FlowTable.out $flow1path s1
echo "s1_flow_step_over"
./FlowTable.out $flow7path s7
echo "s7_flow_step_over"
./FlowTable.out $flow9path s9
echo "s9_flow_step_over"
./FlowTable.out $flow10path s10
echo "s10_flow_step_over"
./FlowTable.out $flow12path s12
echo "s12_flow_step_over"
./FlowTable.out $flow15path s15
echo "s15_flow_step_over"

./ovsfeature.out s1 ../data/data1/datapath_Gary ../data/data1/datapath_upcall ../data/data1/user_table_time ../data/data1/user_upcall ../data/data1/userspace
echo "s1_ovs_step_over"
./ovsfeature.out s7 ../data/data7/datapath_Gary ../data/data7/datapath_upcall ../data/data7/user_table_time ../data/data7/user_upcall ../data/data7/userspace
echo "s7_ovs_step_over"
./ovsfeature.out s9 ../data/data9/datapath_Gary ../data/data9/datapath_upcall ../data/data9/user_table_time ../data/data9/user_upcall ../data/data9/userspace
echo "s9_ovs_step_over"
./ovsfeature.out s10 ../data/data10/datapath_Gary ../data/data10/datapath_upcall ../data/data10/user_table_time ../data/data10/user_upcall ../data/data10/userspace
echo "s10_ovs_step_over"
./ovsfeature.out s12 ../data/data12/datapath_Gary ../data/data12/datapath_upcall ../data/data12/user_table_time ../data/data12/user_upcall ../data/data12/userspace
echo "s12_ovs_step_over"
./ovsfeature.out s15 ../data/data15/datapath_Gary ../data/data15/datapath_upcall ../data/data15/user_table_time ../data/data15/user_upcall ../data/data15/userspace
echo "s15_ovs_step_over"

./link.out $right2time $tag1path TODOdata/s1_packetin_result.txt TODOdata/s1_flow_result.txt s1 TODOdata/s1_datapath_result.txt TODOdata/s1_dataupcall_result.txt TODOdata/s1_tabletime_result.txt TODOdata/s1_userupcall_result.txt TODOdata/s1_userspace_result.txt
./link.out $right2time $tag7path TODOdata/s7_packetin_result.txt TODOdata/s7_flow_result.txt s7 TODOdata/s7_datapath_result.txt TODOdata/s7_dataupcall_result.txt TODOdata/s7_tabletime_result.txt TODOdata/s7_userupcall_result.txt TODOdata/s7_userspace_result.txt
./link.out $left3time $tag9path TODOdata/s9_packetin_result.txt TODOdata/s9_flow_result.txt s9 TODOdata/s9_datapath_result.txt TODOdata/s9_dataupcall_result.txt TODOdata/s9_tabletime_result.txt TODOdata/s9_userupcall_result.txt TODOdata/s9_userspace_result.txt
./link.out $left3time $tag10path TODOdata/s10_packetin_result.txt TODOdata/s10_flow_result.txt s10 TODOdata/s10_datapath_result.txt TODOdata/s10_dataupcall_result.txt TODOdata/s10_tabletime_result.txt TODOdata/s10_userupcall_result.txt TODOdata/s10_userspace_result.txt
./link.out $left5time $tag12path TODOdata/s12_packetin_result.txt TODOdata/s12_flow_result.txt s12 TODOdata/s12_datapath_result.txt TODOdata/s12_dataupcall_result.txt TODOdata/s12_tabletime_result.txt TODOdata/s12_userupcall_result.txt TODOdata/s12_userspace_result.txt
./link.out $left5time $tag15path TODOdata/s15_packetin_result.txt TODOdata/s15_flow_result.txt s15 TODOdata/s15_datapath_result.txt TODOdata/s15_dataupcall_result.txt TODOdata/s15_tabletime_result.txt TODOdata/s15_userupcall_result.txt TODOdata/s15_userspace_result.txt
echo "link_step_over"

#下面的这条命令的第一个参数选取三个时间中的最小值
./linkfive.out $left3time resultdata/s1_final_out.csv resultdata/s7_final_out.csv resultdata/s9_final_out.csv resultdata/s10_final_out.csv resultdata/s12_final_out.csv 
