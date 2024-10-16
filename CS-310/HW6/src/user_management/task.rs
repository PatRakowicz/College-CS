use std::fmt::Debug;
use crate::user_management::profiles::Profile;


// Resource | https://www.youtube.com/watch?v=gRAVZv7V91Q&ab_channel=leddoo
pub struct Task<'lt, T: Debug> {
    pub id: i32,
    pub description: String,
    pub employees: Vec<&'lt Profile<'lt, T>>
}

impl<'lt, T: Debug> Task<'lt, T> {
    pub fn new (id: i32, description: String, employees: Vec<&'lt Profile<T>>) -> Self {
        Self {
            id,
            description,
            employees,
        }
    }

    pub fn display(&self) {
        println!("Task ID: {}", self.id);
        println!("Description: {}", self.description);
        println!("Assigned Employees:");
        for i in &self.employees {
            println!("Email: {}", i.email)
        }

    }
}