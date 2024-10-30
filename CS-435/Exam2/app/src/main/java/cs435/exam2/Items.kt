package cs435.exam2

import kotlin.random.Random

class Items (
    val number : Int
) {
    companion object{
        val Numbers = mutableListOf<Items>()
        fun addToList() {
            val newNum = Random.nextInt(100)
            Numbers.add(newNum)
        }
    }
}