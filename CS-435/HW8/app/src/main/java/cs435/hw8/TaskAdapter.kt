package cs435.hw8

import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class TaskAdapter(
    private var tasks: List<Task>,
    private val onTaskClick: (Task) -> Unit
) : RecyclerView.Adapter<TaskAdapter.TaskViewHolder>() {

    // Holds the views for each task item in the recyclerView
    inner class TaskViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val nameTextView: TextView = itemView.findViewById(R.id.item_name)
        val priorityTextView: TextView = itemView.findViewById(R.id.item_priority)
        val descriptionTextView: TextView = itemView.findViewById(R.id.item_description)

        // bind task object data to the views
        fun bind(task: Task) {
            nameTextView.text = task.name
            descriptionTextView.text = task.description
            priorityTextView.text = "Priority: ${task.priority}"

            when (task.priority) {
                1 -> itemView.setBackgroundColor(Color.RED)
                2 -> itemView.setBackgroundColor(Color.YELLOW)
                3 -> itemView.setBackgroundColor(Color.GREEN)
            }

            itemView.setOnClickListener { onTaskClick(task) }
        }
    }

    // Called when recyclerView needs a new viewHolder to display an item
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): TaskViewHolder {
        val view = LayoutInflater.from(parent.context)
            .inflate(R.layout.task_layout, parent, false)
        return TaskViewHolder(view)
    }

    // Called to display data at the specific position
    override fun onBindViewHolder(holder: TaskViewHolder, position: Int) {
        holder.bind(tasks[position])
    }

    override fun getItemCount() = tasks.size

    // Updates list and refreshes the recyclerView
    fun updateTasks(newTasks: List<Task>) {
        tasks = newTasks
        notifyDataSetChanged()
    }
}