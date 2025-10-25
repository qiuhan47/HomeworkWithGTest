#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
    // 重载Pose的==，用的全局函数，用于比较两个姿态对象是不是相对
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }
    // 下面两个测试用例，测试静态方法Executor::NewExcutor
    // 测试用例1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given 给定测试条件
        // 测试条件就是调用Executor的静态方法Executor::NewExcutor
        std::unique_ptr<Executor> executor(Executor::NewExcutor({0, 0, 'E'})); // 初始姿势

        // when

        // then
        const Pose target({0, 0, 'E'}); // 构造一个姿势对象

        ASSERT_EQ(target, executor->Query()); // 调用重载的Pose的==
    }
    // 测试用例2
    TEST(ExecutorTest, should_return_default_pose_when_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExcutor());

        // when

        // then
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // M
    // 测试用例3 测试Execute方法，在朝向为E、起点为原点时执行M指令是否正确
    TEST(ExecutorTest, should_return_x_plus_1_given_commmad_is_M_and_facing_is_E)
    {
        // given 给定一个Executor
        std::unique_ptr<Executor> executor(Executor::NewExcutor({0, 0, 'E'}));

        // when 调用executor的Execute方法去执行M指令
        executor->Execute("M");

        // then
        const Pose target({1, 0, 'E'});       // 如果M指令正确，新姿势应当是这个
        ASSERT_EQ(target, executor->Query()); // 验证
    }
    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
    {
        std::unique_ptr<Executor> executor(Executor::NewExcutor({0, 0, 'W'}));

        executor->Execute("M");

        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
    {
        std::unique_ptr<Executor> executor(Executor::NewExcutor({0, 0, 'N'}));

        executor->Execute("M");

        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
    {
        std::unique_ptr<Executor> executor(Executor::NewExcutor({0, 0, 'S'}));

        executor->Execute("M");

        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
}