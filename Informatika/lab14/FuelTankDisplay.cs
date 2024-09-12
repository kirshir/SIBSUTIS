public class FuelTankDisplay : IFuelTankDisplay
{
    private readonly IFuelTank fuelTank;

    public FuelTankDisplay(IFuelTank fuelTank)
    {
        this.fuelTank = fuelTank;
    }

    public double CurrentFuelLevel => Math.Round(fuelTank.FillLevel, 2);
}
