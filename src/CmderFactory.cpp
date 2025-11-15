#include "CmderFactory.hpp"

namespace adas
{
    std::list<std::function<void(PoseHandler &PoseHandler)>> CmderFactory::GetCmders(
        const std::string &commands) const noexcept
    {
        std::list<std::function<void(PoseHandler &PoseHandler)>> cmders;
        
        for (const auto cmd : commands)
        {
            const auto it = cmdMap.find(cmd);
            if (it != cmdMap.end())
            {
                cmders.push_back(it->second);
            }
        }
        
        return cmders;
    }
}