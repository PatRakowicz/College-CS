package cs435.lab4

import android.os.Bundle
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {

    private lateinit var textView: TextView
    private val stringBuilder = StringBuilder()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)

        textView = findViewById(R.id.lifecycleTextView)

        if (savedInstanceState != null) {
            stringBuilder.append(savedInstanceState.getString("saved_events"))
            textView.text = stringBuilder.toString()
        }

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        trackEvent("onCreate")
    }

    override fun onStart() {
        super.onStart()
        trackEvent("onStart")
    }

    override fun onResume() {
        super.onResume()
        trackEvent("onResume")
    }

    override fun onPause() {
        super.onPause()
        trackEvent("onPause")
    }

    override fun onStop() {
        super.onStop()
        trackEvent("onStop")
    }

    override fun onDestroy() {
        super.onDestroy()
        trackEvent("onDestroy")
    }

    private fun trackEvent(event: String) {
        stringBuilder.append(event).append("\n")
        textView.text = stringBuilder.toString()
    }

    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        outState.putString("saved_events", stringBuilder.toString())
    }
}
