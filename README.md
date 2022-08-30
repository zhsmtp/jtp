# jtp

#### 介绍
nodejs ctp extension

#### 软件架构
软件架构说明
api函数，直接通过InstanceMethod定义导出到JS，例如：
    InstanceMethod("CreateFtdcMdApi", &MdApi::CreateFtdcMdApi),
spi的函数，调用继承自EventEmitter的emit函数，把事件发送给JS。


#### 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

#### 使用说明

1.  gb2312转utf8在js里进行，使用jtp.g2u(rsp)
2.  xxxx
3.  xxxx