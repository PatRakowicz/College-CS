package com.example.act81

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.activity.result.contract.ActivityResultContracts
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    private lateinit var textView : TextView
    companion object {
        const val RESULT_CODE: Int = 55
        const val KEY:String = "TEXT"
    }

    private val startForResult = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) {
        result ->
        if (result.resultCode == RESULT_CODE) {
            val data = result.data
            val msg  = data?.getStringExtra(KEY)
            textView.text = msg
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        textView = findViewById(R.id.textViewMain)
    }

    fun onClick(view: View) {
        val intent = Intent(applicationContext, SecondActivity::class.java)
        startForResult.launch(intent)
    }
}