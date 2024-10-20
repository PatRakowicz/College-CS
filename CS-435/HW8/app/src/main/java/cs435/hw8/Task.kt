package cs435.hw8

class Task (
    var name: String,
    var description: String,
    var priority: Int
) {
    companion object {
        // hard code for now
        private val taskList = listOf(
            Task("Task 1", "Description of task 1", 1),
            Task("Task 2", "Description of task 2", 2),
            Task("Task 3", "Description of task 3", 3),
        )
        fun getTaskList(): List<Task> {
            return taskList
        }
    }

    override fun toString(): String {
        return name ?: ""
    }
}