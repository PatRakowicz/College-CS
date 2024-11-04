package com.example.activity11

class Beer(
    var name: String? = null,
    var description: String? = null,
    var imageResourceID: Int? = null) {

    companion object {
        val beers = arrayOf(
            Beer("Boneyard RPM", "well-balanced IPA from Bend, OR", R.drawable.boneyard),
            Beer("Crux Pilz", "delicious pilsner for after biking", R.drawable.crux),
            Beer("Deschutes Obsidian Stout", "good dark beer for post skiing", R.drawable.stout)
        )
    }

    override fun toString(): String {
        return name?: ""
    }
}
