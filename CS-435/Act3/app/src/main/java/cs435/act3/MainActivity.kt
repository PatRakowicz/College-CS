package cs435.act3

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private lateinit var buttonGo : Button
    private lateinit var textMsg : EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        buttonGo = findViewById(R.id.buttonGo)
        textMsg = findViewById(R.id.editTextMsg)
    }

    fun buttonGoClick(view : View) {

        val textmessage = textMsg.text.toString()
        val intent = Intent(this, SecondActivity::class.java)

        intent.putExtra("MSG", textmessage)


        startActivity(intent)
    }
}