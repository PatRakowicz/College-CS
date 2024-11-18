package cs435.lab12

import android.os.Bundle
import android.util.Log
import android.widget.ArrayAdapter
import android.widget.ListView
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
import java.io.InputStreamReader
import java.net.HttpURLConnection
import java.net.URL
import kotlin.math.max

class MainActivity : AppCompatActivity() {
    private lateinit var listView : ListView
    private var factsList : MutableList<String> = mutableListOf()
    private lateinit var adapter : ArrayAdapter<String>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        listView = findViewById(R.id.listView)

        adapter = ArrayAdapter(
            this@MainActivity,
            android.R.layout.simple_list_item_1,
            factsList
        )
        listView.adapter = adapter
        
        fetchCatFacts()
    }

    private fun fetchCatFacts() {
        CoroutineScope(Dispatchers.IO).launch {
            var result = ""
            var httpURLConnection: HttpURLConnection? = null
            try {
                val limit = 1000
                val charLimit = 140
                var url = URL("https://catfact.ninja/facts?limit=$limit&max_length=$charLimit")

                httpURLConnection = url.openConnection() as HttpURLConnection
                httpURLConnection.requestMethod = "GET"

                if (httpURLConnection.responseCode != HttpURLConnection.HTTP_OK) {
                    result = "BAD CONNECTION"
                } else {
                    val bufferReader =
                        BufferedReader(InputStreamReader(httpURLConnection.inputStream))

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
                    val factsList = mutableListOf<String>()
                    val jsonObject = JSONObject(result)
                    val jsonArray = jsonObject.getJSONArray("data")
                    for (i in 0 until jsonArray.length()) {
                        factsList.add(jsonArray.getJSONObject(i).getString("fact"))
                    }

                    adapter.notifyDataSetChanged();
                } catch (e: Exception) {
                    Log.d("result ERROR ", e.toString())
                }
            }
        }
    }
}
