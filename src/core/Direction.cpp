#include "Direction.hpp"

namespace adas
{
    static const Direction directions[4] = {
        {0, 'E'},
        {1, 'S'},
        {2, 'W'},
        {3, 'N'},
    };

    static const Point points[4] = {
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 1},
    };

    const Direction &Direction::GetDirection(const char heading) noexcept
    {
        for (const auto &direction : directions)
        {
            if (direction.heading == heading)
            {
                return direction;
            }
        }

        return directions[3];
    }

    Direction::Direction(const unsigned index, const char heading) noexcept
        : index(index), heading(heading) {} // 实现构造函数

    const Point &Direction::Move() const noexcept
    {
        return points[index]; // 返回对应方向的移动向量
    }

    const Direction &Direction::LeftOne() const noexcept
    {
        return directions[(index + 3) % 4]; // 左转：逆时针
    }

    const Direction &Direction::RightOne() const noexcept
    {
        return directions[(index + 1) % 4]; // 右转：顺时针
    }

    const char Direction::GetHeading() const noexcept
    {
        return heading; // 返回朝向字符
    }
}