using Microsoft.VisualStudio.TestTools.UnitTesting;
using hw1_1;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw1_1.Tests
{
    [TestClass()]
    public class ProgramTests
    {
        [TestMethod()]
        public void FactorialTest1()
        {
            Assert.AreEqual(120, Program.Factorial(5));
        }
        [TestMethod()]
        public void FactorialTest2()
        {
            Assert.AreEqual(1, Program.Factorial(1));
        }
        [TestMethod()]
        public void FactorialTest3()
        {
            Assert.AreEqual(6, Program.Factorial(3));
        }
        [TestMethod()]
        public void FactorialTest4()
        {
            Assert.AreEqual(-1, Program.Factorial(-32));
        }
    }
}