#pragma once
#include <string>
namespace adas
{
    /* 汽车姿态 */
    struct Pose
    {
        int x;
        int y;
        char heading; // NSEW四个方向
    };
    /* 执行器接口类 */
    class Executor
    {
    public:
        static Executor *NewExcutor(const Pose &pose = {0, 0, 'N'}) noexcept;

    public:
        // 默认构造函数
        Executor(void) = default;
        // 默认析构函数
        virtual ~Executor(void) = default;

        // 不允许拷贝
        Executor(const Executor &) = delete;
        // 不允许赋值
        Executor &operator=(const Executor &) = delete;

    public:
        // 查询当前汽车姿态，纯虚函数，留给子类具体实现
        virtual Pose Query(void) const noexcept = 0;
        // 新增纯虚函数，留给子类ExecutorImpl去实现
        virtual void Execute(const std::string &commands) noexcept = 0;
    };
}