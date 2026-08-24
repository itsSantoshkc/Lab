using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using WebApplication1.Models;

namespace WebApplication1.Controllers;

public class HomeController : Controller
{
    public IActionResult Index(double? principal, double? time, double? rate)
    {
        if (principal.HasValue && time.HasValue && rate.HasValue)
        {
            double interest = (principal.Value * time.Value * rate.Value) / 100;
            ViewBag.Interest = interest;
        }

        return View();
    }

    [HttpPost]
    public IActionResult AddTodo(string? title)

    {
        Console.WriteLine(title);
        return RedirectToAction("Index");
    }
    public IActionResult Privacy()
    {
        return View();
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}
