pub struct Book {
    title: String,
    author: String,
    on_loan: bool,
}

impl Book {
    pub fn new(title: &str, author: &str) {
        Self {
            title: title.to_string(),
            author: author.to_string(),
            on_loan: false
        };
    }

    pub fn display(&self) -> String {
        format!("{} by {}", self.title, self.author)
    }
}