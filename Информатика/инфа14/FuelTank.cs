public class FuelTank : IFuelTank
{
    private const double MaxCapacity = 60.0;
    private const double StandardLevel = 20.0;
    private const double ReserveLevel = 5.0;

    public double FillLevel { get; private set; } = StandardLevel;

    public bool IsOnReserve => FillLevel <= ReserveLevel;

    public bool IsComplete => FillLevel == MaxCapacity;
}
