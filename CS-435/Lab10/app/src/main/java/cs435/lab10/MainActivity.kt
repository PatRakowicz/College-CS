package cs435.lab10

import android.content.ContentValues
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlin.random.Random

class MainActivity : AppCompatActivity() {

    var currentNum = 0
    private lateinit var DBHelper : DBHelper

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }

    fun Add(view : View) {
        val SQLdb = DBHelper.readableDatabase
        val randomNum = Random.nextInt(9)
        val randomName : Array<String> =  arrayOf("one", "two", "three", "four", "five", "six", "seven")

        val values = ContentValues().apply{
            put("number", randomNum)
            put("name", randomName[randomNum])
        }
        SQLdb?.insert("numbers", null, values)

        currentNum++
        findViewById<TextView>(R.id.textView).text = currentNum.toString()
    }
}