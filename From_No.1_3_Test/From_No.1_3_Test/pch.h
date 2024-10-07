//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>

/**
 *データを入れる構造体です。
 *
 * @param Score スコア
 * @param Name  名前
 */
struct DATA
{
    int Score = 0;
    std::string Name = "Dummy";
};
