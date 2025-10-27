#include "ExecutorImpl.hpp"
#include <new>
#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose), isFast(false) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return pose;
    }

    Executor *Executor::NewExcutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &command) noexcept
    {
        for (const auto cmd : command)
        {
            if (cmd == 'M')
            {
                // 智能指针指向MoveCommand实例，不用担心delete了
                std::unique_ptr<MoveCommand> cmder = std::make_unique<MoveCommand>();
                // *this就是ExecutorImpl实例对象，作为实参传递给DoOperate方法
                cmder->DoOperate(*this); // 执行MoveCommand的DoOperate，即Move
            }
            else if (cmd == 'L')
            {
                TurnLeft();
            }
            else if (cmd == 'R')
            {
                TurnRight();
            }
            else if (cmd == 'F')
            {
                isFast = !isFast;
            }
        }
    }

    void ExecutorImpl::Move() noexcept
    {
        if (!isFast)
        {
            if (pose.heading == 'E')
            {
                ++pose.x;
            }
            else if (pose.heading == 'W')
            {
                --pose.x;
            }
            else if (pose.heading == 'N')
            {
                ++pose.y;
            }
            else if (pose.heading == 'S')
            {
                --pose.y;
            }
        }
        else
        {
        }
    }

    void ExecutorImpl::TurnLeft() noexcept
    {
        if (!isFast)
        {
            if (pose.heading == 'E')
            {
                pose.heading = 'N';
            }
            else if (pose.heading == 'W')
            {
                pose.heading = 'S';
            }
            else if (pose.heading == 'N')
            {
                pose.heading = 'W';
            }
            else if (pose.heading == 'S')
            {
                pose.heading = 'E';
            }
        }
        else
        {
        }
    }

    void ExecutorImpl::TurnRight() noexcept
    {
        if (!isFast)
        {
            if (pose.heading == 'E')
            {
                pose.heading = 'S';
            }
            else if (pose.heading == 'W')
            {
                pose.heading = 'N';
            }
            else if (pose.heading == 'N')
            {
                pose.heading = 'E';
            }
            else if (pose.heading == 'S')
            {
                pose.heading = 'W';
            }
        }
        else
        {
        }
    }
}