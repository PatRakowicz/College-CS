package cs435.act7

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
        val child = ChildFragment()
        val ft = childFragmentManager.beginTransaction()
        ft.replace(R.id.frameLayoutForChild, child)
        ft.commit()

        return view
    }
}