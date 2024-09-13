package cs435.hw3_enc_dec

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.SeekBar
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private lateinit var inputText: EditText
    private lateinit var shiftSeekBar: SeekBar
    private lateinit var encryptButton: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        inputText = findViewById(R.id.inputText)
        shiftSeekBar = findViewById(R.id.shiftSeekBar)
        encryptButton = findViewById(R.id.encryptButton)

        encryptButton.setOnClickListener {
            val message = inputText.text.toString()
            val shift = shiftSeekBar.progress

            if (message.isNotEmpty()) {
                val encryptedMessage = encryptMessage(message, shift)

                val intent = Intent(this, Decypher::class.java)
                intent.putExtra("encryptedMessage", encryptedMessage)
                intent.putExtra("shift", shift)
                startActivity(intent)
            }
        }
    }

    private fun encryptMessage(message: String, shift: Int): String {
//        https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.text/to-char-array.html
        /*
        * This is used because it allows the edit of characters inside the given array to be
        * manipulated. Thus allowing for characters to be edited in a loop then pushed back
        * into an array.
        * */
        val charArray = message.toCharArray()
        for (i in charArray.indices) {
            if (charArray[i].isLetter()) {
                val base = if (charArray[i].isUpperCase()) 'A' else 'a'
                charArray[i] = ((charArray[i] - base + shift) % 26 + base.code).toChar()
            }
        }
        return String(charArray)
    }
}