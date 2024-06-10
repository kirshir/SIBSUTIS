public interface IFuelTank
{
    double FillLevel { get; }
    bool IsOnReserve { get; }
    bool IsComplete { get; }
}
