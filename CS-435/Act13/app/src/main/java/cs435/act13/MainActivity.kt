package cs435.act13

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.lifecycleScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.delay
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext

class MainActivity : AppCompatActivity() {
    private val RESULT_1 = "Result1"
    private val RESULT_2 = "Result2"
    private lateinit var textResult: TextView
    private lateinit var button : Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        textResult = findViewById(R.id.textView)
        button = findViewById(R.id.button)
        button.setOnClickListener { callAPI() }
    }

    fun callAPI() {
        // Old method, needs to be closed after use
        /*CoroutineScope(Dispatchers.IO).launch {
            Log.d("Thread", Thread.currentThread().name)
        }*/
        button.isEnabled = true
        lifecycleScope.launch(Dispatchers.IO) {
            fakeAPIRequest()
        }
        Log.d("button Check", "clicked")
    }


    private suspend fun fakeAPIRequest() {
        try {
            // Get API response
            val result1 = getResult1FromAPI()

            // update textView
            //textResult.text = result
            setNewText(result1)

            var result2 = getResult2FromAPI(result1)
            setNewText(result2)
            withContext(Dispatchers.Main) { button.isEnabled = false }
        } catch (e: Exception) {
            val newText = textResult.text.toString() + "\n ERROR $e"
            textResult.text = newText
        }
    }


    private suspend fun getResult1FromAPI(): String {
        delay(1000)
        Log.d("Thread", Thread.currentThread().name)
        return RESULT_1
    }
    private suspend fun getResult2FromAPI(result1: String): String {
        delay(1000)
        Log.d("Thread", Thread.currentThread().name)
        return RESULT_2 + " | " + result1
    }

    private suspend fun setNewText(result: String) {
        withContext(Dispatchers.Main) {
            val newText = textResult.text.toString() + "\n$result"
            textResult.text = newText
        }
    }
}