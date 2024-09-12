using System;
namespace src 
{
    public static partial class HW12_11
    {
        public delegate bool CounterLinkedListDelegate(string str);
        public static int Function11(LinkedList<string> linkedListString, CounterLinkedListDelegate filter) {
            int count = 0;
            foreach(var item in linkedListString) {
                if (filter(item)) {
                    count ++;
                }
            }
            return count;
        }
    }
}