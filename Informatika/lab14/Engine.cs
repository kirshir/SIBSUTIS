public class Engine : IEngine
{
    private readonly IFuelTank fuelTank;

    public Engine(IFuelTank fuelTank)
    {
        this.fuelTank = fuelTank;
    }

    public void Start()
    {
        Console.WriteLine("Engine started.");
    }

    public void Stop()
    {
        Console.WriteLine("Engine stopped.");
    }
}
