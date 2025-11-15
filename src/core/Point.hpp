#pragma once

namespace adas
{
    class Point final
    {
    public:
        Point(const int x, const int y) noexcept;
        Point(const Point &rhs) noexcept;
        Point &operator=(const Point &rhs) noexcept;
        Point &operator+=(const Point &rhs) noexcept; // 前进
        Point &operator-=(const Point &rhs) noexcept; // 后退

    public:
        int GetX(void) const noexcept;
        int GetY(void) const noexcept;

    private:
        int x;
        int y;
    };
}