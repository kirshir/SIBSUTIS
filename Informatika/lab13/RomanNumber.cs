using System;

namespace RomanNumber.Models
{
    public class RomanNumber : ICloneable, IComparable
    {
        private ushort value;

        public RomanNumber(ushort n)
        {
            if (n < 1 || n > 3999)
                throw new RomanNumberException("Invalid Roman number. Must be in the range [1; 3999].");

            value = n;
        }

        public static RomanNumber Add(RomanNumber? n1, RomanNumber? n2)
        {
            // Implement addition logic
            // Check for possible exceptions and throw RomanNumberException if needed
        }

        public static RomanNumber operator +(RomanNumber? n1, RomanNumber? n2)
        {
            return Add(n1, n2);
        }

        public static RomanNumber Sub(RomanNumber? n1, RomanNumber? n2)
        {
            // Implement subtraction logic
            // Check for possible exceptions and throw RomanNumberException if needed
        }

        public static RomanNumber operator -(RomanNumber? n1, RomanNumber? n2)
        {
            return Sub(n1, n2);
        }

        // Implement Mul, Div, ToString, Clone, CompareTo methods similarly

        public object Clone()
        {
            return new RomanNumber(value);
        }

        public int CompareTo(object? obj)
        {
            if (obj == null)
                return 1;

            if (obj is RomanNumber otherRomanNumber)
            {
                return value.CompareTo(otherRomanNumber.value);
            }

            throw new ArgumentException("Object is not a RomanNumber");
        }
    }
}

public static RomanNumber Add(RomanNumber? n1, RomanNumber? n2)
{
    if (n1 == null || n2 == null)
        throw new RomanNumberException("Cannot perform addition with null operands.");

    ushort result = (ushort)(n1.value + n2.value);

    if (result > 3999)
        throw new RomanNumberException("Result exceeds the maximum Roman number representation (3999).");

    return new RomanNumber(result);
}

public static RomanNumber Sub(RomanNumber? n1, RomanNumber? n2)
{
    if (n1 == null || n2 == null)
        throw new RomanNumberException("Cannot perform subtraction with null operands.");

    if (n1.value < n2.value)
        throw new RomanNumberException("Result of subtraction cannot be negative in Roman numerals.");

    ushort result = (ushort)(n1.value - n2.value);
    return new RomanNumber(result);
}

public static RomanNumber Mul(RomanNumber? n1, RomanNumber? n2)
{
    if (n1 == null || n2 == null)
        throw new RomanNumberException("Cannot perform multiplication with null operands.");

    ushort result = (ushort)(n1.value * n2.value);

    if (result > 3999)
        throw new RomanNumberException("Result exceeds the maximum Roman number representation (3999).");

    return new RomanNumber(result);
}

public static RomanNumber Div(RomanNumber? n1, RomanNumber? n2)
{
    if (n1 == null || n2 == null)
        throw new RomanNumberException("Cannot perform division with null operands.");

    if (n2.value == 0)
        throw new RomanNumberException("Cannot divide by zero in Roman numerals.");

    ushort result = (ushort)(n1.value / n2.value);
    return new RomanNumber(result);
}