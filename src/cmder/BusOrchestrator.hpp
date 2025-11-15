#pragma once
#include "NormalOrchestrator.hpp"
namespace adas
{
    class BusOrchestrator : public NormalOrchestrator
    {
    public:
        // Move方法继承NormalOrchestrator（前进1格）

        ActionGroup TurnLeft(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            // Bus：前进1格，左转90度
            actionGroup.PushAction(GetStepAction(poseHandler));
            ActionType turnAction = poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
            actionGroup.PushAction(turnAction);
            return actionGroup;
        }

        ActionGroup TurnRight(const PoseHandler &poseHandler) const noexcept override
        {
            ActionGroup actionGroup;
            actionGroup += OnFast(poseHandler);
            // Bus：前进1格，右转90度
            actionGroup.PushAction(GetStepAction(poseHandler));
            ActionType turnAction = poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
            actionGroup.PushAction(turnAction);
            return actionGroup;
        }
    };
}
