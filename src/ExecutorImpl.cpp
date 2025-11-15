#include "ExecutorImpl.hpp"
#include <algorithm>
#include <new>

#include "cmder/NormalOrchestrator.hpp"
#include "cmder/SportsCarOrchestrator.hpp"
#include "cmder/BusOrchestrator.hpp"

#include "cmder/CmderFactory.hpp"
#include "core/Singleton.hpp"
namespace adas
{
    Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept
    {
        CmderOrchestrator *orchestrator = nullptr;
        switch (executorType)
        {
        case ExecutorType::NORMAL:
        {
            orchestrator = new NormalOrchestrator();
            break;
        }
        case ExecutorType::SPORTS_CAR:
        {
            orchestrator = new SportsCarOrchestrator();
            break;
        }
        case ExecutorType::BUS:
        {
            orchestrator = new BusOrchestrator();
            break;
        }
        }
        return new ExecutorImpl(pose, orchestrator);
    }

    ExecutorImpl::ExecutorImpl(const Pose &pose, CmderOrchestrator *orchestrator) noexcept : poseHandler(pose), orchestrator(orchestrator) {}

    Pose ExecutorImpl::Query(void) const noexcept // 添加这个方法
    {
        return poseHandler.Query();
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);

        std::for_each(cmders.begin(), cmders.end(),
                      [this](const Cmder &cmder) noexcept
                      { cmder(poseHandler, *orchestrator).DoOperate(poseHandler); });
    }
}