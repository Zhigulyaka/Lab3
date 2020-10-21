#include "Stack.h"
#include <../gtest/gtest.h>

TEST(Queue, can_create_stack_with_default_constructor)
{
    ASSERT_NO_THROW(Queue<int> s);
}

TEST(Queue, can_create_stack_with_size_one)
{
    ASSERT_NO_THROW(Queue<double> s(1));
}

TEST(Queue, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Queue<double> s(5));
}

TEST(Queue, can_create_stack_with_zero_size)
{
    ASSERT_NO_THROW(Queue<double> s(0));
}

TEST(Queue, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Queue<double> s(-1));
}

TEST(Queue, can_create_copied_vector)
{
    Queue<int> s(5);
    ASSERT_NO_THROW(Queue<int> s1(s));
}

TEST(Queue, copied_vector_is_equal_to_source_one)
{
    Queue<int> s1(5);
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i + 1);
    Queue<int> s2(s1);
    EXPECT_EQ(s1.GetLength(), s2.GetLength());
    for (int i = 0; i < s1.GetLength(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(Queue, can_get_size)
{
    Queue<int> s(5);

    EXPECT_EQ(5, s.GetLength());
}

TEST(Queue, can_set_and_get_element)
{
    Queue<int> s(5);
    s.push(6);
    EXPECT_EQ(6, s.pull());
}

TEST(Queue, can_assign_vector_to_itself)
{
    Queue<int> s(5);
    ASSERT_NO_THROW(s = s);

}

TEST(Queue, can_assign_vectors_of_equal_size)
{
    Queue<int> s1(5);
    Queue<int> s2(5);
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i + 1);
    s2 = s1;
    EXPECT_EQ(s1.GetLength(), s2.GetLength());
    for (int i = 0; i < s1.GetLength(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(Queue, can_assign_vectors_of_different_size)
{
    Queue<int> s1(10);
    Queue<int> s2(5);
    for (int i = 0; i < s1.GetLength(); i++)
    {
        s1.push(i + 1);
    }
    for (int i = 0; i < s2.GetLength(); i++)
    {
        s2.push(i + 1);
    }
    s2 = s1;
    EXPECT_EQ(s1.GetLength(), s2.GetLength());
    for (int i = 0; i < s1.GetLength(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(Queue, compare_equal_vectors_return_true)
{
    Queue<int> s1(5);
    Queue<int> s2(5);
    for (int i = 0; i < s1.GetLength(); i++)
    {
        s1.push(i + 1);
        s2.push(i + 1);
    }
    bool f;
    f = (s1.GetLength() == s2.GetLength());
    if (f != 0)
        for (int i = 0; i < s1.GetLength(); i++)
        {
            if (f != 0)
                f = (s1.pull() == s2.pull());
            else break;
        }
    EXPECT_EQ(1, f);
}

TEST(Queue, compare_vector_with_itself_return_true)
{
    Queue<int> s(5);
    bool f;
    int k;
    for (int i = 0; i < s.GetLength(); i++)
        s.push(i + 1);
    f = (s.GetLength() == s.GetLength());
    if (f != 0)
        for (int i = 0; i < s.GetLength(); i++)
        {
            if (f != 0)
            {
                k = s.pull();
                f = (k == k);
            }
            else break;
        }
    EXPECT_EQ(1, f);
}

TEST(Queue, vectors_with_different_size_are_not_equal)
{
    Queue<int> s1(5);
    Queue<int> s2(10);
    bool f;
    f = (s1.GetLength() == s2.GetLength());
    if (f != 0)
        for (int i = 0; i < s1.GetLength(); i++)
        {
            if (f != 0)
                f = (s1.pull() == s2.pull());
            else break;
        }
    EXPECT_EQ(0, f);
}
