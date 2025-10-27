#include "ExecutorImpl.hpp"
#include <new>

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
                Move();
            }
            else if (cmd == 'L')
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
            else if (cmd == 'R')
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
}