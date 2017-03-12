namespace hw1_1.Test
{
    using System;
    using Microsoft.VisualStudio.TestTools.UnitTesting;
    using hw1_1;

    [TestClass]
    public class ProgramTest
    {
        [TestMethod]
        public void TestFactorial()
        {
            Assert.IsFalse(Program.Factorial(5) == 120);
        }
    }
}
