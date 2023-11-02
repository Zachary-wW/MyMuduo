#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
#include <string>

// 时间类
class Timestamp
{
public:
    Timestamp();
    explicit Timestamp(int64_t microSecondsSinceEpoch); // 添加explicit防止出现隐式转换
    // 比如说有个函数 display(const Timestamp& t) 我调用的时候传入display(1)也能通过编译 这时出现了隐式转换
    static Timestamp now();
    std::string toString() const; // const是常方法 函数无法改变除mutable外变量的属性
private:
    int64_t microSecondsSinceEpoch_;
};

#endif