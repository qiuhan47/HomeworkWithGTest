#pragma once
#include "PoseHandler.hpp"

namespace adas
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    };

    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept
        {
            // 如果是F状态，多执行一次MOVE
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.Move();
        }
    };
    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept
        {
            // 如果是F状态，先执行一次Move，再执行TurnLeft
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        }
    };
    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept
        {
            // 如果是F状态，先执行一次Move，再执行TurnRight
            if (poseHandler.IsFast())
            {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        }
    };
    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &poseHandler) const noexcept override
        {
            poseHandler.Fast();
        }
    };

}