
class Program
{
    public static void Main()
    {
        string[] cities =
        {
            "ROME", "LONDON", "NAIROBI", "CALIFORNIA",
            "ZURICH", "NEWDELHI", "AMSTERDAM",
            "ABU DHABI", "PARIS"
        };

        Console.Write("Enter starting character: ");
        char firstLetter = Char.ToUpper(Console.ReadLine()[0]);

        Console.Write("Enter ending character: ");
        char lastLetter = Char.ToUpper(Console.ReadLine()[0]);

        var filteredCities = cities.Where(city =>
            city.StartsWith(firstLetter.ToString()) &&
            city.EndsWith(lastLetter.ToString()));

        Console.WriteLine("\nMatching Cities:");

        foreach (var city in filteredCities)
        {
            Console.WriteLine(city);
        }
    }
}