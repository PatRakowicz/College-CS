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
        val input = findViewById<EditText>(R.id.inputText)
        val shift = findViewById<SeekBar>(R.id.shiftSeekBar)
        val encryptBut = findViewById<Button>(R.id.encryptButton)

//        Check if there is a decrypted message being sent back
        val decryptedText = intent.getStringExtra("decryptedText")
        if (!decryptedText.isNullOrEmpty()) { input.setText(decryptedText) }

        encryptBut.setOnClickListener {
            if (input.text.toString().isNotEmpty()) {
                val encryptedMessage = encryptMsg(input.text.toString(), shift.progress)

                val intent = Intent(this, Decypher::class.java)
                intent.putExtra("encryptedMessage", encryptedMessage)
                intent.putExtra("shift", shift.progress)
                startActivity(intent)
            }
        }
    }

    private fun encryptMsg(message: String, shift: Int): String {
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