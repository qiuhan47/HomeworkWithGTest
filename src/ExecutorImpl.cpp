#include "ExecutorImpl.hpp"
#include "Command.hpp"
#include <new>
#include <memory>
#include <unordered_map>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}

    Pose ExecutorImpl::Query(void) const noexcept
    {
        return poseHandler.Query();
    }

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        std::unordered_map<char, std::function<void(PoseHandler & PoseHandler)>> cmderMap;
        MoveCommand moveCommand;
        cmderMap.emplace('M', moveCommand.operate);
        TurnLeftCommand turnLeftCommand;
        cmderMap.emplace('L', turnLeftCommand.operate);
        TurnRightCommand turnRightCommand;
        cmderMap.emplace('R', turnRightCommand.operate);
        FastCommand fastCommand;
        cmderMap.emplace('F', fastCommand.operate);

        for (const auto cmd : commands)
        {
            const auto it = cmderMap.find(cmd);

            if (it != cmderMap.end())
            {
                it->second(poseHandler);
            }
        }
    }
}