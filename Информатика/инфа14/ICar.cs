public interface ICar
{
    IFuelTank FuelTank { get; }
    IEngine Engine { get; }
    IFuelTankDisplay FuelTankDisplay { get; }
}
