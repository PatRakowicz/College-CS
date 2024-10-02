package cs435.exam1

import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.ListView
import android.widget.Toast
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import kotlin.random.Random

class MainActivity : AppCompatActivity() {

    private val numberList = ArrayList<Int>()
    private lateinit var listView : ListView
    private lateinit var buttonNew : Button
    private lateinit var buttonSum : Button
    private lateinit var buttonClear : Button

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
        buttonNew = findViewById(R.id.buttonNew)
        buttonSum = findViewById(R.id.buttonSum)
        buttonClear = findViewById(R.id.buttonClear)

        val adapter = ArrayAdapter(this, android.R.layout.simple_list_item_1, numberList)
        listView.adapter = adapter

        buttonNew.setOnClickListener {
            val newNumber = Random.nextInt(0, 10)
            numberList.add(newNumber)
            adapter.notifyDataSetChanged()
        }

        buttonSum.setOnClickListener {
            val sum = calculateSum(numberList)
            Toast.makeText(this, "Total Sum: $sum", Toast.LENGTH_SHORT).show()
        }

        buttonClear.setOnClickListener {
            numberList.clear()
            adapter.notifyDataSetChanged()
        }

        listView.setOnItemClickListener { _, _, i, _ ->
            numberList[i] = -numberList[i]
            adapter.notifyDataSetChanged()
        }

        listView.setOnItemLongClickListener { _, _, i, _ ->
            numberList.removeAt(i)
            adapter.notifyDataSetChanged()
            true
        }
    }

    private fun calculateSum(numbers: List<Int>): Int {
        var sum = 0
        for (number in numbers) {
            sum += number
        }
        return sum
    }
}





