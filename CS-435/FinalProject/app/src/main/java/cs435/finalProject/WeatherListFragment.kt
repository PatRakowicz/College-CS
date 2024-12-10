package cs435.finalProject

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ListView
import android.widget.SimpleAdapter

class WeatherListFragment : Fragment() {

    private lateinit var db: DBController

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_weather_list, container, false)
        val listView = view.findViewById<ListView>(R.id.weather_list)

//        db = DBController(requireContext())
//
//        val data = db.getRawWeatherData()
//
//        val adapter = SimpleAdapter(
//            requireContext(),
//            data,
//            android.R.layout.simple_list_item_2,
//            arrayOf("timestamp", "details"),
//            intArrayOf(android.R.id.text1, android.R.id.text2)
//        )
//        listView.adapter = adapter


        return view
    }
}