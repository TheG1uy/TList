#include "TList.h"

#include <gtest.h>

TEST(TList, can_add_first)
{
	TList<int> a;
	ASSERT_NO_THROW(a.addFirst(1));

}

TEST(TList, can_add_last)
{
    TList<int> a;
	ASSERT_NO_THROW(a.addLast(1));
}

TEST(TList, can_add_curr)
{
	 TList<int> a;
	ASSERT_NO_THROW(a.addCurr(1));
}
TEST(TList, can_del_first)
{
	 TList<int> a;
	 a.addFirst(1);

	ASSERT_NO_THROW(a.delFirst());
}
TEST(TList, can_del_last)
{
	 TList<int> a;
	 a.addLast(1);

	ASSERT_NO_THROW(a.delLast());
}
TEST(TList, cant_del_curr)
{
	 TList<int> a;
	 a.addCurr(1);

	ASSERT_NO_THROW(a.delCurr());
}
TEST(TList, can_take_val)
{
	 TList<int> a;
	 a.addFirst(5);

	 EXPECT_EQ(5, a.getElelm());
}
TEST(TList, can_check_list_is_empty)
{
	 TList<int> a;
	 a.addFirst(5);
	 EXPECT_EQ(false, a.isEmpty());

}
TEST(TList, can_use_sort_input)
{
	 TList<int> a;
	a.sortInput(5);
	a.sortInput(2);
	a.sortInput(1);
	a.sortInput(7);
	a.sortInput(3);
	a.sortInput(4);
	a.sortInput(8);
	a.sortInput(6);
	a.sortInput(3);
	a.reset();
	EXPECT_EQ(1, a.getElelm());
}


