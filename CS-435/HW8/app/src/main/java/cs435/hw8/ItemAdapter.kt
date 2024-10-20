package cs435.hw8

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class ItemAdapter(private val taskList: List<Task>) : RecyclerView.Adapter<ItemAdapter.ViewHolder>() {
    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val taskName: TextView = view.findViewById(R.id.item_name)
        val taskDescription: TextView = view.findViewById(R.id.item_description)
        val taskPriority: TextView = view.findViewById(R.id.item_priority)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_layout, parent, false)
        return ViewHolder(view)
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        val currentTask = taskList[position]
        holder.taskName.text = currentTask.name
        holder.taskDescription.text = currentTask.description
        holder.taskPriority.text = "Priority: ${currentTask.priority}"
    }

    override fun getItemCount(): Int {
        return taskList.size
    }
}