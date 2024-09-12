using src;

namespace TestApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            // Создаем связанный список строк
            var linkedList = new LinkedList<string>(new[] { "apple", "banana", "orange", "grape", "kiwi" });

            // Определяем условие для фильтрации
            src.HW12_11.CounterLinkedListDelegate filter = s => s.Length > 5;

            // Вызываем метод Function11 для подсчета элементов, удовлетворяющих условию
            int count = src.HW12_11.Function11(linkedList, filter);

            // Выводим результат
            Console.WriteLine($"Количество элементов, удовлетворяющих условию: {count}");
        }
    }
}
