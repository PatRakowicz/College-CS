package cd435.act2

import android.graphics.Color
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.RadioButton
import android.widget.RadioGroup
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.SwitchCompat
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private lateinit var dark: SwitchCompat
    private lateinit var colorGroup: RadioGroup
    private lateinit var submitButton: Button
    private lateinit var colorText: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        dark = findViewById(R.id.switchDark)
        colorGroup = findViewById(R.id.groupColor)
        submitButton = findViewById(R.id.buttonSubmit)
        colorText = findViewById(R.id.TextViewDisplay)
    }

    fun buttonClick(view: View) {
//        submitButton.text = "test"
        val selectedColor = colorGroup.checkedRadioButtonId
        val radioButton = findViewById<RadioButton>(selectedColor)
        val colorName = radioButton.text.toString()

        val isDark = dark.isChecked
        val color = getColor(colorName, isDark)
        setButtonColor(color)


        colorText.setText(colorName)
    }

    fun getColor(color: String, isDark : Boolean) : Int {
        return when (color) {
            "Red" -> if(isDark) Color.rgb(150, 0, 0) else Color.RED
            "Green" -> if(isDark) Color.rgb(0, 150, 0) else Color.GREEN
            "Blue" -> if (isDark) Color.rgb(0, 0, 150) else Color.BLUE
            "Yellow" ->         Color.YELLOW
            else -> Color.WHITE
        }
    }

    private fun setButtonColor(color : Int) {
        submitButton.setBackgroundColor(color)
    }
}