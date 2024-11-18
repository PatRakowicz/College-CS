package cs435.hw12

import android.database.Cursor
import android.os.Bundle
import android.webkit.WebView
import android.widget.TextView
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class ComicDetailActivity : AppCompatActivity() {
    private lateinit var dbHelper: DBHelper

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_comic_detail)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        val comicId = intent.getIntExtra("comic_id", -1)
        if (comicId == -1) { finish(); return }

        dbHelper = DBHelper(this)

        val cursor: Cursor = dbHelper.getComic(comicId)
        if (cursor.moveToFirst()) {
            val num = cursor.getInt(cursor.getColumnIndexOrThrow("num"))
            val title = cursor.getString(cursor.getColumnIndexOrThrow("title"))
            val imgUrl = cursor.getString(cursor.getColumnIndexOrThrow("img"))

            val comicId : TextView = findViewById(R.id.comic_id)
            val comicTitle : TextView = findViewById(R.id.comic_title)
            val comicImg : WebView = findViewById(R.id.comic_image)

            comicId.text = "ID: $num"
            comicTitle.text = title.toString()
            comicImg.loadUrl(imgUrl.toString())
        }
        cursor.close()
    }
}