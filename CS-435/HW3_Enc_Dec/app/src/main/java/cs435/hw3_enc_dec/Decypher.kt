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

class Decypher : AppCompatActivity() {

    private lateinit var outputText: EditText
    private lateinit var shiftSeekBar: SeekBar
    private lateinit var decryptButton: Button
    private lateinit var backButton: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_decypher)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        outputText = findViewById(R.id.outputText)
        shiftSeekBar = findViewById(R.id.shiftSeekBar)
        decryptButton = findViewById(R.id.decryptButton)
        backButton = findViewById(R.id.backButton)

        outputText.isEnabled = false
        shiftSeekBar.isEnabled = false

        val encryptedMessage = intent.getStringExtra("encryptedMessage")
        val shift = intent.getIntExtra("shift", 0)

        outputText.setText(encryptedMessage)
        shiftSeekBar.progress = shift

        decryptButton.setOnClickListener {
            val decryptedMessage = decryptMessage(encryptedMessage!!, shift)
            outputText.setText(decryptedMessage)
            shiftSeekBar.progress = 0
        }

        backButton.setOnClickListener {
            val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)
        }
    }

    private fun decryptMessage(message: String, shift: Int): String {
        val charArray = message.toCharArray()
        for (i in charArray.indices) {
            if (charArray[i].isLetter()) {
                val base = if (charArray[i].isUpperCase()) 'A' else 'a'
                charArray[i] = ((charArray[i] - base - shift + 26) % 26 + base.code).toChar()
            }
        }
        return String(charArray)
    }
}