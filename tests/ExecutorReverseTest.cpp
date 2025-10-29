#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"
#include <memory>

namespace adas
{
    // 测试输入：BM (根据表格：当前朝向E执行BM X-1)
    TEST(ExecutorReverseTest, should_return_x_minus_1_given_status_is_reverse_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BM");

        // then
        const Pose target{-1, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：BL (根据表格：当前朝向E执行BL 朝向S)
    TEST(ExecutorReverseTest, should_return_heading_S_given_status_is_reverse_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BL");

        // then
        const Pose target{0, 0, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：BR (根据表格：当前朝向E执行BR 朝向N)
    TEST(ExecutorReverseTest, should_return_heading_N_given_status_is_reverse_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("BR");

        // then
        const Pose target{0, 0, 'N'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：BBM (根据表格：当前朝向N执行BBM Y+1，BB取消后退模式)
    TEST(ExecutorReverseTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));

        // when
        executor->Execute("BBM");

        // then
        const Pose target{0, 1, 'N'};
        ASSERT_EQ(target, executor->Query());
    }
}