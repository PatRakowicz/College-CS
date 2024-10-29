package cs435.hw9

class Books (
    val id : Int,
    val title: String,
    val author: String,
    val coverImage: Int
) {
    companion object {
        val books = listOf(
            Books(1, "To Kill a Mockingbird", "Harper Lee", R.drawable.cover_mockingbird),
            Books(2, "1984", "George Orwell", R.drawable.cover_1984),
            Books(3, "Ready Player One", "Ernest Cline", R.drawable.cover_ready_player_one),
            Books(4, "The Great Gatsby", "F. Scott Fitzgerald", R.drawable.cover_gatsby),
            Books(5, "Moby-Dick", "Herman Melville", R.drawable.cover_mobydick)
        )
    }
}