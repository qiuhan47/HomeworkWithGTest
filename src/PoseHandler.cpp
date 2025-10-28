#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept
        : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)) {}

    void PoseHandler::Move() noexcept
    {
        point += facing->Move();
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

    bool PoseHandler::IsFast() const noexcept
    {
        return fast; // 返回当前加速状态
    }

    Pose PoseHandler::Query(void) const noexcept
    {
        return {point.GetX(), point.GetY(), facing->GetHeading()};
    }
}