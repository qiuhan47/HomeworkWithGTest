#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept
        : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}

    void PoseHandler::Forward() noexcept
    {
        point += facing->Move();
    }

    void PoseHandler::Backward() noexcept
    {
        // 后退：向当前朝向的反方向移动
        point -= facing->Move();
    }

    void PoseHandler::TurnLeft() noexcept
    {
        facing = &(facing->LeftOne());
    }

    void PoseHandler::TurnRight() noexcept
    {
        facing = &(facing->RightOne());
    }

    void PoseHandler::Fast() noexcept
    {
        fast = !fast; // 切换加速状态
    }

    void PoseHandler::Reverse() noexcept
    {
        reverse = !reverse; // 切换后退状态
    }

    bool PoseHandler::IsFast() const noexcept
    {
        return fast; // 返回当前加速状态
    }

    bool PoseHandler::IsReverse() const noexcept
    {
        return reverse; // 返回当前后退状态
    }

    Pose PoseHandler::Query(void) const noexcept
    {
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }
}