#pragma once
#include "NormalOrchestrator.hpp"
namespace adas
{
    class SportsCarOrchestrator : public NormalOrchestrator
    {
    public:
        ActionGroup Move(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            if (poseHandler.IsFast())
            {
                // 跑车Fast状态：移动4格 (2×2)
                actionGroup.PushAction(GetStepAction(poseHandler));
                actionGroup.PushAction(GetStepAction(poseHandler));
                actionGroup.PushAction(GetStepAction(poseHandler));
                actionGroup.PushAction(GetStepAction(poseHandler));
            }
            else
            {
                // 跑车普通状态：移动2格
                actionGroup.PushAction(GetStepAction(poseHandler));
                actionGroup.PushAction(GetStepAction(poseHandler));
            }
            return actionGroup;
        }

        ActionGroup TurnLeft(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            // 跑车：左转90度，再前进1格（与普通车相同）
            ActionType turnAction = poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
            actionGroup.PushAction(turnAction);
            actionGroup.PushAction(GetStepAction(poseHandler));
            return actionGroup;
        }

        ActionGroup TurnRight(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            // 跑车：右转90度，再前进1格（与普通车相同）
            ActionType turnAction = poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
            actionGroup.PushAction(turnAction);
            actionGroup.PushAction(GetStepAction(poseHandler));
            return actionGroup;
        }
    };
}
