package cs435.hw8

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.activity.OnBackPressedCallback
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class ViewTaskActivity : AppCompatActivity() {
    private lateinit var task: Task
    private lateinit var priorityEditText: EditText
    private lateinit var deleteButton : Button
    private lateinit var taskName : TextView
    private lateinit var taskDescription: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_view_task)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        taskName = findViewById(R.id.taskName)
        taskDescription = findViewById(R.id.taskDescription)
        priorityEditText = findViewById(R.id.priorityEditText)
        deleteButton = findViewById(R.id.deleteButton)

        val taskId = intent.getIntExtra("TASK_ID", -1)
        task = Task.getTaskById(taskId) ?: return

        taskName.text = task.name
        taskDescription.text = task.description
        priorityEditText.setText(task.priority.toString())

        deleteButton.setOnClickListener {
            Task.deleteTask(task.id)
            setResult(RESULT_OK)
            finish()
        }

        // https://developer.android.com/reference/kotlin/androidx/activity/OnBackPressedDispatcher | Dev notes
        // https://www.youtube.com/watch?v=fL5UggoTBbI&ab_channel=Codingwithcat | An example
        onBackPressedDispatcher.addCallback(this, object : OnBackPressedCallback(true) {
            override fun handleOnBackPressed() {
                val newPriority = priorityEditText.text.toString().toIntOrNull()

                if (newPriority != null && newPriority in 1..3) {
                    task.priority = newPriority
                    Task.updateTask(task)
                }

                setResult(RESULT_OK)
                finish()
            }
        })
    }
}