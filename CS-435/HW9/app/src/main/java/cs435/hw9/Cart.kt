package cs435.hw9

class Cart {
    companion object {
        private val cartItems = mutableListOf<Books>()
        private var deliveryDate: String? = null
        private var deliveryTime: String? = null

        fun getCartItems(): List<Books> { return cartItems }

        fun clearCart() {
            cartItems.clear()
            deliveryDate = null
            deliveryTime = null
        }

        fun addToCartById(bookId: Int) {
            val book = Books.books.find { it.id == bookId }
            if (book != null) { cartItems.add(book) }
        }

        fun updateDeliveryDate(date: String) { deliveryDate = date }
        fun updateDeliveryTime(time: String) { deliveryTime = time }
        fun retrieveDeliveryDate(): String? = deliveryDate
        fun retrieveDeliveryTime(): String? = deliveryTime
    }
}