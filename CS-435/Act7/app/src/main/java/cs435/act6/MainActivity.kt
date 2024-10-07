package cs435.act6

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.AdapterView
import android.widget.FrameLayout
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.fragment.app.FragmentTransaction

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

        val work =
            supportFragmentManager.findFragmentById(R.id.fragmentContainerView) as? WorkoutListFragment


        /*work?.setOnItemClickListener(object : AdapterView.OnItemClickListener{
            override fun onItemClick(p0: AdapterView<*>?, p1: View?, p2: Int, p3: Long) {
                val workoutDetailFragment = WorkoutDetailFragment()
                workoutDetailFragment.setWorkoutID(p2)

                val ft = supportFragmentManager.beginTransaction()
                ft.replace(R.id.frameLayout, workoutDetailFragment)

                // not required, will see in documentation
                ft.addToBackStack(null)
                ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE)

                ft.commit()
            }
        })*/

//        Lambda Expression
        work?.setOnItemClickListener { p0, p1, p2, p3 ->
            val frame: FrameLayout? = findViewById(R.id.frameLayout)
            if (frame != null) {

                val workoutDetailFragment = WorkoutDetailFragment()
                workoutDetailFragment.setWorkoutID(p2)

                val ft = supportFragmentManager.beginTransaction()
                ft.replace(R.id.frameLayout, workoutDetailFragment)
                ft.addToBackStack(null)
                ft.setTransition(FragmentTransaction.TRANSIT_FRAGMENT_FADE)
                ft.commit()
            } else {
                val intent = Intent(applicationContext, WorkoutDetailActivity::class.java)
                intent.putExtra("ID", p2)
                startActivity(intent)
            }
        }
    }
}