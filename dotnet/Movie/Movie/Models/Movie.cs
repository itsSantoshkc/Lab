namespace Movie.Models;

public class Movie
{
    public int      Id          { get; set; }
    public string   Title       { get; set; } = string.Empty;
    public string?  Description { get; set; }
    public float    rating { get; set; }
    public string   Director       { get; set; } = string.Empty;
    
    public DateTime CreatedAt   { get; set; } = DateTime.UtcNow;
    
    public DateTime? releasedAt { get; set; }

    // Foreign key — which user owns this todo
    public int    UserId { get; set; }
    public User?  User   { get; set; }  // navigation property
}





