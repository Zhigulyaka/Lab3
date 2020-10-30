
#include "Stack.h"
#include <../gtest/gtest.h>

TEST(Stack, can_create_stack_with_default_constructor)
{
    ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_create_stack_with_size_one)
{
    ASSERT_NO_THROW(Stack<double> s(1));
}

TEST(Stack, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Stack<double> s(5));
}

TEST(Stack, can_create_stack_with_zero_size)
{
    ASSERT_NO_THROW(Stack<double> s(0));
}

TEST(Stack, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Stack<double> s(-1));
}

TEST(Stack, can_create_copied_vector)
{
    Stack<int> s(5);
    ASSERT_NO_THROW(Stack<int> s1(s));
}

TEST(Stack, copied_vector_is_equal_to_source_one)
{
    Stack<int> s1(5);
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i);
    Stack<int> s2(s1);
    EXPECT_EQ(s1.GetLength(), s2.GetLength());
    for (int i = 0; i < s1.GetLength(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(Stack, can_get_size)
{
    Stack<int> s(5);

    EXPECT_EQ(5, s.GetLength());
}

TEST(Stack, can_set_and_get_element)
{
    Stack<int> s(5);
    s.push(6);
    EXPECT_EQ(6, s.pull());
}

TEST(Stack, can_assign_vector_to_itself)
{
    Stack<int> s(5);
    ASSERT_NO_THROW(s = s);
    
}

TEST(Stack, can_assign_vectors_of_equal_size)
{
    Stack<int> s1(5);
    Stack<int> s2(5);
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i);
    s2 = s1;
    EXPECT_EQ(s1.GetLength(), s2.GetLength());
    for (int i = 0; i < s1.GetLength(); i++)
        EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(Stack, can_assign_vectors_of_different_size)
{
    Stack<int> s1(10);
    Stack<int> s2(5);
    for (int i = 0; i < s1.GetLength(); i++)
    {
        s1.push(i);
    }
    for (int i = 0; i < s2.GetLength(); i++)
    {
        s2.push(i);
    }
    s2 = s1;
    EXPECT_EQ(s1.GetLength(), s2.GetLength());
    for (int i = 0; i < s1.GetLength(); i++)
    EXPECT_EQ(s1.pull(), s2.pull());
}

TEST(Stack, compare_equal_vectors_return_true)
{
    Stack<int> s1(5);
    Stack<int> s2(5);
    for (int i = 0; i < s1.GetLength(); i++)
    {
        s1.push(i+1);
        s2.push(i+1);
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

TEST(Stack, compare_vector_with_itself_return_true)
{
    Stack<int> s(5);
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

TEST(Stack, vectors_with_different_size_are_not_equal)
{
    Stack<int> s1(5);
    Stack<int> s2(10);
    bool f;
    f = (s1.GetLength() == s2.GetLength());
    if(f!=0)
        for (int i = 0; i < s1.GetLength(); i++)
        {
            if (f != 0)
                f = (s1.pull() == s2.pull());
            else break;
    }
    EXPECT_EQ(0, f);
}

TEST(Stack, find_even_number_maximum_in_stack)
{
    Stack<int> s1(10);
    for (int i = 0; i < s1.GetLength(); i++)
    {
        s1.push(i);
    }
    EXPECT_EQ(8, s1.EvMax());
}
TEST(Stack, copy_even_number_in_stack)
{
    Stack<int> s1(10);
    Stack<int> s2;
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i);
    s2.EvCopy(s1);
    for (int i = 0; i < s2.GetLength(); i++)
      EXPECT_EQ(2*i, s2.pull());

    
}
TEST(Stack, resize_stack_to_smaler_size)
{
    Stack<int> s1(10);
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i+1);
    s1.Resize(5);
    for (int i = 0; i < s1.GetLength(); i++)
        EXPECT_EQ(i+1, s1.pull());


}
TEST(Stack, resize_stack_to_lager_size)
{
    Stack<int> s1(5);
    for (int i = 0; i < s1.GetLength(); i++)
        s1.push(i + 1);
    s1.Resize(10);
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(i + 1, s1.pull());
    for (int i = 5; i < s1.GetLength(); i++)
        ASSERT_ANY_THROW(s1.pull());

}