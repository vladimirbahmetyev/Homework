using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hw1_3
{
    public class Program
    {
        public static void Sort(int[] array, int sizeOfArray)
        {
            for (int i = 0; i < sizeOfArray - 1; i++)
            {
                int min = array[i];
                int minNumber = i;
                for (int j = i + 1; j < sizeOfArray; j++)
                {
                    if (array[j] < min)
                    {
                        min = array[j];
                        minNumber = j;
                    }
                }
                array[minNumber] = array[i];
                array[i] = min;
            }
        }
        static void Main(string[] args)
        {
        }
    }
}
