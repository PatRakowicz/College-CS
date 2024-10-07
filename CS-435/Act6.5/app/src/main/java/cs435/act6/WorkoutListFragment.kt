package cs435.act6

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.AdapterView
import android.widget.AdapterView.OnItemClickListener
import android.widget.ArrayAdapter
import android.widget.ListView


class WorkoutListFragment : Fragment() {

    private lateinit var listView : ListView
    private var itemClickListener : AdapterView.OnItemClickListener? = null

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view =  inflater.inflate(R.layout.fragment_workout_list, container, false)
        listView = view.findViewById(R.id.listViewWorkouts)

        listView.adapter = ArrayAdapter(
            requireContext(),
            android.R.layout.simple_list_item_1,
            Workout.workouts
        )

        listView.onItemClickListener = itemClickListener

        return view
    }

    fun setOnItemClickListener(onItemClickListener: AdapterView.OnItemClickListener){
        itemClickListener = onItemClickListener
    }
}