namespace TodoAPP.Models
{
    public class ToDoItem
    {
        public int Id { get; set; }
        public string Nume { get; set; } = string.Empty;
        public bool EsteFinalizat { get; set; }
    }
}