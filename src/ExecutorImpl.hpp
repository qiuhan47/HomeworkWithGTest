#pragma once
#include "Executor.hpp"
#include <string>

namespace adas
{
    // Executor的具体实现
    class ExecutorImpl final : public Executor
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
        class ICommand
        {
        public:
            virtual ~ICommand() = default;
            virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
        };

        class MoveCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept
            {
                // 如果是F状态，多执行一次MOVE
                executor.Move();
                if (executor.IsFast())
                {
                    executor.Move();
                }
            }
        };
        class TurnLeftCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept
            {
                // 如果是F状态，先执行一次Move，再执行TurnLeft
                if (executor.IsFast())
                {
                    executor.Move();
                }
                executor.TurnLeft();
            }
        };
        class TurnRightCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept
            {
                // 如果是F状态，先执行一次Move，再执行TurnRight
                if (executor.IsFast())
                {
                    executor.Move();
                }
                executor.TurnRight();
            }
        };
        class FastCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.Fast();
            }
        };

    private:
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        void Fast(void) noexcept;

        bool IsFast(void) const noexcept;

    private:
        Pose pose;
        bool fast{false};
    };
}