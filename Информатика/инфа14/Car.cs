public class Car : ICar
{
    public IFuelTank FuelTank { get; }
    public IEngine Engine { get; }
    public IFuelTankDisplay FuelTankDisplay { get; }

    public Car()
    {
        FuelTank = new FuelTank();
        Engine = new Engine(FuelTank);
        FuelTankDisplay = new FuelTankDisplay(FuelTank);
    }
}
