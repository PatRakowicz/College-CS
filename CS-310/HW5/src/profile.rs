pub struct Profile {
    pub name: String,
    pub email: String,
}

impl Profile {}

impl Profile {
    pub fn new(name: &str, email: &str) -> Self {
        Self {
            email: email.to_string(),
            name: name.to_string(),
        }
    }

    pub fn display(&self) {
        println!("~~~Profle Information: ");
        println!("Name: {}", self.name);
        println!("Email: {}", self.email);
    }
}
