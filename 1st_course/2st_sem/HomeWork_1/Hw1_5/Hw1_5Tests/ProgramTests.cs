using Microsoft.VisualStudio.TestTools.UnitTesting;
using Hw1_5;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hw1_5.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        const int sizeOfString = 2;
        [TestMethod()]
        public void SwapStringTest()
        {
            int[,] testMatrix = new int[sizeOfString,sizeOfString] { { 1,2}, { 3,4 } };
            Program.SwapString(testMatrix, 0, 1, sizeOfString);
            Assert.AreEqual(true, testMatrix[0, 0] == 3 && testMatrix[0, 1] == 4 && testMatrix[1, 0] == 1 && testMatrix[1, 1] == 2);
        }

        [TestMethod()]
        public void MatrixSortTest()
        {
            int[,] testMatrix = new int[3, 2] { { 5, 2 }, { 3, 4 }, { 1,2 } };
            Program.MatrixSort(testMatrix, sizeOfString, sizeOfString + 1);
            bool flag = true;
            for (int i = 0; i < sizeOfString; i++)
            {
                flag = flag && (testMatrix[i, 0] <= testMatrix[i + 1, 0]);
            }
            Assert.AreEqual(true, flag);
        }
    }
}