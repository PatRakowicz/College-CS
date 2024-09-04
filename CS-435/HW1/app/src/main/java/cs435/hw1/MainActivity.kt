package cs435.hw1

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlin.random.Random

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)

        val questionInput = findViewById<EditText>(R.id.question_input)
        val getAnswerButton = findViewById<Button>(R.id.get_answer_button)
        val answerText = findViewById<TextView>(R.id.answer_text)

        val responses = resources.getStringArray(R.array.magic_8_ball_responses)

        getAnswerButton.setOnClickListener {
            // Check if user input anything
            val question = questionInput.text.toString().trim()
            if (question.isEmpty()) {
                Toast.makeText(this, R.string.ask_question, Toast.LENGTH_SHORT).show()
            } else {
                val randomIndex = Random.nextInt(responses.size)
                val randomResponse = responses[randomIndex]

                answerText.text = randomResponse
            }
        }

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }
}