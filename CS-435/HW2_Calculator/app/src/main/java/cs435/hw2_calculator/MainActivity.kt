package cs435.hw2_calculator

import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private lateinit var display: TextView
    private var currentNumber = ""
    private var operation = ""
    private var firstNumber: Double = 0.0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        display = findViewById(R.id.display)

        val buttons = listOf(
            findViewById<Button>(R.id.button0),
            findViewById<Button>(R.id.button1),
            findViewById<Button>(R.id.button2),
            findViewById<Button>(R.id.button3),
            findViewById<Button>(R.id.button4),
            findViewById<Button>(R.id.button5),
            findViewById<Button>(R.id.button6),
            findViewById<Button>(R.id.button7),
            findViewById<Button>(R.id.button8),
            findViewById<Button>(R.id.button9)
        )

        buttons.forEach { button ->
            button.setOnClickListener { onNumberClick(button.text.toString()) }
        }

        findViewById<Button>(R.id.buttonPlus).setOnClickListener { onOperationClick("+") }
        findViewById<Button>(R.id.buttonMinus).setOnClickListener { onOperationClick("-") }
        findViewById<Button>(R.id.buttonMultiply).setOnClickListener { onOperationClick("*") }
        findViewById<Button>(R.id.buttonDivide).setOnClickListener { onOperationClick("/") }
        findViewById<Button>(R.id.buttonExponent).setOnClickListener { onOperationClick("^") }
        findViewById<Button>(R.id.buttonModulus).setOnClickListener { onOperationClick("%") }

        findViewById<Button>(R.id.buttonCalculate).setOnClickListener { onEqualsClick() }
        findViewById<Button>(R.id.buttonClear).setOnClickListener { onClearClick() }

        findViewById<Button>(R.id.buttonSign).setOnClickListener { onSignToggleClick() }
    }

    private fun onNumberClick(number: String) {
        currentNumber += number
        display.text = currentNumber
    }

    private fun onOperationClick(op: String) {
        if (currentNumber.isNotEmpty()) {
            firstNumber = currentNumber.toDouble()
            currentNumber = ""
            operation = op
        }
    }

    private fun onEqualsClick() {
        if (currentNumber.isNotEmpty()) {
            val secondNumber = currentNumber.toDouble()
            val result = when (operation) {
                "+" -> firstNumber + secondNumber
                "-" -> firstNumber - secondNumber
                "*" -> firstNumber * secondNumber
                "/" -> if (secondNumber != 0.0) firstNumber / secondNumber else getString(R.string.error_divide_by_zero)
                "^" -> Math.pow(firstNumber, secondNumber)
                "%" -> firstNumber % secondNumber
                else -> 0
            }
            display.text = result.toString()
            currentNumber = result.toString()
        }
    }

    private fun onClearClick() {
        currentNumber = ""
        firstNumber = 0.0
        operation = ""
        display.text = getString(R.string.initial_display_value)
    }

    private fun onSignToggleClick() {
        if (currentNumber.isNotEmpty()) {
            currentNumber = if (currentNumber.startsWith("-")) {
                currentNumber.removePrefix("-")
            } else {
                "-$currentNumber"
            }
            display.text = currentNumber
        }
    }
}