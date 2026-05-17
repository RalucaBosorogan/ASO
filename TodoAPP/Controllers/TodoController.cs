using Microsoft.AspNetCore.Mvc;
using TodoAPP.Models;

namespace TodoAPP.Controllers
{
    public class TodoController : Controller
    {
        private static readonly List<ToDoItem> _toDoList = new()
        {
            new ToDoItem { Id = 1, Nume = "Cumpara produse", EsteFinalizat = false },
            new ToDoItem { Id = 2, Nume = "Tunde iarba", EsteFinalizat = true }
        };

        public IActionResult Index() => View(_toDoList);

        [HttpPost]
        public IActionResult Create(string nouTask)
        {
            if (string.IsNullOrWhiteSpace(nouTask))
                return RedirectToAction("Index");

            _toDoList.Add(new ToDoItem
            {
                Id = _toDoList.Count > 0 ? _toDoList.Select(x => x.Id).Max() + 1 : 1,
                Nume = nouTask,
                EsteFinalizat = false
            });

            return RedirectToAction("Index");
        }

        [HttpPost]
        public IActionResult ToggleComplete(int id)
        {
            var task = _toDoList.Find(x => x.Id == id);
            if (task != null)
            {
                task.EsteFinalizat = !task.EsteFinalizat;
            }
            return RedirectToAction("Index");
        }

        [HttpPost]
        public IActionResult Delete(int id)
        {
            var task = _toDoList.Find(x => x.Id == id);
            if (task != null)
            {
                _toDoList.Remove(task);
            }
            return RedirectToAction("Index");
        }
    }
}