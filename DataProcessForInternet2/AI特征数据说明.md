> **用于训练AI模型的数据文件有两个**

 - 第一个文件（s1-s12.csv）是把交换机S1到S12的特征进行整合，目前一共有33*5（33个特征）+5（标签）=170列。
 - 第二个文件（s15_final_out.csv）是交换机S15的特征，第一列是时间戳，接着是33个特征和一个标签，一共35列。

 

> 文件中出现值为-1的项，是该项数据的缺省值，代表的含义是在此时刻，该特征数据缺失。（大概率是该项数据没有采集到，也有可能是经计算该项数据不存在，例如计算过程中会有除法操作，除数为0时无法进行除法）

> **第一个文件S1-S12.csv中每一列数据含义说明如下：**

 - 第1列到第33列是交换机S1的特征数据
 - 第34列到第66列是交换机S7的特征数据
 - 第67列到第99列是交换机S9的特征数据
 - 第100列到第132列是交换机S10的特征数据
 - 第133列到第165列是交换机S12的特征数据
 - 第166列是交换机S1的标签
 - 第167列是交换机S7的标签
 - 第168列是交换机S9的标签
 - 第169列是交换机S10的标签
 - 第170列是交换机S12的标签
 

> **接下来以第1列到第33列（S1的特征数据）为例子说明每个数据的含义.由于第34列到第165列的特征也是如此，只是换了个交换机，所以不再一一列出：**

 1. 收到的数据包数量，ReceivePacket。S1收到的服务器（聚合流地址为192.0.0.0/8）发送的数据包的数量。
 2. 发送的数据包数量，SendPacket。S1发送给服务器的数据包的数量。
 3. 收到的字节数，ReceiveByte。S1收到的服务器发送的总字节数。
 4. 发送的字节数，SendByte。S1发送给服务器的总字节数。
 5. 发送数据包平均大小，AvgLength。S1发送给服务器的数据包平均大小。
 6. 源IP地址熵，IPEntropy。S1发送给服务器的聚合流的源IP地址信息熵。
 7. 源端口地址熵，PortEntropy。S1发送给服务器的聚合流的源端口地址信息熵。
 8. 字节数中位数，Mid。S1发送给服务器的数据包字节数的中位数。
 9. IP地址增长率，IPRate。S1发送给服务器的源IP地址变换率。即当前IP地址数与上一个时间间隔内IP地址数的比值。
 10. packetin数据包数量，PktNum。S1与控制器之间发送的packetin数量。
 11. packetin数据包变化率，PktRate。S1与控制器之间发送的packetin变化率。即当前S1与控制器之间发送的packetin数量与上一个时间间隔内S1与控制器之间发送的packetin数量的比值。
 12. 命中内核态流表的数据包数目，HitTable。
 13. 命中内核流表失败次数，HitFailure。
 14. 查找内核态流表使用的毫秒数，FindFlowms。
 15. ovs_flow_cmd_set()执行次数，OFCSNum。
 16. ovs_flow_cmd_get()执行次数，OFCGNum。
 17. ovs_flow_cmd_del()执行次数，OFCDNum。
 18. ovs_execute_actions()执行次数，OEANum。
 19. 命中mask_catch数目，HitMask。
 20. 查询mask_cache的次数，FindMask。
 21. 命中mask&flow_key hash表的次数,HitFlowkey。
 22. 查询mask&flow_key hash表的次数,FindFlowkey。
 23. ovs_packet_cmd_execute（）执行失败次数，OPCENum。
 24. 当前upcall数量，UpcallNum。
 25. 当前upcall长度，UpcallLength。
 26. 查找用户态流表时间，FindUserFlow。
 27. upcall时延，UpcallDelay。
 28. 接收到控制器数据包数，RevPkt。
 29. 发送给控制器的数据包数，SendPkt。
 30. udpif_upcall_handler执行次数，UUHNum。
 31.  命中用户态流表次数，HitUserFlow。
 32. 用户态流表项数目，UserTableItem。
 33. main函数循环执行次数，MainNum。

> 每一行的数据的含义，是统计一个时间间隔内（目前为1秒）的数据特征。<br>第165列到第170列分别是5个交换机的标签，标签值为0代表正常流量，标签值为1代表攻击流量。

>**第二个文件 是关于交换机S15的特征数据：** 每一列特征含义如下
 1. 时间戳。
 2. 发送的数据包数量，SendPacket。服务器发送给各个交换机的数据包的数量。
 3. 收到的数据包数量，ReceivePacket。服务器收到的来自各个交换机的数据包的数量。
 4. 发送的字节数，SendByte。服务器发送给各个交换机的总字节数。
 5. 收到的字节数，ReceiveByte。服务器收到的来自各个交换机的总字节数。
 6. 收到的数据包平均大小，AvgLength。服务器收到的数据包平均大小。
 7. 源IP地址熵，IPEntropy。服务器收到的聚合流的源IP地址信息熵。
 8. 源端口地址熵，PortEntropy。服务器收到的聚合流的源端口地址信息熵。
 9. 字节数中位数，Mid。服务器收到的数据包字节数的中位数。
 10. IP地址增长率，IPRate。服务器收到的源IP地址变换率。即当前IP地址数与上一个时间间隔内IP地址数的比值。
 11. packetin数据包数量，PktNum。S15与控制器之间发送的packetin数量。
 12. packetin数据包变化率，PktRate。S15与控制器之间发送的packetin变化率。即当前S15与控制器之间发送的packetin数量与上一个时间间隔内S15与控制器之间发送的packetin数量的比值。
 13.  命中内核态流表的数据包数目，HitTable。
 14. 命中内核流表失败次数，HitFailure。
 15. 查找内核态流表使用的毫秒数，FindFlowms。
 16. ovs_flow_cmd_set()执行次数，OFCSNum。
 17. ovs_flow_cmd_get()执行次数，OFCGNum。
 18. ovs_flow_cmd_del()执行次数，OFCDNum。
 19. ovs_execute_actions()执行次数，OEANum。
 20. 命中mask_catch数目，HitMask。
 21. 查询mask_cache的次数，FindMask。
 22. 命中mask&flow_key hash表的次数,HitFlowkey。
 23. 查询mask&flow_key hash表的次数,FindFlowkey。
 24. ovs_packet_cmd_execute（）执行失败次数，OPCENum。
 25. 当前upcall数量，UpcallNum。
 26. 当前upcall长度，UpcallLength。
 27. 查找用户态流表时间，FindUserFlow。
 28. upcall时延，UpcallDelay。
 29. 接收到控制器数据包数，RevPkt。
 30. 发送给控制器的数据包数，SendPkt。
 31. udpif_upcall_handler执行次数，UUHNum。
 32.  命中用户态流表次数，HitUserFlow。
 33. 用户态流表项数目，UserTableItem。
 34. main函数循环执行次数，MainNum。
 35. 标签，tag。为0代表没有攻击，为1代表有攻击。
> FAQs：数据文件开始时，有很多行的数据值基本都为-1，这些行数据缺失的原因是相应的时间间隔内，没有采集到数据。原因是采集数据的脚本和pcap文件重放脚本是两个脚本，在金同学的实验步骤说明中分别是在第四步和第五步运行的。运行两个脚本之间有时间间隔，且要在三台宿主机上运行，这进一步扩大了时间间隔。但是，在处理数据时，因为标签是根据pcap文件的重发时间来计算的，所以处理数据也是以pcap文件的重放时间为起始时间，在这个时间间隔内，没有采集到数据，所以会在文件开始看到很多行为-1的现象。<br>解决办法：不用前几行的数据即可。<br>
> 文件中途也会出现部分数据为-1，这是因为该时间间隔内，某个交换机的数据缺失，例如没有发包也没有收到包，即在这个时间间隔里交换机没有数据包转发行为。预计后续加入ovs特征之后，会有很多为-1的数据，因为ovs原始数据的时间戳不是严格递增的，有些时段的原始数据不存在。<br>**关于列名：由于AI模块的需要，故为每一列的数据加一个列名，列名的形式为：交换机名称+下划线+上文中列的含义所对应的英文名。例如交换机s1发送的数据包数量这一列的列名为：S1_SendPacket**
 
  


