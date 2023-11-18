#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H


class noncopyable
{
public:
    // 禁用拷贝和赋值构造函数
    noncopyable(const noncopyable &) = delete;
    noncopyable &operator=(const noncopyable &) = delete;

protected:
    // 使用protected修饰构造函数是为了不能实例化当前类 只能继承当前类 在派生类中实例化
    // 使用protected 派生类可以构造和析构
    noncopyable() = default;
    ~noncopyable() = default;
};

#endif // NONCOPYABLE_H