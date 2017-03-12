using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hw1_4
{
    class Program
    {
        static void PrintMatrix(int[,] matrix, int sizeOfMatrix)
        {
            bool horizontal = true;
            bool vertical = true;
            int[] position = new int[2] { sizeOfMatrix / 2, sizeOfMatrix / 2 };
            Console.Write("{0} ", matrix[position[0], position[1]]);
            for (int i = 1; i <= sizeOfMatrix; i++)
            {
                for (int j = 0; j <i; j++)
                {
                    if (horizontal)
                    {
                        position[1]++;
                        if (position[0] >= sizeOfMatrix || position[1] >= sizeOfMatrix)
                        {
                            return;
                        }
                        Console.Write("{0} ", matrix[position[0], position[1]]);
                    }
                    else
                    {
                        position[1]--;
                        Console.Write("{0} ", matrix[position[0], position[1]]);
                    }
                }
                for (int j = 0; j < i; j++)
                {
                    if (vertical)
                    {
                        position[0]++;

                        if (position[0] >= sizeOfMatrix || position[1] >= sizeOfMatrix)
                        {
                            return;
                        }
                        Console.Write("{0} ", matrix[position[0], position[1]]);
                    }
                    else
                    {
                        position[0]--;
                        Console.Write("{0} ", matrix[position[0], position[1]]);
                    }           
                }
                horizontal = !horizontal;
                vertical = !vertical;
            }
        }

        static void Main(string[] args)
        {
            int sizeOfMatrix = 3;
            int[,] matrix = new int[3, 3] { {7, 8, 9},{6,1 ,2},{5, 4, 3} };
            PrintMatrix(matrix, sizeOfMatrix);            
        }
    }
}
