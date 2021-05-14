// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(test,prefix_t)
{
    vector<string> v{"a","b","c","d"};
    textgen t(2,v);
    map<prefix,vector<string>> table = t.get_table();
    ASSERT_EQ(table.begin()->first,prefix{"a","b"});
}
TEST(test,prefix-suffix)
{
    vector<string> v{"a","b","c","d"};
    textgen t(2,v);
    map<prefix,vector<string>> table = t.get_table();
    ASSERT_EQ(table.begin()->second,vector<string>{"a"});
}
TEST(test,prefix-suffix-2)
{
    vector<string> v{"a","b","c","d","a","c"};
    textgen t(2,v);
    map<prefix,vector<string>> table = t.get_table();
    ASSERT_EQ(table.begin()->second,vector<string>{"b","c"});
}
TEST(test,text)
{
    vector<string> v{"a","b","c","d"};
    textgen t(2,v);
    string text = t.generate(3);
    ASSERT_EQ(text,"a b c ");
}