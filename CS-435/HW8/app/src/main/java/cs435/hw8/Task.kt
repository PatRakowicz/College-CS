package cs435.hw8

class Task(
    val id: Int,
    var name: String,
    var description: String,
    var priority: Int
) {
    companion object {
        private var nextId = 1
        private val taskList: MutableList<Task> = mutableListOf()

        // Hardcoded for testing
        init {
            addTask("Task 1", "Description of task 1", 1)
            addTask("Task 2", "Description of task 2", 2)
            addTask("Task 3", "Description of task 3", 3)
        }

        fun getTaskList(): List<Task> {
            return taskList
        }

        fun addTask(name: String, description: String, priority: Int) {
            val task = Task(nextId++, name, description, priority)
            taskList.add(task)
        }

        fun deleteTask(taskId: Int) {
            val task = taskList.find { it.id == taskId }
            task?.let { taskList.remove(it) }
        }

        fun getTaskById(taskId: Int): Task? {
            return taskList.find { it.id == taskId }
        }

        fun updateTask(updatedTask: Task) {
            val task = taskList.find { it.id == updatedTask.id }
            task?.let {
                it.name = updatedTask.name
                it.description = updatedTask.description
                it.priority = updatedTask.priority
            }
        }
    }

    override fun toString(): String {
        return name
    }
}