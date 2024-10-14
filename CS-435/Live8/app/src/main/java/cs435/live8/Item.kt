package cs435.live8

import kotlin.random.Random

class Item (var red:Int? = null, var green:Int? = null, var blue:Int? = null ) {
    init {
        red = Random.nextInt(256)
        green = Random.nextInt(256)
        blue = Random.nextInt(256)
    }
}