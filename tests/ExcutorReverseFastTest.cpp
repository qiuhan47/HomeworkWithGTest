#include <gtest/gtest.h>
#include "Executor.hpp"
#include "PoseEq.hpp"
#include <memory>

namespace adas
{
    // 测试输入：FBM
    TEST(ExecutorReverseFastTest, should_return_x_minus_2_given_status_is_reverse_fast_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("FBM");

        // then
        const Pose target{-2, 0, 'E'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FBL
    TEST(ExecutorReverseFastTest, should_return_x_minus_1_and_heading_S_given_status_is_reverse_fast_command_is_L_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("FBL");

        // then
        const Pose target{-1, 0, 'S'};
        ASSERT_EQ(target, executor->Query());
    }

    // 测试输入：FBR (根据表格：当前朝向E执行BFR X-1，朝向N)
    TEST(ExecutorReverseFastTest, should_return_x_minus_1_and_heading_N_given_status_is_reverse_fast_command_is_R_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("FBR");

        // then
        const Pose target{-1, 0, 'N'};
        ASSERT_EQ(target, executor->Query());
    }
}