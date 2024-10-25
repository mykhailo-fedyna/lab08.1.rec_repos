#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountSymbols)
        {
            char str[] = "a+b=c-+-=+-";
            int plusCount = 0, minusCount = 0, equalCount = 0;

            CountSymbols(str, plusCount, minusCount, equalCount);

            // Перевіряємо, що кількість символів '+' дорівнює 2, '-' дорівнює 2, '=' дорівнює 2
            Assert::AreEqual(3, plusCount);
            Assert::AreEqual(3, minusCount);
            Assert::AreEqual(2, equalCount);
        }

        TEST_METHOD(TestReplacePairs)
        {
            char str[] = "++--==";
            char expected[] = "*********";
            char dest[151];
            dest[0] = '\0';

            ReplacePairs(dest, str, dest);

            // Перевіряємо, що результат заміни співпадає з очікуваним
            Assert::AreEqual(expected, dest);
        }
    };
}
