#pragma once
#include "PoseHandler.hpp"
#include <functional>

namespace adas
{
    class MoveCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse())
            {
                poseHandler.Backward();
            }
            else
            {
                poseHandler.Forward();
            }
        }
    };

    class TurnLeftCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse())
            {
                poseHandler.TurnRight(); // 后退模式下左转变右转
            }
            else
            {
                poseHandler.TurnLeft();
            }
        }
    };

    class TurnRightCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            if (poseHandler.IsFast())
            {
                if (poseHandler.IsReverse())
                {
                    poseHandler.Backward();
                }
                else
                {
                    poseHandler.Forward();
                }
            }

            if (poseHandler.IsReverse())
            {
                poseHandler.TurnLeft(); // 后退模式下右转变左转
            }
            else
            {
                poseHandler.TurnRight();
            }
        }
    };

    class FastCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Fast();
        }
    };

    class ReverseCommand final
    {
    public:
        void operator()(PoseHandler &poseHandler) const noexcept
        {
            poseHandler.Reverse();
        }
    };
}