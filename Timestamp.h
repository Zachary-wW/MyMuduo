#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
#include <string>

// 时间戳类
class Timestamp
{
public:
    Timestamp();
    // 添加explicit防止出现隐式转换
    // 比如说有个函数 display(const Timestamp& t) 我调用的时候传入display(1)也能通过编译 这时出现了隐式转换
    explicit Timestamp(int64_t microSecondsSinceEpoch);
    static Timestamp now();
    // const在后面表明是常方法 函数无法改变除mutable外变量的属性
    std::string toString() const;
private:
    int64_t microSecondsSinceEpoch_;
};

#endif