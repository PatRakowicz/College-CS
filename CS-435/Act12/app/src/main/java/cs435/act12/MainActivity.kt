package cs435.act12

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import org.json.JSONObject
import java.io.BufferedReader
import java.io.IOException
import java.io.InputStream
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL

class MainActivity : AppCompatActivity() {
    private lateinit var id: TextView
    private lateinit var joke: TextView
    private lateinit var textResult : TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        id = findViewById(R.id.textViewID)
        joke = findViewById(R.id.textViewJoke)
        textResult = findViewById(R.id.textViewResult)
    }

    fun onClickGetJoke(view: View) {
        fetchJoke()
    }

    private fun fetchJoke() {
        CoroutineScope(Dispatchers.IO).launch {
            var result = ""
            var httpURLConnection: HttpURLConnection? = null
            try {

                var url = URL("https://official-joke-api.appspot.com/jokes/random")

                httpURLConnection = url.openConnection() as HttpURLConnection
                httpURLConnection.requestMethod = "GET"

                if (httpURLConnection.responseCode != HttpURLConnection.HTTP_OK) {
                    result = "BAD CONNECTION"
                } else {
                    val bufferReader = BufferedReader(InputStreamReader(httpURLConnection.inputStream))
                    result = bufferReader.readText()
                    bufferReader.close()
                }
            } catch (e: IOException) {
                e.printStackTrace()
            } finally {
                httpURLConnection?.disconnect()
            }

            withContext(Dispatchers.Main) {
                try {
                    val jsonObject = JSONObject(result)
                    val jokeID = jsonObject.getInt("id")
                    val jokeSetup = jsonObject.getString("setup")
                    val jokeResult = jsonObject.getString("punchline")

                    id.text = jokeID.toString()
                    joke.text = jokeSetup.toString()
                    textResult.text = jokeResult.toString()
                } catch (e: Exception) {
                    Log.d("result ERROR ", e.toString())
                }
            }
        }
    }
}