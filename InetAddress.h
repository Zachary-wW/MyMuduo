#ifndef INETADDRESS_H
#define INETADDRESS_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

// 封装socket地址类型
class InetAddress
{
public:
    // 默认主机环回地址
    // explicit防止隐式转换
    // port是16位无符号整型 对应了TCP头的端口长度
    explicit InetAddress(uint16_t port = 0, std::string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in &addr)
        : addr_(addr)
    {}
    // 获取IP地址
    std::string toIp() const;
    // 获取IP端口号
    std::string toIpPort() const;
    // 获取端口号
    uint16_t toPort() const;

    // 获取socket地址
    // 这里注意在高性能服务器编程中提到 所有的专用地址最后都得转换成socketaddr（为了保持一致性）
    const sockaddr_in* getSockAddr() const {return &addr_;}
    // 设置socket地址
    void setSockAddr(const sockaddr_in &addr) { addr_ = addr; }
private:
    // sockaddr_in是TCP/IP协议族的专用socket地址
    sockaddr_in addr_; // IPv4
};

#endif