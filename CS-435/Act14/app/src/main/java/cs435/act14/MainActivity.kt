package cs435.act14

import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.work.Data
import androidx.work.OneTimeWorkRequestBuilder
import androidx.work.PeriodicWorkRequestBuilder
import androidx.work.WorkManager
import java.util.concurrent.TimeUnit

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


        DelayedMessageWorker.messageLiveData.observe(this) {
            msg -> Toast.makeText(this, msg, Toast.LENGTH_SHORT).show()
        }

    }
    fun buttonClick(view : View) {
        val message = "42"

        val inputData = Data.Builder().putString("message", message).build()

/*
        val workRequest = OneTimeWorkRequestBuilder<DelayedMessageWorker>()
            .setInitialDelay(10, TimeUnit.SECONDS)
            .setInputData(inputData)
            .build()
*/

        val workRequest = PeriodicWorkRequestBuilder<DelayedMessageWorker>(15, TimeUnit.MINUTES)
            .setInputData(inputData)
            .addTag("Delayed message worker")
            .build()

        WorkManager.getInstance(this).enqueue(workRequest)

    }

    override fun onDestroy() {
        super.onDestroy()
        Log.d("Worker Cancellation", "Worker was canceled")
        WorkManager.getInstance(this).cancelAllWorkByTag("Delayed message worker")
    }
}