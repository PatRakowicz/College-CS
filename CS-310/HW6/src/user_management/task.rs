use std::fmt::Debug;
use std::cmp::PartialOrd;
use std::cmp::Ord;
use crate::user_management::profiles::Profile;


// Resource | https://www.youtube.com/watch?v=gRAVZv7V91Q&ab_channel=leddoo
struct Task<'lt, T: Debug + PartialOrd + Ord> {
    id: i32,
    description: String,
    employees: Vec<&'lt Profile<'lt, T>>
}

impl<'lt, T: Debug + PartialOrd + Ord> Task<'lt, T> {
    pub fn new (id: i32, description: String, employees: Vec<&'lt Profile<T>>) -> Self {
        Self {
            id,
            description,
            employees,
        }
    }

    pub fn display(&self) {
        println!("~~~ Task Information ~~~");
        println!("Task ID: {}", self.id);
        println!("Description: {}", self.description);
        println!("Assigned Employees:");

        for i in &self.employees {
            println!("Email: {}", i.email)
        }

    }
    pub fn print_task(&self) {
        println!("Task ID: {}", self.id);
        println!("Description: {}", self.description);
        println!("Assigned Employees:");

        for i in &self.employees {
            println!("Email: {}", i.email)
        }
    }
}