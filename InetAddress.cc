#include "InetAddress.h"
#include <strings.h>
#include <string.h>

InetAddress::InetAddress(uint16_t port, std::string ip)
{
    // 清零地址内容
    bzero(&addr_, sizeof addr_);
    // 赋值 addr_其实就是一个sockadd_in 结构体
    addr_.sin_family = AF_INET;// AF是地址族
    addr_.sin_port = htons(port); //主机字节序（小端）转成网络字节序（大端）
    // sin_addr也是一个结构体 s_addr表示IPv4地址
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());// 其实inet_addr就是将十进制的IP转换成二进制的
}

std::string InetAddress::toIp() const
{
    // addr_
    char buf[64] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    // 加上::说明该函数是全局作用域的
    //::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    return buf;
}

std::string InetAddress::toIpPort() const
{
    // ip:port
    char buf[64] = {0};
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    size_t end = strlen(buf);// 获取buf的末尾
    uint16_t port = ntohs(addr_.sin_port);// 网络 -> 主机
    sprintf(buf+end, ":%u", port);
    return buf;
}

uint16_t InetAddress::toPort() const
{
    return ntohs(addr_.sin_port);
}
