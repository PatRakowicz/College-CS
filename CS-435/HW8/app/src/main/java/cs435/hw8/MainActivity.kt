package cs435.hw8

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.ActivityResultLauncher
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class MainActivity : AppCompatActivity() {
    private lateinit var taskAdapter: TaskAdapter
    private lateinit var recyclerView: RecyclerView
    private lateinit var addTaskButton: Button

    private lateinit var addTaskLauncher: ActivityResultLauncher<Intent>
    private lateinit var viewTaskLauncher: ActivityResultLauncher<Intent>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        recyclerView = findViewById(R.id.recyclerView)
        addTaskButton = findViewById(R.id.addTaskButton)

        taskAdapter = TaskAdapter(Task.getTaskList()) { task -> onTaskSelected(task) }
        recyclerView.adapter = taskAdapter
        recyclerView.layoutManager = LinearLayoutManager(this)


        // https://stackoverflow.com/questions/61455381/how-to-replace-startactivityforresult-with-activity-result-apis
        addTaskLauncher = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
            if (result.resultCode == RESULT_OK) { taskAdapter.updateTasks(Task.getTaskList()) }
        }

        viewTaskLauncher = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
            if (result.resultCode == RESULT_OK) { taskAdapter.updateTasks(Task.getTaskList()) }
        }

        addTaskButton.setOnClickListener {
            val intent = Intent(this, AddTaskActivity::class.java)
            addTaskLauncher.launch(intent)
        }
    }

    private fun onTaskSelected(task: Task) {
        val intent = Intent(this, ViewTaskActivity::class.java)
        intent.putExtra("TASK_ID", task.id)
        viewTaskLauncher.launch(intent)
    }
}