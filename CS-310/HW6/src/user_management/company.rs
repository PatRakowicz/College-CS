use std::collections::HashMap;
use crate::user_management::profiles::Profile;
use std::fmt::Debug;
use std::cmp::PartialOrd;
use std::cmp::Ord;
use crate::user_management::task::Task;

//Resource - https://www.youtube.com/watch?v=juIINGuZyBc&ab_channel=Let%27sGetRusty
/// Struct representing a company with depart and profiles
pub struct Company<'lt, T: Debug + PartialOrd + Ord> {
    depart: HashMap<String, Vec<&'lt Profile<'lt, T>>>, // Maps department names to a list of profiles
    employee: Vec<&'lt Profile<'lt, T>>,
    task: Vec<Task<'lt, T>>
}

impl<'lt, T: Debug + PartialOrd + Ord> Company<'lt, T> {
    /// Creates a new `Company` with an initial department and profile
    pub fn new(initial_department: &str, initial_profile: &'lt Profile<T>) -> Self {
        let mut depart = HashMap::new();
        let mut employee = Vec::new(); // new employee to an empty vector
        let mut task= Vec::new(); // new task to empty vector

        depart.insert(initial_department.to_string(), vec![initial_profile]);

        Self { depart, employee, task }
    }

    /// Adds a new profile to the specified department
    pub fn add_profile(&mut self, department: &str, profile: &'lt Profile<'lt, T>) {
        self.depart
            .entry(department.to_string())
            .or_insert_with(Vec::new)
            .push(profile);
    }

    /// Retrieves a reference to the profiles of the specified department
    pub fn get_department_profiles(&self, department: &str) -> Option<&Vec<&'lt Profile<'lt, T>>> {
        self.depart.get(department)
    }

    /// Lists all profiles in all depart
    pub fn list_all_profiles(&self) {
        for (department, profiles) in &self.depart {
            println!("Department: {}", department);
            for profile in profiles { profile.display(); }
        }
    }

    /// Adds a new employee to the vector given the input of generic Profile
    pub fn add_employee(&mut self, employee: &'lt Profile<T>) { self.employee.push(employee) }


    /// Gets the employee profile
    pub fn get_employee_profiles(&'lt self, employeeIDs: &Vec<T>) -> Vec<&'lt Profile<'lt, T>> {
        let mut checkedProfile = Vec::new();

        for i in &self.employee {
            for y in employeeIDs {
                if &i.user_id == y {
                    checkedProfile.push(*i);
                    break;
                }
            }
        }
        checkedProfile
    }

    /// Assigns a new given task and pushes to task vector to store
    // getting cannon borrow self.task mutable because it is also borrowed as immutable
    // asked chat on why this error is happening to the below function
    /*pub fn assign_task(&'lt mut self, description: String, employee_id: Vec<T>) {
        let employee_profile = self.get_employee_profiles(&employee_id);
        let mut set_id = 0;

        for i in &self.task {
            if i.id > set_id {
                set_id = i.id;
            }
        }

        let task_id = set_id + 1;
        self.task.push(Task::new(task_id, description, employee_profile));
    }*/
    // set the set_id in a separate loop or use a different method that doesn't require borrowing
    // line 90, iterates thought the task and gets the max id, returns 0 if no task, ensuring first task starts with 1
    pub fn assign_task(&mut self, description: String, employee_id: Vec<T>) {
        let employee_profile = self.get_employee_profiles(&employee_id);

        // Find the max task id (without borrowing self.task mutably)
        let set_id = self.task.iter().map(|t| t.id).max().unwrap_or(0);

        // Increment the set_id for the new task
        let task_id = set_id + 1;

        // Now you can safely push a new task
        self.task.push(Task::new(task_id, description, employee_profile));
    }
    // still getting lifetime may not live long enough....
    // it's somewhere in my task.rs and I don't know where

    /// Displays employees tasks, and who is assigned to them.
    pub fn display_EmployeeTask(&self) {
        println!("Employee Tasks:");
        for i in &self.task {
            println!("Task ID: {}", i.id);
            println!("Task ID: {}", i.description);
            for y in &i.employees {
                println!("Employee Name: {}", y.email);
            }
            println!("~~~~");
        }
    }
}