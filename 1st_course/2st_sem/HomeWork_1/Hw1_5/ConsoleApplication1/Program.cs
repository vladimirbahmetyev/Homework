using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hw1_5
{
    public class Program
    {
        public static void SwapString(int[,] matrix, int firstString, int secondString, int sizeOfString)
        {
            for (int i = 0; i < sizeOfString; i++)
            {
                int timeNumber = matrix[firstString,i];
                matrix[firstString, i] = matrix[secondString, i];
                matrix[secondString, i] = timeNumber;
            }
        }
        public static void MatrixSort(int[,] matrix, int sizeOfString, int countOfString)
        {
            const int firstElement = 0;
            for (int i = 0; i < countOfString; i++)
            {
                int min = matrix[i,firstElement];
                int minNumber = i;
                for (int j = i + 1; j < countOfString; j++)
                {
                    if (matrix[j, firstElement] < min)
                    {
                        min = matrix[j, firstElement];
                        minNumber = j;
                    }
                }
                Program.SwapString(matrix, i, minNumber, sizeOfString);
            }
        }
            static void Main(string[] args)
        {
        }
    }
}
