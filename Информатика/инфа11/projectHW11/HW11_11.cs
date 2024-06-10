namespace src;

public static partial class HW11
{
    public static int Function11(int[] array)
    {
        int minOdd = int.MaxValue;
        foreach (int item in array)
        {
            if(item % 2 != 0 && item < minOdd)
            {
                minOdd = item;
            }
        }
        if (minOdd == int.MaxValue)
        {
            Console.WriteLine("В массиве нет нечетных элементов");
            return 0;
        }
        return minOdd;
    }
}