pub struct Profile<T> {
    pub user_id: T,
    pub name: String,
    pub email: String,
}

// Build was giving me an error so it suggested to add
// : std::fmt::Debug
impl<T: std::fmt::Debug> Profile<T> {
    pub fn new(user_id: T,name: &str, email: &str) -> Self {
        Self {
            user_id,
            email: email.to_string(),
            name: name.to_string(),
        }
    }

    pub fn display(&self) {
        println!("~~~Profle Information: ");
        println!("User ID: {:?}", self.user_id);
        println!("Name: {}", self.name);
        println!("Email: {}", self.email);
    }
}