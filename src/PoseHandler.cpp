#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose), fast(false) {}

    Pose PoseHandler::Query(void) const noexcept
    {
        return pose;
    }

    void PoseHandler::Move() noexcept
    {
        // if (!IsFast())
        // {
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
        // }
        // else
        // {
        // }
    }

    void PoseHandler::TurnLeft() noexcept
    {
        // if (!IsFast())
        // {
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
        // }
        // else
        // {
        // }
    }

    void PoseHandler::TurnRight() noexcept
    {
        // if (!IsFast())
        // {
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
        // }
        // else
        // {
        // }
    }

    void PoseHandler::Fast() noexcept
    {
        fast = !fast; // 切换加速状态
    }

    bool PoseHandler::IsFast() const noexcept
    {
        return fast; // 返回当前加速状态
    }
}