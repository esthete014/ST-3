// Copyright 2024 Kochetov Nikolay

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TimedDoor.h"

class MockTimerClient : public TimerClient {
public:
    MOCK_METHOD(void, Timeout, (), (override));
};

TEST(TimedDoorTest, TestDoorOpen) {
    int timeout = 5;
    MockTimerClient mockTimer;
    TimedDoor timedDoor(timeout);
    timedDoor.unlock();

    EXPECT_CALL(mockTimer, Timeout()).Times(1);

    timedDoor.throwState();
}

TEST(TimedDoorTest, TestDoorClose) {
    int timeout = 5;
    MockTimerClient mockTimer;
    TimedDoor timedDoor(timeout);
    timedDoor.lock();

    EXPECT_CALL(mockTimer, Timeout()).Times(0);

    timedDoor.throwState();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
