package cs435.lab7

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup

class ParentFragment : Fragment() {

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_parent, container, false)

        val childFragment1 = ChildFragment()
        childFragmentManager.beginTransaction()
            .replace(R.id.frameLayoutForChild1, childFragment1)
            .commit()

        val childFragment2 = ChildFragment()
        childFragmentManager.beginTransaction()
            .replace(R.id.frameLayoutForChild2, childFragment2)
            .commit()

        return view
    }
}