using Microsoft.VisualStudio.TestTools.UnitTesting;
using Hw1_2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hw1_2.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void FibonacciTest1()
        {
            Assert.AreEqual(1, Program.Fibonacci(1));
        }
        [TestMethod()]
        public void FibonacciTest2()
        {
            Assert.AreEqual(1, Program.Fibonacci(2));
        }
        [TestMethod()]
        public void FibonacciTest3()
        {
            Assert.AreEqual(8, Program.Fibonacci(6));
        }
        [TestMethod()]
        public void FibonacciTest4()
        {
            Assert.AreEqual(55, Program.Fibonacci(10));
        }
    }
}