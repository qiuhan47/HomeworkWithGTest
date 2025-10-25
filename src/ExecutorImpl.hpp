#pragma once
#include "Executor.hpp"
#include <string>

namespace adas
{
    // Executor的具体实现
    class ExecutorImpl : public Executor
    {
    public:
        // 构造函数
        explicit ExecutorImpl(const Pose &pose) noexcept;
        // 构造默认函数
        ~ExecutorImpl() noexcept = default;

        // 不能拷贝
        ExecutorImpl(const ExecutorImpl &) = delete;
        // 不能赋值
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        // 查询当前汽车姿态。是Query的具体实现
        Pose Query(void) const noexcept override;
        // Execute方法的声明
        void Execute(const std::string &commands) noexcept override;

    private:
        // 私有数据成员，汽车当前姿态
        Pose pose;
    };
}