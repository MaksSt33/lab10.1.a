#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.1a/lab10.1a.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFindMaxAverage)
        {
            Student students[3] = {
                { "Ivanenko", 1, KN, {5, 4, 3} },
                { "Petrenko", 2, PM, {4, 4, 4} },
                { "Semenko", 3, FI, {3, 3, 5} }
            };

            double maxAverage = FindMaxAverage(students, 3);
            Assert::AreEqual(4.0, maxAverage);
        }

        TEST_METHOD(TestCalculatePhysicsHighGradesPercentage)
        {
            Student students[4] = {
                { "Ivanenko", 1, KN, {5, 4, 3} },
                { "Petrenko", 2, PM, {4, 3, 4} },
                { "Semenko", 3, FI, {3, 4, 5} },
                { "Boyko", 1, KN, {2, 4, 4} }
            };

            double percentage = PhysicsPercentage(students, 4);
            Assert::AreEqual(50.0, percentage);
        }
    };
}
