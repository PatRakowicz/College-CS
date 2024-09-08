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
    private lateinit var button0: Button
    private lateinit var button1: Button
    private lateinit var button2: Button
    private lateinit var button3: Button
    private lateinit var button4: Button
    private lateinit var button5: Button
    private lateinit var button6: Button
    private lateinit var button7: Button
    private lateinit var button8: Button
    private lateinit var button9: Button
    private lateinit var buttonPlus: Button
    private lateinit var buttonMinus: Button
    private lateinit var buttonMultiply: Button
    private lateinit var buttonDivide: Button
    private lateinit var buttonModulus: Button
    private lateinit var buttonExponent: Button
    private lateinit var buttonClear: Button
    private lateinit var buttonSign: Button
    private lateinit var buttonCalculate: Button

    private var currentNumber = ""
    private var operation = ""
    private var firstNumber: Double = 0.0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        display = findViewById(R.id.display)
        button0 = findViewById(R.id.button0)
        button1 = findViewById(R.id.button1)
        button2 = findViewById(R.id.button2)
        button3 = findViewById(R.id.button3)
        button4 = findViewById(R.id.button4)
        button5 = findViewById(R.id.button5)
        button6 = findViewById(R.id.button6)
        button7 = findViewById(R.id.button7)
        button8 = findViewById(R.id.button8)
        button9 = findViewById(R.id.button9)
        buttonPlus = findViewById(R.id.buttonPlus)
        buttonMinus = findViewById(R.id.buttonMinus)
        buttonMultiply = findViewById(R.id.buttonMultiply)
        buttonDivide = findViewById(R.id.buttonDivide)
        buttonModulus = findViewById(R.id.buttonModulus)
        buttonExponent = findViewById(R.id.buttonExponent)
        buttonClear = findViewById(R.id.buttonClear)
        buttonSign = findViewById(R.id.buttonSign)
        buttonCalculate = findViewById(R.id.buttonCalculate)

        button0.setOnClickListener { onNumberClick("0") }
        button1.setOnClickListener { onNumberClick("1") }
        button2.setOnClickListener { onNumberClick("2") }
        button3.setOnClickListener { onNumberClick("3") }
        button4.setOnClickListener { onNumberClick("4") }
        button5.setOnClickListener { onNumberClick("5") }
        button6.setOnClickListener { onNumberClick("6") }
        button7.setOnClickListener { onNumberClick("7") }
        button8.setOnClickListener { onNumberClick("8") }
        button9.setOnClickListener { onNumberClick("9") }

        buttonPlus.setOnClickListener { onOperationClick("+") }
        buttonMinus.setOnClickListener { onOperationClick("-") }
        buttonMultiply.setOnClickListener { onOperationClick("*") }
        buttonDivide.setOnClickListener { onOperationClick("/") }
        buttonModulus.setOnClickListener { onOperationClick("%") }
        buttonExponent.setOnClickListener { onOperationClick("^") }

        buttonClear.setOnClickListener { onClearClick() }
        buttonSign.setOnClickListener { onSignToggleClick() }
        buttonCalculate.setOnClickListener { onEqualsClick() }
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