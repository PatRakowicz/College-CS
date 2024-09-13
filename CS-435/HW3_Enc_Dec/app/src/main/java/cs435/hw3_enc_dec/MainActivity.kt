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
    private lateinit var shiftBar: SeekBar
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

//        Init user text input/button
        inputText = findViewById(R.id.inputText)
        shiftBar = findViewById(R.id.shiftSeekBar)
        encryptButton = findViewById(R.id.encryptButton)

//        check if there is decrypted message being sent back
        val decryptedText = intent.getStringExtra("decryptedText")
        if (!decryptedText.isNullOrEmpty()) { inputText.setText(decryptedText) }

        encryptButton.setOnClickListener {
            val message = inputText.text.toString()
            val shift = shiftBar.progress

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
        val inputArray = message.toCharArray()
        for (i in inputArray.indices) {
            if (inputArray[i].isLetter()) {
                val baseValues = if (inputArray[i].isUpperCase()) 'A' else 'a'
                inputArray[i] = ((inputArray[i] - baseValues + shift) % 26 + baseValues.code).toChar()
            }
        }
        return String(inputArray)
    }
}