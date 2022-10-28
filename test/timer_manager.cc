#include <timer_manager.h>
#include <gtest/gtest.h>
#include <cstring>

class TimerManagerTest : public ::testing::Test {
protected:
	void SetUp() override;
	void TearDown() override;

	TimerManager::TimerManager *tm;
};

void TimerManagerTest::SetUp() {
	tm = new TimerManager::TimerManager;
}

void TimerManagerTest::TearDown() {
	delete tm;
}

TEST_F(TimerManagerTest, TestInitialConditions) {
	EXPECT_TRUE(TimerManager::getInternalMap(tm).empty());
}

TEST_F(TimerManagerTest, TestCreateGetDelete) {
	ASSERT_FALSE(tm == NULL);
	char *data = (char *)malloc(10);
	::strcpy(data, "TEST_DATA");
	int fd = tm->createTimer(10, (void *)data);
	EXPECT_GE(fd, 0);
	
	EXPECT_NO_THROW({
		const char *data_copy = (const char *)tm->getTimerData(fd);
		EXPECT_STREQ(data, data_copy);
	});

	EXPECT_NO_THROW(tm->deleteTimer(fd));
}

//TEST_F(TimerManagerTest, TestGetThrowsIfNoData) {
//	ASSERT_FALSE(tm == NULL);
//	EXPECT_ANY_THROW(tm->getTimerData(3));
//}

TEST_F(TimerManagerTest, TestSeveralInsertsAndDeletes) {
	ASSERT_FALSE(tm == NULL);
	char 	*data1 = (char *)malloc(16),
		*data2 = (char *)malloc(16),
		*data3 = (char *)malloc(16);

	strcpy(data1, "TEST_DATA_1");
	strcpy(data2, "TEST_DATA_2");
	strcpy(data3, "TEST_DATA_3");

	int fd1 = tm->createTimer(10, (void *)data1);
	EXPECT_GE(fd1, 0);
	int fd2 = tm->createTimer(10, (void *)data2);
	EXPECT_GE(fd2, 0);
	int fd3 = tm->createTimer(10, (void *)data3);
	EXPECT_GE(fd3, 0);

	EXPECT_EQ(getInternalMap(tm).size(), 3);
	EXPECT_NE(getInternalMap(tm)[fd1], (TimerManager::Timer *)NULL);
	EXPECT_NE(getInternalMap(tm)[fd2], (TimerManager::Timer *)NULL);
	EXPECT_NE(getInternalMap(tm)[fd3], (TimerManager::Timer *)NULL);

	EXPECT_STREQ((char *)tm->getTimerData(fd1), data1);
	EXPECT_STREQ((char *)tm->getTimerData(fd2), data2);
	EXPECT_STREQ((char *)tm->getTimerData(fd3), data3);

	EXPECT_NO_THROW(tm->deleteTimer(fd1));

	EXPECT_EQ(getInternalMap(tm).size(), 2);
	EXPECT_NE(getInternalMap(tm)[fd2], (TimerManager::Timer *)NULL);
	EXPECT_NE(getInternalMap(tm)[fd3], (TimerManager::Timer *)NULL);

	EXPECT_STREQ((char *)tm->getTimerData(fd2), data2);
	EXPECT_STREQ((char *)tm->getTimerData(fd3), data3);

	EXPECT_NO_THROW(tm->deleteTimer(fd2));

	EXPECT_EQ(getInternalMap(tm).size(), 1);
	EXPECT_NE(getInternalMap(tm)[fd3], (TimerManager::Timer *)NULL);
	EXPECT_STREQ((char *)tm->getTimerData(fd3), data3);

	EXPECT_NO_THROW(tm->deleteTimer(fd3));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
