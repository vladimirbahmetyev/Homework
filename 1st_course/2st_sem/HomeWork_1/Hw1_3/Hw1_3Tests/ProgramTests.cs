using Microsoft.VisualStudio.TestTools.UnitTesting;
using Hw1_3;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hw1_3.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void SortTest1()
        {
            const int sizeOfArray = 10;
            int[] testArray = new int[sizeOfArray] { 1, 6, 7, 3, 7, 2, 1, 8, 17, 0 };
            Program.Sort(testArray, sizeOfArray);
            bool flag = true;
            for (int i = 0;i < sizeOfArray - 1; i++)
            {
                flag = flag && (testArray[i] <= testArray[i + 1]);
            }
            Assert.AreEqual(true, flag);
        }

        [TestMethod()]
        public void SortTest2()
        {
            const int sizeOfArray = 3;
            int[] testArray = new int[sizeOfArray] { 1, 1, 1};
            Program.Sort(testArray, sizeOfArray);
            bool flag = true;
            for (int i = 0; i < sizeOfArray - 1; i++)
            {
                flag = flag && (testArray[i] <= testArray[i + 1]);
            }
            Assert.AreEqual(true, flag);
        }

        [TestMethod()]
        public void SortTest3()
        {
            const int sizeOfArray = 1;
            int[] testArray = new int[sizeOfArray] { 1 };
            Program.Sort(testArray, sizeOfArray);
            bool flag = true;
            for (int i = 0; i < sizeOfArray - 1; i++)
            {
                flag = flag && (testArray[i] <= testArray[i + 1]);
            }
            Assert.AreEqual(true, flag);
        }

        [TestMethod()]
        public void SortTest4()
        {
            const int sizeOfArray = 3;
            int[] testArray = new int[sizeOfArray] { 1, 2, 3 };
            Program.Sort(testArray, sizeOfArray);
            bool flag = true;
            for (int i = 0; i < sizeOfArray - 1; i++)
            {
                flag = flag && (testArray[i] <= testArray[i + 1]);
            }
            Assert.AreEqual(true, flag);
        }
    }
}