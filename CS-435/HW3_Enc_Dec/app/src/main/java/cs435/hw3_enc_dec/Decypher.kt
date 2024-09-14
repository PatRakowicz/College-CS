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
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_decypher)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val output = findViewById<EditText>(R.id.outputText)
        val shiftBar = findViewById<SeekBar>(R.id.shiftSeekBar)
        val decryptButton = findViewById<Button>(R.id.decryptButton)

        output.isEnabled = false
        shiftBar.isEnabled = false

        val encryptedMsg = intent.getStringExtra("encryptedMessage")
        val shift = intent.getIntExtra("shift", 0)

        output.setText(encryptedMsg)
        shiftBar.progress = shift

        decryptButton.setOnClickListener {
            val decryptedMessage = decryptMsg(encryptedMsg!!, shift)
            output.setText(decryptedMessage)
            shiftBar.progress = 0

            val intent = Intent(this, MainActivity::class.java)
            intent.putExtra("decryptedText", decryptedMessage)
            startActivity(intent)
        }
    }

    private fun decryptMsg(message: String, shift: Int): String {
        val inputArray = message.toCharArray()
        for (i in inputArray.indices) {
            if (inputArray[i].isLetter()) {
                val baseVales = if (inputArray[i].isUpperCase()) 'A' else 'a'
                inputArray[i] =
                    ((inputArray[i] - baseVales - shift + 26) % 26 + baseVales.code).toChar()
            }
        }
        return String(inputArray)
    }
}