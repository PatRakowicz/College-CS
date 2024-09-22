package cs435.hw4_stooptest

import android.graphics.Color
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlin.random.Random

class MainActivity : AppCompatActivity() {

    private lateinit var colorText: TextView;
    private lateinit var scoreText: TextView;
    private lateinit var correctButton: Button;
    private lateinit var wrongButton: Button;

    private var correctScore = 0
    private var wrongScore = 0
    private var colors = arrayOf(
        "RED", "GREEN", "BLUE", "YELLOW", "MAGENTA", "CYAN"
    );
    private var colorValue = arrayOf(
        Color.RED, Color.GREEN, Color.BLUE, Color.YELLOW, Color.MAGENTA, Color.CYAN
    )
    private var currentColorIndex = 0
    private var displayedTextColorIndex = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        colorText = findViewById(R.id.colorText)
        scoreText = findViewById(R.id.scoreText)
        correctButton = findViewById(R.id.correctButton)
        wrongButton = findViewById(R.id.wrongButton)

        /*
        if (savedInstanceState != null) {
            score = savedInstanceState.getInt("score")
            wrongScore = savedInstanceState.getInt"wrongScore")
        }
        else { score = 0 wrongScore = 0 }
        */
//        https://kotlinlang.org/docs/null-safety.html
//        Did not know you can compress an if statement with an null-safety operator
        correctScore = savedInstanceState?.getInt("correctScore") ?: 0
        wrongScore = savedInstanceState?.getInt("wrongScore") ?: 0
        currentColorIndex =
            savedInstanceState?.getInt("currentColorIndex") ?: Random.nextInt(colors.size)
        displayedTextColorIndex =
            savedInstanceState?.getInt("displayedTextColorIndex") ?: Random.nextInt(colors.size)
        /*==========*/

        updateScore()
        updateColorText()

        correctButton.setOnClickListener {
            if (isCorrectColor()) correctScore++ else wrongScore++
            updateScore()
            displayNewColor()
        }

        wrongButton.setOnClickListener {
            if (!isCorrectColor()) correctScore++ else wrongScore++
            updateScore()
            displayNewColor()
        }
    }

    private fun displayNewColor() {
        currentColorIndex = Random.nextInt(colors.size)
        displayedTextColorIndex = Random.nextInt(colors.size)

        colorText.text = colors[displayedTextColorIndex]
        colorText.setTextColor(colorValue[currentColorIndex])
    }

    private fun updateColorText() {
        colorText.text = colors[displayedTextColorIndex]
        colorText.setTextColor(colorValue[currentColorIndex])
    }

    private fun isCorrectColor(): Boolean {
        return currentColorIndex == displayedTextColorIndex
    }

    private fun updateScore() {
        scoreText.text = "Correct: $correctScore | Wrong: $wrongScore"
    }

    override fun onPause() {
        super.onPause()
        scoreText.text = "Score: 0"
    }

    override fun onResume() {
        super.onResume()
        updateScore()
    }

    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        outState.putInt("correctScore", correctScore)
        outState.putInt("wrongScore", wrongScore)
        outState.putInt("currentColorIndex", currentColorIndex)
        outState.putInt("displayedTextColorIndex", displayedTextColorIndex)
    }

    override fun onRestoreInstanceState(savedInstanceState: Bundle) {
        super.onRestoreInstanceState(savedInstanceState)
        correctScore = savedInstanceState.getInt("correctScore")
        wrongScore = savedInstanceState.getInt("wrongScore")
        currentColorIndex = savedInstanceState.getInt("currentColorIndex")
        displayedTextColorIndex = savedInstanceState.getInt("displayedTextColorIndex")
        updateScore()
        updateColorText()
    }
}