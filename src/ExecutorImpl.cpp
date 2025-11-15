#include "ExecutorImpl.hpp"
// #include "Command.hpp"

#include "CmderFactory.hpp"
#include "Singleton.hpp"

#include <algorithm>
// #include <new>
// #include <memory>
// #include <unordered_map>

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
        const auto cmders =
            Singleton<CmderFactory>::Instance().GetCmders(commands);
        std::for_each(
            cmders.begin(), cmders.end(),
            [this](const std::function<void(PoseHandler & poseHandler)> &cmder) noexcept
            {
                cmder(poseHandler);
            });
    }
}