#pragma once
#include "ExecutorImpl.hpp"

namespace adas
{
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

}