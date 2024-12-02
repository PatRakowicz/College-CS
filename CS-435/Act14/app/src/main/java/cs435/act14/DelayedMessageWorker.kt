package cs435.act14

import android.content.Context
import android.util.Log
import androidx.work.Worker
import androidx.work.WorkerParameters

class DelayedMessageWorker(context: Context, workerParams: WorkerParameters) :
    Worker(context, workerParams) {
    override fun doWork(): Result {
        val message = inputData.getString("message") ?: "no message"
        Log.d("Delayed Message worker", message)

        return Result.success()
    }

}